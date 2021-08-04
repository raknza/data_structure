#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*

Base64編碼解碼
每4個字元為一組進行解碼
1.將字元從Base64 code 轉換為 二進位 : 4 * 6-bit
2.補齊24格後每8格切出一組 3 * 8-bit
3.每組轉為十進位後找到對應的 ascii code 字元輸出

Base加密：
以64個字元表示二進位資料的方法。每三個位元組對應4個Base64單元（皆有24個位元）3 * 8-bit -> 4 * 6-bit

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
			printf("%s\n",text_decrypted); // 輸出字串
			strcpy(text_decrypted,""); // 清空字串 
			break;
		}
        if (text_crypted[0]== '#'){
        	strcat(text_decrypted,"#\0");
        	break;
        }
    	for(i=0;text_crypted[i]!='\0';i++){ // 刪除非base64表之字元 
    		int wrong = 1;
    		for(j=0;j<66;j++){
    			if(text_crypted[i] == Base64_code[j]){
    				wrong = 0;
    				break; // 抓到即中出 
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
        //strcpy(text_decrypted,""); // 清空字串 
        while(strlen(text_crypted)!=0){
        	// 初始化 
            strcpy(text_binary,"000000000000000000000000"); // 先補滿0 
            if (strlen(text_crypted)>=4){ 
            	strncpy(text_crypting,text_crypted,4); // 複製4個字元
                strncpy(text_crypted,text_crypted+4,strlen(text_crypted)-3);// 已複製的字元刪去
        	}
            else{ // 不滿四字元 
            	strcpy(text_crypting,text_crypted);
            	if(strlen(text_crypting)<5)
            		for(i=strlen(text_crypting);i<4;i++)
            			text_crypting[i] = '='; // 補 "=" 符號 
                strcpy(text_crypted,""); // 清空text_crypted 
			}
            // 開始解碼 
            for(i=0;i<4;i++){
                for(j=0;j<65;j++){
                    if(text_crypting[i] == Base64_code[j]){ // 將字元從Base64編碼 轉成二進制
                        int text_Base64_code = j;
                        if (j == 64) // '='符號時直接跳出 
                        	text_Base64_code = 0;
                        int k = 5;
                        while(text_Base64_code >1){ // 從4 * 6-bit 轉換為 1 * 24-bit 
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
            // 轉換完畢 
            for(i=0;i<3;i++){ // 切割成3 * 8-bit 並轉換成對應的 ascii code 後將字元串接至 text_decrypted 
            	text_ASCII_code[i] = text_binary[8*i + 7]*1 + text_binary[8*i + 6]*2 +  text_binary[8*i + 5]*4 + text_binary[8*i + 4]*8 + text_binary[8*i + 3]*16 +  text_binary[8*i + 2]*32 +  text_binary[8*i + 1]*64 +  text_binary[8*i + 0]*128 ;
				// printf("asco:%d\n",text_ASCII_code[i]); 檢查ascii code 
				if(text_ASCII_code[i] == 0)
					text_ASCII_code[i] = '\0';
			}
			strcat(text_decrypted,text_ASCII_code);
        }
    }
    return 0;
}
