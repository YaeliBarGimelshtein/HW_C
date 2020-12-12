#ifndef MENUMETHODS_H_
#define MENUMETHODS_H_

#include "AirportManager.h"
#include "Airline.h"

int addFlightToAirline(Airline* airline,AirportManager* airportManager);
int addAirportToAirportManager(AirportManager* airportManager);
void printAirlineDetalis(Airline* airline);
void printAirportManagerDetails(AirportManager* airportManager);
void printFlightsOfAirlineBetweenAirports(Airline* airline);
void freeAllMemory(AirportManager* airportManager, Airline* airline);

#endif
