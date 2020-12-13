#ifndef AIRPORT_H_
#define AIRPORT_H_

#define IATA_CODE 3
#define MAX_NAME 255

typedef struct
{
	char* name;
	char* country;
	char* IATA;
} Airport;

//musts:
void initAirportName(Airport* airport);
void initAirportIATA(Airport* airport);
int initAirport(Airport* airport);
void printAirport(const Airport* airport);
void freeAirport(Airport* airport);


//extra:
int isAirportsSame(const Airport* airport1,const Airport* airport2);
int isIataSameToAirport(const Airport* airport, char IATA[IATA_CODE]);

#endif
