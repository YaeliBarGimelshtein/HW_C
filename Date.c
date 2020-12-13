#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include "Utils.h"
#include "Flight.h"
#include "Date.h"

int checkDateFormat(char* date)
{
	for (int i = 0; i <MAX_DATE-1 ; ++i)
	{
		if((i==2 && *date!='/' )|| (i==5 && *date!='/' ))
			return 0;

		else if(!(isdigit(*date)) && i!=2 &&i!=5)
			return 0;

		date++;
	}
	return 1;
}

void getNumbersDateAsString(char** day, char** month ,char** year, char* dateStr)
{
	char* delimiters = "/";
	int lenght=strlen(dateStr);
	char temp[lenght];
	strcpy(temp,dateStr);
	int counter=1;
	char* check= strtok(temp,delimiters);
	while (check != NULL) {
		if(counter==1)
			*day=check;
		if(counter==2)
			*month=check;
		if(counter==3)
			*year=check;
		check = strtok(NULL, delimiters);
		counter++;
	}
}

void makeNumbersDate(int* day, int* month, int* year, char* dayChar, char* monthChar,char* yearChar)
{
	int fd;
	int sd;
	int td;
	int forthd;
	//for day
	fd= *dayChar -'0';
	dayChar++;
	sd= *dayChar -'0';
	*day= fd*10 +sd;

	//for month
	fd= *monthChar -'0';
	monthChar++;
	sd= *monthChar -'0';
	*month= fd*10 +sd;

	//for year
	fd= *yearChar -'0';
	yearChar++;
	sd= *yearChar -'0';
	yearChar++;
	td= *yearChar -'0';
	yearChar++;
	forthd= *yearChar -'0';
	*year= fd*1000 +sd*100+td*10+forthd;
}

int checkDateNumbers(char* dateStr, int* day, int* month, int* year)
{
	char** dayStr;
	dayStr = (char**)malloc(MAX_DAY*sizeof(char));
	char** monthStr ;
	monthStr = (char**)malloc(MAX_MONTH*sizeof(char));
	char** yearStr;
	yearStr = (char**)malloc(MAX_YEAR*sizeof(char));

	getNumbersDateAsString(dayStr, monthStr, yearStr, dateStr); //puts into strings
	makeNumbersDate(day, month, year, *dayStr, *monthStr,*yearStr); //puts into numbers

	free(dayStr);
	free(monthStr);
	free(yearStr);

	if(*day<0 || *month<0 || *year<1000|| *month>12|| *month>31|| *day>31)
		return 0;

	return 1;
}

int checkDayMonth(int* day,int* month)
{
	int tempMonth=*month;
	tempMonth-=1;
	switch (tempMonth) {
		case eJanuary:
			if(*day>31)
				return 0;
			break;
		case eFebruary:
			if(*day>28)
				return 0;
			break;
		case eMarch:
			if(*day>31)
				return 0;
			break;
		case eApril:
			if(*day>30)
				return 0;
			break;
		case eMay:
			if(*day>31)
				return 0;
			break;
		case eJune:
			if(*day>30)
				return 0;
			break;
		case eJuly:
			if(*day>31)
				return 0;
			break;
		case eAugust:
			if(*day>31)
				return 0;
			break;
		case eSeptember:
			if(*day>30)
				return 0;
			break;
		case eOctober:
			if(*day>31)
				return 0;
			break;
		case eNovember:
			if(*day>30)
				return 0;
			break;
		case eDecember:
			if(*day>31)
				return 0;
			break;
	}
	return 1;
}

void initDate(Date* date)
{
	int okStracture=0;
	int okNumbers=0;
	int okdayToMonth=0;
	int firstTime=1;

	char tempDate[MAX_DATE];
	int day;
	int month;
	int year;

	do{
		printf("enter flight date in format dd/mm/yyyy\n");

		if(firstTime)
		{
			getchar(); //whitespace
			firstTime=0;
		}

		myGets(tempDate, MAX_DATE);

		if(strlen(tempDate)==MAX_DATE-1)
		{
			okStracture=checkDateFormat(tempDate);
			getchar(); //whitespace
			if(okStracture)
			{
				okNumbers=checkDateNumbers(tempDate, &day,&month,&year);
				if(okNumbers)
				{
					okdayToMonth=checkDayMonth(&day,&month);
				}
			}
		}
	}
	while(!okStracture || !okNumbers || !okdayToMonth);

	date->day=day;
	date->month=month;
	date->year=year;
}

void printDate(const Date* date)
{
	printf("Date: %d/%d/%d \n", date->day, date->month, date->year);
}
