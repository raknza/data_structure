#include <stdio.h>
#include <stdlib.h>
/*

�m��20171025 �ѹ����g�c - ��X�f(���|����) + 20171026 �̵u���|

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
    // ��V�w�q
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
    // �ŧi�g�c�}�C
    int maze[60][60]={};
    int row = 0;
    int col = 0;
    // Ū���g�c�ɮ�
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
    // �ŧi���|
    int top=-1;
    element stack[64];
    // ���|�аO
    int mark[13][17];
    int min_maze[13][17];
    int found = 0,i,j;
    // �_�I���I�w�q
    stack[0].row = 1;
    stack[0].col = 1;
    stack[0].dir = 0;
    mark[1][1] = 1;
    top++;
    int min;
    int endrow = row-2;
    int endcol = col-2;
    // �g�c���X
    while(top>=0){  // ����|������
        while(stack[top].dir<8){
            int nextrow = stack[top].row + move[stack[top].dir].vert;
            int nextcol =  stack[top].col + move[stack[top].dir].horiz;
            stack[top].dir++;
            if(maze[nextrow][nextcol]==0 && mark[nextrow][nextcol] == 0){ // ��U�Ӧ�m�����B�S���L
                mark[nextrow][nextcol] = 1;
                stack[++top].row = nextrow;
                stack[top].col = nextcol;
                stack[top].dir = 0;
                if(nextrow == endrow && nextcol== endcol){
                	++found;
                	//printf("found road %d\n",found);
                	// �P�_��e���|�O�_���
                	if(found == 1){
                		min = top;
                		// �ƻs��e���|
                		for(i=0;i<row;i++){
								for(j=0;j<col;j++)
									min_maze[i][j] = mark[i][j];
							}
                	}
                	else{
                		if(min>top){
                			min = top;
                		// �ƻs��e���|
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
            		// ������I��h��
            		mark[stack[top].row][stack[top].col] = 0;
					top--;
            	}
            	// �Y�ثe��������̵u���|�j��ε���hpop
            	if(found>0 && top>=min){
            		mark[stack[top].row][stack[top].col] = 0;
            		top--;
				}

            }
        }
        // �h��ɱN�樫�����|�аO����
        mark[stack[top].row][stack[top].col] = 0;
        top--;
    }
    // ��X�g�c���|
    if(!found)
        printf("There is no path\n");
    else{
    	printf("�M��:%d�� �̵u���|:%d�B\n\n",found,min);
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

