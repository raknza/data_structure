#include <stdio.h>
#include <stdlib.h>

/*
�ŧi���c�G
key:�s��

top:�������ݪ��s��

��ƻݨD�G
pop �G��J�Ʀr top++
push�G���X�Ʀr top--

���|�w���ɤ��i�Apush
���|���Ůɤ��i�Apop
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
