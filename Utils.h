#ifndef UTILS_H_
#define UTILS_H_

#include "Airport.h"

//to get input
char* myGets(char* buf, size_t size);

//for airport
void checkSpacesFirst(char* str);
void checkSpacesLast(char* str);
void capitalLetters(char* str);
void twoSpaces(char* str);
void bigSmallLetters(char* str);
int checkIATA(char* iata);

//for fight
int checkTime(int time);

//for getting numer of flights
int checkIATAsame(char IATA1[IATA_CODE], char IATA2[IATA_CODE]);

#endif
