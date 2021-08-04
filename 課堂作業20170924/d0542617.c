#include <stdio.h>
#include <stdlib.h>

/*

�굲�Ұ�m��20170924 Binary Search

*/


int main (){
    int i=0,searchnum,data[10000];
    // Ū��
    FILE *ptr = fopen("sort_data.txt","r");
    while(!feof(ptr)){
        fscanf(ptr,"%d",&data[i]);
        i++;
    }
    fclose(ptr); // ����
    // �Ƨ�
    SelectionSort(data,10000);
    // �ϥΪ̿�J
    while(scanf("%d",&searchnum)!=EOF){
        if(BinarySearch(data,10000,searchnum) == 1)
            printf("���%d\n",searchnum);
        else
            printf("�����%d\n",searchnum);
    }
    return 0;
}

int BinarySearch(int data[],int n,int searchnum){
    int right,left;
    left = 0; // �����
    right = n-1; // �k���
    while(left<=right){ // ����ɥk��ɥ���������p�~��j�M
        if (data[((left+right)/2)] > searchnum)
            right = ((left+right)/2)-1; // �Y�����Ȥj��ؼмƦr�A���ʥk���
        else if (data[((left+right)/2)] < searchnum)
            left = ((left+right)/2)+1;// �Y�����Ȥp��ؼмƦr�A���ʥ����
        else
            return 1;
    }
    return 0;

}

void SelectionSort(int *data[],int n){ // ��ܱƧ�
    int min,temp,i,j;
    for(i=0;i<n;i++){
        min = data[i];
        for(j=i;j<n;j++){
            if(data[j]<min){ // �M��̤p��
                temp = min;
                min = data[j];
                data[j] = temp;
            }
        }
        data[i] = min; // �N��e�Ʀr�̤p�̱Ʀܭ���
    }
}

