#include <stdio.h>
#include <stdlib.h>

/*

資結課堂練習20170924 Binary Search

*/


int main (){
    int i=0,searchnum,data[10000];
    // 讀檔
    FILE *ptr = fopen("sort_data.txt","r");
    while(!feof(ptr)){
        fscanf(ptr,"%d",&data[i]);
        i++;
    }
    fclose(ptr); // 釋放
    // 排序
    SelectionSort(data,10000);
    // 使用者輸入
    while(scanf("%d",&searchnum)!=EOF){
        if(BinarySearch(data,10000,searchnum) == 1)
            printf("找到%d\n",searchnum);
        else
            printf("未找到%d\n",searchnum);
    }
    return 0;
}

int BinarySearch(int data[],int n,int searchnum){
    int right,left;
    left = 0; // 左邊界
    right = n-1; // 右邊界
    while(left<=right){ // 左邊界右邊界未交錯的情況繼續搜尋
        if (data[((left+right)/2)] > searchnum)
            right = ((left+right)/2)-1; // 若中間值大於目標數字，移動右邊界
        else if (data[((left+right)/2)] < searchnum)
            left = ((left+right)/2)+1;// 若中間值小於目標數字，移動左邊界
        else
            return 1;
    }
    return 0;

}

void SelectionSort(int *data[],int n){ // 選擇排序
    int min,temp,i,j;
    for(i=0;i<n;i++){
        min = data[i];
        for(j=i;j<n;j++){
            if(data[j]<min){ // 尋找最小值
                temp = min;
                min = data[j];
                data[j] = temp;
            }
        }
        data[i] = min; // 將當前數字最小者排至首位
    }
}

