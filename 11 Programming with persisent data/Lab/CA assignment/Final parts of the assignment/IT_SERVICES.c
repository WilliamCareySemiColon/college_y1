/****************************************************************************************************
This programme is to implement a queue IT ticketing system. This will let the user add people as
requested when to fix an item. The programme will not let any more then five people on the system and
will use a linked list data. The program is to be modularised with functions that add peopple when
they make a call (unless it is already five people on them system). and when that person is done,
then remove them from the system.
Date started: 28-03-2017
Date finished:
Error-checking: yes
Author:William Carey
****************************************************************************************************/

//header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//symbolic constants
#define MAX 5
#define TIME 6
#define NAME 21
#define TELEPHONE 11
#define INCIDENT 51

//Structure template
struct user_info_and_problem
{
	//Variables inside this structure
	char name [NAME];
	char contact_info [TELEPHONE];
	char incident [INCIDENT];
	char time_of_call [TIME];

	//Linked list data
	struct user_info_and_problem *next;
};//end of structure template

//function prototypes
void person_input(struct user_info_and_problem *, int *);
void person_done(struct user_info_and_problem *, int *);
void display(struct user_info_and_problem *, int *);

//implement main
int main()
{
	//implementing each structure to point to each other
	struct user_info_and_problem head;
	head.next = NULL;

	//character variables
	char switch_input, switch_input_arr [MAX];

	//int variables
	int count = 0;

	do
	{

		puts("\nDo you want to \
			\n1)Add another person to ticket queue\
			\n2)Remove a person from the queue\
			\n3) Exit the prgramme");

		scanf("%3s",switch_input_arr);

	    switch_input = switch_input_arr[0];

		switch(switch_input)
		{
			case '1':
			{
				person_input(&head, &count);
				break;
			}//end case for adding a person

			case '2':
			{
				person_done(&head,&count);
				break;
			}//end case for removing a person

			case '3':
			{
				puts("Thank you for using this programme");
				break;
			}//end display list case

			default:
			{
				puts("That is not one of the options");
			}//end default case
		}//end switch case
	}while (switch_input != '3');

	fflush(stdin);

	getchar();

	return 0;
}//end main

/************************************************************************************
The following is to add another person to the liked lists. If there is more than five
people then do not add another person to the list, displaying a suitable message to
the user.
************************************************************************************/
void person_input(struct user_info_and_problem *head, int *count)
{
	if ((*count) < MAX)
	{
		typedef struct user_info_and_problem
		{
			//Variables inside this structure
			char name [NAME];
			char contact_info [TELEPHONE];
			char incident [INCIDENT];
			char time_of_call [TIME];

			//Linked list data
			struct user_info_and_problem *next;
		} USER_INFO;
		//Above is using typedef function

		//intialising struct variables
		USER_INFO *current = head;

		//int variables
		int count_for_characters, i;
		count_for_characters = 0;

		//searching for suitable location for adding a list
		while ((current->next) != NULL)
		{
			current = current->next;
		}//end while loop


		//create a new linked list
		current->next = malloc(sizeof(USER_INFO));

		if (current->next == NULL)
		{
			puts("Sorry, cannot implement");
		}//end if

		else
		{
			current = current->next;
			//Implementing the details of the the new user
			puts("Enter details of person calling:");
			//Getting the name from user
			do
			{
				count_for_characters = 0;

				puts("Firstname:");
				scanf("%20s",current->name);

				for (i = 0; i < strlen(current->name); i++)
				{
					if (isdigit(current->name[i]))
					{
						count_for_characters++;
					}
				}//end for loop

				if (count_for_characters == 0)
				{
					puts("Suffient entry");
				}

				else
				{
					puts("Unsuffient entry");
				}

			} while(count_for_characters != 0);

			//Getting the telephone number
			do
			{
				count_for_characters = 0;

				puts("\nContact details:");
				scanf("%10s",current->contact_info);

				for (i = 0; i < strlen(current->contact_info); i++)
				{
					if (isalpha(current->contact_info[i]))
					{
						count_for_characters++;
					}
				}//end for loop

				if (count_for_characters == 0)
				{
					puts("Suffient entry");
				}

				else
				{
					puts("Unsuffient entry");
				}
			}while (count_for_characters != 0);

			//Getting the time from the user
			do
			{
				count_for_characters = 0;
				puts("\nTime of details in the format 23:55");
				scanf("%5s",current->time_of_call);

				//Making sure no alpha characters are entered
				for (i = 0; i < strlen(current->time_of_call); i++)
				{
					if (isalpha(current->time_of_call[i]))
					{
						count_for_characters++;
					}
				}//end for loop

				//Making sure no alpha characters are entered
				if (count_for_characters == 0)
				{
					puts("Suffient entry");
				}

				else
				{
					puts("Unsuffient entry");
				}//end if...else statement
			}while (count_for_characters != 0);

			//Making sure we have four inputs
			getchar();
			//Getting the problem from the user
			do
			{
				count_for_characters = 0;

				puts("\nIncident:");
				gets(current->incident);

				for (i = 0; i < strlen(current->incident); i++)
				{
					if (isdigit(current->incident[i]))
					{
						count_for_characters++;
					}
				}//end for loop

				//Making sure no alpha characters are entered
				if (count_for_characters == 0)
				{
					puts("Suffient entry");
				}

				else
				{
					puts("Unsuffient entry");
				}//end if...else statement
			}while(count_for_characters != 0);

			//Making the new list the end of the list
			current->next = NULL;

			//Displaying to user task has been completed
			puts("Details have been added to the list");

			//Incrrementing the amount of people on the list counter
			(*count) += 1;

			display(head, count);
		}
	}

	else
	{
		puts("\nToo many people on the list already");
	}


}//end call input

/************************************************************************************
The programme is done on the basis on first come first served basis. This means
everytime we are done with a problem, we erase it from the problem sheet at the
begining of the programme
Error checking: Yes
Author: William
************************************************************************************/
void person_done(struct user_info_and_problem *head, int *count)
{
	struct user_info_and_problem *current = head->next;


	if ((*count) == 0)
	{
		puts("There are no more people that are on the list");
	}//end if

	else
	{
		head->next = current->next;
		(*count) -= 1;
		puts("person has been removed");
		display(head, count);
	}//end else statement

	//calling the function to display the list

}//end person_done

/************************************************************************************
To display the linked list after someone has added or taken information away
************************************************************************************/
void display(struct user_info_and_problem *head, int *count)
{
	//To check if there is people on the list
	if ( (*count) > 0)
	{	struct user_info_and_problem *current = head->next;

		int counter = 1;

		printf("Details of all the people on the linked lists are:\n");

		while (current != NULL)
		{
			if (counter > 1 )
			{
				printf("\nName: %s \nPhone number: %s \nProblem: %s \nTime called: %s\
				\n",current->name, current->contact_info,current->incident, current->time_of_call);

				current = current->next;
			}//end if statement
			counter++;
		}//end while loop
	}
	else
	{
		puts("\nNo more people are on the list");
	}
}//end display
