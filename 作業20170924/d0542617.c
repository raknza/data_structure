#include <stdio.h>
#include <stdlib.h>
#define SIZE 10000000
/*

姓名：張佑瑋
學號：D0542617
撰寫日期：20170924
dev-cpp版本：5.11.0.0
資結作業20170924 尋找第100000個質數

*/

int prime[SIZE];

int main()
{
    printf("%d",FindPrime(100000));
    return 0;
}

int FindPrime(int n){
    int i,j,k=0,count =0;
    // 建立質數表 1~10000000
    for(i=0;i<SIZE;i++)
        prime[i] = 0;
    prime[0] = 1; // 0,1先判定為非質數
    prime[1] = 1;
	for(i = 2;i < sqrt(SIZE) ;i++){ // 由2開始刪去其倍數到該數開根號（根據篩法）
		if(!prime[i]){
			for(j = i*i; j < SIZE; j+=i) // 從i*i開始刪 因為i*（i-1) 前已被上一次迴圈內的i刪除
				prime[j] = 1; // 判定為非質數
		}
	}
	// 尋找第n個質數 滿足count = n 時返回
    for(i=0;count<n;i++){
        if(prime[i]==0)
            count++;
    }
    return i-1;
}
