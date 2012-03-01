#include "tool.h"
ChinaChar stArrayChinaChar[10000]={0};
int	iArrayChinaCharSize;

char** findPinyin(char* sHanzi,int *iPinyinNum)
{
	static 	char sArrayPinyin[MAX_DUOYINZI_DUYIN][10]={0};
	int i;
	int j = 0;
	int iArrayPinyinSize = 0;
	
	bzero(sArrayPinyin,sizeof(sArrayPinyin));
	for(i=0;i<iArrayChinaCharSize;i++)
	{
		if(strcmp(stArrayChinaChar[i].sHanzi,sHanzi) == 0)
		{
			strncpy(sArrayPinyin[j],stArrayChinaChar[i].sPinyin,sizeof(sArrayPinyin[j]));
			j++;
			if(iArrayPinyinSize == MAX_DUOYINZI_DUYIN)
				return 0;
			iArrayPinyinSize ++;
		}
	}	
	*iPinyinNum = iArrayPinyinSize;
	return (char**)sArrayPinyin;
	
}

void printPinyin(char  pinyin[][MAX_DUOYINZI_DUYIN],int iLen)
{
	int i;
	for(i=0;i<iLen;i++)
	{
		printf("%s:",pinyin[i]);
		
	}
	printf("\n");
		
}	

int fillArrayChinaChar(char *fileName)
{
	FILE* fp = fopen(fileName,"r");
	char buffer[100]={0};
	int iPoint=0;

	if(fp==0)
	{
		printf("China Char Dict doesnot exist\n");
		return -1;
	}

	bzero(&stArrayChinaChar,sizeof(stArrayChinaChar)); 
	while(fgets(buffer,sizeof(buffer),fp))
	{
		memcpy(stArrayChinaChar[iPoint].sHanzi,buffer,3);
		memcpy(stArrayChinaChar[iPoint].sPinyin,buffer+4,strlen(buffer)-5);
		//printf("%s%s\n",stArrayChinaChar[iPoint].sHanzi,stArrayChinaChar[iPoint].sPinyin);
		iPoint ++;
		bzero(buffer,sizeof(buffer));
	}
	iArrayChinaCharSize = iPoint;
	//printf("totally:%d china chars\n",iPoint);
	fclose(fp);

}
