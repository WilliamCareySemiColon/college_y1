//Creators are William and Chris Clake

//header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Symbolic name
#define POST_ADDRESS 201
#define PPSN 11
#define NAME 16

//Global Structure Templates
struct ADDRESS
{
	//Varables for this structure address
	char address [POST_ADDRESS];

};//end of structure Address

struct Phone_Number
{
	//Variables for this structure phone number
	char phone_num [NAME];

};//end of structure phone number

struct CREDIT_UNION
{
	//variables for this structure Credit Union
	char first_name [NAME], surname [NAME];
	char PUBLIC_PERSONAL_SERVICE_NUM [PPSN];
	char Account_code [PPSN];
	float Balance;
	char Date_of_birth [NAME];


//Indented structure within structure
	struct ADDRESS add;
	struct Phone_Number tele;

};//end of structure Credit_Union

void main()
{
	//File variables
	FILE *fp = fopen("DIT_Credit_Union_list2.txt","w");

	//Intialise variable of structure
	struct CREDIT_UNION DIT_2;

	if (fp == NULL)
	{
		puts("Cannot Find that file");
	}

	else
	{

		//intialising DIT_2 variables
		strcpy(DIT_2.Account_code,"B2C3D4E5");
		DIT_2.Balance = 0.00;

		//Getting input from user
		//First name
		puts("What is your first name");
		gets(DIT_2.first_name);
		//Surname
		puts("What is your surname");
		gets(DIT_2.surname);
		//Address
		puts("What is your Address");
		gets(DIT_2.add.address);
		//PPSN
		puts("What is your PPSN");
		gets(DIT_2.PUBLIC_PERSONAL_SERVICE_NUM);
		//Phone Number
		puts("What is your Phone number");
		gets(DIT_2.tele.phone_num);
		//DOB
		puts("What is your Date of Birth in the form dd-mm-yyyy");
		gets(DIT_2.Date_of_birth);


		//Printing DIT 2 details to a file
		fprintf(fp, "\n\nThe details of student b are: \nName:%s \nSurname:%s \nDOB:%s \nAddress:%s\
		 \nPhone Number:%s \nPPSN:%s\nBank Number:%s\
		  \nBank Balance:%.2f\n\n", DIT_2.first_name, DIT_2.surname, DIT_2.Date_of_birth, DIT_2.add.address, DIT_2.tele.phone_num, DIT_2.PUBLIC_PERSONAL_SERVICE_NUM,DIT_2.Account_code,DIT_2.Balance);

		//printing to the screen
		printf("\n\nThe details of student b are: \nName:%s \nSurname:%s \nDOB:%s \nAddress:%s\
		 \nPhone Number:%s \nPPSN:%s\nBank Number:%s\
		  \nBank Balance:%.2f\n\n", DIT_2.first_name, DIT_2.surname, DIT_2.Date_of_birth, DIT_2.add.address, DIT_2.tele.phone_num, DIT_2.PUBLIC_PERSONAL_SERVICE_NUM,DIT_2.Account_code,DIT_2.Balance);
	}//end if...else statemnt

	getchar();

}// end main ()
