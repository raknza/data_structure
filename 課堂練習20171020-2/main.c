#include <stdio.h>
#include <stdlib.h>
/*

課堂練習20171020 稀疏陣列儲存

*/

typedef struct{
    int col;
    int row;
    int value;
}term;


int main()
{
    FILE *fp;
    char c;
    fp = fopen("sparse.txt","r");
    int term_ori[8][8]={},i=0,j=0,num=0;
    while(1){
        if(feof(fp)) break;
        fscanf(fp,"%c",&c);
        if(c>='0' && c<='9'){
            term_ori[i][j] = c - '0';
            if(term_ori[i][j]!=0)
                num++;
            j++;
            if(j>7){
                if(i==7)
                    break;
                j = 0;
                i++;
            }
        }
    }
    fclose(fp);
   printf("原矩陣:\n");
    for(i=0;i<8;i++){
        for(j=0;j<8;j++)
            printf("%d ",term_ori[i][j]);
        printf("\n");
    }
    printf("\n\n");
    int k=1;
    term A[num+1];
    A[0].value = num;
    A[0].col = 8;
    A[0].row = 8;
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            if(term_ori[i][j] !=0){
                A[k].col = j;
                A[k].row = i;
                A[k].value = term_ori[i][j];
                k++;
            }
        }
    }
    printf("稀疏矩陣:\n");
    for(i=0;i<=A[0].value;i++)
        printf("A[%d] %d %d %d\n",i,A[i].row,A[i].col,A[i].value);
    printf("\n");
	// fast transport
	int rowTerms[A[0].value];
	int startingPos[A[0].value];
	
	for(i=0;i<=A[0].value;i++){
		rowTerms[i] = 0;
		startingPos[i] = 0;
	}
	
	for(i=1;i<=A[0].value;i++){
		rowTerms[A[i].col]++; // 儲存col編號i之數量  
	}
	startingPos[0] = 0;
	for(i=1;i<=A[0].value;i++){
		startingPos[i] = startingPos[i-1] + rowTerms[i-1]; // 起始位置 = 前一個位置 + 前一個col的數量 
	}
	printf("rowSize:\n");
	for(i=1;i<=A[0].value;i++)
        printf("%d ",rowTerms[i]);
    printf("\nstartingPos:\n");
	for(i=1;i<=A[0].value;i++)
        printf("%d ",startingPos[i]);  
    j=0;
    term B[num+1];
    B[0].value = A[0].value;
    B[0].col = A[0].col;
    B[0].row = A[0].row;
    for(i=1;i<=A[0].value;i++){
    	j = startingPos[A[i].col] + 1; // j = 起始位置[A[i]的col] + 1 
    	B[j].row = A[i].col;
    	B[j].col = A[i].row;
    	B[j].value = A[i].value;
    	startingPos[A[i].col]++;
	}
	printf("\n\n");
	printf("快速轉置矩陣:\n");
	for(i=0;i<=B[0].value;i++){
		printf("B[%d] %d %d %d\n",i,B[i].row,B[i].col,B[i].value);
	}
    return 0;
}
