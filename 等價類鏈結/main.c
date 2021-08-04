#include <stdio.h>
#include <stdlib.h>

typedef struct node *listpointer;
typedef struct node{
    int data;
    listpointer next;
};

listpointer makenode();
void addnode(listpointer ,int );

int main()
{
    int i,j;
    int num = 0;
    listpointer temp,seq[20];
    int out[20];
    for(i = 0;i<20;i++){
        seq[i] = makenode();
        seq[i]->data = i;
        out[i] = 0;
    }
    while(scanf("%d %d",&i,&j)){
        if(i == -1 && j == -1)
            break;
        addnode(seq[i],j);
        addnode(seq[j],i);

    }
    // 建立的鏈結
    printf("鏈結串列:\n");
    for(i=0;i<20;i++){
        temp = seq[i];
        for(;(temp);temp = temp->next)
            printf("%d ",temp->data);
        printf("\n");
    }
    // 從seq[0] 開始走訪 若seq[0]->next->data為5 且out[5] = False 則印出 接著 往seq[5]走訪 直到為NULL返回
    // 需要堆疊紀錄
    printf("走訪結果:\n");
    listpointer current;
    listpointer stack[25];
    int top = -1;
    for(i=0;i<20;i++){
        stack[++top] = seq[i];
        while(out[i])
            stack[top] = seq[++i];
        while(top!=-1){
            // print已走訪的數字
            if(!out[stack[top]->data]){
                printf("%5d ",stack[top]->data);
                out[stack[top]->data] = 1;
            }
            // 查看是否還有節點可拜訪 且 (若未輸出 則拜訪下個節點的數字 否則繼續走至下個節點)
            while(stack[top]->next){
                if(!out[stack[top]->next->data]){
                    stack[top+1] = seq[stack[top]->next->data];
                    top++;
                    break;
                }
                else
                    stack[top] = stack[top]->next;
            }
            // 已無下個節點可拜訪時 (pop該列seq[])
            if(!stack[top]->next)
                top--;
        }
        printf("\n");
    }
    return 0;
}


listpointer makenode(){
    listpointer new_node = malloc(sizeof(struct node));
    new_node->data = -1;
    new_node->next = NULL;
    return new_node;
}

void addnode(listpointer ptr,int data){
    listpointer temp = makenode();
    temp->data = data;
    if(ptr->next){
        temp->next = ptr->next;
        ptr->next = temp;
    }
    else
        ptr->next = temp;
}
