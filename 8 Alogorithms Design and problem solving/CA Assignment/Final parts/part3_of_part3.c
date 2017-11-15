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
	int counter,counter_2;
	counter_2 = counter = 1;
	char surname_123 [SURNAME];
	FILE *fp = fopen("DT_265_postgratuate_student_list.txt","r");
	struct student_details temp;

	if (fp == NULL)
	{
		puts("\nFile does not exist");
	}

	else
	{
		puts("\n What is the surname of the person you are looking for");
		scanf("%s",surname_123);

		while ((fscanf(fp,"%s %s %s %s %s",temp.firstname, temp.surname, temp.age, temp.student_id, temp.type)) != EOF)
		{
			if (strcmp(temp.surname,surname_123) == 0)
			{
				printf("\nStudent was found on line %d",counter);
				fseek(fp, 0, SEEK_END);
			}//end if

			else
			{
				counter++;
			}

			counter_2++;
		}//end while loop

		if (counter == counter_2)
		{
			puts("\nStudent does not exist");
		}//end if statement


	}//end if...else statement


	fflush(stdin);

	getchar();
}//end main
