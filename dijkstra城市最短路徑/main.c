#include <stdio.h>
#include <stdlib.h>

void dijkstra(int);

int graph[5][5];
int d[5];
int min;

int main()
{
    int i,j;
    int a,b,distance;
    for(i=0;i<5;i++){
        d[i] = -1;
        for(j=0;j<5;j++){
            graph[i][j] = -1; // ��l�Ƭ��Ҧ��������۳q
        }
    }
    for(i=0;i<5;i++)
        graph[i][i] = 0;
    printf("�п�J��⫰���۶Z:\n");
    while(1){
        // ��J ��a����������b�������Z��
        scanf("%d",&a);
        if(a == 0)
            break;
        scanf("%d %d",&b,&distance);
        graph[a-1][b-1] = distance;
        graph[b-1][a-1] = distance;
    }
    printf("��ضZ����G\n");
    printf("   %3d%3d%3d%3d%3d\n",1,2,3,4,5);
    for(i=0;i<5;i++){
        printf("%3d",i+1);
        for(j=0;j<5;j++){
            printf("%3d",graph[i][j]);
        }
        printf("\n");
    }
    while(1){
        printf("�п�J���j�M�������̵u��|:\n");
        scanf("%d",&a);
        dijkstra(a-1);
        for(i=0;i<5;i++)
            printf("d[%d] = %d\n",i+1,d[i]);
    }

    return 0;
}

void dijkstra(int source){
    int visited[5];
    int i,j,n;
    for(i=0;i<5;i++){
        visited[i] = 0;
        d[i] = 100000;
    }
    d[source] = 0;
    for(n=0;n<5;n++){
        int a,b,min;
        a = -1;
        b = -1;
        min = 1000000;
        for(i=0;i<5;i++){
            if(!visited[i] && d[i] < min){
                a = i;
                min = d[i];
            }
        }
        //printf("�ثe�̵u��:(%d,%d) = %d\n",1,a+1,min);
        if(a == -1)
            break;
        for(j=0;j<5;j++){
            if( d[a] + graph[a][j] < d[j] && graph[a][j] > 0 ){
                d[j] = d[a] + graph[a][j];
            }
        }
        visited[a] = 1;
        //printf("�w�M��:%d\n",a+1);

    }
    for(i=0;i<5;i++){
        if(d[i] == 100000)
            d[i] = -1;
    }
}
