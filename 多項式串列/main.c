#include <stdio.h>
#include <stdlib.h>
typedef struct polynomial{
    int expon;
    int coef;
    struct polynomial *next;
}*polyPointer;

polyPointer newnode();
void addpoly(polyPointer,int,int);
void delpoly(polyPointer);
polyPointer padd(polyPointer,polyPointer);
int compare(int ,int );
void attach(int,int,polyPointer );

int main()
{
    int select,expon,coef;
    polyPointer poly_A,poly_B,poly_sum,current=NULL;
    poly_A = newnode();
    poly_B = newnode();
    poly_sum = newnode();
    // 建立多項式B
    printf("loading poly_B:\n");
    addpoly(poly_B,5,4);
    addpoly(poly_B,6,3);
    addpoly(poly_B,2,1);
    addpoly(poly_B,7,0);
    printf("loading poly_B complete:\n");
    printf("1-(add polyA) 2-(print poly)  3-(polyA + polyB)   4-(clean A):");
    while(~scanf("%d",&select)){
        if(select == 1){
            printf("enter coef and expon:");
            scanf("%d %d",&coef,&expon);
            addpoly(poly_A,coef,expon);
        }
        else if (select == 2){
            // print poly A and B
            current = poly_A->next;
            printf("A = ");
            while(current!=NULL){
                printf("%dx^%d + ",current->coef,current->expon);
                current = current->next;
            }
            printf("\n");
            current = poly_B->next;
            printf("B = ");
            while(current!=NULL){
                printf("%dx^%d + ",current->coef,current->expon);
                current = current->next;
            }
            printf("\n");
        }
        else if(select == 3){
            poly_sum = padd(poly_A,poly_B);
            current = poly_sum->next;
            printf("sum = ");
            while(current!=NULL){
                printf("%dx^%d + ",current->coef,current->expon);
                current = current->next;
            }
            printf("\n");
            delpoly(poly_sum);
        }
        else if(select == 4){
            delpoly(poly_A);
        }
    }
    return 0;
}

polyPointer newnode(){
    polyPointer temp;
    temp = malloc(sizeof(struct polynomial));
    temp->next = NULL;
    return temp;
}

void addpoly(polyPointer node,int coef,int expon){
    polyPointer current = node;
    while(current->next!=NULL)
        current = current->next;
    polyPointer new_poly = newnode();
    new_poly->expon = expon;
    new_poly->coef = coef;
    current->next = new_poly;
    printf("finish\n");
}

void delpoly(polyPointer node){
    polyPointer current = node,temp=NULL;
    if(node->next == NULL){
        printf("It's empty\n");
    }
    else{
        while(current->next!=NULL){
            temp = current->next;
            current->next = temp->next;
            free(temp);
        }
        printf("finish clean\n");
    }
}

polyPointer padd(polyPointer A,polyPointer B){
    polyPointer C,tmp_A=A->next,tmp_B=B->next;
    C = newnode();
    while(tmp_A!=NULL && tmp_B!=NULL){
        switch (compare(tmp_A->expon,tmp_B->expon)){
            // A > B
            case 1:
                attach(tmp_A->coef,tmp_A->expon,C);
                tmp_A = tmp_A->next;
                break;
            // A = B
            case 0:
                attach(tmp_A->coef + tmp_B->coef,tmp_A->expon,C);
                tmp_A = tmp_A->next;
                tmp_B = tmp_B->next;
                break;
            // A < B
            case -1:
                attach(tmp_B->coef,tmp_B->expon,C);
                tmp_B = tmp_B->next;

        }
    }
    for(;tmp_A!=NULL;tmp_A=tmp_A->next)
        attach(tmp_A->coef,tmp_A->expon,C);
    for(;tmp_B!=NULL;tmp_B=tmp_B->next)
        attach(tmp_B->coef,tmp_B->expon,C);
    return C;
}

int compare(int a,int b){
    if(a>b)
        return 1;
    else if(a<b)
        return -1;
    else
        return 0;
}

void attach(int coef,int expon,polyPointer poly_new){
    polyPointer current = poly_new;
    while(current->next!=NULL)
        current = current->next;
    polyPointer temp = newnode();
    temp->coef = coef;
    temp->expon = expon;
    current->next = temp;
}


