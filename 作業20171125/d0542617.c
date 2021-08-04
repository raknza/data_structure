#include <stdio.h>
#include <stdlib.h>
/*

�m�W�G�i��޳
�Ǹ��GD0542617
���g����G20171125
dev-cpp�����G5.11.0.0
�굲�@�~20171125 �쵲��Clinked list�x�s���

*/
typedef struct linked{
    int data;
    struct linked* next;
}*node;

node makenode();
node addnode(node,int);
node changenum(node,int,int);
node delnum(node,int);
int repeat(node ,int );
int findnum(node ,int );

int main()
{
    node list = NULL,current=NULL;
    int select,data;
    printf("Please use a function :(1)addnum (2)changenum (3)delect num (4)show list (5)exit:\n");
    while(~scanf("%d",&select)){
        if(select == 1){
            printf("Please input a num:");
            scanf("%d",&data);
            current = addnode(list,data);
            if(current)
                list = current;
        }
        else if(select == 2){
            int new_data;
            printf("Please input two num:");
            scanf("%d",&data);
            scanf("%d",&new_data);
            current = changenum(list,data,new_data);
            if(current)
                list = current;

        }
        else if(select == 3){
            printf("Please input a num:");
            scanf("%d",&data);
            current = delnum(list,data);
            if(current)
                list = current;
        }
        else if(select == 4){
            current = list;
            if(!current)
                printf("empty");
            while(current!=NULL){
                printf("%d",current->data);
                current = current->next;
                if(current)
                    printf(" -> ");
            }
            printf("\n");
        }
        else if(select == 5)
            return 0;
    }
    return 0;
}

node makenode(){
    node new_node = malloc(sizeof(struct linked));
    new_node->next = NULL;
    return new_node;
}

node addnode(node list,int data){
    node new_node = makenode();
    new_node->data = data;
    if(!list){ // �L��C�s�b�ɤ��걵
        printf("add succeed!\n");
        return new_node;
    }
    else{
        node before = NULL,current = list;
        if(repeat(list,data)){// ����ƿ�J�Ʀr
            printf("error\n");
            return NULL;
        }
        while(current->data < data ){ // ���в��ʦܤj��data����
            before = current ;current = current->next;
            if(!current) // �W�X����break
                break;
        }
        if(before){ // �D���N�Y �@�⦸�걵(�e�@�ӻP��@��)
            before->next = new_node;
            new_node->next = current;
            printf("add succeed!\n");
            return list;
        }
        else{ // ���N�Y
            new_node->next = current;
            printf("add succeed!\n");
            return new_node;
        }
    }
    return NULL;
}

node delnum(node list,int data){
    if(!list)
        printf("It's empty\n");
    else{
        node before = NULL,current = list;
        while(current->data != data){ // ���ʦܸ�Ʀ�m
            before = current; current = current->next;
            if(!current)
                break;
        }
        if(!findnum(list,data)){ // �䤣�쪺���p�^��NULL
            printf("not found\n");
            return NULL;
        }
        else{
            if(!before){ // �R���Y
                node temp  = current;
                current = current->next;
                free(temp);
                printf("delect succeed!\n");
                if(!current)
                    return NULL;
                return current;

            }
            else{ // �R���D�Y
                before->next = current->next;
                free(current);
                printf("delect succeed!\n");
                return list;
            }
        }
    }
}

node changenum(node list,int data,int new_data){
    if(!list)
        printf("It's empty\n");
    else{
        if(repeat(list,new_data)){// ����ƿ�J�Ʀr
            printf("error\n");
            return NULL;
        }
        if(!findnum(list,data)){ // �����data�^��NULL
            printf("not found\n");
            return NULL;
        }
         // �ק�Ȭ����R���A�s�W
        node current = delnum(list,data); // �R�����
        if(current){ // ���\�R�������p
            current = addnode(current,new_data);// addnode()��ƥ[�J�Ʀr�ɦ۰ʱƧ�
            printf("change succeed!\n");
            return current;
        }
        else // �S���ӼƦr�^��NULL
            return NULL;
    }
}

int repeat(node list,int data){
    node current = list;
    while(current){
        if(current->data == data)
            return 1;
        current = current->next;
    }
    return 0;
}

int findnum(node list,int data){
    node current = list;
    while(current){
        if(current->data == data)
            return 1;
        current = current->next;
    }
    return 0;
}
