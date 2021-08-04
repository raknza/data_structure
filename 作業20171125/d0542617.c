#include <stdio.h>
#include <stdlib.h>
/*

姓名：張佑瑋
學號：D0542617
撰寫日期：20171125
dev-cpp版本：5.11.0.0
資結作業20171125 鏈結串列linked list儲存資料

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
    if(!list){ // 無串列存在時不串接
        printf("add succeed!\n");
        return new_node;
    }
    else{
        node before = NULL,current = list;
        if(repeat(list,data)){// 防止重複輸入數字
            printf("error\n");
            return NULL;
        }
        while(current->data < data ){ // 指標移動至大於data的數
            before = current ;current = current->next;
            if(!current) // 超出尾時break
                break;
        }
        if(before){ // 非取代頭 作兩次串接(前一個與後一個)
            before->next = new_node;
            new_node->next = current;
            printf("add succeed!\n");
            return list;
        }
        else{ // 取代頭
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
        while(current->data != data){ // 移動至資料位置
            before = current; current = current->next;
            if(!current)
                break;
        }
        if(!findnum(list,data)){ // 找不到的情況回傳NULL
            printf("not found\n");
            return NULL;
        }
        else{
            if(!before){ // 刪除頭
                node temp  = current;
                current = current->next;
                free(temp);
                printf("delect succeed!\n");
                if(!current)
                    return NULL;
                return current;

            }
            else{ // 刪除非頭
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
        if(repeat(list,new_data)){// 防止重複輸入數字
            printf("error\n");
            return NULL;
        }
        if(!findnum(list,data)){ // 未找到data回傳NULL
            printf("not found\n");
            return NULL;
        }
         // 修改值為先刪除再新增
        node current = delnum(list,data); // 刪除資料
        if(current){ // 成功刪除的情況
            current = addnode(current,new_data);// addnode()函數加入數字時自動排序
            printf("change succeed!\n");
            return current;
        }
        else // 沒找到該數字回傳NULL
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
