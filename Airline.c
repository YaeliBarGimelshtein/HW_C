#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "Airline.h"
#include "AirportManager.h"
#include "Flight.h"
#include "Utils.h"


void initAirline(Airline* airline)
{
	airline->name= (char*)malloc(MAX_NAME*sizeof(char));
	if(airline->name!=NULL)
	{
		printf("please enter the name of Airline\n");
		getchar(); //removes white space
		myGets(airline->name, MAX_NAME);
	}
	airline->numOfFlights=0;
}



void printAirline(const Airline* airline)
{
	printf("Airline: name= %s , number of flights= %d \n" ,airline->name , airline->numOfFlights);
	if(airline->numOfFlights!=0)
	{
		printf("The flights in this airline are:\n");
		for (int i = 0; i < airline->numOfFlights; i++)
			printFlight(airline->allFlights[i]);
	}
	printf("\n");
}

void freeAirline(Airline* airline)
{
	free(airline->allFlights);
	free(airline->name);
	free(airline);
}

int addFlight(Flight* flight, Airline* airline)
{
	if(airline->numOfFlights==0)
		airline->allFlights = (Flight**)malloc((airline->numOfFlights+1)*sizeof(Flight*));

	else
		airline->allFlights = (Flight**)realloc(airline->allFlights, (airline->numOfFlights+1)*sizeof(Flight*));


	if(airline->allFlights==NULL)
		return 0;

	airline->numOfFlights+=1;
	airline->allFlights[airline->numOfFlights-1]=flight;
	return 1;
}

int howManyFlightsInLineToAirline(Airline* airline, char IATAOrigin[IATA_CODE], char IATADestenation[IATA_CODE])
{
	if(airline->numOfFlights==0)
		return 0;
	else
	{
		int counter=howManyFlightsBetweenAirports(airline->allFlights, IATAOrigin, IATADestenation);
		return counter;
	}
}


