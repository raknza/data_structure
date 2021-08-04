#include <stdio.h>
#include <stdlib.h>
#define swap(x,y,z) (z = x , x = y , y = z)

void makeheap(int [],int);
void heapsort(int [],int);

int main()
{
    int tree[21];
    int num = 1,i;
    tree[0] = 9999;
    for(i=1;i<21;i++)
        tree[i] = -2;
    // 建立樹
    for(;tree[num-1]!=-1;num++)
        scanf("%d",&tree[num]);
    printf("陣列樹:\n");
    for(i=1;i<num-1;i++)
        printf("%d ",tree[i]);
    printf("\n");
    // 二元樹轉最大堆積
    makeheap(tree,num-1);
    printf("max heap:\n");
    for(i=1;i<num-1;i++)
        printf("%d ",tree[i]);

    return 0;
}

void heapsort(int heap[],int num){
    int i ;
    for(i=num;i>1;i--){

    }
}

void makeheap(int heap[],int num){
    int temp;
    int n = num/2;
    while(n >= 1){
        if(heap[n] < heap[n*2+1]){
            //printf("交換%d %d\n",heap[n],heap[n*2+1]);
            swap(heap[n],heap[n*2+1],temp);
            makeheap(heap,num);
        }
        if(heap[n] < heap[n*2]){
            //printf("交換%d %d\n",heap[n],heap[n*2]);
            swap(heap[n],heap[n*2],temp);
            makeheap(heap,num);
        }
        n--;
    }
}
