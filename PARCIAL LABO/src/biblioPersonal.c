/*
 * PersonalBiblio.c
 *
 *  Created on: 19 may 2022
 *      Author: --
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "biblioCENSO.h"
#include "biblioPersonal.h"

int isNum(char* string)
{
	int i;
	int haveWord;
	int haveNum;
	int haveSpace;
	int ret;
	haveSpace = 0;
	haveNum = 0;
	haveWord = 0;
	ret=0;
	if(string!=NULL)
	{
		for (i = 0; i < strlen(string); i++)
		{
			char word = string[i];
			if(isalpha(word))
			{
				haveWord = 1;
			}
			if(isdigit(word))
			{
				haveNum = 1;
			}
			if(word==32)
			{
				haveSpace = 1;
			}
		}
		if(haveWord==0 && haveNum==1 && haveSpace==0)
		{
			ret=1;
		}
	}
	return ret;// retorna 1 si es numero o 0 si no es numero
}

int isFloat(char* string)

{
	int i;
	int haveWord;
	int haveNum;
	int havePoint;
	int haveSpace;
	int flagNum;
	int flagPoint;
	int ret;
	havePoint = 0;
	haveNum = 0;
	haveWord = 0;
	haveSpace = 0;
	flagPoint = 0;
	flagNum = 0;
	ret=0;
	if(string!=NULL)
	{
		for (i = 0; i < strlen(string); i++)
		{
			char word = string[i];
			if(isalpha(word))
			{
				haveWord = 1;
			}
			if(isdigit(word))
			{
				haveNum = 1;
				flagNum++;
			}
			if(word==32)// ASCII 32 -> SPACE
			{
				haveSpace = 1;
			}
			if (word==46 && flagNum!=0)// ASCII 46 -> .
			{
				havePoint = 1;
				flagPoint++;
			}
		}
		if(haveWord==0 && haveNum==1 && havePoint == 1 && flagPoint == 1 && haveSpace == 0)
		{
			ret=1;
		}
	}
	return ret;// retorna 1 si es flotante o 0 si no es flotante
}

int isText(char* string)
{
	int ret;
	int i;
	int tieneLetra = 0;
	int tieneNumero = 0;
	ret=0;
	if(string!=NULL)
	{
		for (i = 0; i < strlen(string); i++)
		{
			char letra = string[i];
			if (isalpha(letra))
			{
				tieneLetra = 1;
			}
			if (isdigit(letra))
			{
				tieneNumero = 1;
			}
		}
		if(tieneLetra==1 && tieneNumero==0)
		{
			ret=1;
		}
	}
	return ret; //retorna 1 si es Texto o 0 si no es texto

}

int isAlphanumeric(char *string)
{
	int ret;
	int i;
	int haveWord = 0;
	int haveNum = 0;
	ret=0;
	if(string!=NULL)
	{
		for (i = 0; i < strlen(string); i++)
		{
			char word = string[i];
			if (isalpha(word))
			{
				haveWord = 1;
			}
			if (isdigit(word))
			{
				haveNum = 1;
			}
		}
		if(haveWord==1 && haveNum==1)
		{
			ret=1;
		}
		else
		{
			ret=0;
		}
	}
	return ret;
}

int convertWordFirstUppAndRestLower(char* string)
{
	int ret;
	int i;
	char convertMayus;
	char convertMinus;
	int countSpace;
	countSpace=1;
	ret=-1;
	if(string!=NULL)
	{
		for(i=0;i<strlen(string);i++)
		{
			if(isalpha(*(string+i)) && countSpace==1)
			{
				convertMayus = toupper(string[i]);
				string[i]=convertMayus;
				countSpace=0;
			}
			else if(isalpha(*(string+i)))
			{
				convertMinus=tolower(string[i]);
				string[i]=convertMinus;
			}
			if(*(string+i)==32)
			{
				countSpace=1;
			}
		}
		ret=0;
	}
	return ret;
}

int convertStringMayus(char* string)
{
	int ret;
	int i;
	char convertMayus;
	ret=-1;
	if(string!=NULL)
	{
		for(i=0;i<strlen(string);i++)
		{
			if(isalpha(string[i])!=0)
			{
				convertMayus = toupper(string[i]);
				string[i]=convertMayus;
			}
		}
		ret=0;
	}
	return ret;
}

int getMenuForInt(int* option, char* message, char* messageError, int maxOption, int minOption)
{
	char bufferOption[2];
	int ret;
	ret=-1;
	if(option!=NULL && message!=NULL && messageError!=NULL)
	{
		system("cls");
		printf(message);
		fflush(stdin);
		gets(bufferOption);
		while(isNum(bufferOption)==0 || atoi(bufferOption)<minOption || atoi(bufferOption)>maxOption)
		{
			system("cls");
			printf(messageError);
			fflush(stdin);
			gets(bufferOption);
		}
		*option = atoi(bufferOption);
		ret=0;
	}
	return ret;
}

int getMenuForChar(char* option, char* message, char* messageError, int maxOption, int minOption)
{
	char bufferOption[2];
	int ret;
	ret=-1;
	if(option!=NULL && message!=NULL && messageError!=NULL)
	{
		system("cls");
		printf(message);
		fflush(stdin);
		scanf("%s", bufferOption);
		if(isupper(*bufferOption)==0)
		{
			*bufferOption=toupper(*bufferOption);
		}
		while(isText(bufferOption)==0 || *bufferOption<minOption || *bufferOption>maxOption || strlen(bufferOption)!=1)
		{
			system("cls");
			printf(messageError);
			fflush(stdin);
			scanf("%s", bufferOption);
			if(isupper(*bufferOption)==0 && isalpha(*bufferOption)!=0)
			{
					*bufferOption=toupper(*bufferOption);
			}
		}
		*option=*(bufferOption);
		ret=0;
		}
		return ret;
}
