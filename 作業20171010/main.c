#include <stdio.h>
#include <stdlib.h>
/*

�m�W�G�i��޳
�Ǹ��GD0542617
���g����G20171010
dev-cpp�����G5.11.0.0
�굲�@�~20171010 �L�X���B�f�ɰw���ۯx�} 

*/
int main()
{   int size,number=1,x=0,y=0,i,j;
    printf("�п�J�x�}�e�סG");
	scanf("%d",&size); // ��J�x�}�j�p 
    while(size > 10){
    	printf("���~�I\n");
    	printf("�п�J�x�}�e�סG");
    	scanf("%d",&size); // ���s��J 
	}
    int martix[size][size]; // �ŧi�}�C 
    // �]�w�x�}��Ȭ�0
    for(i=0;i<size;i++)
        for(j=0;j<size;j++)
            martix[i][j] = 0;
    // x,y���ثe�y�� �V�k�� +x �V����-x �V�W��-y �V�U��+y 
    // �f�ɰw ��V�H�G�U�B�k�B�W�B�� ���@���`��  
    while(number<=size*size){ // ���J���Ʀr���j�� size*size�� 
        //�V�U
        while(martix[y][x]==0 && y<size){
            martix[y][x] =number;
            y++;
            number++;
        }
        y--; // �h��@�� 
        x++; // ���U�Ӥ�V�e�i�@�� 
        //�V�k
        while(martix[y][x]==0 && x<size){
            martix[y][x] =number;
            x++;
            number++;
        }
        x--;
        y--;
        //�V�W
        while(martix[y][x]==0 && y>-1){
            martix[y][x] =number;
            y--;
            number++;
        }
        y++;
        x--;
        //�V��
        while(martix[y][x]==0 && x>-1){
            martix[y][x] = number;
            x--;
            number++;
        }
        x++;
        y++;
    }
    // ��X�x�} 
    printf("�f�ɰw�G\n");
    for(i=0;i<size;i++){
        for(j=0;j<size;j++)
            printf("%4d",martix[i][j]); // �̤j��10*10 �̤j�u�ݭn3���� �h�Ť@��ƪ� 
        printf("\n");
    }

    // �ܼƭ��] 
    for(i=0;i<size;i++)
        for(j=0;j<size;j++)
            martix[i][j] = 0;
    number = 1;
    x=0;
	y=0;
    // ���ɰw ��V�H�G�k�B�U�B���B�W ���@���`��  
    while(number<=size*size){
        //�V�k
        while(martix[y][x]==0 && x<size){
            martix[y][x] =number;
            x++;
            number++;
        }
        x--;
        y++;
        //�V�U
        while(martix[y][x]==0 && y<size){
            martix[y][x] =number;
            y++;
            number++;
        }
        y--;
        x--;
        //�V��
        while(martix[y][x]==0 && x>-1){
            martix[y][x] = number;
            x--;
            number++;
        }
        x++;
        y--;
        //�V�W
        while(martix[y][x]==0 && y>-1){
            martix[y][x] =number;
            y--;
            number++;
        }
        y++;
        x++;
    }
    // ��X�x�} 
    printf("\n���ɰw�G\n");
    for(i=0;i<size;i++){
        for(j=0;j<size;j++)
            printf("%4d",martix[i][j]);
        printf("\n");
    }
    return 0;
}
