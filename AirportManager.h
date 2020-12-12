#ifndef AIRPORTMANAGER_H_
#define AIRPORTMANAGER_H_

#include "Airport.h"

typedef struct
{
	Airport* allAirports;
	int numOfAitports;
} AirportManager;

//must:
int initAirportManager(AirportManager* airportManager);
int initAllAirports(AirportManager* airportManager);
void printAirportManager(const AirportManager* airportManager);
void freeAirportManager(AirportManager* airportManager);

//extra:
int addAirport(Airport* airport, AirportManager* airportManager);
Airport* findAirport(char IATA[IATA_CODE], AirportManager* airportManager);


#endif
