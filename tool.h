#ifndef __TOOL__H
#define __TOOL__H
#include <stdio.h>
#include <string.h>

#define MAX_DUOYINZI_DUYIN 20

typedef struct  
{
	char sHanzi[4];
	char sPinyin[10];
}ChinaChar;


char** findPinyin(char* sHanzi,int *iPinyinNum);
void printPinyin(char  pinyin[][MAX_DUOYINZI_DUYIN],int iLen);
int fillArrayChinaChar(char *fileName);
#endif
