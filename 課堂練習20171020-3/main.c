#include <stdio.h>
#include <stdlib.h>

/*
宣告結構：
key:存值

top:紀錄頂端的編號

函數需求：
pop ：填入數字 top++
push：取出數字 top--

堆疊已滿時不可再push
堆疊為空時不可再pop
*/
typedef struct{
    int value;
}element;


void pop();
void push(int );

element A[5];
int top = -1;

int main()
{
    int n,num;
	while(1){
		printf("please select 1.push 2.pop 3.exit:\n");
    	scanf("%d",&n);
    	if(n==3)
    		return 0;
    	else if(n==1){
    		if(top>=4)
    			printf("stack is full\n");
			else{
    			printf("please input the number:\n");
    			scanf("%d",&num);
    			push(num);
    		}
		}
		else if(n==2){
			if(top==-1)
				printf("It's empty\n'");
			else
				pop();
		}
	}
    return 0;
}

void pop(){
	printf("pop:%d\n",A[top--]);
}

void push(int num){
	A[++top].value = num;
	printf("finsh push\n");
}
