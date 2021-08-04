#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int key;
}element;

typedef struct{
    int disk;
    int key;
    int from;
    int to;
    int aup;
}reucursion;

element stack[3][50];
reucursion stackn[100];
int top[3]={-1,-1,-1};
int count = 0;

void hanoi(int,int,int,int);
void printhanoi();
void push(int,int);
int pop(int);

int main()
{
    int n,i;
    printf(">>>> Please enter numbers of disk:");
    while(~scanf("%d",&n)){
        for(i=n;i>=1;i--)
            push(i,0);
        count = 0;
        printhanoi();
        printf("\n");
        hanoi(n,'A','C','B');
        printf("\n>>>> Please enter numbers of disk:");
    }
    return 0;
}

void hanoi(int n,int from,int to ,int aup){
    int top_n = 0;
    int num,fp,tp,ap,disk;
    stackn[top_n].key = n;
    stackn[top_n].disk = n;
    stackn[top_n].from = from;
    stackn[top_n].aup = aup;
    stackn[top_n].to = to;
    while(top_n!=-1){
        num = stackn[top_n].key;
        fp = stackn[top_n].from;
        tp = stackn[top_n].to;
        ap = stackn[top_n].aup;
        disk = stackn[top_n].disk;
        top_n--;
        if(num == 1){
            push(pop(fp-'A'),tp-'A');
            printhanoi();
            printf("count%d: move disk%d from %c to %c\n",++count,disk,fp,tp);
        }
        else{
            top_n++;
            stackn[top_n].key = num-1;
            stackn[top_n].disk = disk-1;
            stackn[top_n].from = ap;
            stackn[top_n].aup = fp;
            stackn[top_n].to = tp;


            top_n++;
            stackn[top_n].key = 1;
            stackn[top_n].disk = disk;
            stackn[top_n].from = fp;
            stackn[top_n].aup = ap;
            stackn[top_n].to = tp;


            top_n++;
            stackn[top_n].key = num-1;
            stackn[top_n].disk = disk-1;
            stackn[top_n].from = fp;
            stackn[top_n].aup = tp;
            stackn[top_n].to = ap;
        }
    }

}

void printhanoi(){
    int i,j,k;
    printf("******************************************************\n\n");
    for(i=0;i<3;i++){
        printf("%c:  ",'A' + i);

        for(j=0;j<=top[i];j++){
            printf("%d  ",stack[i][j]);
        }
        printf("\n");
    }
}


void push(int key,int p){
    stack[p][++top[p]].key = key;
}

int pop(int p){
    return stack[p][top[p]--].key;
}
