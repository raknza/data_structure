#include <stdio.h>
#include <stdlib.h>

char stack[50];
int top = -1;
int parent = 0;

void push(char);
char pop();

int main()
{
    flag:
    while(1){
        char buff;
        buff = getchar();
        if(buff == '.')
            break;
        else if(buff == '(' || buff == ')'){
            push(buff);
        }
    }
    printf("top = %d\n",top);
    if(top!=-1)
        printf("False\n");
    else
        printf("True\n");
    top = -1;
    parent = 0;
    goto flag;
    return 0;
}

void push(char data){
    if(data == '('){
        parent++;
        stack[++top] = data;
    }
    else if(data == ')' && parent){
        char temp = pop();
    }
    else{
        stack[++top] = data;
    }
}

char pop(){
    return stack[top--];
}
