#include <stdio.h>
#include <stdlib.h>

int main()
{
    int row1,col1,row2,col2,row3,col3,i,j,k;
    printf("input row1 col1:");
    scanf("%d %d",&row1,&col1);
    int matrix1[row1][col1];
    for(i=0;i<row1;i++){
        for(j=0;j<col1;j++)
            scanf("%d",&matrix1[i][j]);
    }
    printf("input row2 col2:");
    scanf("%d %d",&row2,&col2);
    int matrix2[row2][col2];
    for(i=0;i<row2;i++){
        for(j=0;j<col2;j++)
            scanf("%d",&matrix2[i][j]);
    }
    printf("matrix1:\n");
    for(i=0;i<row1;i++){
        for(j=0;j<col1;j++)
            printf("%2d",matrix1[i][j]);
        printf("\n");
    }
    printf("matrix2:\n");
    for(i=0;i<row2;i++){
        for(j=0;j<col2;j++)
            printf("%2d",matrix2[i][j]);
        printf("\n");
    }
    int matrix3[row1][col2];
    for(i=0;i<row1;i++){
        for(j=0;j<col2;j++)
            matrix3[i][j] = 0;
    }
    int t;
    for(i=0;i<row1;i++){
        for(j=0;j<col2;j++){
            for(k=0;k<col1;k++){
                matrix3[i][j] = matrix3[i][j] + matrix1[i][k]*matrix2[k][j];
                //printf("m[%d][%d] + = %d\n",i,j,matrix1[i][k]*matrix2[k][j]);
            }
        }
    }
    printf("matrix3:\n");
    for(i=0;i<row1;i++){
        for(j=0;j<col2;j++)
            printf("%4d",matrix3[i][j]);
        printf("\n");
    }
    system("PAUSE");
    return 0;
}
