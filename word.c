#include <stdio.h>
#include <string.h>
#include "tool.h"
extern ChinaChar stArrayChinaChar[];
extern int iArrayChinaCharSize;

int main(int argc,char** argv)
{
	if(argc!=3)
	{
		printf("%s ChinaCharDict(format:ChinaCharPinyin) phraceDictFile",argv[0]);
		return 0;
	}
	char buffer[100];
	FILE* fp ;
	char sFirstChar[4]={0};
	char sLastChar[4]={0};
	char sPhrase[100]={0};
	char **arrayPinyin;
	char arrayPinyinFirst[10][MAX_DUOYINZI_DUYIN];
	char arrayPinyinLast[10][MAX_DUOYINZI_DUYIN];
	int iPinyinNumFirst;
	int iPinyinNumLast;
	int i,j;
	int lineNum =0;
	int iRet;

	iRet = fillArrayChinaChar(argv[1]);
	if(iRet)
	{	
		printf("fill array china char fail!exit!\n");
		return -1;
	}	
	fp = fopen(argv[2],"r");
	if(fp == 0)
	{
		printf("Phrase Dict File doesnot exist\n");
		return -2;
	}
	while(fgets(buffer,sizeof(buffer),fp))
	{
		bzero(sFirstChar,sizeof(sFirstChar));
		bzero(sLastChar,sizeof(sLastChar));
		bzero(sPhrase,sizeof(sPhrase));
		bzero(arrayPinyinFirst,sizeof(arrayPinyinFirst));
		bzero(arrayPinyinLast,sizeof(arrayPinyinLast));

		memcpy(sFirstChar,buffer,3);
		memcpy(sLastChar,buffer+strlen(buffer)-4,3);
		memcpy(sPhrase,buffer,strlen(buffer)-1);
		
		arrayPinyin = findPinyin(sFirstChar,&iPinyinNumFirst);	
		memcpy(arrayPinyinFirst,arrayPinyin,sizeof(arrayPinyinFirst));

		arrayPinyin = findPinyin(sLastChar,&iPinyinNumLast);
		memcpy(arrayPinyinLast,arrayPinyin,sizeof(arrayPinyinLast));

		if(iPinyinNumFirst == 0)
		{
			fprintf(stderr,"%s %s cant find pinyin.line %d\n",sPhrase,sFirstChar,lineNum);
			continue;
		}
		if(iPinyinNumLast == 0)
		{
			fprintf(stderr,"%s %s cant find pinyin.line %d\n",sPhrase,sLastChar,lineNum);
			continue;
		}
		
		
		//printf("%s %s %s\n",sPhrase,sFirstChar,sLastChar);		
		//printPinyin(arrayPinyinFirst,iPinyinNumFirst);
		//printPinyin(arrayPinyinLast,iPinyinNumLast);
		//break;
		for(i=0;i<iPinyinNumFirst;i++)
			for(j=0;j<iPinyinNumLast;j++)

		{
			printf("%s\t%s\t%s\t%s\t%s\n",sPhrase,sFirstChar,arrayPinyinFirst[i],sLastChar,arrayPinyinLast[j]);
		}
		lineNum ++;
	}	
	fclose(fp);	
	return 0;
}
