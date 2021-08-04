#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int value;
}element;

int rear=0,front=0;
element queue[6];

void enqueue();
void dequeue();


int main()
{
    int n,num;
	while(1){
		printf("please select 1.enqueue 2.dequeue 3.exit:\n");
    	scanf("%d",&n);
    	if(n==3)
    		return 0;
    	else if(n==1){
            enqueue();
		}
		else if(n==2){
            dequeue();
		}
	}
    return 0;
}

void enqueue(){
    int value;
    if((rear+1)%6==front)
        printf("queue is full\n");
    else{
        printf("please input the number:\n");
        scanf("%d",&value);
        rear = (rear+1)%6;
        queue[rear].value = value;
        printf("finish\n");
        printf("rear:%d front:%d\n",rear,front);
    }
}

void dequeue(){
    if(front == rear)
        printf("queue is empty\n");
    else{
        front = (front+1)%6;
        printf("dequeue:%d\n",queue[front]);
        //printf("rear:%d front:%d\n",rear,front);
    }
}
