#include <stdio.h>
#include <stdlib.h>

typedef struct list *node;
typedef struct list{
	int data; //數值
	int priority;
	node left;
	node right;
	node parent; //parent node
}nod;

node makenode(){
    node newnode;
    newnode = malloc(sizeof(nod));  //動態配置記憶體大小
    newnode->left = NULL;   //左子樹預設為空
    newnode->right = NULL;  //右子樹預設為空
    newnode->parent = NULL;
    return newnode;
}


node addnode(node,int);
void pop(node);
void ptree(node,int);
void pheap(node ,int );
void check_up(node);
void check_down(node);

int index = 0;

node findnode(node root,int data){
    if(root){
        if(root->data == data){
            //printf("find\n");
            return root;
        }
        else if(root->data > data)
            return findnode(root->left,data);
        else
            return findnode(root->right,data);
    }
    else
        return NULL;
}

int main()
{
    int select;
    node tree = NULL;
    srand(time(NULL));
    while(1){
        printf("(1)insert (2)delete (3)print (4)leave (5)test (6)findparent\n");
        scanf("%d",&select);
        if(select == 1){
            int data;
            scanf("%d",&data);
            tree = addnode(tree,data);
        }
        else if(select == 2){
            node tmp;
            //pop(tree);
            if(index == 0)
                tree = NULL;

        }
        else if(select == 3){
            int data;
            if(!tree){
                printf("It's NULL\n");
                continue;
            }
            printf("(1)tree (2)heap:");
            scanf("%d",&data);
            if(data == 1)
                ptree(tree,1);
            else if(data == 2)
                pheap(tree,1);
        }
        else if(select ==5 ){
            int data,i;
            printf("inupt numbers:");
            scanf("%d",&data);
            for(i=0;i<data;i++){
                int num = rand()%100+1;
                if(findnum(tree,num)){
                    i--;
                }
                else
                    tree = addnode(tree,num);
            }

        }
        else if(select == 6){
            int data;
            scanf("%d",&data);
            node parent = NULL;
            parent = findnode(tree,data);
            if(parent->parent)
                printf("%d -> %d\n",parent->parent->data,parent->data);
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

int findprority(node root,int data){
    if(root){
        if(root->priority == data)
            return 1;
        int left = findprority(root->left,data);
        if(left)
            return 1;
        int right = findprority(root->right,data);
        if(right)
            return 1;
        return 0;
    }
    return 0;

}

node addnode(node root,int data){
    if(findnum(root,data)){
        printf("The num is already exist\n");
        return root;
    }
    node newnode = makenode();
    newnode->data = data;
    newnode->priority = rand()%100+1;
    while(findprority(root,newnode->priority))
        newnode->priority = rand()%100+1;
    if(!root){
        //printf("add root\n");
        return newnode;
    }
    else{
        node troot = root;
        while(1){
            if(root->data > data && !root->left){
                root->left = newnode;
                newnode->parent = root;
                break;
            }
            else if( root->data > data )
                root = root->left;
            else if( root->data < data && !root->right ){
                root->right = newnode;
                newnode->parent = root;
                break;
            }
            else if( root->data < data )
                root = root->right;
        }
        //newnode->parent = parent;
        //printf("add succeed\n");
        if(newnode->parent)
            check_up(newnode);
        return troot;
    }
}


void check_up(node tree){
    if(tree->parent->priority > tree->priority){
        // 先交換交換資料
        int tmp,tmp2;
        tmp = tree->parent->priority;
        tmp2 = tree->parent->data;

        tree->parent->priority = tree->priority;
        tree->parent->data = tree->data;

        tree->priority = tmp;
        tree->data = tmp2;

        node temp = tree->parent;
        // 當前節點為父節點之右子 因為先交換資料所以旋轉方向剛好相反
        if( tree->parent->data < tree->data ){
            //printf("ur\n");
            node temp2 = tree;
            temp = tree->parent;
            node a = temp2->left;
            node b = temp2->right;
            node c = temp->right;

            temp->left = a;
            if(a)
                a->parent = temp;
            temp->right = temp2;
            temp2->parent = temp;
            temp2->left = b;
            if(b)
                b->parent = temp2;
            temp2->right = c;
            if(c)
                c->parent = temp2;
            //printf("??\n");

        }
        else if( tree->parent->data > tree->data ){ // 當前節點為父節點之左子
            //printf("e\n");
            node temp2 = tree;
            temp = tree->parent;
            node a = temp->left;
            node b = temp2->left;
            node c = temp2->right;

            temp->left = temp2;
            temp->right = c;
            if(c)
                c->parent = temp;

            temp2->parent = temp;
            temp2->left = a;
            if(a)
                a->parent = temp2;
            temp2->right = b;
            if(b)
                b->parent = temp2;
            //printf("?\n");
        }
        //printf("switch\n");
        if(temp->parent)
            check_up(temp);
    }
}


/*void pop(node tree){
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


}*/


/*void check_down(node tree){
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
}*/


void ptree(node tree,int level){
	if(tree){
		if(tree->right)
			ptree(tree->right,level+1);
		int i;
		for(i=1;i<level;i++)
			printf("\t");
		printf("%d\n",tree->data);
		if(tree->left)
			ptree(tree->left,level+1);
	}
}

void pheap(node tree,int level){
	if(tree){
		if(tree->right)
			pheap(tree->right,level+1);
		int i;
		for(i=1;i<level;i++)
			printf("\t");
		printf("%d\n",tree->priority);
		if(tree->left)
			pheap(tree->left,level+1);
	}
}
