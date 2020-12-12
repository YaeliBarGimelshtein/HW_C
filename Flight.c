#include <stdio.h>
#include <stdlib.h>
#include "Flight.h"
#include "Airport.h"
#include "Utils.h"
#include "Date.h"
#include "AirportManager.h"

void initFlightAirports(Flight* flight, AirportManager* airportManager)
{
	int notOk=0;
	int okIATAorigin=0;
	int okIATAdest=0;
	char originIATA[IATA_CODE];
	char destenationIATA[IATA_CODE];

	do {

		do{
			printf("please enter the IATA of origin airport\n");
			scanf("%s",originIATA);
			okIATAorigin=checkIATA(originIATA);
		}while(!okIATAorigin);
		flight->origin= findAirport(originIATA, airportManager);

		do{
			printf("please enter the IATA of destination airport\n");
			printf("Make sure it is not the same airport as origin\n");
			scanf("%s",destenationIATA);
			okIATAdest=checkIATA(destenationIATA);
		}while(!okIATAdest);
		flight->destination= findAirport(destenationIATA, airportManager);

		if(flight->origin!= NULL && flight->destination!=NULL)
		{
			notOk= isAirportsSame(flight->origin, flight->destination);
			if(notOk)
			{
				printf("Sama airport. try again\n");
			}
		}
		else
		{
			printf("This airports can not be found. make sure IATA is correct and try again.\n");
			notOk=1;
		}

	}
	while(notOk);
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
	initFlightAirports(flight, airportManager);
	initTakeOffTime(flight);
	initDateForFlight(&flight->date);
	return 0;
}

void printFlight(const Flight* flight)
{
	printf("Flight taking off at %d ",flight->time);
	printDate(&flight->date);
	printf("from ");
	printAirport(flight->origin);
	printf("to ");
	printAirport(flight->destination);
	printf("\n");
}

void freeFlight(Flight* flight)
{
	free(flight);
}

int isTheSameFlight(Flight* flight, char IATAOrigin[IATA_CODE], char IATADestenation[IATA_CODE])
{
	if(!(isIataSameToAirport(flight->origin, IATAOrigin)))
	{
		return 0;
	}
	if(!(isIataSameToAirport(flight->destination, IATADestenation)))
	{
		return 0;
	}
	return 1;
}

int howManyFlightsInTheLine(Flight** flights,char IATAOrigin[IATA_CODE], char IATADestenation[IATA_CODE])
{
	int counter=0;
	while(*flights)
	{
		if(isTheSameFlight(*flights, IATAOrigin, IATADestenation))
		{
			counter++;
		}
		flights++;
	}
	return counter;
}




