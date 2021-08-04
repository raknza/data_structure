#include <stdio.h>
#include <stdlib.h>
typedef struct node *element;
typedef struct node{
    int data;
    element prev;
};

element makenode();
void push(int);
element pop();

element top=NULL;

int main()
{
    element current;
    int select;
    printf("enter a command:(1)push (2)pop (3)print:");
    while(~scanf("%d",&select)){
        if(select == 1){
            int value;
            printf("input the value:");
            scanf("%d",&value);
            push(value);
        }
        else if(select == 2){
            current = pop();
            if(current!=NULL){
                printf("pop:%d \n",current->data);
                free(current);
            }
        }
        else if(select == 3){
            current = top;
            while(current !=NULL){
                printf("%d\n",current->data);
                current = current->prev;
            }
        }
    }
    return 0;
}

element makenode(){
    element temp;
    temp = malloc(sizeof(struct node));
    temp->prev = NULL;
    return temp;
}

void push(int value){
    if(!top){
        top = makenode();
        top->data = value;
        printf("push finish1\n");
    }
    else{
        element temp = makenode();
        temp->data = value;
        temp->prev = top;
        top = temp;
        printf("push finish2\n");
    }

}

element pop(){
    if(!top)
        printf("It's empty\n");
    else{
        element temp = top;
        top = top->prev;
        return temp;
    }
}
