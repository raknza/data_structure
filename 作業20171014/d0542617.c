#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*

姓名：張佑瑋
學號：D0542617
撰寫日期：20171014
dev-cpp版本：5.11.0.0
資結作業20171014

*/
typedef struct student{
	char name[10];
	char num[10];
	char grade[4];
}stu;

int main(int argc, char *argv[]) {
	int count=0,n,i,j; // count 為學生數量
	stu students_A[100];
	while(1){
		printf("請輸入想使用的功能:(1)新增 (2)印出 (3)離開\n");
		scanf("%d",&n);
		if(n==1){
			printf("請依序輸入姓名 學號 成績 輸入\"-1\" 即可離開\n");
			while(scanf("%s",students_A[count].name)!=EOF || count <100 ){
				if(!strcmp(students_A[count].name,"-1"))
					break;
                scanf("%s %s",students_A[count].num,students_A[count].grade);
                // 檢查分數是否為數字 否則重新輸入
                for(i=0;i<strlen(students_A[count].grade);i++){
                    if(students_A[count].grade[i]>'9' ||students_A[count].grade[i]<'0'){
                        printf("分數輸入錯誤 請重新輸入:\n");
                        scanf("%s",students_A[count].grade);
                        i = -1;
                    }
                }
				count++; // 學生數量 + 1
			}
		}
		else if(n==2){
			float ClassSum = 0.0; // 班總和
			int digit; // 位數
			for(i=0;i<count;i++){
				printf("%s %s %s\n",students_A[i].name,students_A[i].num,students_A[i].grade);
				for(j=strlen(students_A[i].grade)-1,digit=1;j>=0;j--){
                    ClassSum = ClassSum + digit * (students_A[i].grade[j] - '0'); // 分數 = 位數*數字
                    digit = digit*10;
				}
			}
			printf("全班平均:%.2f\n",ClassSum/count);
		}
		else if(n==3)
			break;
		else
			printf("無效指令\n");

	}
	return 0;
}



