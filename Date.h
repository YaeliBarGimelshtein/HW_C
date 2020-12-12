#ifndef DATE_H_
#define DATE_H_

#define MAX_DATE 10
#define MAX_DAY 2
#define MAX_MONTH 2
#define MAX_YEAR 4

typedef enum{eJanuary, eFebruary, eMarch, eApril,eMay, eJune, eJuly, eAugust,
	eSeptember, eOctober, eNovember, eDecember,eNumOfMonths} months;

const char* allKinds[eNumOfMonths];

typedef struct
{
	int day;
	int month;
	int year;
} Date;

void initDate(Date* date);
void printDate(const Date* date);

int checkDateFormat(char* date);
void getNumbersDateAsString(char** day, char** month ,char** year, char* dateStr);
void makeNumbersDate(int* day, int* month, int* year, char* dayChar, char* monthChar,char* yearChar);
int checkDateNumbers(char* dateStr, int* day, int* month, int* year);
int checkDayMonth(int* day,int* month);

#endif
