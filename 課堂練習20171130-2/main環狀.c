#include <stdio.h>
#include <stdlib.h>

typedef struct linked{
    int data;
    struct linked* next;
}*node;

node makenode();
node addnode(node ,int);
node findnum(node ,int);

int main()
{
    int select;
    node list = makenode(),current,end = list;
    end->next = NULL;
    while(1){
        printf("select a function:");
        scanf("%d",&select);
        if(select == 1){
            printf("input a num\n");
            int value;
            scanf("%d",&value);
            end = addnode(end,value);
        }
        else if(select == 2){
            int start,end;
            node end_link;
            printf("input start and end\n");
            scanf("%d %d",&start,&end);
            current = findnum(list,start);
            end_link = findnum(list,end);
            if(current&& end_link){
                while(current!=end_link){
                    printf("%d ",current->data);
                    current = current->next;
                }
                printf("\n");
            }
            else
                printf("can't find the num\n");
        }
        else if(select == 3){
            current = list;
            while(current){
                printf("%d \n",current->data);
                current = current->next;
                system("PAUSE");
            }
        }
    }
    return 0;
}

node addnode(node list,int data){
    if(!list->next){
        list->data = data;
        list->next = list;
        return list;
    }
    node new_node = makenode();
    new_node->data = data;
    new_node->next = list->next;
    list->next = new_node;
    printf("add succeed\n");
    return new_node;
}

node makenode(){
    node new_node = malloc(sizeof(struct linked));
    new_node->next = NULL;
    return new_node;
}

node findnum(node list,int data){
    node current = list;
    while(list){
        if(list->data == data)
            return list;
        list = list->next;
        current = current->next->next;
        if(current->data == list->data)
            break;
    }
    return NULL;
}
