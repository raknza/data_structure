#include <stdio.h>
#include <stdlib.h>
#define swap(x,y,z) (z = x, x = y , y = z)

int getmax(int,int,int);
void pheap(int root,int level);
int heap[50];
int last = 1;

int main()
{
    int j;
    for(j=0;j<50;j++)
        heap[j] = 0;
    heap[0] = 9999;
    int select = 0;
    int value;
    printf("(1)add num (2)del num(pop) (3)print\n");
    while(select != 4 ){
        scanf("%d",&select);
        if(select == 1){
            int temp;
            printf("input a num:");
            scanf("%d",&value);
            heap[last++] = value;
            if(last!=2){
                int temp2 = last-1;
                while(heap[temp2] > heap[temp2/2]){
                    swap(heap[temp2],heap[temp2/2],temp);
                    temp2 = temp2/2;
                }
            }
            printf("add succeed\n");
        }
        else if(select == 2){
            int temp;
            // last -1 為末項元素
            // 將末項移動至根節點位置
            heap[1] = heap[last-1];
            last--;
            int i = 1;
            while( heap[i] < heap[i*2] || heap[i] < heap[i*2+1] ){
                if( !(i*2 < last))
                    break;
                int max = getmax(heap[i],heap[i*2],heap[i*2+1]);
                if(max == 1)
                    max = i;
                else if(max == 2)
                    max = i*2;
                else
                    max = i*2+1;
                if( (max) < last ) {
                    printf("swap %d %d\n",heap[i],heap[max]);
                    swap(heap[i],heap[max],temp);
                }
                i = max;
            }
            printf("del succeed\n");
        }
        else if(select == 3){
            pheap(1,1);
        }
    }
    return 0;
}


void pheap(int root,int level){
    if(root<last){
        pheap(root*2+1,level+1);
        int i;
        for(i=1;i<level;i++)
            printf("\t");
        printf("%d\n",heap[root]);
        pheap(root*2,level+1);
    }
}

int getmax(int a,int b,int c){
    if( a > b && a > c)
        return 1;
    else if( b > a && b > c )
        return 2;
    else if( c > a && c > b  )
        return 3;

}
