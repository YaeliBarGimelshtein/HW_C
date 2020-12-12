#include <stdio.h>
#include "menuMethods.h"
#include "AirportManager.h"
#include "Airline.h"

void printMenu()
{
	printf("Please choose one of the following options:\n");
	printf("press 1 to add a flight to the airline \n");
	printf("press 2 to add an airport the the airport manager \n");
	printf("press 3 to print details of airline \n");
	printf("press 4 to print details of airport manager \n");
	printf("press 5 to print the flights to airline between to airports \n");
	printf("press 6 to exit the program \n");

}

int main()
{
	printf("Hello and welcome to the flights program\n");
	AirportManager rashut;
	initAirportManager(&rashut);

	Airline elal;
	initAirline(&elal);
	printf("airport manager and airline added succesfully\n");
	int choise=0;
	int ok1;
	int ok2;
	do{
		printMenu();
		scanf("%d", &choise);
		switch (choise) {
			case 1:
				ok1=addFlightToAirline(&elal, &rashut);
				if(!ok1)
					printf("Can't add this flight , out of memory\n");
				else
					printf("flight added successfully\n");
				break;
			case 2:
				ok2=addAirportToAirportManager(&rashut);
				if(ok2==0)
					printf("Can't add this airport since it already exists\n");
				else if(ok2==-1)
					printf("Can't add this flight , out of memory\n");
				else
					printf("Airport added successfully\n");
				break;
			case 3:
				printAirlineDetalis(&elal);
				break;
			case 4:
				printAirportManagerDetails(&rashut);
				break;
			case 5:
				printFlightsOfAirlineBetweenAirports(&elal);
				break;
			case 6:
				printf("You chise to exit. Have a good day, bye! \n");
				freeAllMemory(&rashut, &elal);
				break;
			default:
				printf("pressed a wrong key. Try again.\n");
				break;
		}
	}
	while(choise!=6);
}
