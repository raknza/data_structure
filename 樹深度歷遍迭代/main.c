#include <stdio.h>
#include <stdlib.h>

typedef struct list* node;
typedef struct list{
    int data;
    node left;
    node right;
};

typedef struct element* queue;
typedef struct element{
    node tree;
    queue next;
};

node makenode();
node push(int);
node pop();
queue makequeue();

queue front=NULL,rear=NULL;

void Inorder(node );
void Postorder(node );
void Preorder(node tree);
int main()
{
    node tree = NULL,head = NULL;
    head = push(0);
    int left,leftThread,right,rightThread;
    while(~(scanf("%d %d %d %d",&leftThread,&left,&rightThread,&right))){
        tree = pop();
        if(tree == NULL)
            break;
        printf("tree->data = %d ",tree->data);
        if(leftThread==0 && rightThread==0)
            continue;
        if(leftThread == 1)
            tree->left = push(left);
        if(rightThread == 1)
            tree->right = push(right);
        printf("finish set\n");
    }
    // 前序迭代走訪
    printf("前序迭代走訪：");
    Preorder(head);
    printf("\n");
    // 中序迭代走訪
    printf("中序迭代走訪：");
    Inorder(head);
    printf("\n");
    // 後序迭代走訪
    printf("後序遞迴走訪：");
    Postorder(head);
    printf("\n");
    return 0;
}

queue makequeue(){
    queue new_queue = malloc(sizeof(struct element));
    new_queue->next = NULL;
    new_queue->tree = NULL;
    return new_queue;
}

node makenode(){
    node new_node = malloc(sizeof(struct list));
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->data = -1;
    return new_node;
}

node push(int data){
    node temp = makenode();
    queue temp2 = makequeue();
    temp->data = data;
    temp2->tree = temp;
    if(rear == NULL){
        rear = temp2;
    }
    else{
        rear->next = temp2;
        rear = rear->next;
    }
    return temp;
}

node pop(){
    if(front == NULL){
        front = rear;
        return front->tree;
    }
    else if(front == rear)
        return NULL;
    else{
        front = front->next;
        return front->tree;
    }
}


void Inorder(node tree){
    queue stack=NULL;
    stack = makequeue();
    stack->tree = tree;
    while(1){
        while(stack->tree){
            queue temp = makequeue();
            temp->next = stack;
            temp->tree = stack->tree->left;
            stack = temp;
        }
        queue temp = stack;
        stack = stack->next;
        free(temp);
        if(!stack) break;
        printf("%d",stack->tree->data);
        stack->tree = stack->tree->right;
    }
}

void Postorder(node tree){
    if(tree){
        Postorder(tree->left);
        Postorder(tree->right);
        printf("%d",tree->data);
    }
}

void Preorder(node tree){
    queue stack=NULL;
    stack = makequeue();
    stack->tree = tree;
    while(1){
        while(stack->tree){
            printf("%d",stack->tree->data);
            queue temp = makequeue();
            temp->next = stack;
            temp->tree = stack->tree->left;
            stack = temp;
        }
        queue temp = stack;
        stack = stack->next;
        free(temp);
        if(!stack) break;
        stack->tree = stack->tree->right;
    }
}



