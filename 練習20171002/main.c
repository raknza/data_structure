#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define LONG 1000000
/*

�M���ƽm�� - �հ��k

*/
int main()
{
	prime();//�I�s�禡
	return 0;
}
void prime(void)
{
	int i,j,k,count=2;//count���ĴX�ӼƦr
	i=5;
	while(count<LONG)
    {	
        for(j=2;j<=(int)sqrt(i);j++) // �[�t��240s 
        {
            if(i%j==0)//�۰�����s�N�����j��
            {
                break;
            }
            if((int)sqrt(i)==j&&i%j!=0)//��P�_��i���e�@�ӭ�,�Y�ŦX����hcount++
            {
                count++;
            }
        }
        i+=2; // �[�t��0.1��s
    }
    printf("%d",i-2);//print��,�]���e����i++,�ҥH��X�n�h��@��2
}
