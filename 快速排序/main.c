#include <stdio.h>
#include <stdlib.h>
#define swap(x,y,z) ( z = x, x = y, y = z)

void QuickSort(int [],int,int);

int main()
{
    int num[100],i=0,j;
    printf("請輸入數字(-1即停止)：\n");
    while(1){
        scanf("%d",&num[i]);
        if(num[i] == -1)
            break;
        i++;
    }
    QuickSort(num,0,i-1);
    printf("快速排序後：\n");
    for(j=0;j<i;j++)
        printf("%d ",num[j]);
    return 0;
}


void QuickSort(int num[],int left,int right){
    if(left > right)
        return;
    int base = left;
    int i = base; // 從左往右找大於base的數
    int j = right; // 從右往左找小於base的數
    int temp;
    while(i!=j){ // 因基準數在左邊，因此根據排列順序，先找會排在左邊的數字，並與基準數交換
        //  否則可能變成將排列順序相反的數往左邊交換
        while(num[j] <= num[base] && i<j)
            j--;
       while(num[i] >= num[base] && i<j)
            i++;
        if( i < j)
            swap(num[i],num[j],temp);
    }
    swap(num[base],num[i],temp);
    printf("快速排序1回後：\n");
    for(j=0;j<i;j++)
        printf("%d ",num[j]);
    system("PAUSE");
    QuickSort(num,left,i-1);
    QuickSort(num,i+1,right);
}
