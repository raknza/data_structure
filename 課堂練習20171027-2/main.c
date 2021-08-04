#include <stdio.h>
#include <stdlib.h>
/*

括號處理方式：將運算子一直留在堆疊中直到遇見右括弧後進行運算

*/
typedef struct{
    char value;
    int priority;
}element;

element stack[100];
int top=-1;
int parent=0;

void push(char ,int );
void pop();

int main()
{
    char c;
    printf("input:\n");
    while(~scanf("%c",&c)){
        /*if (top>=1)
            printf("stack[%d] = %c stack[%d] = %c\n",top-1,stack[top-1].value,top,stack[top].value);*/
        switch(c){
            case '+':case'-':
                push(c,1);
                break;

            case '*':case '/':
                push(c,2);
                break;

            case '(':case ')':
                push(c,3);
                break;

            case '\n':
                while(top!=-1)
                    pop();
                printf("\n");
                break;
            default:
                printf("%c",c);
        }

    }
    return 0;
}


void push(char c,int priority){
    //printf("c=%c pri:%d\n",c,priority);
    if(c == '(')
        parent++;
    if(c == ')'){
        int tmp = parent;
        while(tmp == parent)
            pop();
    }
    else{
        if(stack[top].priority>=priority && top>=0 && parent==0){
            pop();
            push(c,priority);
        }
        else{
            stack[top+1].value = c;
            stack[top+1].priority = priority;
            top++;
        //printf("now top:%d\n",top);
        }
    }
}

void pop(){
    if(stack[top].value == '('){
        parent--;
        top--;
    }
    else{
        printf("%c",stack[top].value);
        top--;
    }
    //printf("now top:%d\n",top);
}
// a* ( b+c ) * d
// a*(bc+ * d
