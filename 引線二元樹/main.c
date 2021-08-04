#include <stdio.h>
#include <stdlib.h>

typedef struct list{
    short leftT;
    short rightT;
    int data;
    struct list* left;
    struct list* right;
}*node;

node makenode();
void addnode(node,int);
void Inorder(node);
void ThBtree();
void ThBtreeInorder(node);

node stack[100];
int top = -1;
int height = 0;

int main()
{
    int i;
    for(i=0;i<100;i++)
        stack[i] = NULL;
    node tree = NULL;
    int value;
    tree = makenode();
    tree->data = 0;
    // 建立二元搜尋樹
    printf("請輸入數字（-1即停止）\n");
    while(1){
        scanf("%d",&value);
        if(value == -1)
            break;
        else
            addnode(tree,value);
    }
    tree = tree->right;
    printf("一般二元搜尋樹建立完成。\n");
    dfs_find(tree,height);
    printf("深度：%d\n",height);
    printf("中序走訪:\n");
    Inorder(tree);
    printf("\n");
    printf("一般二元樹轉換引線二元樹：\n");
    ThBtree();
    printf("引線二元樹走訪：\n");
    ThBtreeInorder(tree);
    return 0;
}

void addnode(node tree,int value){
    if(tree){
        if(tree->data < value){
            if(tree->right)
                addnode(tree->right,value);
            else{
                node new_node = makenode();
                new_node->data = value;
                tree->right = new_node;
                tree->rightT = 1;
            }
        }
        else{
            if(tree->left)
                addnode(tree->left,value);
            else{
                node new_node = makenode();
                new_node->data = value;
                tree->left = new_node;
                tree->leftT = 1;
            }
        }
    }
}

node makenode(){
    node new_node = malloc(sizeof(struct list));
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->leftT = 0;
    new_node->rightT = 0;
    return new_node;
}

void Inorder(node tree){
    if(tree){
        Inorder(tree->left);
        stack[++top] = tree;
        printf("%d ",tree->data);
        Inorder(tree->right);
    }
}

void dfs_find(node tree,int h){
    if(tree){
        h++;
        if(h > height)
            height = h;
        dfs_find(tree->left,h);
        dfs_find(tree->right,h);
    }
}

void ThBtree(){
    int i = 0;
    for(i=0;i<=top;i++){
        printf("%d: ",stack[i]->data);
        if(stack[i]->leftT == 0 && (i-1)>=0){
            stack[i]->left = stack[i-1];
            printf("left = %d ,",stack[i-1]->data);
        }
        if(stack[i]->rightT == 0 && (i+1)<=top){
            stack[i]->right = stack[i+1];
            printf("right = %d ",stack[i+1]->data);
        }
        printf("\n");
    }
}

void ThBtreeInorder(node tree){
    while(tree->left)
        tree = tree->left;
    while(tree){
        printf("%d ",tree->data);
        if(tree->rightT == 0)
            tree = tree->right;
        else{
            tree = tree->right;
            while(tree->leftT !=0)
                tree = tree->left;
        }
    }

}
