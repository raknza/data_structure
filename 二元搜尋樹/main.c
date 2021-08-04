#include <stdio.h>
#include <stdlib.h>

typedef struct list{
    int data;
    int level;
    struct list* left;
    struct list* right;
}*node;

node makenode();
void addnode(node,int);
void delnode(node,int);
node search(node,int);
void printTree(node);

int main()
{
    int i;
    node tree = NULL;
    tree = makenode();
    tree->data = -1;
    tree->level = -1;
    int value;
    int select = 0;
    // �إߤG���j�M��
    printf("(1)add num (2)del num (3)search num (4)print tree (5)exit\n");
    while(select != 5){
        scanf("%d",&select);
        if(select == 1){
            printf("input a num\n");
            scanf("%d",&value);
            addnode(tree,value);
        }
        else if(select == 2){
            printf("input a num\n");
            scanf("%d",&value);
            delnode(tree,value);
        }
        else if(select == 3){
            scanf("%d",&value);
            if(search(tree,value))
                printf("find the num:%d\n",value);
            else
                printf("not found\n");
        }
        else if(select == 4){
            printTree(tree->right);
        }
    }
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
                new_node->level = tree->level+1;
                tree->right = new_node;
                printf("add succeed\n");
            }
        }
        else{
            if(tree->left)
                addnode(tree->left,value);
            else{
                node new_node = makenode();
                new_node->data = value;
                new_node->level = tree->level+1;
                tree->left = new_node;
                printf("add succeed\n");
            }
        }
    }
}

node makenode(){
    node new_node = malloc(sizeof(struct list));
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void delnode(node tree,int num){
    node ptr = search(tree,num);
    if(!ptr){
        printf("not found\n");
    }
    else{
        // �j�M���`�I
        node parent = tree;
        while(1){
            if( parent->left && parent->left->data == num )
                break;
            if( parent->right && parent->right->data == num )
                break;
            if(parent->data > num)
                parent = parent->left;
            else
                parent = parent->right;
        }
        // �L���l�k�l
        if(!ptr->left && !ptr->right){
            node temp = ptr;
            if(parent->left && parent->left->data == num)
                parent->left = NULL;
            else
                parent->right = NULL;
            free(temp);
            printf("del succeed\n");
        }
        else{
            node temp = ptr;
            // �����k�l
            if(ptr->left && ptr->right){
                temp = temp->left;
                // �M��l�𤤳̤j��
                while(temp->right)
                    temp = temp->right;
                // �M�����`�I
                parent = tree;
                while(1){
                if( parent->left && parent->left->data == temp->data )
                    break;
                if( parent->right && parent->right->data == temp->data )
                    break;
                if(parent->data > temp->data)
                    parent = parent->left;
                else
                    parent = parent->right;
                }
                //printf("par:%d temp:%d\n",parent->data,temp->data);
                parent->left = temp->left;
                ptr->data = temp->data;
                free(temp);
                //printf("del 2\n");
            }
            else if(!ptr->right){   // �u�����l
                temp = ptr->left;
                ptr->data = ptr->left->data;
                ptr->left = temp->left;
                ptr->right = temp->right;
                free(temp);
                //printf("del3\n");

            }
            else if(!ptr->left){    // �u���k�l
                temp = ptr->right;
                ptr->data = ptr->right->data;
                ptr->right = temp->right;
                ptr->left = temp->left;
                free(temp);
                //printf("del4\n");
            }
            printf("del succeed\n");
        }
    }
}

node search(node tree,int num){
    if(!tree)
        return NULL;
    else{
        if(tree){
            if(tree->data == num)
                return tree;
            else{
                if(tree->data > num)
                    return search(tree->left,num);
                else
                    return search(tree->right,num);
            }
        }
    }
}

void printTree(node tree){
	if(tree){
		if(tree->right)
			printTree(tree->right);
		int i = 0;
		for(i=0;i<(tree->level);i++)
			printf("\t");
		printf("%d\n",tree->data);
		if(tree->left)
			printTree(tree->left);
	}

}

