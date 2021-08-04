#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define LONG 1000000
/*

尋找質數練習 - 試除法

*/
int main()
{
	prime();//呼叫函式
	return 0;
}
void prime(void)
{
	int i,j,k,count=2;//count為第幾個數字
	i=5;
	while(count<LONG)
    {	
        for(j=2;j<=(int)sqrt(i);j++) // 加速約240s 
        {
            if(i%j==0)//相除等於零就跳離迴圈
            {
                break;
            }
            if((int)sqrt(i)==j&&i%j!=0)//當判斷到i的前一個值,若符合條件則count++
            {
                count++;
            }
        }
        i+=2; // 加速約0.1秒s
    }
    printf("%d",i-2);//print值,因為前面有i++,所以輸出要多減一個2
}
