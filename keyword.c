#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NAME 30

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct keytab{ //����ü ����  
	int num;	//�� �� ������
	char name [MAX_NAME]; 
};

struct keytab keywrds[13]= {  //���� 
	{0, "int"},
	{0, "float"},
	{0, "return"},
	{0, "if"},
	{0, "for"},
	{0, "while"},
	{0, "goto"},
	{0, "switch"},
	{0, "case"},
	{0, "void"},
	{0, "default"},
	{0, "char"},
	{0, "do"}
};
void count_word (char*word)
{
	int i;
	//�� keyword ����  
	for (i=0;i<13;i++)
	{
		//if word�� i ��° keyword�� ������ 
		if(strncmp(word, keywrds[i].name, strlen(keywrds[i].name))==0)
		{
			//nums++; 
			keywrds[i].num++;
		}
	}	
} 

void print_word()
{
	int i;
	//i�� ° keyword�� ���ؼ�
	for(i=0;i<13;i++)
		//printf(Ű���� �̸�: �󵵼�); 
		printf("%s :%i\n", keywrds[i].name, keywrds[i].name); 
}


