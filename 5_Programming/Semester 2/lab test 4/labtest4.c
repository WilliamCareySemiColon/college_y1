/****************************************************************************************
This programme is going to take in details for a flight on the bryanair on any particular
day.
****************************************************************************************/

//header files
#include <stdio.h>
#include <string.h>

//symbloc names
#define Max 2
#define FLIGHT 7
#define F_NAME 12
#define S_NAME 21
#define SEAT 4

//struct templates
struct date
{
	int day;
	int month;
	int year;
};

struct bryanair
{
	char flight_num [FLIGHT];
	struct date DOF;
	char firstname [F_NAME];
	char surname [S_NAME];
	char seat_num [SEAT];
};

//function prototypes
void get_details_of_passenger(struct bryanair *);
void display_passenger_details(struct bryanair *);

void main()
{
	struct bryanair passengers [Max];

	get_details_of_passenger(&passengers);
}//end main

/****************************************************************************************
This function is going to take in two passenger details and then call another function to
display these details back to the user
****************************************************************************************/

void get_details_of_passenger(struct bryanair *passengers)
{
	int i;

	puts("Please enter the details of the people who are flying with Bryanair in the near future");

	for (i = 0; i < Max; i++)
	{
		puts("Firstname:");
		scanf("%11s",(passengers + i)->firstname);
		puts("\nSurname:");
		scanf("%20s",(passengers + i)->surname);
		puts("\nSeat number");
		scanf("%3s",(passengers+i)->seat_num);
		getchar();

		//ensuring we place the two varaibles with the same flight number and date
		if (i == 0)
		{
			puts("\nDate of flight");
			puts("Day:");
			scanf("%d",&(passengers+i)->DOF.day);
			puts("\nMonth:");
			scanf("%d",&(passengers+i)->DOF.month);
			puts("\nYear:");
			scanf("%d",&(passengers+i)->DOF.year);
			puts("Flight number:");
			scanf("%6s",(passengers+i)->flight_num);
		}
		else
		{
			(passengers+(Max/2))->DOF.day = passengers->DOF.day;
			(passengers+(Max/2))->DOF.month = passengers->DOF.month;
			(passengers+(Max/2))->DOF.year = passengers->DOF.year;
			strcpy((passengers + Max/2)->flight_num,passengers->flight_num);
		}//end if...else statement
	}//end for loop

	display_passenger_details(passengers);
}//end get_details_of_passengers

/************************************************************************************************
To display the details of the input gained from the previous function to the end user
************************************************************************************************/

void display_passenger_details(struct bryanair *passengers)
{
	int i;

	puts("Details of the users enterd previously are:");

	for (i = 0; i < Max; i++)
	{
		puts("Firstname:");
		printf("%s\n",(passengers + i)->firstname);

		puts("\nSurname:");
		printf("%s\n",(passengers + i)->surname);

		puts("\nSeat number");
		printf("%s\n",(passengers+i)->seat_num);

		puts("\nDate of flight");

		puts("Day:");
		printf("%d\n",(passengers+i)->DOF.day);

		puts("\nMonth:");
		printf("%d\n",(passengers+i)->DOF.month);

		puts("\nYear:");
		printf("%d\n",(passengers+i)->DOF.year);

		puts("Flight number:");
		printf("%s\n",(passengers+i)->flight_num);

	}//end for loop
}
