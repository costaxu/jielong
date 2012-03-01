#include <stdio.h>
#include <string.h>
#include "tool.h"
extern ChinaChar stArrayChinaChar[];
extern int iArrayChinaCharSize;
typedef char (*PINYIN)[10];
int main(int argc,char** argv)
{
	if(argc!=3)
	{
		printf("%s ChinaCharDict(format:ChinaCharPinyin) phrase",argv[0]);
		return 0;
	}
	char buffer[100];
	int iRet;
	char sLastChar[4]={0};
	char *phrase = argv[2];
	PINYIN pinyin;
	int iPinyinNum;
	int i;
	iRet = fillArrayChinaChar(argv[1]);
	if(iRet)
	{
		printf("cant fill array china char\n");
		return -1;
	}
	memcpy(sLastChar,phrase+strlen(phrase)-3,3);
	//printf("%s\n",sLastChar);
	pinyin = (PINYIN )findPinyin(sLastChar,&iPinyinNum);
	
	if(pinyin ==0 )
	{
		printf("cant find pinyin\n");
		return -2;
	}
	for(i=0;i<iPinyinNum;i++)
	{
		printf("%s\n",pinyin[i]);
	}
	return 0;
}
