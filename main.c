#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "keyword.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int is_whitespace(char c)
{
	if(	c == ' '||
		c =='\n'||
		c== '\r'||
		c== '\t'||
		c== '(' ){
		return 1; 
	}
	return 0;
}
int fget_word(FILE*fp, char*word)
{	
	char c;
	int cnt;
	
	while ((c=fgetc(fp))!=EOF) //글자 하나 읽어서 공백글자 버림  
	{
		if(is_whitespace(c)==0)
			break;
	}
	if (c ==EOF) //끝까지 가서 읽을게 없을 때 
	{
		return 0; 
	}
	cnt =0;
	word[cnt++] = c;
	word[cnt]= '\0';
	
	while((word[cnt]=fgetc(fp))!=EOF)
	{
		if(is_whitespace(word[cnt])==1)
		{
			word[cnt] = '\0'; //읽을게 없다.  
			break;
		}
		else
		cnt++; //아닐경우 +1  
	}	
	return cnt;		
}
int main(int argc, char*argv[]){

	FILE*fp;
	char filepath[100];
	char word[100];
	
	printf("input the file path: ");
	scanf("%s", filepath);
	fp=fopen(filepath, "r"); //입력받은 값 열기 	
	
	if(fp == NULL) //방어코드 구현 (다른 파일 입력할 시)  
	{
		printf("file path is wrong! %s\n", filepath);
		return -1;
	}

	
	while (fget_word(fp, word)!= 0)
	{
		count_word(word);
	} 
	
	print_word();
	fclose(fp);
	return 0;
}
