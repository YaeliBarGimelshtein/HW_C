#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menuMethods.h"
#include "Airline.h"
#include "Airport.h"
#include "AirportManager.h"
#include "Date.h"
#include "Flight.h"
#include "Utils.h"


int addFlightToAirline(Airline* airline, AirportManager* airportManager)
{
	Flight* flight;
	flight= (Flight*)malloc(1*sizeof(Flight));
	int okflight=initFlight(flight, airportManager);
	if(okflight)
	{
		int ok=addFlight(flight, airline);
		if(!ok)
			free(flight);
		return ok;
	}
	return 0;
}

int addAirportToAirportManager(AirportManager* airportManager, Airline* airline)
{
	Airport* airport;
	airport= (Airport*)malloc(1*sizeof(Airport));
	int okAirport=initAirport(airport);
	if(okAirport)
	{
		for (int i = 0; i < airportManager->numOfAitports; ++i)
		{
			if(isAirportsSame(airport, &(airportManager->allAirports[i]))==1)
				return 0;
		}
		int ok=addAirport(airport, airportManager);
		if(!ok)
			free(airport);
		return ok;
	}
	return -1;
}

void printAirlineDetalis(Airline* airline)
{
	printAirline(airline);
}
void printAirportManagerDetails(AirportManager* airportManager)
{
	printAirportManager(airportManager);
}

void printFlightsOfAirlineBetweenAirports(Airline* airline)
{
	char* IATAfirst;
	char* IATAsecond;
	int counter=0;
	IATAfirst= (char*)malloc(IATA_CODE*sizeof(char));
	IATAsecond= (char*)malloc(IATA_CODE*sizeof(char));

	int func=1;
	initIATA(&IATAfirst, &IATAsecond,func);

	counter=howManyFlightsInLineToAirline(airline, IATAfirst, IATAsecond);
	printf("Number of flights in this line to airline: %d  \n",counter);
	free(IATAsecond);
	free(IATAfirst);
}
void freeAllMemory(AirportManager* airportManager, Airline* airline)
{
	freeAirline(airline);
	freeAirportManager(airportManager);
}
