#include <stdio.h>
#include <stdlib.h>

typedef struct stu *student;
typedef struct stu{ // 節點結構
    int score; // 資料
    student next; // link
};

student makenode();
student newnode(student ,int );
student delectnode(student,int);
student invert(student);
void insert(student,int,int);

int main()
{
    student head,last,current;
    // 創造鏈結（首節點）
    head = makenode();
    last = head;
    head->score = -1;
    int select,score,x;
    printf("請輸入欲使用的指令：(1)新增節點 (2)刪除節點 (3)插入節點 (4)反轉 (5)印出 (6)結束\n");
    while(1){
        scanf("%d",&select);
        if(select == 1){
            printf("請輸入score:");
            scanf("%d",&score);
            last = newnode(last,score);
        }
        else if (select == 2){
            printf("請輸入位置(0為刪除last):");
            scanf("%d",&x);
            last = delectnode(head,x);
        }
        else if(select == 3){
            printf("請輸入欲插入的位置及score:");
            scanf("%d %d",&x,&score);
            insert(head,x,score);
        }
        else if(select == 4){
            head = invert(head);
        }
        else if (select ==5){
            printf("印出:\n");
            current = head->next;
            while(current!=NULL){
                printf("%d ",current->score);
                current = current->next;
                if(current!=NULL)
                    printf("→ ");
            }
            printf("\n");
        }
        else if(select == 6)
            return 0;
        else
            printf("無效指令，請重新輸入\n");

    }
    // 新增節點
    current = newnode(current,70);

    return 0;
}


student makenode(){
    student temp;
    temp = malloc(sizeof(struct stu));
    temp->next = NULL;
    return temp;
}

student newnode(student last,int data){
    // 製作節點
    student temp = makenode();
    temp->score = data;
    last-> next = temp;
    printf("新增結束");
    printf("\n");
    return last -> next;
}

student delectnode(student first ,int x){
    student front,temp = first;
    if(first->next == NULL){
        printf("已經無節點可刪除\n");
        return first;
    }
    // 刪除尾端
    if(x==0){
        while(temp->next!=NULL){
            front = temp;
            temp = temp->next;
        }
        // 傳回新尾端
        front->next = NULL;
        free(temp);
        temp = NULL;
        printf("已刪除\n");
        return front;
    }
    else{ // 刪除指定位置
        int current = 0;
        while((current+1)!=x){
            first = first->next;
            if(first->next == NULL){
                printf("超出鏈結範圍\n");
                return first;
            }
            current++;
        }
        temp = first->next;
        first->next = temp->next;
        free(temp);
        temp = NULL;
        printf("已刪除\n");
        // 傳回新尾端
        while(first->next!=NULL){
            front = first;
            first = first->next;
        }
        return front;
    }
}

void insert(student first,int x,int score){
    int start =0;
    student temp;
    while(start !=x){
        if(first->next == NULL){
            printf("超出鏈結範圍\n");
            return ;
        }
        first = first->next;
        start++;
    }
    temp = makenode();
    temp->score = score;
    temp->next = first->next;
    first ->next = temp;
    printf("插入結束");
    printf("\n");
}

student invert(student first){
    student front=NULL,next,temp;
    temp = first;
    first = first->next;
    while(first!=NULL){
        next = first->next;
        first->next = front;
        front = first;
        first = next;
    }
    temp->next = front;
    printf("反轉結束\n");
    return temp;
}

