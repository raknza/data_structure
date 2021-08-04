#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define swap(x,y,z) (z=x , x = y ,y = z)


void Permu(char [],int ,int);

int main()
{
    char buff[10];
    while(1){
        scanf("%s",buff);
        printf("ALL Permutations:\n");
        Permu(buff,0,strlen(buff)-1);
    }
    return 0;
}


void Permu(char buff[],int start,int end){
    int i;
    char temp;
    if(start == end){
        printf("%s\n",buff);
    }
    else{
        for(i=start;i<=end;i++){
            swap(buff[start],buff[i],temp);
            Permu(buff,start+1,end);
            swap(buff[start],buff[i],temp);
        }
    }
}
