#ifndef FLIGHT_H_
#define FLIGHT_H_

#include "Airport.h"
#include "AirportManager.h"
#include "Date.h"

typedef struct
{
	Airport* origin;
	Airport* destination;
	int time;
	Date date;
} Flight;

//must:
void initFlightAirports(Flight* flight, AirportManager* airportManager);
void initTakeOffTime(Flight* flight);
void initDateForFlight(Date* date);
int initFlight(Flight* flight, AirportManager* airportManager);
void printFlight(const Flight* flight);
void freeFlight(Flight* flight);


//extra:
int isTheSameFlight(Flight* flight, char IATAOrigin[IATA_CODE], char IATADestenation[IATA_CODE]);
int howManyFlightsInTheLine(Flight** flights,char IATAOrigin[IATA_CODE], char IATADestenation[IATA_CODE]);

#endif