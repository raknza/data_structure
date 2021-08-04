#include <stdio.h>
#include <stdlib.h>
#define SIZE 10000000
/*

�m�W�G�i��޳
�Ǹ��GD0542617
���g����G20170924
dev-cpp�����G5.11.0.0
�굲�@�~20170924 �M���100000�ӽ��

*/

int prime[SIZE];

int main()
{
    printf("%d",FindPrime(100000));
    return 0;
}

int FindPrime(int n){
    int i,j,k=0,count =0;
    // �إ߽�ƪ� 1~10000000
    for(i=0;i<SIZE;i++)
        prime[i] = 0;
    prime[0] = 1; // 0,1���P�w���D���
    prime[1] = 1;
	for(i = 2;i < sqrt(SIZE) ;i++){ // ��2�}�l�R�h�䭿�ƨ�Ӽƶ}�ڸ��]�ھڿz�k�^
		if(!prime[i]){
			for(j = i*i; j < SIZE; j+=i) // �qi*i�}�l�R �]��i*�]i-1) �e�w�Q�W�@���j�餺��i�R��
				prime[j] = 1; // �P�w���D���
		}
	}
	// �M���n�ӽ�� ����count = n �ɪ�^
    for(i=0;count<n;i++){
        if(prime[i]==0)
            count++;
    }
    return i-1;
}
