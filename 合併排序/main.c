#include <stdio.h>
#include <stdlib.h>

void MergePass(int [],int,int,int,int);
void MergeSort(int [],int,int);
int compare(int ,int);

int main()
{
    int i,num[20];
    for(i=0; i<20 && num[i-1]!=-1 ;i++)
        scanf("%d",&num[i]);
    MergeSort(num,0,i-2);
    int j;
    for(j=0;j<i-1;j++)
        printf("%d ",num[j]);
    return 0;
}


void MergeSort(int num[],int left,int right){
    if( (right - left) >= 1){
            int middle = (left+right)/2;
            //printf("上 %d %d\n",left,middle);
            MergeSort(num,left,middle);
            //printf("中 %d %d\n",middle+1,right);
            MergeSort(num,middle+1,right);
            //printf("合併： %d %d\n",left,right);
            MergePass(num,left,middle,middle+1,right);
    }
}

void MergePass(int num[],int leftA,int rightA,int leftB,int rightB){
    int new_num[ (rightA - leftA + 1)*2];
    int start = leftA;
    int top = 0;
    while(leftA<=rightA && leftB<=rightB){
        if(compare(num[leftA],num[leftB])){
            new_num[top++] = num[leftA];
            leftA++;
        }
        else{
            new_num[top++] = num[leftB];
            leftB++;
        }
    }
    for(leftA;leftA<=rightA;leftA++)
        new_num[top++] = num[leftA];
    for(leftB;leftB<=rightB;leftB++)
        new_num[top++] = num[leftB];
    int i;
    for(i = 0;i<top;i++)
        num[start++] = new_num[i];
    /*printf("排序完成：");
    for(i = 0;i<top;i++)
        printf("%d ",new_num[i]);
    printf("\n");*/

}

int compare(int a,int b){
    if(a<=b)
        return 1;
    else
        return 0;
}
