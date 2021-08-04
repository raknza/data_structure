#include <stdio.h>
#include <stdlib.h>

typedef struct list* node;
typedef struct list{
    int data;
    node left;
    node right;
};


node makenode();
void push(node);
node pop();
node insert(node);
void ptree(node ,int);

int front = -1;
int rear = -1;

node queue[30];

int main()
{
    node tree = NULL;
    int select = 0;
    while(1){
        printf("(1)insert (2)delete (3)print (4)leave\n");
        scanf("%d",&select);
        if(select == 1){
            tree = insert(tree);
        }
        else if(select == 2){

        }
        else if(select == 3){
            ptree(tree,1);
        }

    }
    return 0;
}


node makenode(){
    node new_node = malloc(sizeof(struct list));
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->data = -1;
    return new_node;
}

node insert(node root){
    node newnode = makenode();
    int data;
    if(!root){
        printf("input root:");
        scanf("%d",&data);
        newnode->data = data;
        printf("add root\n");
        push(newnode);
        return newnode;
    }
    else{
        int left,right;
        node temp = pop();
        printf("now root:%d\n",temp->data);
        printf("input left subtree\n");
        scanf("%d",&left);
        newnode->data = left;
        if(left){
            temp->left = newnode;
            push(temp->left);
        }
        printf("input right subtree\n");
        scanf("%d",&right);
        if(right){
            node newnode2 = makenode();
            newnode2->data = right;
            temp->right = newnode2;
            push(temp->right);
        }
        return root;
    }
}

void push(node root){
    queue[++rear] = root;
}

node pop(){
    return queue[++front];
}


void ptree(node tree,int level){
	if(tree){
		if(tree->right)
			ptree(tree->right,level+1);
		int i = 1;
		for(i;i<level;i++)
			printf("\t");
		printf("%d\n",tree->data);
		if(tree->left)
			ptree(tree->left,level+1);
	}

}

