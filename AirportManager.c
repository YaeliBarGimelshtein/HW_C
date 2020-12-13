#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AirportManager.h"
#include "Airport.h"
#include "Airline.h"

int initAllAirports(AirportManager* airportManager)
{
	int ok=0;
	airportManager->allAirports= (Airport*)malloc(airportManager->numOfAitports*sizeof(Airport));
	if(airportManager->allAirports!=NULL)
	{
		for(int i=0; i<airportManager->numOfAitports; i++)
		{
			printf("Airport %d\n",i+1);
			ok=initAirport(&airportManager->allAirports[i]);
			if(!ok)
				return 0;
		}
	}
	return 1;
}

int initAirportManager(AirportManager* airportManager)
{
	printf("Please enter the number of airports \n");
	scanf("%d", &airportManager->numOfAitports);
	int ok=initAllAirports(airportManager);
	return ok;
}

void printAirportManager(const AirportManager* airportManager)
{
	printf("Number of airports in managment= %d. \n", airportManager->numOfAitports);
	if(airportManager->numOfAitports!=0)
	{
		for(int i=0; i<airportManager->numOfAitports; i++)
			printAirport(&airportManager->allAirports[i]);
	}
	printf("\n");
}

void freeAirportManager(AirportManager* airportManager)
{
	for(int i=0; i<airportManager->numOfAitports; i++)
	{
		freeAirport(&airportManager->allAirports[i]);
	}
	free(airportManager->allAirports);
	free(airportManager);
}

int addAirport(Airport* airport, AirportManager* airportManager)
{
	airportManager->allAirports = (Airport*)realloc(airportManager->allAirports, (airportManager->numOfAitports+1)*sizeof(Airport));

	if(airportManager->allAirports!=NULL)
	{
		airportManager->numOfAitports++;
		airportManager->allAirports[(airportManager->numOfAitports)-1]=*airport;
		return 1;
	}
	return 0;
}

Airport* findAirport(char IATA[IATA_CODE], AirportManager* airportManager)
{
	int compare=0;
	for (int i = 0; i < airportManager->numOfAitports; ++i) {
		compare=strcmp(airportManager->allAirports[i].IATA, IATA);
		if(compare==0){
			return &airportManager->allAirports[i];
		}
	}
	return NULL;
}
