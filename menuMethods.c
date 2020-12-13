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

Flight* flight;
Airport* airport;
char* IATAorigin;
char* IATAdestination;

int addFlightToAirline(Airline* airline, AirportManager* airportManager)
{
	flight= (Flight*)malloc(1*sizeof(flight));
	int okflight=initFlight(flight, airportManager);
	if(okflight)
	{
		int ok=addFlight(flight, airline);
		return ok;
	}
	return 0;
}

int addAirportToAirportManager(AirportManager* airportManager, Airline* airline)
{
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
	int counter=0;
	IATAorigin= (char*)malloc(IATA_CODE*sizeof(char));
	IATAdestination= (char*)malloc(IATA_CODE*sizeof(char));

	initIATA(&IATAorigin, &IATAdestination);

	counter=howManyFlightsInLineToAirline(airline, IATAorigin, IATAdestination);
	printf("Number of flights in this line to airline: %d  \n",counter);
}
void freeAllMemory(AirportManager* airportManager, Airline* airline)
{
	freeAirline(airline);
	freeAirportManager(airportManager);
	free(flight);
	free(airport);
	free(IATAorigin);
	free(IATAdestination);
}
