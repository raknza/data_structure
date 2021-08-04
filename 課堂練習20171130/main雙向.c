#include <stdio.h>
#include <stdlib.h>

typedef struct linked{
    int data;
    struct linked* left;
    struct linked* right;
}*node;

node makenode();
void addnode(node ,int);

int main()
{
    int select;
    node list = makenode(),current;
    while(1){
        printf("select a function:");
        scanf("%d",&select);
        if(select == 1){
            printf("input a num\n");
            int value;
            scanf("%d",&value);
            addnode(list,value);
        }
        else if(select == 2){
            int value;
            scanf("%d",&value);
            current = list->right;
            if(value == 1){
                while(current){
                    printf("%d ",current->data);
                    current = current->right;
                }
                printf("\n");
            }
            else{
                while(current->right)
                    current = current->right;
                while(current->left){
                    printf("%d ",current->data);
                    current = current->left;
                }
                printf("\n");
            }
        }
    }
    return 0;
}

void addnode(node list,int data){
    node new_node = makenode();
    new_node->data = data;
    while(list->right)
        list = list->right;
    list->right = new_node;
    new_node->left = list;
    printf("add succeed\n");
}

node makenode(){
    node new_node = malloc(sizeof(struct linked));
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}
