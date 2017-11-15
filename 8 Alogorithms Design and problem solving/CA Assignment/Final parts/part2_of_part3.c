/**********************************************************************************************************
This programme will search for all of the international students in the new file created by the prevoius 
programme. If an international student is found, increment a counter.
**********************************************************************************************************/

//header files
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//symbolic names
#define FIRSTNAME 11
#define SURNAME 21
#define STUDENT_ID 10
#define YEAR 4
#define TOTAL 36
#define STATUS 15

//structure template
struct student_details
{
	char firstname [FIRSTNAME];
	char surname [SURNAME];
	char student_id [STUDENT_ID];
	char type [STATUS];
	char age [YEAR];
};

//implementing the main body
void main()
{
	int counter = 0;
	FILE *fp = fopen("DT_265_postgratuate_student_list.txt","r");
	struct student_details temp;

	if (fp == NULL)
	{
		puts("\nFile does not exist");
	}

	else
	{
		while ((fscanf(fp,"%s %s %s %s %s",temp.firstname, temp.surname, temp.age, temp.student_id, temp.type)) != EOF)
		{
			if (strcmp(temp.type,"International") == 0)
			{
				counter++;
			}//end if 
		}//end while loop

		if (counter == 10)
		{
			puts("\nAll the international were found");
		}

		else
		{
			puts("\nNot all the international students were found");
		}//end if..else
	}//end if...else statement


	fflush(stdin);

	getchar();
}//end main