#include <stdio.h>
#include <stdlib.h>

typedef struct list{
    char data;
    struct list* left;
    struct list* right;
}*node;

typedef struct{
    char data;
    node link;
}element;

int top = -1;
element stack[50];

node makenode();
void Inorder(node);
void Preorder(node);
void Postorder(node);

void push(char,node);
element pop();


int main()
{
    char input;
    node tree = NULL;
    while(1){
        // 樹的根節點為最後建立（樹會一直往上長） 最早建立的節點僅代表第一個運算的式子
        input = getchar();
        switch (input){
            case '+':case'-':case'*':case'/':
                // 遇到運算符號 從stack中pop()出兩項 建立節點並串接
                //printf("not number\n");
                // 建立節點
                tree = makenode();
                tree->data = input;
                // 左右節點處理
                node left,right;
                element temp1 = pop();
                // 堆疊中為節點情況
                if(temp1.link)
                    tree->right = temp1.link;
                else{
                    right = makenode();
                    right->data = temp1.data;
                    tree->right = right;
                }
                temp1 = pop();
                if(temp1.link)
                    tree->left = temp1.link;
                else{
                    left = makenode();
                    left->data = temp1.data;
                    tree->left = left;
                }
                push('1',tree);
                break;
            case '\n':
                break;
            case '.':
                printf("Preorder:");
                Preorder(tree);
                printf("\n");
                printf("Inorder:");
                Inorder(tree);
                printf("\n");
                printf("Postorder:");
                Postorder(tree);
                break;
            default:
                push(input,NULL);
                //printf("number\n");
        }
    }
    return 0;
}

node makenode(){
    node new_node = malloc(sizeof(struct list));
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void push(char data,node link){
    stack[++top].link = link;
    stack[top].data = data;
}

element pop(){
    return stack[top--];
}


void Inorder(node tree){
    if(tree){
        Inorder(tree->left);
        printf("%c",tree->data);
        Inorder(tree->right);
    }
}

void Preorder(node tree){
    if(tree){
        printf("%c",tree->data);
        Preorder(tree->left);
        Preorder(tree->right);
    }
}

void Postorder(node tree){
    if(tree){
        Postorder(tree->left);
        Postorder(tree->right);
        printf("%c",tree->data);
    }
}
