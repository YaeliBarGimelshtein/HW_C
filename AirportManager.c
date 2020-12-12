#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AirportManager.h"
#include "Airport.h"

int initAllAirports(AirportManager* airportManager)
{
	airportManager->allAirports= (Airport*)malloc(airportManager->numOfAitports*sizeof(Airport));
	for(int i=0; i<airportManager->numOfAitports; i++)
	{
		airportManager->allAirports[i].name= (char*)malloc(MAX_NAME*sizeof(char));
		airportManager->allAirports[i].country= (char*)malloc(MAX_NAME*sizeof(char));
		initAirport(&airportManager->allAirports[i]);
	}
	return 0;
}

int initAirportManager(AirportManager* airportManager)
{
	printf("Please enter the number of airports \n");
	scanf("%d", &airportManager->numOfAitports);
	initAllAirports(airportManager);
	return 0;
}

void printAirportManager(const AirportManager* airportManager)
{
	printf("There are %d airports: \n", airportManager->numOfAitports);
	if(airportManager->numOfAitports!=0)
	{
		for(int i=0; i<airportManager->numOfAitports; i++)
			printAirport(&airportManager->allAirports[i]);
	}
}

void freeAirportManager(AirportManager* airportManager)
{
	for(int i=0; i<airportManager->numOfAitports; i++)
	{
		free(airportManager->allAirports[i].name);
		free(airportManager->allAirports[i].country);
	}
	free(airportManager->allAirports);
}

int addAirport(Airport* airport, AirportManager* airportManager)
{
	airportManager->numOfAitports++;
	airportManager->allAirports = (Airport*)realloc(airportManager->allAirports, airportManager->numOfAitports*sizeof(Airport));
	//initAirport(&airportManager->allAirports[(airportManager->numOfAitports)-1]);
	if(airportManager->allAirports!=NULL)
	{
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
