#include <stdio.h>
#include <stdlib.h>
typedef struct list *node;
typedef struct list{
    int data;
    struct list* left;
    struct list* right;
};
node makenode(){
    node newnode = malloc(sizeof(struct list));
    newnode->left = NULL;
    newnode->right = NULL;
}
node insert(node,int,int);
node findindex(node ,int);
void ptree(node );
void ptree2(node ,int);

int index = 0;

int main()
{
    int select;
    int value;
    node tree = NULL;
    while(1){
        printf("(1)insert (2)delete (3)print tree\n");
        scanf("%d",&select);
        if(select == 1){
            scanf("%d",&value);
            tree = insert(tree,value,++index);
        }
        else if(select == 2){

        }
        else if(select == 3){
            //ptree(tree);
            ptree2(tree,0);
        }
    }
    return 0;
}


node insert(node root,int data,int index ){
    node newnode = makenode();
    newnode->data = data;
    if(!root){
        printf("add root\n");
        return newnode;
    }
    else{
        node parent = findindex(root,index/2);
        if(index%2 == 0){
            parent->left = newnode;
        }
        else{
            parent->right = newnode;
        }
        printf("add succeed\n");
        return root;
    }
}
node findindex(node root,int index){
    int stack[20];
    int top = -1;
    stack[++top] = index;
    while(stack[top] !=1){
        stack[top+1] = stack[top]/2;
        top++;
    }
    while(1){
        if(top == 0)
            break;
        if(stack[top-1]%2 == 0)
            root = root->left;
        else
            root = root->right;
        top--;
    }
    return root;
}


/*void ptree(node tree){
	if(tree){
		if(tree->right)
			ptree(tree->right);
		int i = 0;
		for(i;i<floor(log(tree->index)/log(2));i++)
			printf("\t");
		printf("%d\n",tree->data);
		if(tree->left)
			ptree(tree->left);
	}

}*/

void ptree2(node tree,int level){
	if(tree){
		if(tree->right)
			ptree2(tree->right,level+1);
		int i = 0;
		for(i;i<level;i++)
			printf("\t");
		printf("%d\n",tree->data);
		if(tree->left)
			ptree2(tree->left,level+1);
	}

}

int dfs_find(node tree,int h){
    if(tree){
        h++;
        return dfs_find(tree->left,h);
        return dfs_find(tree->right,h);
    }
    return h;
}

int front;
int rear;
node queue[50];

void push(node root){
    if(rear == 49)
        rear = -1;
    queue[++rear] = root;
}

node pop(){
    if(front == 49)
        rear = -1;
    return queue[++front];
}

int pow(int a,int n){
    if(n==0)
        return 1;
    else{
        if(n>0)
            return a*pow(a,n-1);
    }
}

/*void ptree2(node tree){
    int h = 0;
    front = -1;
    rear = -1;
    int last = 1;
    h = dfs_find(tree,h);
    push(tree);
    node root = pop();
    while(1){
        int level = floor(log(root->index)/log(2))+1;
        if(last != level){
            printf("\n");
            last++;
        }
        if(pow(2,level-1) == root->index || pow(2,level-1)+(level-1) == root->index){
            int i;
            for(i=0;i<((pow(2,h-2)-pow(2,level-1))+1)/2;i++)
                printf("\t");
        }
        printf("%d\t",root->data);
        if(root->index == index)
            break;
        if(root->left)
            push(root->left);
        if(root->right)
            push(root->right);
        root = pop();
    }
    printf("\n");
}*/


