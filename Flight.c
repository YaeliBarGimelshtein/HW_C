#include <stdio.h>
#include <stdlib.h>
#include "Flight.h"
#include "Airport.h"
#include "Utils.h"
#include "Date.h"
#include "AirportManager.h"

void initIATA(char** IATAorigin, char** IATAdestination, int func)
{
	int okDestination;
	int okOrigin;
	int same;
	do{
		if(func)
			printf("please enter the IATA of first airport\n");
		else
			printf("please enter the IATA of origin airport\n");
		scanf("%s",*IATAorigin);
		okOrigin=checkIATA(*IATAorigin);

		if(func)
			printf("please enter the IATA of second airport\nMake sure it is not the same airport as origin\n");
		else
			printf("please enter the IATA of destination airport\nMake sure it is not the same airport as origin\n");
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

void initFlightAirports(Flight* flight, AirportManager* airportManager)
{
	int func=0;
	Airport* temp;
	Airport* temp2;
	do{
		initIATA(&flight->IATAorigin, &flight->IATAdestination, func);
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

int howManyFlightsBetweenAirports(Flight** flights,int numOfFlights,char IATAOrigin[IATA_CODE], char IATADestenation[IATA_CODE])
{
	int counter=0;

	for (int i = 0; i < numOfFlights; ++i)
	{
		if(isTheSameFlight(*flights, IATAOrigin, IATADestenation))
			counter++;
		if(isTheSameFlight(*flights, IATADestenation,IATAOrigin))
			counter++;
		flights++;
	}
	return counter;
}

