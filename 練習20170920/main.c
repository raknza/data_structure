#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int n,i,blist[100];
    scanf("%d",&n);
    bool_arrangement(blist,0,n);
    return 0;
}
void bool_arrangement(int blist[100],int i,int n){
    int k;
    if (i>=n){
        for(k=0;k<n;k++){
            if (blist[k] == 1)
                printf("¯u ");
            if (blist[k] == 0)
                printf("°² ");
        }
        printf("\n");
    }
    else{
        blist[i] = 1;
        bool_arrangement(blist,i+1,n);
        blist[i] = 0;
        bool_arrangement(blist,i+1,n);
    }

}
