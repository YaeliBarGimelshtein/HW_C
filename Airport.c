#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Airport.h"
#include "Utils.h"

void initAirportName(Airport* airport)
{
	printf("Please enter the Airport's name\n");
	myGets(airport->name, MAX_NAME);
	checkSpacesFirst(airport->name);
	checkSpacesLast(airport->name);
	capitalLetters(airport->name);
	twoSpaces(airport->name);
	bigSmallLetters(airport->name);
}

void initAirportIATA(Airport* airport)
{
	int ok=0;
	do{
		printf("Please enter the Airport's IATA: ");
		printf("Make sure it is ONLY 3 letters and UPPER CASE \n");
		scanf("%s", airport->IATA);
		ok=checkIATA(airport->IATA);
		if(!ok)
			printf("Wrong input, try again\n");
	}
	while(!ok);
	//strcpy(airport->IATA,temp);

}


int initAirport(Airport* airport)
{
	airport->name= (char*)malloc(MAX_NAME*sizeof(char));
	airport->country= (char*)malloc(MAX_NAME*sizeof(char));
	airport->IATA=(char*)malloc(IATA_CODE*sizeof(char));

	if(airport->name!= NULL && airport->country!= NULL &&airport->IATA!=NULL)
	{
		getchar(); //there is a white space in buffer

		initAirportName(airport);

		printf("Please enter the Airport's country\n");
		myGets(airport->country, MAX_NAME);

		initAirportIATA(airport);
		return 1;
	}
	return 0;
}
void printAirport(const Airport* airport)
{
	printf("Airport: %s ,IATA: %s ,country: %s \n", airport->name, airport->IATA, airport->country);
}

void freeAirport(Airport* airport)
{
	free(airport->name);
	free(airport->country);
	free(airport->IATA);
}

int isAirportsSame(const Airport* airport1, const Airport* airport2)
{
	int same=strcmp(airport1->IATA, airport2->IATA);
	if(same==0)
		return 1;
	return 0;
}

int isIataSameToAirport(const Airport* airport, char IATA[IATA_CODE])
{
	int same=strcmp(airport->IATA, IATA);
	if(same==0)
		return 1;
	return 0;
}

void initIATA(char** IATAorigin, char** IATAdestination)
{
	int okDestination;
	int okOrigin;
	int same;
	do{
		printf("please enter the IATA of origin airport\n");
		scanf("%s",*IATAorigin);
		okOrigin=checkIATA(*IATAorigin);

		printf("please enter the IATA of destination airport\n");
		printf("Make sure it is not the same airport as origin\n");
		scanf("%s",*IATAdestination);
		okDestination=checkIATA(*IATAdestination);
		if(!okDestination || !okOrigin)
		{
			printf("problem with syntax of IATA, try again\n");
		}
		else
		{
			same=checkIATAsame(*IATAdestination, *IATAorigin);
			if(same)
				printf("Same airports, try again\n");
		}
	}
	while(!okDestination || !okOrigin|| same);
}
