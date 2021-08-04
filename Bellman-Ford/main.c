#include <stdio.h>
#include <stdlib.h>
#define unlimited 9999

int graph[5][5];
int u[5],v[5],w[5];
int dis[5];
int min;

int queue[10];
int front=-1,rear = -1;
void push(int key){
    queue[(++rear)%10] = key;
}

int pop(){
    return queue[(++front)%10];
}

void Bellman_Ford(int );

int main()
{
    int i,j;
    int a,b,distance;
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            graph[i][j] = unlimited; // 無限遠
        }
    }
    for(i=0;i<5;i++)
        graph[i][i] = 0;
    printf("輸入圖形資訊:\n");
    i = 0;
    while(1){
        scanf("%d",&a);
        if(a == 0)
            break;
        scanf("%d %d",&b,&distance);
        graph[b-1][a-1] = distance;
        u[i] = a-1;
        v[i] = b-1;
        w[i] = distance;
        //printf("u[%d] = %d v[%d] = %d w[%d] = %d\n",i,u[i],i,v[i],i,w[i]);
        i++;
    }
    printf("原始圖\n");
    printf("   %3d%3d%3d%3d%3d\n",1,2,3,4,5);
    for(i=0;i<5;i++){
        printf("%3d",i+1);
        for(j=0;j<5;j++){
            if(graph[i][j] == unlimited)
                printf("%3c",'-');
            else
                printf("%3d",graph[i][j]);
        }
        printf("\n");
    }
    while(1){
        printf("輸入欲搜尋最短路徑之城市:\n");
        scanf("%d",&a);
        Bellman_Ford(a-1);
        for(i=0;i<5;i++){
            printf("dis[%d] = ",i+1);
            if(dis[i] == unlimited)
                printf("%c\n",'-');
            else
                printf("%d\n",dis[i]);
        }
    }

    return 0;
}

void Bellman_Ford(int source){
    int i ,j;
    int mark[5]={};
    for(i=0;i<5;i++)
        dis[i] = unlimited;
    dis[source] = 0;
    push(source);
    mark[source] = 1;
    while(1){
        int temp = pop();
        for(i=0;i<5;i++){
            if( u[i] == temp ){
                if ( dis[u[i]] + w[i] < dis[v[i]]){
                    dis[v[i]] = dis[u[i]] + w[i];
                    if( mark[v[i]] == 0 ){
                        push(v[i]);
                        mark[v[i]] = 1;
                        printf("push %d\n",v[i]+1);
                    }
                }
            }
        }
        mark[temp] = 0;
        if( front == rear )
            break;
    }
}

