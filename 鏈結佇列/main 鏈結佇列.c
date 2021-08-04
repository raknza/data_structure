#include <stdio.h>
#include <stdlib.h>
typedef struct node *element;
typedef struct node{
    int data;
    element next;
};

element makenode();
void enqueue(int);
element dequeue();

element front=NULL,rear=NULL;

int main()
{
    element current;
    int select;
    printf("enter a command:(1)enqueue (2)dequeue (3)print:");
    while(~scanf("%d",&select)){
        if(select == 1){
            int value;
            printf("input the value:");
            scanf("%d",&value);
            enqueue(value);
        }
        else if(select == 2){
            current = dequeue();
            if(current){
                printf("pop:%d\n",current->data);
                free(current);
            }
            else
                rear = NULL;
        }
        else if(select == 3){
            current = front;
            while(current !=NULL){
                printf("%d\n",current->data);
                current = current->next;
            }
        }
    }
    return 0;
}

element makenode(){
    element temp;
    temp = malloc(sizeof(struct node));
    temp->next = NULL;
    return temp;
}


void enqueue(int value){
    if(rear == NULL){
        rear = makenode();
        rear->data = value;
        front = rear;
        printf("finish enqueue1\n");
    }
    else{
        element temp = makenode();
        temp->data = value;
        rear->next = temp;
        rear = rear->next;
        printf("finish enqueue2\n");
    }

}

element dequeue(){
    if(!front){
        printf("It's empty\n");
        return NULL;
    }
    else{
        element temp = front;
        front = front->next;
        return temp;
    }

}
