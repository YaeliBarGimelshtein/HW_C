#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "Utils.h"
#include "Airport.h"
#include "Flight.h"

char* myGets(char* buf, size_t size)
{
	if(buf != NULL && size > 0)
	{
		if(fgets(buf,size,stdin))
		{
			buf[strcspn(buf,"\n")] = '\0';
			return buf;
		}
		*buf = '\0';
	}
	return NULL;
}

void checkSpacesFirst(char* str)
{
	char* pLook = str;
	char* pWrite= str;
	if(*pLook==' ')
	{
		pLook++;
		while(*pLook)
		{
			*pWrite=*pLook;
			pLook++;
			pWrite++;
		}
	}
	*pWrite=*pLook;
}

void checkSpacesLast(char* str)
{
	int lastChar=strlen(str);
	lastChar--;


	if(str[lastChar]!=' ')
		return;

	while(str[lastChar]==' ')
	{
		*(str+lastChar)='\0';
	}
}


void capitalLetters(char* str)
{
	int spacebefore = 0;
	int letter=0;
	char* pLook = str;
	char* temp;

	while (*pLook)
	{
		if ((*pLook != ' ' && letter==0) || (*pLook != ' ' && (spacebefore)))
		{
			temp=strchr(pLook,' ');
			if(temp==NULL && letter!=0) //its the last word
				return;

			spacebefore=0;
			str[letter] = toupper(str[letter]);
		}
		else if (*pLook == ' ')
			spacebefore=1;

		letter++;
		pLook++;
	}
}

void twoSpaces(char* str)
{
	char* pLook = str;
	char* pWrite= str;
	//char* temp;
	int i=0;

	while(*pLook)
	{
		if(*pLook== ' ')
		{
			pLook++;
			pWrite=pLook;
			int size= strlen(pLook);
			char reWrite[size];
			strcpy(reWrite,pLook);
			*pWrite=' ';
			pWrite++;
			while(i<size)
			{
				*pWrite=reWrite[i];
				i++;
				pWrite++;
			}
		}
		i=0;
		pLook++;
	}
}

void bigSmallLetters(char* str)
{
	char* pLook = str;
	char* pCount=str;
	char* pWrite= str;
	int twoSpaces=0;
	int firstWord=1;
	int numLetters=0;

	char* end = str;
	while(*end != '\0') {
		end++;
	}

	while(*pLook)
	{
		if(firstWord || (twoSpaces==2))
		{
			pCount=pLook;
			while(pCount<end)
			{
				if(*pCount!=' ')
				{
					numLetters++;
					pCount++;
				}
				else
				{
					break;
				}
			}
			if(numLetters%2==0)
			{
				pWrite=pLook;
				for(int i=0; i<(numLetters/2);i++)
				{
					*(pWrite)=toupper(*pWrite);
					pWrite++;
					*(pWrite)=tolower(*pWrite);
					pWrite++;
				}
			}
			numLetters=0;
			twoSpaces=0;
			firstWord=0;
		}
		if(*pLook==' ')
			twoSpaces++;

		pLook++;
	}
}

int checkIATA(char* iata)
{
	if(strlen(iata)!=IATA_CODE)
		return 0;

	for(int i=0; i<IATA_CODE; i++)
	{
		if(islower(*iata))
		{
			return 0;
		}
		iata++;
	}
	return 1;
}

int checkTime(int time)
{
	if(time<0 || time>23)
		return 0;
	return 1;
}

int checkIATAsame(char IATA1[IATA_CODE], char IATA2[IATA_CODE])
{
	int same=strcmp(IATA1, IATA2);
	if(same==0)
		return 1;
	return 0;
}

