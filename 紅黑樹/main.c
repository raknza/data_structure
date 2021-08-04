#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define RED 1
#define BLACK -1

typedef struct treepointer{
    int data;
    short int color;
    struct treepointer* left;
    struct treepointer* right;
    struct treepointer* parent;
}*node;

node makenode();
node addnode();
void ptree(node,int);

node findnum(node root,int data){
    if(root){
        if(root->data == data)
            return root;
        else if(root->data > data)
            return findnum(root->left,data);
        else
            return findnum(root->right,data);
    }
    else
    return NULL;
}
int main()
{
    int select;
    int i;
    srand(time(NULL));
    node tree = NULL;
    while(1){
        printf("(1)addnode (2)del (3)print tree (4)random numbers \n");
        scanf("%d",&select);
        if(select == 1){
            int data;
            scanf("%d",&data);
            tree = addnode(tree,data);
        }
        else if(select == 2){

        }
        else if(select == 3){
            ptree(tree,1);
            printf("\n");
        }
        else if(select == 4){
            int data;
            printf("input count:");
            scanf("%d",&data);
            for(i=0;i<data;i++){
                int key = rand()%100+1;
                if(findnum(tree,key)){
                    i--;
                    printf("重複\n");
                }
                else
                    tree = addnode(tree,key);
            }

        }
        else if (select == 5)
            return 1;
    }
    return 0;
}


node makenode(){
    node newnode = malloc(sizeof(struct treepointer));
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->parent = NULL;
}

node search(node root,int data){
    if(root->data > data){
        if(!root->left)
            return root;
        return search(root->left,data);
    }
    else if(root->data < data){
        if(!root->right)
            return root;
        return search(root->right,data);
    }
}

node addnode(node root,int data){
    if(!root){
        root = makenode();
        root->data = data;
        root->color = BLACK;
        return root;
    }
    // 新增
    node newnode = makenode();
    newnode->data = data;
    newnode->color = RED;
    node parent = search(root,data);
    if(parent->data > data)
        parent->left = newnode;
    else
        parent->right = newnode;
    newnode->parent = parent;

    // 旋轉
    while( newnode->parent && newnode->parent->color == RED ){

        if(newnode->parent->parent->left == newnode->parent){ // 父為左節點
            if( newnode->parent->parent->right&& newnode->parent->parent->right->color == RED ){// 父節點之兄弟為紅
                printf("1\n");
                newnode->parent->parent->color = RED;
                newnode->parent->color = BLACK;
                newnode->parent->parent->right->color = BLACK;
                newnode = newnode->parent->parent;
            }
            else{ // 父節點之兄弟為黑
                if( newnode->parent->left == newnode ){ // 當前為左節點
                    printf("2\n");
                    newnode->parent->color = BLACK;
                    newnode->parent->parent->color = RED;

                    node temp = newnode->parent->parent; // 祖節點
                    node temp2 = newnode->parent; // 父節點
                    // 以祖父節點為支點進行右旋
                    // 交換資料
                    int tmp_data = temp->data;
                    int tmp_color = temp->color;
                    temp->data = temp2->data;
                    temp->color = temp2->color;
                    temp2->data = tmp_data;
                    temp2->color = tmp_color;
                    // 交換鏈結
                    node a = temp2->left;
                    node b = temp2->right;
                    node c = temp->right;

                    temp->right = temp2;
                    temp->left = a;
                    if(a)
                        a->parent = temp;
                    temp2->left = b;
                    if(b)
                        b->parent = temp2;
                    temp2->right = c;
                    if(c)
                        c->parent = temp2;

                }
                else{ // 當前為右節點
                    // 以父親節點當前節點進行左璇
                    // 交換資料
                    printf("3\n");
                    node temp = newnode->parent; // 父節點
                    node temp2 = newnode; // 右子節點
                    int tmp_data = temp->data;
                    int tmp_color = temp->color;
                    temp->data = temp2->data;
                    temp->color = temp2->color;
                    temp2->data = tmp_data;
                    temp2->color = tmp_color;
                    // 交換鏈結
                    node a = temp->left;
                    node b = temp2->left;
                    node c = temp2->right;
                    temp->left = temp2;
                    temp2->parent = temp;
                    temp->right = c;
                    if(c)
                        c->parent = temp;
                    temp2->left = a;
                    if(a)
                        a->parent = temp2;
                    temp2->right = b;
                    if(b)
                        b->parent = temp2;
                    //printf("跑這爆\n");
                    newnode = temp;
                    if(newnode == root)
                        newnode->color = BLACK;
                    else{
                        newnode = newnode->left;
                        //printf("??\n");
                        //goto cas1;
                    }
                }
            }
        }
        else if( newnode->parent->parent->right == newnode->parent ){ // 父為右節點
            if( newnode->parent->parent->left&& newnode->parent->parent->left->color == RED ){// 父節點之兄弟為紅
                printf("4\n");
                newnode->parent->parent->color = RED;
                newnode->parent->color = BLACK;
                newnode->parent->parent->left->color = BLACK;
                newnode = newnode->parent->parent;
            }
            else{ // 父節點之兄弟為黑
                if( newnode->parent->left == newnode ){ // 當前為左節點
                    printf("5\n");
                    newnode->parent->parent->color = RED;

                    node temp = newnode->parent->parent; // 祖節點
                    node temp2 = newnode; // 新節點
                    node temp3 = newnode->parent; // 父節點
                    // RL旋轉
                    // 交換資料
                    int tmp_data = temp->data;
                    int tmp_color = temp->color;
                    temp->data = temp2->data;
                    temp->color = temp2->color;
                    temp2->data = tmp_data;
                    temp2->color = tmp_color;
                    // 交換鏈結
                    node a = temp->left;
                    node b = temp2->left;
                    node c = temp2->right;


                    temp->left = temp2;
                    temp->right = temp3;
                    temp2->parent = temp;
                    temp3->parent = temp;

                    temp2->left = a;
                    if(a)
                        a->parent = temp2;
                    temp2->right = b;
                    if(b)
                        b->parent = temp2;
                    temp3->left = c;
                    if(c)
                        c->parent = temp3;
                    newnode = temp;
                    //printf("e??\n");
                }
                else{ // 當前為右節點
                    // 以父親為當前節點進行左璇
                    // 交換資料
                    printf("6\n");
                    node temp = newnode->parent; // 父節點
                    node temp2 = newnode; // 右子節點
                    int tmp_data = temp->data;
                    int tmp_color = temp->color;
                    temp->data = temp2->data;
                    temp->color = temp2->color;
                    temp2->data = tmp_data;
                    temp2->color = tmp_color;
                    // 交換鏈結
                    node a = temp->left;
                    node b = temp2->left;
                    node c = temp2->right;
                    temp->left = temp2;
                    temp2->parent = temp;
                    temp->right = c;
                    if(c)
                        c->parent = temp;
                    temp2->left = a;
                    if(a)
                        a->parent = temp2;
                    temp2->right = b;
                    if(b)
                        b->parent = temp2;
                    //printf("跑這爆\n");
                    newnode = temp;
                    if(newnode == root)
                        newnode->color = BLACK;
                    else{
                        newnode = newnode->left;
                        //printf("??\n");
                        //goto cas2;
                    }
                }
            }
        }
        if(newnode->data == root->data && newnode->color == RED)
            newnode->color = BLACK;
    }
    printf("add succeed\n");
    return root;

}

void ptree(node root,int level){
    if(root){
        ptree(root->right,level+1);
        int i;
        for(i=1;i<level;i++)
            printf("\t");
        printf("%d\n",root->data);
        ptree(root->left,level+1);
    }
}
