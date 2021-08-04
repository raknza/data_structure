#include <stdio.h>
#include <stdlib.h>
/*

河內塔練習 20170922 - 20171003

分為三步驟：
1.將n-1個環從來源移動至中間（藉由目標）
2.將第n個移動至目標
3.再發動一次遞迴 將n-1個從中間移動至目標（藉由旁邊） 直到n==1

A與B的作用會一直互換 原本n個在A n-1個就會移動至B 再移動一次n-2個會到A 不斷更替
*/
int main()
{   int n;
    Tower(3,'A','C','B');
    return 0;
}

void Tower(int n,char from,char to,char aux){// 將n個移動至C
    if (n==1){ // n剩餘一個時 做最後一次移動 不必再發動遞迴（因n-1=0 0個需要移動）
        printf("Move %d from %c to %c\n",n,from,to); // 剩餘一個時將其移至C
    }
    else{
        Tower(n-1,from,aux,to); // 將n-1個全移動至中間
        printf("Move %d from %c to %c\n",n,from,to); // 將第n個移動至C
        // 上述完成一次遞迴(將第n個移動至C)
        Tower(n-1,aux,to,from); // 將第n-1個移動至C
    }

}
