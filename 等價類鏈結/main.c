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
    // �إߪ��쵲
    printf("�쵲��C:\n");
    for(i=0;i<20;i++){
        temp = seq[i];
        for(;(temp);temp = temp->next)
            printf("%d ",temp->data);
        printf("\n");
    }
    // �qseq[0] �}�l���X �Yseq[0]->next->data��5 �Bout[5] = False �h�L�X ���� ��seq[5]���X ���쬰NULL��^
    // �ݭn���|����
    printf("���X���G:\n");
    listpointer current;
    listpointer stack[25];
    int top = -1;
    for(i=0;i<20;i++){
        stack[++top] = seq[i];
        while(out[i])
            stack[top] = seq[++i];
        while(top!=-1){
            // print�w���X���Ʀr
            if(!out[stack[top]->data]){
                printf("%5d ",stack[top]->data);
                out[stack[top]->data] = 1;
            }
            // �d�ݬO�_�٦��`�I�i���X �B (�Y����X �h���X�U�Ӹ`�I���Ʀr �_�h�~�򨫦ܤU�Ӹ`�I)
            while(stack[top]->next){
                if(!out[stack[top]->next->data]){
                    stack[top+1] = seq[stack[top]->next->data];
                    top++;
                    break;
                }
                else
                    stack[top] = stack[top]->next;
            }
            // �w�L�U�Ӹ`�I�i���X�� (pop�ӦCseq[])
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
