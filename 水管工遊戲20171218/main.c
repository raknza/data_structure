#include <stdio.h>
#include <stdlib.h>

int dfs_maze(int ,int ,int);

// 宣告迷宮陣列
int maze[10][10]={};
int mark[10][10];
int book[10][10] ={};


int main()
{
    int i,j;
    // 標記初始化
    for(i=0;i<10;i++){
        for(j=0;j<10;j++)
            mark[i][j] = 0;
    }
    // 讀取迷宮檔案
    FILE *fp;
    fp = fopen("maze.txt","r");
    if(fp==NULL){
        printf("can't find maze file\n");
        return 0;
    }
    else{
        for(i=0;i<7;i++){
            for(j=0;j<6;j++)
                fscanf(fp,"%d",&maze[i][j]);
        }
    }
    fclose(fp);
    if(dfs_maze(1,1,4)){
        int i,j;
        printf("find\n");
        printf("now maze:\n");
        for(i=0;i<7;i++){
            for(j=0;j<6;j++)
                printf("%d ",maze[i][j]);
            printf("\n");
        }
    }
    else
        printf("無路可通\n");
    return 0;
}


int dfs_maze(int x,int y,int front){
    if(x == 5 && y == 5)
        return 1;
    // 超出邊界
    if(x < 1 || x > 4 || y < 1 || y > 5)
        return 0;
    if(mark[y][x] == 1)
        return 0;
    mark[y][x] = 1;

    int record = maze[y][x];
    int temp = 0;
    if( maze[y][x] <= 4 && maze[y][x]>=1){
        if(front == 1){
            if(dfs_maze(x+1,y,4)){
                record = 1;
                temp = 1;
            }
            if(dfs_maze(x-1,y,2)){
                record = 3;
                temp = 1;
            }
        }
        if(front == 2){
            if(dfs_maze(x,y-1,3)){
                record = 1;
                temp = 1;
            }
            if(dfs_maze(x,y+1,1)){
                record = 2;
                temp = 1;
            }
        }
        if(front == 3){
            if(dfs_maze(x+1,y,4)){
                record = 2;
                temp = 1;
            }
            if(dfs_maze(x-1,y,3)){
                record = 3;
            }
        }
        if (front == 4){
            if(dfs_maze(x,y+1,1)){
                record = 3;
                temp = 1;
            }
            if(dfs_maze(x,y-1,3)){
                record = 4;
                temp = 1;
            }
        }
    }
    else if(maze[x][y] >=5 && maze[x][y]<=6){
        if(front == 1){
            if(dfs_maze(x,y+1,1)){
                record = 6;
                temp = 1;
            }
        }
        if(front == 2){
            if(dfs_maze(x-1,y,2)){
                record = 5;
                temp = 1;
            }
        }
        if(front == 3){
            if(dfs_maze(x,y-1,3)){
                record = 6;
                temp = 1;

            }
        }
        if(front == 4){
            if(dfs_maze(x+1,y,4)){
                record = 5;
                temp = 1;
            }
        }
    }
    maze[y][x] = record;
    mark[y][x] = 0;
    if(temp == 1)
        printf("經過(%d,%d)\n",y,x);
    return temp;
}

