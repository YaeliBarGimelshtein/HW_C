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
	flight= (Flight*)malloc(1*sizeof(flight));
	initFlight(flight, airportManager);
	int ok=addFlight(flight, airline);
	return ok;
}

int addAirportToAirportManager(AirportManager* airportManager, Airline* airline)
{
	Airport* temp;
	temp= (Airport*)malloc(1*sizeof(Airport));
	initAirport(temp);
	for (int i = 0; i < airportManager->numOfAitports; ++i) {
		if(isAirportsSame(temp, &(airportManager->allAirports[i]))==1)
			return 0;
	}
	int ok=addAirport(temp, airportManager);
	if(ok)
	{
		return 1;
	}

	else
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
	char* IATAorigin;
	char* IATAdestination;
	int counter=0;
	IATAorigin= (char*)malloc(IATA_CODE*sizeof(char));
	IATAdestination= (char*)malloc(IATA_CODE*sizeof(char));

	initIATA(IATAorigin, IATAdestination);

	counter=howManyFlightsInLineToAirline(airline, IATAorigin, IATAdestination);
	printf("There are %d  flights in same line to the airline\n",counter);
}
void freeAllMemory(AirportManager* airportManager, Airline* airline)
{
	freeAirline(airline);
	freeAirportManager(airportManager);
}
