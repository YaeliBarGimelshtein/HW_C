#include <stdio.h>
#include <stdlib.h>
#include "menuMethods.h"
#include "AirportManager.h"
#include "Airline.h"
#include "Utils.h"


int programStart(AirportManager* rashut,Airline* airlineCompany)
{
	printf("Hello and welcome to the flights program\n");
	printf("We start by entering Airport Manager and Airline.\n");
	printf("\n");

	if(rashut!=NULL && airlineCompany!=NULL)
	{
		int ok=initAirportManager(rashut);
		initAirline(airlineCompany);
		if(ok)
		{
			printf("airport manager and airline added succesfully\n");
			printf("\n");
			return 1;
		}
		else
		{
			printf("problem starting program\n");
			return 0;
		}
	}
	else
	{
		printf("problem starting program\n");
		return 0;
	}
}

int main()
{
	AirportManager* rashut;
	Airline* airlineCompany;

	rashut= (AirportManager*)malloc(1*sizeof(AirportManager));
	airlineCompany= (Airline*)malloc(1*sizeof(Airline));

	int choise=0;
	int ok1;
	int ok2;

	int start=programStart(rashut, airlineCompany);

	if(start)
	{
		do{
			printMenu();
			scanf("%d", &choise);
			switch (choise) {
				case 1:
					ok1=addFlightToAirline(airlineCompany, rashut);
					if(!ok1)
						printf("Can't add this flight , out of memory\n");
					else
						printf("flight added successfully\n");
					break;
				case 2:
					ok2=addAirportToAirportManager(rashut,airlineCompany);
					if(ok2==0)
						printf("Can't add this airport since it already exists\n");
					else if(ok2==-1)
						printf("Can't add this airport , out of memory\n");
					else
						printf("Airport added successfully\n");
					break;
				case 3:
					printAirlineDetalis(airlineCompany);
					break;
				case 4:
					printAirportManagerDetails(rashut);
					break;
				case 5:
					printFlightsOfAirlineBetweenAirports(airlineCompany);
					break;
				case 6:
					freeAllMemory(rashut, airlineCompany);
					printf("You chise to exit. Have a good day, bye! \n");
					break;
				default:
					printf("pressed a wrong key. Try again.\n");
					break;
			}
		}
		while(choise!=6);
	}
}
