#include <stdio.h>
#include<string.h>
/*
Ӧ����Ԥ����
int main(){
	FILE *p;
	int i = 0, j = 0;
	char str[5000], str1[5000], c;
	printf("7");
	if ((p = fopen("test.txt", "rt")) == NULL){
		printf("�޷���");
		return 0;
	}
	else{
		while ((c = getc(p)) != EOF) {
			str[i] = c;
			i++;
		}
		fclose(p);
		str[i] = '\0';
		for (i = 0; i<strlen(str); i++){
			if (str[i] == '/'&& str[i + 1] == '/') {
				while (str[i++] != '\n'){}
				//��Ϊ�Ʊ�� \t�Ĵ��� ��\nǿ��һ��
				//i--;
			}//����ע��
			else if (str[i] == '/' && str[i + 1] == '*'){
				while (!(str[i] == '*' && str[i + 1] == '/')){
					i++;
				}
				i += 1;
			}//����ע��
			else if (str[i] == ' ' && str[i + 1] == ' '){
				while (str[i] == ' '){
					i++;
				}
				i--;
				if (str1[j - 1] != ' ')
					str1[j++] = ' ';//����ո�ȥ���ո�
			}
			else if (str[i] == '\n'){
				//��Ϊ�Ʊ�� \t�Ĵ��� ��\nǿ��һ��
				i++;
				if (str1[j - 1] != ' '){
					str1[j++] = ' ';
				}
				else if (str[i] == 9){
					while (str[i] == 9){
						i++;
					}
				}
				if (str1[j - 1] != ' '){
					str1[j++] = ' ';
				}
				i--;
			}
			else str1[j++] = str[i];
		}
		str1[j] = '\0';
		printf("55");
		if ((p = fopen("test1.txt","w")) == NULL){
			printf("can not find it!");
			return 0;
		}
		else{
			if (fputs(str1, p) != 0){
				printf("�洢ʧ��");
			}
			else{
				printf("�洢�ɹ�");
			}
		}
		fclose(p);
	}
	return 0;
}
*/