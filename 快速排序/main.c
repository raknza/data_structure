#include <stdio.h>
#include <stdlib.h>
#define swap(x,y,z) ( z = x, x = y, y = z)

void QuickSort(int [],int,int);

int main()
{
    int num[100],i=0,j;
    printf("�п�J�Ʀr(-1�Y����)�G\n");
    while(1){
        scanf("%d",&num[i]);
        if(num[i] == -1)
            break;
        i++;
    }
    QuickSort(num,0,i-1);
    printf("�ֳt�Ƨǫ�G\n");
    for(j=0;j<i;j++)
        printf("%d ",num[j]);
    return 0;
}


void QuickSort(int num[],int left,int right){
    if(left > right)
        return;
    int base = left;
    int i = base; // �q�����k��j��base����
    int j = right; // �q�k������p��base����
    int temp;
    while(i!=j){ // �]��ǼƦb����A�]���ھڱƦC���ǡA����|�Ʀb���䪺�Ʀr�A�ûP��Ǽƥ洫
        //  �_�h�i���ܦ��N�ƦC���ǬۤϪ��Ʃ�����洫
        while(num[j] <= num[base] && i<j)
            j--;
       while(num[i] >= num[base] && i<j)
            i++;
        if( i < j)
            swap(num[i],num[j],temp);
    }
    swap(num[base],num[i],temp);
    printf("�ֳt�Ƨ�1�^��G\n");
    for(j=0;j<i;j++)
        printf("%d ",num[j]);
    system("PAUSE");
    QuickSort(num,left,i-1);
    QuickSort(num,i+1,right);
}
