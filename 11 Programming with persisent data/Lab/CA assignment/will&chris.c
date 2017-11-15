/* Program description: Program that allows the user via menu to enter new contacts, deleted contacts, edit contacts, find contacts and record contacts into a phonebook text file.
    Author: Chris Clarke and William or as you know us C16398141 and C16315253
    Date: 22/03/17
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Symbolic names
#define END 6

//Prototypes
char menu(void);
void new_contact(struct contact *,struct contact *,struct contact *);
void delete_contact(struct contact *,struct contact *,struct contact *,struct contact *,struct contact *);
void edit_contact(struct contact *,struct contact *,struct contact *,struct contact *,struct contact *);
void find_contact(struct contact *,struct contact *,struct contact *,struct contact *,struct contact *);
void record_contacts(struct contact *,struct contact *,struct contact *,struct contact *,struct contact *);
void display(void);
int terminate(void);

//struct initialisation
struct contact{
    char name[21];
    char number[11];
    char email[41];
};
    
int main()
{
     //initialise variables
    int program=0;
    char num;
    struct contact base_person;
    struct contact person1={"Steve","0875239642","steve.cool@gmail.com"};
    struct contact person2={"Crazy Joe","0865641564","cashmeousside@gmail.com"};
    struct contact person3={"Henry","999","horridhenry@hotmail.com"};
    struct contact person4;
    struct contact person5;
    
     //keep the program going until the user ends it
    while(program!=END)
    {
        //call menu function and return value (1-5)
        num=menu();
        flushall();
        switch(num)
        //each case calls a unique function
        {
            case'1':
            {
                new_contact(&base_person,&person4,&person5);
                break;
            }
            case'2':
            {
                delete_contact(&person1,&person2,&person3,&person4,&person5);
                break;
            }
            case'3':
            {
                edit_contact(&person1,&person2,&person3,&person4,&person5);
                break;
            }
            case'4':
            {
                find_contact(&person1,&person2,&person3,&person4,&person5);
                break;
            }
            case'5':
            {
                record_contacts(&person1,&person2,&person3,&person4,&person5);
                break;
            }
            case'6':
            {
                program=terminate();
                break;
            }
            
            default:
            {
                printf("You have made an invalid entry, please try again\n");
            }
        }//end switch
    }//end while
    //gracefully end program
 
    getchar();
    flushall();
    return 0;    
}//end main()

char menu()
//displays the menu
{
    char selection, select_input[1];
    
    printf("\n\n**********\n\n");
    printf("Please enter one of the numbers below to activate its associated function\n\n");
    printf("1. Add new contact\n");
    printf("2. Delete old contact\n");
    printf("3. Edit contact\n");
    printf("4. Find contact\n");
    printf("5. Record contacts\n");
    printf("6. Exit Program\n");
    printf("\n\n**********\n\n");
    scanf("%s",select_input);//get user's choice of menu function
    selection = *select_input;
    return selection;
}

//add contact (struct)
void new_contact(struct contact *base_person,struct contact *person4,struct contact *person5)
{
    static int i=0;
    //enter data into base (temporary) struct to be transferred later to its own unique struct
    printf("Please enter the contact's details\n\n");
    printf("Name: \n");
    gets(base_person->name);
    printf("Phone number:\n");
    gets(base_person->number);
    printf("Email:\n");
    gets(base_person->email);
    
    /*tranfer data from the base struct to a unique struct. The if statement finds the next available empty struct.
        The first 3 contacts have been pre-initialised so starting at person4) */
    if(i==0)
    {
        strcpy((person4->name),(base_person->name));
        strcpy((person4->number),(base_person->number));
        strcpy((person4->email),(base_person->email));
    }
    else if(i==1)//last contact
    {
        strcpy((person5->name),(base_person->name));
        strcpy((person5->number),(base_person->number));
        strcpy((person5->email),(base_person->email));
    }
    printf("Contact added!\n");
    i++;
    
}

//asks the user for the contact's name to be deleted, searches for the correct struct and empties the contents of the struct
void delete_contact(struct contact *person1,struct contact *person2,struct contact *person3,struct contact *person4,struct contact *person5)
{
    char clear[21];
    printf("Enter the contact's name to be deleted\n");
    gets(clear);
    
    if(strcmp(person1->name,clear)==0)
    {
        strcpy((person1->name),"");
        strcpy((person1->number),"");
        strcpy((person1->email),"");
        printf("Contact deleted\n");
    }
    
    else if(strcmp(person2->name,clear)==0)
    {
        strcpy((person2->name),"");
        strcpy((person2->number),"");
        strcpy((person2->email),"");
        printf("Contact deleted\n");
    }
    
    else if(strcmp(person3->name,clear)==0)
    {
        strcpy((person3->name),"");
        strcpy((person3->number),"");
        strcpy((person3->email),"");
        printf("Contact deleted\n");
    }
    
    else if(strcmp(person4->name,clear)==0)
    {
        strcpy((person4->name),"");
        strcpy((person4->number),"");
        strcpy((person4->email),"");
        printf("Contact deleted\n");
    }
    
    else if(strcmp(person5->name,clear)==0)
    {
        strcpy((person5->name),"");
        strcpy((person5->number),"");
        strcpy((person5->email),"");
        printf("Contact deleted\n");
    }
    
    else
    {
    printf("Name not recognised\n\n");   
    }
}

//***WILL***-not sure whether to call the find_contact() function inside the edit and delete functions... It's more effiecient but is it what she wants 
//or even worth changing?
//asks the user for the contact's name to be edited, searches for the correct struct and enables the user to re-enter it
void edit_contact(struct contact *person1,struct contact *person2,struct contact *person3,struct contact *person4,struct contact *person5)
{
    char edit[21];
    printf("Enter the contact's name to edit\n");
    gets(edit);
    
    if(strcmp(person1->name,edit)==0)
    {
        printf("Please re-enter the struct with the corrected details\n\n");
        printf("Name: \n");
        gets(person1->name);
        printf("Phone number:\n");
        gets(person1->number);
        printf("Email:\n");
        gets(person1->email);
        printf("\nContact has been changed\n");
    }
    
    else if(strcmp(person2->name,edit)==0)
    {
        printf("Please re-enter the struct with the corrected details\n\n");
        printf("Name: \n");
        gets(person2->name);
        printf("Phone number:\n");
        gets(person2->number);
        printf("Email:\n");
        gets(person2->email);
        printf("\nContact has been changed\n");
    }
    
    else if(strcmp(person3->name,edit)==0)
    {
        printf("Please re-enter the struct with the corrected details\n\n");
        printf("Name: \n");
        gets(person3->name);
        printf("Phone number:\n");
        gets(person3->number);
        printf("Email:\n");
        gets(person3->email);
        printf("\nContact has been changed\n");
    }
    
    else if(strcmp(person4->name,edit)==0)
    {
        printf("Please re-enter the struct with the corrected details\n\n");
        printf("Name: \n");
        gets(person4->name);
        printf("Phone number:\n");
        gets(person4->number);
        printf("Email:\n");
        gets(person4->email);
        printf("\nContact has been changed\n");
    }
    
    else if(strcmp(person5->name,edit)==0)
    {
        printf("Please re-enter the struct with the corrected details\n\n");
        printf("Name: \n");
        gets(person5->name);
        printf("Phone number:\n");
        gets(person5->number);
        printf("Email:\n");
        gets(person5->email);
        printf("\nContact has been changed\n");
    }
    
    else
    {
        printf("Contact not recognised\n");
    }
}
//***WILL***-should the if statements be combined into if(strcmp(person1->name,find)!=0||strcmp(person2->name,empty)==0|| etc etc) for effieciency?
//asks the user for the struct's contact's name to be found, searches for the correct struct and informs the user of its existence
void find_contact(struct contact *person1,struct contact *person2,struct contact *person3,struct contact *person4,struct contact *person5)
{
    char find[21];
    printf("Enter the contact's name to find\n");
    gets(find);
    
    if(strcmp(person1->name,find)==0)
    {
        printf("Contact found!\n");
    }
    
    else if(strcmp(person2->name,find)==0)
    {
        printf("Contact found!\n");
    }
    
    else if(strcmp(person3->name,find)==0)
    {
        printf("Contact found!\n");
    }
    
    else if(strcmp(person4->name,find)==0)
    {
        printf("Contact found!\n");
    }
    
    else if(strcmp(person5->name,find)==0)
    {
        printf("Contact found!\n");
    }
    
    else
    {
        printf("Contact not recogised\n");
    }
}

//enters the data from the existing structs into the file, calls the function display() to display the contents of the file
void record_contacts(struct contact *person1,struct contact *person2,struct contact *person3,struct contact *person4,struct contact *person5)
{
    char empty[21]="";
    printf("Recording contacts...\n\n"); 
    FILE *fp;
    fp=fopen("phonebook.txt","w");
    if (fp== NULL)
    {
        printf("Can't open file.\n");
    }
    else
    //if statements check if the struct has been filled (exists)
    {   
        if(strcmp(person1->name,empty)!=0)
        {
            fwrite(person1, sizeof(struct contact), 1, fp);
        }
        if(strcmp(person2->name,empty)!=0)
        {
            fwrite(person2, sizeof(struct contact), 1, fp);
        }
        if(strcmp(person3->name,empty)!=0)
        {
            fwrite(person3, sizeof(struct contact), 1, fp);
        }
        if(strcmp(person4->name,empty)!=0)
        {
            fwrite(person4, sizeof(struct contact), 1, fp);
        }
        if(strcmp(person5->name,empty)!=0)
        {
            fwrite(person5, sizeof(struct contact), 1, fp);
        }
        fclose(fp);
        display();    
    }
}

//displays the contents of the file
void display()
{
    char ch='0';
    FILE *fp1;
    fp1=fopen("phonebook.txt","r");
    printf("The phonebook now contains: \n\n");
    while(ch!=EOF)
    {
        ch=fgetc(fp1);
        printf("%c",ch);
    }
    
    fclose(fp1);
}

//ends the program
int terminate()
{
    printf("\nThis program will now end\n");
    getchar();
    return END;
}
//Sorry to break it to you but the show is over, no more code in this bad boy.