#include <stdio.h>
#include <stdlib.h>

typedef struct list *node;
typedef struct list{
	int data; //數值
	int index; //在tree中的索引
	node left;
	node right;
	node parent; //parent node
} nod;

node makenode(){
    node newnode;
    newnode = malloc(sizeof(nod));  //動態配置記憶體大小
    newnode->left = NULL;   //左子樹預設為空
    newnode->right = NULL;  //右子樹預設為空
    newnode->parent = NULL;
    return newnode;
}


node addnode(node,int,int);
void pop(node);
node findindex(node,int);
void ptree(node);
void check_up(node);
void check_down(node);

int index = 0;

int main()
{
    int select;
    node tree = NULL;
    while(1){
        printf("(1)insert (2)delete (3)print (4)leave\n");
        scanf("%d",&select);
        if(select == 1){
            int data;
            scanf("%d",&data);
            tree = addnode(tree,data,++index);
        }
        else if(select == 2){
            node tmp;
            pop(tree);
            if(index == 0)
                tree = NULL;

        }
        else if(select == 3){
            ptree(tree);
            if(!tree)
                printf("It's NULL\n");
        }
    }
    return 0;
}




node addnode(node root,int data,int index){
    node newnode = makenode();
    newnode->data = data;
    newnode->index = index;
    if(!root){
        printf("add root\n");
        return newnode;
    }
    else{
        node parent = findindex(root,index/2);
        if(index%2 == 0)
            parent->left = newnode;
        else
            parent->right = newnode;
        newnode->parent = parent;
        printf("add succeed\n");
        check_up(newnode);
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
    while(root->index !=index){
        if(stack[top-1]%2 == 0){
            root = root->left;
        }
        else{
            root = root->right;
        }
        top--;
    }
    return root;
}

void check_up(node tree){
    if(tree && tree->parent && tree->parent->data < tree->data){
        int tmp;
        tmp = tree->parent->data;
        tree->parent->data = tree->data;
        tree->data = tmp;
        printf("switch\n");
        check_up(tree->parent);
    }
}


void pop(node tree){
    //printf("now index:%d\n",index);
    if(!tree){
        printf("It's NULL\n");
    }
    else if(index == 1){
        printf("pop:%d\n",tree->data);
        node tmp = tree;
        tree = NULL;
        index--;
        free(tmp);
    }
    else{
        printf("pop:%d\n",tree->data);
        //printf("index:%d\n",index);
        node last = findindex(tree,index);
        node parent = last->parent;
        if(parent->left && parent->left->data == last->data)
            parent->left = NULL;
        else if(parent->right && parent->right->data == last->data)
            parent->right = NULL;
        //printf("last:%d par:%d \n",last->data,parent->data);
        tree->data = last->data;
        check_down(tree);
        index--;
        free(last);
    }


}


void check_down(node tree){
    if(tree){
        int tmp = tree->data;
        node temp = NULL;
        int max = tree->data;
        if(tree->left && tree->left->data > max){
            max = tree->left->data;
            temp = tree->left;
            printf("switch left\n");
        }
        if(tree->right && tree->right->data >max){
            max = tree->right->data;
            temp = tree->right;
            printf("switch right\n");
        }
        tree->data = max;
        if(temp){
            temp->data = tmp;
            check_down(temp);
        }
    }
}


void ptree(node tree){
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

}
