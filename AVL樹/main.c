#include <stdio.h>
#include <stdlib.h>

typedef struct listnode{
    int data;
    struct listnode* left;
    struct listnode* right;
}*node;

node makenode();
node addnode(node ,int );
void printTree(node ,int);

int level_find(node tree,int h){
    if(tree){
        h++;
        int left = level_find(tree->left,h);
        int right = level_find(tree->right,h);
        if (left > h || right > h){
            if (left >= right)
                return left;
            else
                return right;
        }
        else
            return h;
    }
    else
        return 0;
}

int main()
{
    node tree = NULL;
    srand(time(NULL));
    int select;
    printf("(1)addnode (2) (3)print (4)test\n");
    while(1){
        scanf("%d",&select);
        if(select == 1){
            int data;
            scanf("%d",&data);
            tree = addnode(tree,data);
        }
        else if(select == 3){
            printf("Tree:\n");
            printTree(tree,1);
        }
        else if(select == 4){
            int data,i;
            printf("random num: ");
            for(i=0;i<10;i++){
                data = rand()%100+1;
                printf("%d ",data);
                tree = addnode(tree,data);
            }
            printf("\n");
        }

    }
    return 0;
}

int findnum(node root,int data){
    if(root){
        if(root->data == data)
            return 1;
        if(root->data > data)
            return findnum(root->left,data);
        else
            return findnum(root->right,data);
    }
    return 0;
}

node addnode(node root,int data){
    if(!root){
        root = makenode();
        root->data = data;
        printf("add root\n");
        return root;
    }
    if(findnum(root,data)){
        printf("The num is already exist\n");
        return root;
    }
    if(data < root->data ){
        if(!root->left){
            node newnode = makenode();
            root->left = newnode;
            newnode->data = data;
        }
        else{
            addnode(root->left,data);
            int left = level_find(root->left,0);
            int right = level_find(root->right,0);
            int temp;
            if( left - right == 2){
                if(root->left->right && root->left->left){
                    if(data > root->left->data)
                        goto flag3;
                    else
                        goto flag4;
                }
                if(root->left->left){// LL旋轉
                    flag3:
                    // 交換資料
                    temp = root->data;
                    root->data = root->left->data;
                    root->left->data = temp;

                    // link串接
                    node temp_root_left = root->left;
                    node temp_root_right = root->right;
                    root->left = temp_root_left->left;
                    root->right = temp_root_left;
                    temp_root_left->left = temp_root_left->right;
                    temp_root_left->right = temp_root_right;
                    printf("LL旋轉\n");

                }
                // LR旋轉
                else if(root->left->right){
                    flag4:
                    // 交換資料
                    temp = root->data;
                    root->data = root->left->right->data;
                    root->left->right->data = temp;

                    // link串接
                    node temp_root_left = root->left; // b
                    node temp_root_right = root->right; // 1
                    node temp_root_left_right = root->left->right; // c
                    temp_root_left->right = temp_root_left_right->left;
                    root->right = temp_root_left_right;
                    temp_root_left_right->left = temp_root_left_right->right;
                    temp_root_left_right->right = temp_root_right;
                    printf("LR旋轉\n");
                }
            }
        }
    }
    else{
        if(!root->right){
            node newnode = makenode();
            root->right = newnode;
            newnode->data = data;
        }
        else{
            addnode(root->right,data);
            int left = level_find(root->left,0);
            int right = level_find(root->right,0);
            int temp;
            if( left - right == -2 ){
                if(root->right->right && root->right->left){
                    if(data > root->right->data)
                        goto flag1;
                    else
                        goto flag2;
                }
                else if(root->right->right){// RR旋轉
                    flag1:
                    temp = root->data;
                    root->data = root->right->data;
                    root->right->data = temp;

                    // link串接
                    node temp_root_left = root->left;
                    node temp_root_right = root->right;
                    root->right = temp_root_right->right;
                    root->left = temp_root_right;
                    temp_root_right->right = temp_root_right->left;
                    temp_root_right->left = temp_root_left;
                    printf("RR旋轉\n");
                }
                // RL旋轉
                else if(root->right->left){
                    flag2:
                    // 交換資料
                    temp = root->data;
                    root->data = root->right->left->data;
                    root->right->left->data = temp;

                    // link串接
                    node temp_root_left = root->left; // 1
                    node temp_root_right = root->right; // b
                    node temp_root_right_left = root->right->left; // c

                    temp_root_right->left = temp_root_right_left->right;
                    root->left = temp_root_right_left;
                    temp_root_right_left->right = temp_root_right_left->left;
                    temp_root_right_left->left = temp_root_left;

                    printf("RL旋轉\n");
                }
            }
        }
    }
    //printf("add succeed\n");
    return root;

}

node makenode(){
    node newnode = malloc(sizeof(struct listnode));
    newnode->data = 0;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

void printTree(node tree,int level){
	if(tree){
		if(tree->right)
			printTree(tree->right,level+1);
		int i;
		for(i=1;i<level;i++)
			printf("\t");
		printf("%d\n",tree->data);
		if(tree->left)
			printTree(tree->left,level+1);
	}

}
