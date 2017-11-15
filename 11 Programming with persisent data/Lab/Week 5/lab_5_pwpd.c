/*********************************************************************************************************
This is Lab four week five of Programming with persistent data. This covers all Parts of the question from 
a to f. This program involves using structures and strings to write to a file and is very silmilar to how a 
vector array is formed in another coding language. 
This was completed on 23-02-2017
Created by William Carey and Chris Clake
*********************************************************************************************************/

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

//Main body implemented

void main()
{
	//File variables
	FILE *fp = fopen("DIT_Credit_Union_list.txt","w");

	//Intialise types of structure
	struct CREDIT_UNION DIT;

	if (fp == NULL)
	{
		puts("Cannot Find that file");
	}

	else
	{
		//intialising the DIT variables
		strcpy(DIT.first_name,"Jane");
		strcpy(DIT.surname,"Ferris");
		strcpy(DIT.add.address,"DIT, Kevin Street, Dublin2");
		strcpy(DIT.PUBLIC_PERSONAL_SERVICE_NUM,"123456X");
		strcpy(DIT.Date_of_birth,"01-01-1999");
		strcpy(DIT.tele.phone_num,"01 402300");
		strcpy(DIT.Account_code,"A1B2C3D4");
		DIT.Balance = 0.00;

		
		
		//Printing DIT details to a file
		fprintf(fp, "The details of student a are: \nName:%s \nSurname:%s \nDOB:%s \nAddress:%s\
		 \nPhone Number:%s \nPPSN:%s\nBank Number:%s\
		  \nBank Balance:%.2f\n\n", DIT.first_name, DIT.surname, DIT.Date_of_birth, DIT.add.address, DIT.tele.phone_num, DIT.PUBLIC_PERSONAL_SERVICE_NUM,DIT.Account_code,DIT.Balance);

		
	}//end if...else statemnt

	getchar();

}// end main ()
