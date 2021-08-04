#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *file_in = fopen("data_in.txt","r");
    int length = 0;
    int sum = 0;
    int data;
    while(~fscanf(file_in,"%d",&data)){
        sum = sum + data;
        length++;
    }
    fclose(file_in);
    printf("%.0f\n",(float)sum/length);
    return 0;
}
