#include <stdio.h>
#include <stdlib.h>
#define Nextt 1
#define Downn 0
#define Mix 2

typedef struct listnode *listPointer;
typedef struct listnode{
    int row;
    int col;
    int value;
    listPointer next;
    listPointer down;
};

listPointer makenode();
void addnode(listPointer ,int ,int ,int ,int );

int main()
{
    listPointer mA=NULL,current;
    int numrow,numcol,numvalue,nunzero;
    printf("請輸入 row col nunzero\n");
    scanf("%d %d %d",&numrow,&numcol,&nunzero);
    int i,j;
    mA = makenode();
    mA->col = 0;
    mA->row = 0;
    for(i=1;i<numrow;i++)
        addnode(mA,Downn,i,0,0);
    for(i=1;i<numcol;i++)
        addnode(mA,Nextt,0,i,0);
    printf("請依序輸入每列之非零值\n");
    int row,col,value;
    for(i=0;i<nunzero;i++){
        scanf("%d %d %d",&row,&col,&value);
        addnode(mA,Mix,row,col,value);
    }
    current = mA;
    listPointer temp;
    printf("稀疏矩陣:\n");
    while(current!=NULL){
        temp = current;
        while(current!=NULL){
            if(current->value!=0)
                printf("%d %d %d\n",current->row,current->col,current->value);
            current = current->next;
        }
        current = temp->down;
    }
    current = mA;
    printf("原矩陣:\n");
    for(i=0;i<numrow;i++){
        temp = current;
        for(j=0;j<numcol;j++){
            if(current!=NULL && current->col == j && current->row == i){
                printf("%d ",current->value);
                current = current->next;
            }
            else
                printf("0 ");
        }
        printf("\n");
        if(temp->down!=NULL)
            current = temp->down;
    }
    return 0;
}

listPointer makenode(){
    listPointer new_node;
    new_node = malloc(sizeof(struct listnode));
    new_node->down = NULL;
    new_node->next = NULL;
    return new_node;
}

void addnode(listPointer point,int dir,int row,int col,int value){
    listPointer current = point;
    if(current == NULL){
        current = makenode();
        current->row = row;
        current->col = col;
        current->value = value;
        point = current;
        printf("finish1\n");
    }
    else{
        if(dir == Downn){
            while(current->down!=NULL)
                current = current->down;
            listPointer new_node = makenode();
            new_node->row = row;
            new_node->col = col;
            new_node->value = value;
            current->down = new_node;
            printf("finish2\n");
        }
        else if(dir == Nextt){
            while(current->next!=NULL)
                current = current->next;
            listPointer new_node = makenode();
            new_node->row = row;
            new_node->col = col;
            new_node->value = value;
            current->next = new_node;
            //printf("finish2\n");
        }
        else if(dir == Mix){
            if(col == 0 || row == 0){
                while(current->row!=row)
                    current = current->down;
                while(current->col!=col)
                    current = current->next;
                current->value = value;
            }
            else{
                listPointer new_node = makenode();
                new_node->row = row;
                new_node->col = col;
                new_node->value = value;

                while(current->row<row)
                    current = current->down;
                while(current->col<col && current->next!=NULL)
                    current = current->next;
                //printf("%d %d \n",current->row,current->col);
                current->next = new_node;

                current = point;

                while(current->col<col)
                    current = current->next;
                while(current->row<row && current->down!=NULL)
                    current = current->down;
                //printf("%d %d \n",current->row,current->col);
                current->down= new_node;
            }
            printf("finish 3\n");
        }
    }

}
