#include <stdio.h>
#include <stdlib.h>
/*

課堂練習20171020 多項式加法 - 陣列儲存

*/

typedef struct{
    int expon;
    int coef;
}polynomial;


int subpolynomial(int ,int ,int ,int ,int ,polynomial[]);
int attach(int ,int ,int ,polynomial []);
int compare(int ,int );

int main()
{
    int startA,startB,finshA,finshB,avail;
    polynomial terms[100];
    // 讀入多項式A
    startA = 0;
    finshA = 2;
    terms[0].expon = 10;
    terms[0].coef = 2;
    terms[1].expon = 7;
    terms[1].coef = 5;
    terms[2].expon = 2;
    terms[2].coef = 8;
    // 讀入多項式B
    startB = 3;
    finshB = 6;
    terms[3].expon = 7;
    terms[3].coef = 8;
    terms[4].expon = 4;
    terms[4].coef = 9;
    terms[5].expon = 2;
    terms[5].coef = 3;
    terms[6].expon = 0;
    terms[6].coef = 2;
    avail = 7;
    avail = subpolynomial(startA,startB,finshA,finshB,avail,terms);
    int i;

    for(i=finshB+1;i<avail;i++){
        if(terms[i].expon !=0)
            printf("%dx^%d + ",terms[i].coef,terms[i].expon);
        else
            printf("%d\n",terms[i].coef);
    }
    return 0;
}

int subpolynomial(int startA,int startB,int finshA,int finshB,int avail,polynomial terms[]){
    while(startA <= finshA && startB <= finshB)
        switch (compare(terms[startA].expon,terms[startB].expon)){
            case 0:
                avail = attach(avail,terms[startB].coef,terms[startB].expon,terms);
                startB++;
                break;
            case -1:
                avail = attach(avail,terms[startB].coef + terms[startA].coef,terms[startB].expon,terms);
                startA++;
                startB++;
                break;
            case 1:
                avail = attach(avail,terms[startA].coef,terms[startA].expon,terms);
                startA++;
        }
    for(;startA<=finshA;startA++)
        avail = attach(avail,terms[startA].coef,terms[startA].expon,terms);
    for(;startB<=finshB;startB++)
        avail = attach(avail,terms[startB].coef,terms[startB].expon,terms);
    return avail;
}

int attach(int avail,int coef,int expon,polynomial terms[]){
    terms[avail].coef = coef;
    terms[avail].expon = expon;
    return avail+1;

}

int compare(int A,int B){
    if(A>B)
        return 1;
    else if(A<B)
        return 0;
    else
        return -1;
}
