#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define height 6
#define width 8
#define side_cost 10

typedef struct Vector2{
    int x;
    int y;
}Vector2;

Vector2 openlist[width*height]; // 將要估算的點集合
Vector2 closelist[width*height]; // 已經估算完的點集合
int top[2] = {-1,-1};

int map[width][height]={};
Vector2 came_from[width][height];
int cost_g[width][height]={}; // 實際距離
int cost_h[width][height]={}; // 估計距離
int cost_f[width][height]={}; // 估計函數

Vector2 dir[8];

void pop(Vector2 list[],int index){
    int i;
    for(i=index;i<top[0];i++){
        list[i] = list[i+1];
    }
    top[0]--;
}



int distance(Vector2 start,Vector2 goal,int type){
    if( (start.x - goal.x !=0 && start.y - goal.y  !=0)&&type==0 ){
        int dx = goal.x - start.x;
        int dy = goal.y - start.y;
        if(dy<0)
            dy = -dy;
        if(dx<0)
            dx = -dx;
        return (dx-dy)>0?dx-dy*14+(dx-dy)*side_cost:dx-dy*14*-1+side_cost*(dy-dx) ;
    }
    else{
        int dx = goal.x - start.x;
        int dy = goal.y - start.y;
        if(dy<0)
            dy = -dy;
        if(dx<0)
            dx = -dx;

        return side_cost*(dx + dy);
    }
}

void PrintPath(Vector2 startPoint,Vector2 endPoint){
    Vector2 current_node;
    printf("(%d,%d)\n",endPoint.x,endPoint.y);
    current_node.x =  came_from[endPoint.x][endPoint.y].x;
    current_node.y =  came_from[endPoint.x][endPoint.y].y;
    while( current_node.x != startPoint.x || current_node.y != startPoint.y ){
        printf("(%d,%d)\n",current_node.x,current_node.y);
        int temp_x = came_from[current_node.x][current_node.y].x;
        int temp_y = came_from[current_node.x][current_node.y].y;
        current_node.x =  temp_x;
        current_node.y =  temp_y;
    }
    printf("(%d,%d)\n",current_node.x,current_node.y);
}

int Astar(Vector2 startPoint,Vector2 endPoint){
    Vector2 nowPoint;
    nowPoint.x = startPoint.x;
    nowPoint.y = startPoint.y;
    openlist[++top[0]].x = startPoint.x;
    openlist[top[0]].y = startPoint.y;
    while(top[0]>=0){
        int i;
        int min_f = 9999;
        int min_f_index;
        Vector2 min_f_point;
        // 搜尋openlist中估計函數最小節點
        for(i=0;i<=top[0];i++){
            if (min_f >= cost_f[openlist[i].x][openlist[i].y]){
                min_f = cost_f[openlist[i].x][openlist[i].y];
                min_f_point.x = openlist[i].x;
                min_f_point.y = openlist[i].y;
                min_f_index = i;
            }
        }
        if( min_f!=9999 && min_f_point.x == endPoint.x && min_f_point.y == endPoint.y ){
            printf("find\n");
            PrintPath(startPoint,endPoint);
            break;
        }
        // 移出openlist
        pop(openlist,min_f_index);
        // 移入clostlist
        closelist[++top[1]].x = min_f_point.x;
        closelist[top[1]].y = min_f_point.y;
        // 目前要擴展的點
        nowPoint.x =  min_f_point.x;
        nowPoint.y = min_f_point.y;
        // 遍歷相鄰的點
        for(i=0;i<8;i++){
            Vector2 nextPoint;
            nextPoint.x = nowPoint.x + dir[i].x;
            nextPoint.y = nowPoint.y + dir[i].y;
            int j,close;
            close = 0;
            // 若已被估算過或無法通過則跳過
            for(j=0;j<=top[1];j++){
                if( !(nextPoint.x >=0 && nextPoint.y  >= 0 && nextPoint.x < width && nextPoint.y < height && map[nextPoint.x][nextPoint.y] == 0) ||  nextPoint.x == closelist[j].x && nextPoint.y == closelist[j].y){
                    close = 1;
                }
            }
            if(close==0){
                // 計算g(n)
                int next_g_cost = cost_g[nowPoint.x][nowPoint.y] + distance(nowPoint,nextPoint,0);
                int next_f_cost = distance(nextPoint,endPoint,1);
                int j,open;
                open = 0;
                // 該點是否為將被估算的點 為非則 更新該節點g(n)
                for(j=0;j<=top[0];j++){
                    if(nextPoint.x == openlist[j].x && nextPoint.y == openlist[j].y)
                        open = 1;
                }
                if(  (nextPoint.x >=0 && nextPoint.y  >= 0 && nextPoint.x < width && nextPoint.y < height && map[nextPoint.x][nextPoint.y] == 0) && (open == 0 || next_g_cost < cost_g[nextPoint.x][nextPoint.y])  ){
                    cost_g[nextPoint.x][nextPoint.y] = next_g_cost;
                    cost_h[nextPoint.x][nextPoint.y] = distance(nextPoint,endPoint,1);
                    cost_f[nextPoint.x][nextPoint.y] = cost_g[nextPoint.x][nextPoint.y] + cost_h[nextPoint.x][nextPoint.y];
                    openlist[++top[0]].x = nextPoint.x;
                    openlist[top[0]].y = nextPoint.y;
                    //printf("(%d,%d)\n",nextPoint.x,nextPoint.y);
                    // 將目前節點設為拓展的點的父節點
                    came_from[nextPoint.x][nextPoint.y].x = nowPoint.x;
                    came_from[nextPoint.x][nextPoint.y].y = nowPoint.y;
                }
            }
        }
    }
    int i,j;
    for(i=0;i<height;i++){
        for(j=0;j<width;j++)
            printf("%3d ",cost_f[j][i]);
        printf("\n");
    }
}

int main()
{
    int i,j;
    // 初始化 八方向 從上方順時針繞一圈
    dir[0].x = 0;
    dir[0].y = -1;
    dir[1].x = 1;
    dir[1].y = -1;
    dir[2].x = 1;
    dir[2].y = 0;
    dir[3].x = 1;
    dir[3].y = 1;
    dir[4].x = 0;
    dir[4].y = 1;
    dir[5].x = -1;
    dir[5].y = 1;
    dir[6].x = -1;
    dir[6].y = 0;
    dir[7].x = -1;
    dir[7].y = -1;
    // 初始化 cost值
    for(i=0;i<height;i++){
        for(j=0;j<width;j++)
            cost_g[j][i] = 0;
    }
    // 地圖障礙
    map[4][1] = 1;
    map[4][2] = 1;
    map[4][3] = 1;
    Vector2 startPoint,endPoint;
    startPoint.x = 2;
    startPoint.y = 2;
    endPoint.x = 6;
    endPoint.y = 2;
    Astar(startPoint,endPoint);
    return 0;
}
