#include <stdio.h>
#include <stdlib.h>
/*

姓名：張佑瑋
學號：D0542617
撰寫日期：20171010
dev-cpp版本：5.11.0.0
資結作業20171010 印出順、逆時針螺旋矩陣 

*/
int main()
{   int size,number=1,x=0,y=0,i,j;
    printf("請輸入矩陣寬度：");
	scanf("%d",&size); // 輸入矩陣大小 
    while(size > 10){
    	printf("錯誤！\n");
    	printf("請輸入矩陣寬度：");
    	scanf("%d",&size); // 重新輸入 
	}
    int martix[size][size]; // 宣告陣列 
    // 設定矩陣初值為0
    for(i=0;i<size;i++)
        for(j=0;j<size;j++)
            martix[i][j] = 0;
    // x,y為目前座標 向右為 +x 向左為-x 向上為-y 向下為+y 
    // 逆時針 方向以：下、右、上、左 為一次循環  
    while(number<=size*size){ // 當填入的數字不大於 size*size時 
        //向下
        while(martix[y][x]==0 && y<size){
            martix[y][x] =number;
            y++;
            number++;
        }
        y--; // 退後一格 
        x++; // 往下個方向前進一格 
        //向右
        while(martix[y][x]==0 && x<size){
            martix[y][x] =number;
            x++;
            number++;
        }
        x--;
        y--;
        //向上
        while(martix[y][x]==0 && y>-1){
            martix[y][x] =number;
            y--;
            number++;
        }
        y++;
        x--;
        //向左
        while(martix[y][x]==0 && x>-1){
            martix[y][x] = number;
            x--;
            number++;
        }
        x++;
        y++;
    }
    // 輸出矩陣 
    printf("逆時針：\n");
    for(i=0;i<size;i++){
        for(j=0;j<size;j++)
            printf("%4d",martix[i][j]); // 最大為10*10 最大只需要3格對齊 多空一格排版 
        printf("\n");
    }

    // 變數重設 
    for(i=0;i<size;i++)
        for(j=0;j<size;j++)
            martix[i][j] = 0;
    number = 1;
    x=0;
	y=0;
    // 順時針 方向以：右、下、左、上 為一次循環  
    while(number<=size*size){
        //向右
        while(martix[y][x]==0 && x<size){
            martix[y][x] =number;
            x++;
            number++;
        }
        x--;
        y++;
        //向下
        while(martix[y][x]==0 && y<size){
            martix[y][x] =number;
            y++;
            number++;
        }
        y--;
        x--;
        //向左
        while(martix[y][x]==0 && x>-1){
            martix[y][x] = number;
            x--;
            number++;
        }
        x++;
        y--;
        //向上
        while(martix[y][x]==0 && y>-1){
            martix[y][x] =number;
            y--;
            number++;
        }
        y++;
        x++;
    }
    // 輸出矩陣 
    printf("\n順時針：\n");
    for(i=0;i<size;i++){
        for(j=0;j<size;j++)
            printf("%4d",martix[i][j]);
        printf("\n");
    }
    return 0;
}
