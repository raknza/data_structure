#include <stdio.h>
#include <stdlib.h>
#define R 2
#define Y 3
#define B 4
#define O 5
#define P 6
#define G 7
#define D 8


typedef struct{
    int color;
    int x;
    int y;
}element;

typedef struct{
    int vert;
    int horiz;
}offsets;

element queue[3][2000];
int front[3],rear[3];

void push(element data,int i){
    queue[i][(++rear[i])%2000].color = data.color;
    queue[i][rear[i]].x = data.x;
    queue[i][rear[i]].y = data.y;
}

element pop(int i){
    return queue[i][(++front[i])%2000];
}

int main()
{
    int N,i,j;
    int cloth[100][100]={};
    int visited[3][100][100] = {};
    // 方向定義
    offsets move[8];
    move[0].vert = 1;
    move[0].horiz  = 0;
    move[1].vert = 1;
    move[1].horiz  = 1;
    move[2].vert = 0;
    move[2].horiz  = 1;
    move[3].vert = -1;
    move[3].horiz  = 1;
    move[4].vert = -1;
    move[4].horiz  = 0;
    move[5].vert = -1;
    move[5].horiz  = -1;
    move[6].vert = 0;
    move[6].horiz  = -1;
    move[7].vert = 1;
    move[7].horiz  = -1;
    while(~scanf("%d",&N)){
        int max_R = 0;
        int max_Y = 0;
        int max_B = 0;
        int max_O = 0;
        int max_P = 0;
        int max_G = 0;
        int max_D = 0;
        for(i=0;i<3;i++){
            front[i] = -1;
            rear[i]  = -1;
        }
        int l;
        for(i=0;i<N;i++){
            for(j=0;j<N;j++){
                cloth[i][j] = 0;
                for(l=0;l<3;l++)
                    visited[l][i][j] = 0;
            }
        }
        char color;
        element temp;
        for(i=0;i<3;i++){
            getchar();
            scanf("%c %d %d",&color,&temp.x,&temp.y);
            if( color == 'R' )
                temp.color = R;
            if( color == 'Y' )
                temp.color = Y;
            if( color == 'B' )
                temp.color = B;
            visited[i][N-(temp.y+1)][temp.x] = 1;
            push(temp,i);
            cloth[N-(temp.y+1)][temp.x] = temp.color;
        }
        /*for(i=0;i<N;i++){
            for(j=0;j<N;j++)
                printf("%d ",cloth[i][j]);
            printf("\n");
        }*/
        getchar();
        scanf("%c",&color);
            if( color == 'R' )
                color = R;
            if( color == 'Y' )
                color = Y;
            if( color == 'B' )
                color = B;
        // 染色
        int k = 0;
        int tmp;
        while(1){
            tmp = rear[k];
            while(tmp != front[k]){
                temp = pop(k);
                for(i=0;i<8;i++){
                    int next_x = temp.x + move[i].horiz;
                    int next_y = temp.y + move[i].vert;
                    element newfill;
                    newfill.color = temp.color;
                    newfill.x = next_x;
                    newfill.y = next_y;
                    if( N-(next_y+1) >=0 && N-(next_y+1)< N && next_x >=0 && next_x <N  ){
                        if(visited[k][N-(next_y+1)][next_x]==0){
                            visited[k][N-(next_y+1)][next_x] = 1;
                            //printf("x:%d y:%d \n",next_x,next_y);
                            push(newfill,k);
                            if( cloth[N-(next_y+1)][next_x] <= B ){
                                if( cloth[N-(next_y+1)][next_x] != temp.color )
                                    cloth[N-(next_y+1)][next_x] = cloth[N-(next_y+1)][next_x] + temp.color;
                            }
                            else if( cloth[N-(next_y+1)][next_x] <= G ){
                                if( cloth[N-(next_y+1)][next_x] == O && temp.color == B )
                                    cloth[N-(next_y+1)][next_x] = D;
                                else if( cloth[N-(next_y+1)][next_x] == P && temp.color == Y )
                                    cloth[N-(next_y+1)][next_x] = D;
                                else if( cloth[N-(next_y+1)][next_x] == G && temp.color == R )
                                    cloth[N-(next_y+1)][next_x] = D;
                            }
                        }
                    }
                }
                if(k == 2 && tmp == front[k]){
                    int colo[8]={};
                    for(i=0;i<N;i++){
                        for(j=0;j<N;j++){
                            //printf("%d ",cloth[i][j]);
                            colo[cloth[i][j]]++;
                        }
                        //printf("\n");
                    }
                    //printf("\n");
                    if(colo[R] > max_R)
                        max_R = colo[R];
                    if(colo[Y] > max_Y)
                        max_Y = colo[Y];
                    if(colo[B] > max_B)
                        max_B = colo[B];
                    if(colo[O] > max_O)
                        max_O = colo[O];
                    if(colo[P] > max_P)
                        max_P = colo[P];
                    if(colo[G] > max_G)
                        max_G = colo[G];
                    if(colo[D] > max_D)
                        max_D = colo[D];
                    colo[R] = 0;
                    colo[Y] = 0;
                    colo[B] = 0;
                    colo[O] = 0;
                    colo[P] = 0;
                    colo[G] = 0;
                    colo[D] = 0;
                    //system("PAUSE");
                }
            }
            if( front[0] == rear[0] && front[1] == rear[1] && front[2] == rear[2])
                break;
            //printf("%d %d %d\n",k,front[k],rear[k]);
            k = (k+1)%3;
        }
        printf("%d \n",max_G);

    }
    return 0;
}
