#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "Airline.h"
#include "Flight.h"
#include "Utils.h"

void checkNumberOfFlights(Airline* airline)
{
	int temp=0;
	int ok=0;
	do{
		printf("please enter the number of flights the airline has\n");
		scanf("%d",&temp);
		if(temp<0)
			ok=0;
		else
		{
			airline->numOfFlights=temp;
			ok=1;
		}
	}
	while(!ok);
}


void initAirline(Airline* airline)
{
	airline->name= (char*)malloc(MAX_NAME*sizeof(char));
	printf("please enter the name of Airline\n");
	getchar(); //removes white space
	myGets(airline->name, MAX_NAME);
	airline->numOfFlights=0;
}

void printAirline(const Airline* airline)
{
	printf("Airline: name= %s has %d flights\n" ,airline->name , airline->numOfFlights);
	if(airline->numOfFlights!=0)
	{
		printf("The flights in this airline are:\n");
		for (int i = 0; i < airline->numOfFlights; i++)
			printFlight(airline->allFlights[i]);
	}
}

void freeAirline(Airline* airline)
{
	for (int i = 0; i < airline->numOfFlights; i++)
		freeFlight(airline->allFlights[i]);

	free(airline->allFlights);
	free(airline->name);
}

int addFlight(Flight* flight, Airline* airline)
{
	if(airline->numOfFlights==0)
	{
		airline->numOfFlights+=1;
		airline->allFlights = (Flight**)malloc(airline->numOfFlights*sizeof(Flight*));
	}
	else
	{
		airline->numOfFlights+=1;
		airline->allFlights = (Flight**)realloc(airline->allFlights, airline->numOfFlights*sizeof(Flight*));
	}

	if(airline->allFlights==NULL)
		return 0;

	airline->allFlights[airline->numOfFlights-1]=flight;
	return 1;
}

int howManyFlightsInLineToAirline(Airline* airline, char IATAOrigin[IATA_CODE], char IATADestenation[IATA_CODE])
{
	int counter=howManyFlightsInTheLine(airline->allFlights, IATAOrigin, IATADestenation);
	return counter;
}

