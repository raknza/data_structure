#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*

KMP �˦����t��k 20171018 - KMPmatch + FailureFunction

*/
int main()
{   char str[30]={},str2[100]={};
    int find;
    while(scanf("%s %s",str,str2)!=EOF){
        find = KMPmatch(str,str2);
        if(find == -1)
            printf("not found\n");
        else
            printf("found it at %d\n",find);
    }
    return 0;
}

int KMPmatch(char str1[],char str2[]){
    int length1 = strlen(str1);
    int length2 = strlen(str2);
    int Fail[length1],i=0,j=0;
    FailFun(str1,Fail);
    while(i<length2 && j<length1){
        if(str1[j] !=str2[i]){
            if(j==0)
                i++;
            else
                j = Fail[j-1] + 1; // 0~Fail[j-1]������T +1���m�}�l���
        }
        else{
            i++;
            j++;
        }
    }
    if( j == length1 )
        return i-j;// j��str1���� ��h i�]�bstr2��str1�̫�r������@��^ = str1�bstr2���_�l��m
    else
        return -1;

}

void FailFun(char str[], int Fail[]){
    int length = strlen(str);
    Fail[0] = -1;
    int start = 1,i,j;
    for(i=2;i<=(length);i++){
        int start = 1;
        int current = 0;
        for(j=start;j<i;j++){
            if( str[j] != str[current++]){
                current = 0;
                j = start++;
            }
        }
        if( start < i )
            Fail[i-1] = current-1;
        else
            Fail[i-1] = -1;
    }
    /*
    for(i=0,i<length;i++)
        printf("Fail[%d] = %d\n",i,Fail[i]);
    */
}
