#ifndef AIRLINE_H_
#define AIRLINE_H_

#include "Flight.h"
#include "AirportManager.h"

typedef struct
{
	char* name;
	int numOfFlights;
	Flight** allFlights;
} Airline;

//must:
void initAirline(Airline* airline);
void printAirline(const Airline* airline);
void freeAirline(Airline* airline);

//extra:
int addFlight(Flight* flight, Airline* airline);
int howManyFlightsInLineToAirline(Airline* airline, char IATAOrigin[IATA_CODE], char IATADestenation[IATA_CODE]);


#endif
