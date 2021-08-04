#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*

Base64�s�X�ѽX
�C4�Ӧr�����@�նi��ѽX
1.�N�r���qBase64 code �ഫ�� �G�i�� : 4 * 6-bit
2.�ɻ�24���C8����X�@�� 3 * 8-bit
3.�C���ର�Q�i���������� ascii code �r����X

Base�[�K�G
�H64�Ӧr����ܤG�i���ƪ���k�C�C�T�Ӧ줸�չ���4��Base64�椸�]�Ҧ�24�Ӧ줸�^3 * 8-bit -> 4 * 6-bit

*/
int main()
{   char text_crypted[1000]={},text_crypting[5]={},text_binary[25],text_decrypted[1000]={};
    char Base64_code[66] ={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
                           'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',
                           '0','1','2','3','4','5','6','7','8','9','+','/','=','#'};
    int i,j;
    while(fgets(text_crypted, sizeof(text_crypted), stdin)){
        if(text_crypted[strlen(text_crypted)-1] == '#'){
           	strcat(text_decrypted,"#\0");
			printf("%s\n",text_decrypted); // ��X�r��
			strcpy(text_decrypted,""); // �M�Ŧr�� 
			break;
		}
        if (text_crypted[0]== '#'){
        	strcat(text_decrypted,"#\0");
        	break;
        }
    	for(i=0;text_crypted[i]!='\0';i++){ // �R���Dbase64���r�� 
    		int wrong = 1;
    		for(j=0;j<66;j++){
    			if(text_crypted[i] == Base64_code[j]){
    				wrong = 0;
    				break; // ���Y���X 
    			}
			}
			if(wrong == 1){
				char temp[1000] = {};
				strncpy(temp,text_crypted,i);
				strncat(temp,text_crypted+i+1,strlen(text_crypted)-i);
				strcpy(text_crypted,temp);
				i--;
			}
		}
        //strcpy(text_decrypted,""); // �M�Ŧr�� 
        while(strlen(text_crypted)!=0){
        	// ��l�� 
            strcpy(text_binary,"000000000000000000000000"); // ���ɺ�0 
            if (strlen(text_crypted)>=4){ 
            	strncpy(text_crypting,text_crypted,4); // �ƻs4�Ӧr��
                strncpy(text_crypted,text_crypted+4,strlen(text_crypted)-3);// �w�ƻs���r���R�h
        	}
            else{ // �����|�r�� 
            	strcpy(text_crypting,text_crypted);
            	if(strlen(text_crypting)<5)
            		for(i=strlen(text_crypting);i<4;i++)
            			text_crypting[i] = '='; // �� "=" �Ÿ� 
                strcpy(text_crypted,""); // �M��text_crypted 
			}
            // �}�l�ѽX 
            for(i=0;i<4;i++){
                for(j=0;j<65;j++){
                    if(text_crypting[i] == Base64_code[j]){ // �N�r���qBase64�s�X �ন�G�i��
                        int text_Base64_code = j;
                        if (j == 64) // '='�Ÿ��ɪ������X 
                        	text_Base64_code = 0;
                        int k = 5;
                        while(text_Base64_code >1){ // �q4 * 6-bit �ഫ�� 1 * 24-bit 
                            text_binary[i*6 + k] = text_Base64_code%2 +'0';
                            text_Base64_code = text_Base64_code/2;
                            k--;
                        }
                        if(text_Base64_code >0)
                        	text_binary[i*6 + k] = '1' ;
                        break;
                    }
                }
            }
			//printf("1 * 24-bit:%s\n",text_binary);
			for(i=0;i<24;i++)
				text_binary[i] = text_binary[i] - '0'; 
			char text_ASCII_code[4]={};
            // �ഫ���� 
            for(i=0;i<3;i++){ // ���Φ�3 * 8-bit ���ഫ�������� ascii code ��N�r���걵�� text_decrypted 
            	text_ASCII_code[i] = text_binary[8*i + 7]*1 + text_binary[8*i + 6]*2 +  text_binary[8*i + 5]*4 + text_binary[8*i + 4]*8 + text_binary[8*i + 3]*16 +  text_binary[8*i + 2]*32 +  text_binary[8*i + 1]*64 +  text_binary[8*i + 0]*128 ;
				// printf("asco:%d\n",text_ASCII_code[i]); �ˬdascii code 
				if(text_ASCII_code[i] == 0)
					text_ASCII_code[i] = '\0';
			}
			strcat(text_decrypted,text_ASCII_code);
        }
    }
    return 0;
}
