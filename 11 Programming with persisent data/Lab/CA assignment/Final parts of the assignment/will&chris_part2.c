/************************************************************************************************
Program that use a phonebook features to function. It adds, delete, edits, finds and records
contacts. This is to be done using an array and display after each alteration. For the recording
part, implement a sorting alogorithm so they are in order when written in
************************************************************************************************/

//header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//symbolic names
#define MAX 5

//struct template
struct contact
{
	char name[21];
    char number[11];
    char email[41];
};


//Function prototype
//To display the opening message each time the loop calls this function
char menu(void);
//To add another person to the phone contacts
void new_contact(struct contact *,int *);
//To delete a contact when requested
void delete_contact(struct contact *,int *);
//To edit a contact as requested
void edit_contact(struct contact *,int *);
//To find a contact
void find_contact(struct contact *,int *);
//To write the contacts to a file
void record_contacts(struct contact *,int *);
//To display the contents of the program to the end user
void display(struct contact *,int *);

//Implementing the main body now
int main()
{
    //initialise variables
    char num;
    struct contact person[MAX] = { {"Steve","0875239642","steve.cool@gmail.com"},
							{"Crazy Joe","0865641564","cashmeousside@gmail.com"},
							{"Henry","999","horridhenry@hotmail.com"}
						};
    int amount_inputted = 3;


     //keep the program going until th user ends it
    do
    {
        //call menu function and return value (1-5)
        num = menu();
        fflush(stdin);
        switch(num)
        //each case calls a unique function
        {
            case'1':
            {
                new_contact(person, &amount_inputted);
                break;
            }
            case'2':
            {
                delete_contact(person, &amount_inputted);
                break;
            }
            case'3':
            {
                edit_contact(person, &amount_inputted);
                break;
            }
            case'4':
            {
                find_contact(person, &amount_inputted);
                break;
            }
            case'5':
            {
                record_contacts(person, &amount_inputted);
                break;
            }
            case'6':
            {
                puts("\nThank you for using this program");
                break;
            }

            default:
            {
                puts("\nYou have made an invalid entry, please try again\n");
            }
        }//end switch
    }while(num != '6');//end while
    //gracefully end program

    getchar();
    fflush(stdin);
    return 0;
}//end main()

/********************************************
Displaying the opening message to the user
********************************************/
char menu()
//displays the menu
{
    char selection, select_input [3];

    printf("\n\n**********\n\n");
    printf("Please enter one of the numbers below to activate its associated function\n\n");
    printf("1. Add new contact\n");
    printf("2. Delete old contact\n");
    printf("3. Edit contact\n");
    printf("4. Find contact\n");
    printf("5. Record contacts\n");
    printf("6. Exit Program\n");
    printf("\n\n**********\n\n");

    //get user's choice of menu function
    scanf("%2s",select_input);
    selection = *select_input;

    return selection;
}//end menu()

/***************************************************************************************
To get another person added into the phonebook list. If the list is full to let the user
know
Error checking: Yes
****************************************************************************************/

void new_contact(struct contact *person_input,int *status)
{
	int counter, i;

	if (*status == MAX)
	{
		puts("\nCannot add any more people on to the list");
	}

	else
	{
		puts("\nStarting to enter the details of the user");
	    //To get the name
	    puts("\nName first");
	    gets((person_input + (*status))->name);
	    getchar();

	    //getting the phone number
	    do
	    {
	    	counter = 0;

	    	puts("\nPhone number");
	    	scanf("%10s",(person_input + (*status))->number);

	    	for (i = 0; i < strlen((person_input + (*status))->number); i++)
	    	{
	    		if (isdigit((person_input + (*status))->number[i]))
	    		{
	    			counter++;
	    		}
	    	}//end for loop

	    	if (counter == i)
	    	{
	    		puts("\nSuffiecent entry");
	    	}
	    	else
	    	{
	    		puts("\ninsuffienct entry");
	    	}
	    }while (counter != i);

	    //Getting the email
	    puts("Email now");
	    scanf("%40s",(person_input + (*status))->email);

	    puts("\nContacted has be added");

	    *status += 1;
	    display(person_input,status);
	}
}//end new_contact()

/*******************************************************************************************
To delete a contact from the list. If the list is empthy tell the end user
Error checking: Yes
*******************************************************************************************/
void delete_contact(struct contact *person_input,int *status)
{
	//If there is no one on the list we cannot delete anyone
	if (*status == 0)
	{
		puts("\nThere is no one on the list");
	}

	//there is people on the list
	else
	{
		char name_chack[21];
		int count, i, check;
		check = 0;

		puts("\nPlease enter the name of the contact to be removed from the list");
		gets(name_chack);
		getchar();

		for (count = 0; count < (*status); count++)
		{
			if (strcmp(name_chack,(person_input + count)->name) == 0)
			{
				//overwriting the contact that needs to be deleted by placing the contact at the end in its place
				strcpy((person_input + count)->name, (person_input + ((*status)-1))->name);
				strcpy((person_input + count)->number, (person_input + ((*status)-1))->number);
				strcpy((person_input + count)->email, (person_input + ((*status)-1))->email );

				//Setting the contents of the last name to be empty
				//removing the name
				for (i = 0; i < strlen((person_input + ((*status)-1))->name); i++)
				{
					(person_input + ((*status)-1))->name[i] = '\0';
				}//end fpr loop for name

				//removing the number
				for (i = 0; i < strlen((person_input + ((*status)-1))->number); i++)
				{
					(person_input + ((*status)-1))->number[i] = '\0';
				}//end for loop for number part

				//removing the email
				for (i = 0; i < strlen((person_input + ((*status)-1))->email); i++)
				{
					(person_input + ((*status)-1))->email[i] = '\0';
				}//end for loop for email
			}//end if statement

			//have a counter if we do not find the contact
			else
			{
				check++;
			}//end if..else statement
		}//end for loop

		//Contact does not exist if check equals count
		if (check == count)
		{
			puts("\nContact does not exist");
		}

		else
		{
			puts("\nContact has being removed");

			*status -= 1;

			display(person_input,status);
		}//end if else statement
	}

}//end delete_contact

/***************************************************************************************************
To find a contact and edit the contents of one of the contacts that is in the programme. If there is
no one in the programme then we cannot do this
error checking: yes
***************************************************************************************************/

void edit_contact(struct contact *person_edit,int *status)
{
	//If there is no one on the list than we cannot edit
	if (*status == 0)
	{
		puts("\nThere is no one on the list to edit");
	}

	else
	{
		char name_chack [21];
		int counter, check, i;
		check = counter = 0;


		puts("\nPlease enter the name of the contact you wish to edit");
		gets(name_chack);
		getchar();

		while(counter != (*status))
		{
			if (strcmp(name_chack, (person_edit + counter)->name) == 0)
			{
				//getting the edited number
				do
			    {
			    	counter = 0;

			    	puts("\nPhone number");
			    	scanf("%10s",(person_edit + (*status))->number);

			    	for (i = 0; i < strlen((person_edit + (*status))->number); i++)
			    	{
			    		if (isdigit((person_edit + (*status))->number[i]))
			    		{
			    			counter++;
			    		}
			    	}//end for loop

			    	if (counter == i)
			    	{
			    		puts("\nSuffiecent entry");
			    	}
			    	else
			    	{
			    		puts("\ninsuffienct entry");
			    	}
			    }while (counter != i);

				//getting the email
				puts("\nPlease enter email");
				scanf("%40s",(person_edit + counter)->email);

				puts("\nContact has been changed");
			}

			else
			{
				check++;
			}//end if...else statement

			counter++;
		}//end while loop

		if (counter == check)
		{
			puts("\nContact does not exist");
		}

		else
		{
			display(person_edit,status);
		}//end if...else statement
	}
}//end edit()

/**********************************************************************************************
To find a specfic contact in the contact list in the programme. If there is no one in the list
the user should know about this before they progress
error checking: Yes
**********************************************************************************************/

void find_contact(struct contact *person_find,int *status)
{
	//to check if theere is anyone on the list
	if (*status == 0)
	{
		puts("\nThere is no one on the list to check");
	}

	//we know there is a person on the list
	else
	{
		char name_find [21];
		int counter, check;
		counter = check = 0;

		//to take the name of the contact they are looking for
		puts("please enter the name of the person you are looking");
		gets(name_find);
		getchar();

		while (counter != (*status))
		{
			//checkiing if the contents at the a particular part of the loop is the name we are looking for
			if (strcmp(name_find,(person_find + counter)->name) == 0)
			{
				//If we found the person we should end the loop immmediately
				counter = (*status);
				counter--;
			}

			else
			{
				//we increment the check counter
				check++;
			}//end if...else statement#

			counter++;
		}//end while loop

		//if the person does not exist, the check will equal the counter
		if (check == counter)
		{
			puts("\nContact does not exist");
		}

		else
		{
			puts("\nContact does exist");
		}
	}
}//end find_contact()

/**********************************************************************************************
To write all of the details in the programme to a text file. If there is nothing to write the
previous will not be gone. This will use a sorting alogoritm to list them in aplhabeticaly order
error check: Yes
Alogorithm implmented: Insertion sort
**********************************************************************************************/

void record_contacts(struct contact *person_write,int *status)
{
	//If there is no one on the list to write to a list
	if (*status == 0)
	{
		puts("\nThere is no contact to write to file");
	}

	else
	{
		FILE *fp = fopen("phonebook.txt","w");
		int i, j;

		struct contact file [MAX], validation;

		//writing all the contents from one array to another
		for (i = 0; i < (*status); i++)
		{
			strcpy(file[i].name,(person_write + i)->name);
			strcpy(file[i].number,(person_write + i)->number);
			strcpy(file[i].email,(person_write + i)->email);
		}//end for loop for copying the contents

		//sorting out the contents of the array, based on the first letter of each name
		for (i = 1; i < (*status); i++)
		{
			j = i;
			while(file[j].name[0] < file[j-1].name[0] && j != 0)
			{
				//copying the contents of current postion into temporary varaible
				strcpy(validation.name,file[j].name);
				strcpy(validation.number,file[j].number);
				strcpy(validation.email,file[j].email);

				//moving the contents up one space
				strcpy(file[j].name,file[j-1].name);
				strcpy(file[j].number,file[j-1].number);
				strcpy(file[j].email,file[j-1].email);

				//moving the temporary varables into desire location
				strcpy(file[j-1].name,validation.name);
				strcpy(file[j-1].number,validation.number);
				strcpy(file[j-1].email,validation.email);

				//Reintialisng j so we can keep moving back
				j--;
			}//end while loop
		}

		for (i = 0; i < (*status); i++)
		{
			fprintf(fp, "Name: %s\
			\nNumber: %s\
			\nEmail: %s\n\n", file[i].name, file[i].number, file[i].email);
		}//end for loop

		fclose(fp);

		puts("\nFile now has recorded the files");
	}

}//end record()

/**********************************************************************************************
To display the current contents of the array to the end after each change
error checking: Not needed
**********************************************************************************************/
void display(struct contact *person_display,int *status)
{
	int i;

	for (i = 0; i < (*status); i++)
	{
		printf("\n\nName:%s\
			\nNumber: %s\
			\nEmail: %s",(person_display + i)->name, (person_display + i)->number, (person_display + i)->email);
	}//end for loop
}//end display()
