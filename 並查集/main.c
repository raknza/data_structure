#include <stdio.h>
#include <stdlib.h>

int main()
{
    int robber[10];
    int i,j;
    for(i=0;i<10;i++)
        robber[i] = i; // �]�Ҧ��j�s�Y�ج��ۤv
    while(1){
        int a,b;
        scanf("%d %d",&a,&b);
        if(a == -1)
            break;
        while(robber[a] != a)
            a = robber[a];
        while(robber[b] != b){
            int temp = robber[b];
            robber[b] = a;
            b = robber[temp];
        }
        robber[b] = a;
    }
    int bucket[10]={};
    for(i=0;i<10;i++){
        int temp = i;
        while(robber[temp]!=temp)
            temp = robber[temp];
        bucket[temp]++;
    }
    int count = 0;
    for(i=0;i<10;i++){
        if(bucket[i])
            count++;
    }
    printf("�`�@:%d�Ӹs��\n",count);
    return 0;
}
