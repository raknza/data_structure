#include <stdio.h>
#include <stdlib.h>
/*

練習20171025 老鼠走迷宮 - 找出口(堆疊應用) + 20171026 最短路徑

*/
typedef struct{
    int vert;
    int horiz;
}offsets;

typedef struct{
    int row;
    int col;
    int dir;
}element;

int main()
{
    // 方向定義
    offsets move[8];
    move[0].vert = -1;
    move[0].horiz  = 0;
    move[1].vert = -1;
    move[1].horiz  = 1;
    move[2].vert = 0;
    move[2].horiz  = 1;
    move[3].vert = 1;
    move[3].horiz  = 1;
    move[4].vert = 1;
    move[4].horiz  = 0;
    move[5].vert = 1;
    move[5].horiz  = -1;
    move[6].vert = 0;
    move[6].horiz  = -1;
    move[7].vert = -1;
    move[7].horiz  = -1;
    // 宣告迷宮陣列
    int maze[60][60]={};
    int row = 0;
    int col = 0;
    // 讀取迷宮檔案
    FILE *fp;
    fp = fopen("maze.txt","r");
    if(fp==NULL){
        printf("can't find maze file\n");
        return 0;
    }
    else{
        char c;
        do{
            c = getc(fp);
            if(c == '1' ||c == '0'){
                maze[row][col++] = c - '0';
            }
            else if(c=='\n'){
                row++;
                col = 0;
            }
        }while(~c);
    }
    row++;
    fclose(fp);
    // 宣告堆疊
    int top=-1;
    element stack[64];
    // 路徑標記
    int mark[13][17];
    int min_maze[13][17];
    int found = 0,i,j;
    // 起點終點定義
    stack[0].row = 1;
    stack[0].col = 1;
    stack[0].dir = 0;
    mark[1][1] = 1;
    top++;
    int min;
    int endrow = row-2;
    int endcol = col-2;
    // 迷宮走訪
    while(top>=0){  // 當堆疊不為空
        while(stack[top].dir<8){
            int nextrow = stack[top].row + move[stack[top].dir].vert;
            int nextcol =  stack[top].col + move[stack[top].dir].horiz;
            stack[top].dir++;
            if(maze[nextrow][nextcol]==0 && mark[nextrow][nextcol] == 0){ // 當下個位置為路且沒走過
                mark[nextrow][nextcol] = 1;
                stack[++top].row = nextrow;
                stack[top].col = nextcol;
                stack[top].dir = 0;
                if(nextrow == endrow && nextcol== endcol){
                	++found;
                	//printf("found road %d\n",found);
                	// 判斷當前路徑是否更佳
                	if(found == 1){
                		min = top;
                		// 複製當前路徑
                		for(i=0;i<row;i++){
								for(j=0;j<col;j++)
									min_maze[i][j] = mark[i][j];
							}
                	}
                	else{
                		if(min>top){
                			min = top;
                		// 複製當前路徑
                            for(i=0;i<row;i++){
                                    for(j=0;j<col;j++)
                                        min_maze[i][j] = mark[i][j];
                            }
                		}
					}
                	/*
                	for(i=0;i<row;i++){
            			for(j=0;j<col;j++){
                			if(mark[i][j] == 1)
                    			printf("0 ");
                			else
                    			printf("1 ");
            			}
            			printf("\n");
            		}*/
            		// 走到終點後退後
            		mark[stack[top].row][stack[top].col] = 0;
					top--;
            	}
            	// 若目前走的路比最短路徑大於或等於則pop
            	if(found>0 && top>=min){
            		mark[stack[top].row][stack[top].col] = 0;
            		top--;
				}

            }
        }
        // 退後時將行走的路徑標記拿掉
        mark[stack[top].row][stack[top].col] = 0;
        top--;
    }
    // 輸出迷宮路徑
    if(!found)
        printf("There is no path\n");
    else{
    	printf("遍歷:%d次 最短路徑:%d步\n\n",found,min);
    	for(i=0;i<row;i++){
            for(j=0;j<col;j++){
            	if(min_maze[i][j] == 1)
                    printf("0 ");
                else
                    printf("1 ");
            	}
            	printf("\n");
        }
	}
    return 0;
}

