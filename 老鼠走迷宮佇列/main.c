#include <stdio.h>
#include <stdlib.h>
/*

練習20171123 老鼠走迷宮 - queue歷遍(廣度優先搜尋)

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

void push(element);
element pop();

// 宣告佇列
int rear= -1;
int front = -1;
element queue[64];

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
    // 路徑標記
    int mark[13][17];
    int found = 0,i,j;
    // 起點終點定義
    element temp;
    temp.col = 1;
    temp.row = 1;
    temp.dir = 0;
    push(temp);
    mark[1][1] = 1;
    int min;
    int endrow = row-2;
    int endcol = col-2;
    int walk = 0;
    int walked = 0;
    // 迷宮走訪
    while(rear!=front){  // 當佇列不為空
        element fill;
        fill = pop();
        for(i=0;i<8;i++){
            int nextcol = fill.col + move[i].horiz;
            int nextrow = fill.row + move[i].vert;
            if(!maze[nextrow][nextcol] && (!mark[nextrow][nextcol]|| fill.dir < mark[nextrow][nextcol])){
                if(nextrow == endrow && nextcol == endcol)
                    found = 1;
                element new_fill;
                new_fill.row = nextrow;
                new_fill.col = nextcol;
                new_fill.dir = fill.dir+1;
                push(new_fill);
                mark[nextrow][nextcol] = fill.dir+1;
            }
        }
    }
    // 輸出迷宮路徑
    if(!found)
        printf("There is no path\n");
    else{
        printf("found!!\n");
    	for(i=0;i<row;i++){
            for(j=0;j<col;j++){
            	if(mark[i][j])
                    printf("%2d ",mark[i][j]);
                else
                    printf("XXX");
            	}
            	printf("\n");
        }
	}
    return 0;
}

void push(element item){
    queue[++rear].col = item.col;
    queue[rear].row = item.row;
    queue[rear].dir = item.dir;
}

element pop(){
    return queue[++front];
}
