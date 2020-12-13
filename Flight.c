#include <stdio.h>
#include <stdlib.h>
#include "Flight.h"
#include "Airport.h"
#include "Utils.h"
#include "Date.h"
#include "AirportManager.h"

void initFlightAirports(Flight* flight, AirportManager* airportManager)
{
	Airport* temp;
	Airport* temp2;
	do{
		initIATA(&flight->IATAorigin, &flight->IATAdestination);
		temp=findAirport(flight->IATAdestination, airportManager);
		temp2=findAirport(flight->IATAorigin, airportManager);
	}
	while(temp==NULL || temp2==NULL);
}

void initTakeOffTime(Flight* flight)
{
	int ok=0;
	do {
		printf("please enter time of take off, make sure between 0-23\n");
		scanf("%d",&flight->time);
		ok= checkTime(flight->time);
	}
	while(!ok);
}
void initDateForFlight(Date* date)
{
	initDate(date);
}

int initFlight(Flight* flight, AirportManager* airportManager)
{
	flight->IATAorigin= (char*)malloc(IATA_CODE*sizeof(char));
	flight->IATAdestination= (char*)malloc(IATA_CODE*sizeof(char));
	if(flight->IATAorigin!=NULL && flight->IATAdestination!=NULL)
	{
		initFlightAirports(flight, airportManager);
		initTakeOffTime(flight);
		initDateForFlight(&flight->date);
		return 1;
	}

	return 0;
}

void printFlight(const Flight* flight)
{
	printf("Flight taking off at %d:00 ",flight->time);
	printDate(&flight->date);
	printf("from %s ",flight->IATAorigin);
	printf("to %s",flight->IATAdestination);
	printf("\n");
}

void freeFlight(Flight* flight)
{
	free(flight->IATAdestination);
	free(flight->IATAorigin);
}

int isTheSameFlight(Flight* flight, char IATAOrigin[IATA_CODE], char IATADestenation[IATA_CODE])
{
	if(!(checkIATAsame(flight->IATAorigin, IATAOrigin)))
		return 0;

	if(!(checkIATAsame(flight->IATAdestination, IATADestenation)))
		return 0;

	return 1;
}

int howManyFlightsInTheLine(Flight** flights,char IATAOrigin[IATA_CODE], char IATADestenation[IATA_CODE])
{
	int counter=0;
	while(*flights)
	{
		if(isTheSameFlight(*flights, IATAOrigin, IATADestenation))
			counter++;

		flights++;
	}
	return counter;
}

