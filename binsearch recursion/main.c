#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SWAP(x,y,t) ((t) = (x),(x)= (y),(y) = (t) )

int main()
{   int temp;
    char *str = malloc(sizeof(char));
    scanf("%s",str);
    printf("%s,%d\n",str,strlen(str));
    perm(str,0,strlen(str)-1);
    return 0;
}

void perm(char *list, int i,int n){
    int j,temp;
    if(i == n)
        printf("%s\n",list);
    else{
        for(j=i;j<=n;j++){
            SWAP(list[i],list[j],temp);
            perm(list,i+1,n);
            SWAP(list[i],list[j],temp);
        }
    }
}
