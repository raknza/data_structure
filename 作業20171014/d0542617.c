#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*

�m�W�G�i��޳
�Ǹ��GD0542617
���g����G20171014
dev-cpp�����G5.11.0.0
�굲�@�~20171014

*/
typedef struct student{
	char name[10];
	char num[10];
	char grade[4];
}stu;

int main(int argc, char *argv[]) {
	int count=0,n,i,j; // count ���ǥͼƶq
	stu students_A[100];
	while(1){
		printf("�п�J�Q�ϥΪ��\��:(1)�s�W (2)�L�X (3)���}\n");
		scanf("%d",&n);
		if(n==1){
			printf("�Ш̧ǿ�J�m�W �Ǹ� ���Z ��J\"-1\" �Y�i���}\n");
			while(scanf("%s",students_A[count].name)!=EOF || count <100 ){
				if(!strcmp(students_A[count].name,"-1"))
					break;
                scanf("%s %s",students_A[count].num,students_A[count].grade);
                // �ˬd���ƬO�_���Ʀr �_�h���s��J
                for(i=0;i<strlen(students_A[count].grade);i++){
                    if(students_A[count].grade[i]>'9' ||students_A[count].grade[i]<'0'){
                        printf("���ƿ�J���~ �Э��s��J:\n");
                        scanf("%s",students_A[count].grade);
                        i = -1;
                    }
                }
				count++; // �ǥͼƶq + 1
			}
		}
		else if(n==2){
			float ClassSum = 0.0; // �Z�`�M
			int digit; // ���
			for(i=0;i<count;i++){
				printf("%s %s %s\n",students_A[i].name,students_A[i].num,students_A[i].grade);
				for(j=strlen(students_A[i].grade)-1,digit=1;j>=0;j--){
                    ClassSum = ClassSum + digit * (students_A[i].grade[j] - '0'); // ���� = ���*�Ʀr
                    digit = digit*10;
				}
			}
			printf("���Z����:%.2f\n",ClassSum/count);
		}
		else if(n==3)
			break;
		else
			printf("�L�ī��O\n");

	}
	return 0;
}



