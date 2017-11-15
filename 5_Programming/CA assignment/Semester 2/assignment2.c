/**********************************************************************************************
Description: The development of a program that will perform security authorisation based on
access codes. The access codes are 4 single-digit integer numbers between 0-9. The program
should allow a user to enter a code, encrypt the number and compare it to the authorised
access code.  The program should also allow the user to decrypt an encrypted code. The Access
code wiil not be changed. The program should be menu-driven and must display a simple menu when
ran. Each menu option must be implemented in Functions using Pass by Reference method and all
readings must use pointer notation.
Author: William Carey
Date Started: 23-02-2017
Date Finished:
**********************************************************************************************/

//header files
//header file for input and output
#include <stdio.h>
//header file to check all the characters entered in function 1
#include <ctype.h>
//To read exit functions
#include <stdlib.h>

//Symbolic names
//charcater arrays used and are null terminated
#define CODE_SIZE 5
#define SWAP_CODE 4
//Algorithm symbolic names
#define POSITION_A 0
#define POSITION_B 1
#define POSITION_C 2
#define POSITION_D 3

//Function Protypes
void Enter_code(char *, int *, int *);
void Encrypt_and_check(char *, int *, int *, int *, int *);
void check_with_original_access_code(char *, int *, int *, int *, int *);
void decrypt_code(char *, int *);
void code_correct_and_uncorrect(int *, int *);

//Global variable - Main access code
const char access_code [CODE_SIZE] = "4523";

//Implementing main body now
int main()
{
	//Characters variables 
	//This is to take in the pin from the user
	char user_code [CODE_SIZE];
	//This is to take in the menu input option from the user
	char switch_case_valid [SWAP_CODE];
	//This is used so we do not go more than one loop around the menu 
	char switch_case;
	//Character pointer variables
	char *enter_user_code, *switch_case_valid_address;
	//This is so we can use dereferneve operator for pin input
	enter_user_code = user_code;
	//This is so we can use derefernce operator for menu input
	switch_case_valid_address = switch_case_valid;

	//integers variables
	int correct, incorrect, valid, code_counter;
	//The following is to count how many times the user enterded a type of password
	correct = incorrect = 0;
	//This is so they cannot enter option 2 or three straight away
	valid = 2;
	//integer pointer variables
	int *correct_point = &correct;
	int *incorrect_point = &incorrect;
	int *valid_point = &valid;
	//Is is to make sure we count EVERY time the user entered a passcode
	int *code_counter_point = &code_counter;

	//a do while loop that keeps going until the user inputs five to exit
	do
	{
		//Display opening message to the user
		puts("Hello Sir/Madam. Welcome to this program. You have access to the following features:\
			\n1: Enter the code\
			\n2: Encrypt the code and check if it is the right code \
			\n3: Decrypt the code\
			\n4: Display the amount of times the code was entered (i) correct and (ii) incorrect\
			\n5: To end the program \n\nPlease pick your choice");

		//Getting input from user- no more than 20 will be read - If more like one character has been entered, only the first one will be read
        scanf("%3s",&*(switch_case_valid_address));
        //Putting the first element of the array into the character variable
        switch_case = *switch_case_valid_address;
        fflush(stdin);
		switch(switch_case)
		{
			case '1':
			{
				//calling function to take in the code from the user
				Enter_code(enter_user_code, valid_point, code_counter_point);
				break;
			}//end case 1

			case '2':
			{
				//calling the function to encrypt the code and check if it is correct
				Encrypt_and_check(enter_user_code, correct_point, incorrect_point, valid_point, code_counter_point);
				break;
			}//end case 2

			case '3':
			{
				//calling the function to decrypt the code
				decrypt_code(enter_user_code,valid_point);
				break;
			}//end case 3

			case '4':
			{
				//To display the number of times the user input the code wrong and right
				code_correct_and_uncorrect(correct_point, incorrect_point);
				break;
			}//end case 4

			case '5':
			{
				//Closing message to the user
				puts("Thank you for using this Program and have good day");
				break;
			}//end case 5

			default:
			{
				//To tell the user they are out of the boundaries of the program
				printf("That was not one of the options\n");

			}//end default

		}//end switch case

	//This will keep the menu going until they entered the exit option
	} while (switch_case != '5');
	//end do...while loop

	fflush(stdin);
	getchar();
	return(0);
}//end main body

/*********************************************************************************************
Function: Enter_code function
Purpose: To get the pin from the user and save it in an array using pointer notation
Date started: 24-02-2017
Date finished: 26-02-2017
Error-checking: Yes
*********************************************************************************************/

void Enter_code (char *code_getter, int *verify_checked, int *counting_code_check)
{
	//counter for validation of number input
	int case_1_checker = 0;
	int i;
	//This loop will keep going until the user inputs four digits
	do
	{
		//Taking input from the user
		puts("Please enter your code");
		scanf("%4s",& *(code_getter));
		fflush(stdin);

		//counts how many "digit 0 - 9" have been inputted
		for (i = 0; i < CODE_SIZE; i++)
		{
			//function inside c-type.h file to check how many digits have been entered
			if (isdigit(*(code_getter + i)))
			{
				case_1_checker++;

			}//end if statement

		}//end for loop checking each each input

		//If the user have entered four digits
		if (case_1_checker == 4)
		{
			//user coperated and put four digits
			puts("Thank you for entering the code");
		}

		else
		{
			//obviuosly the user try to put in a non-digit
			puts("The code is not valid");

			//this resets the counter for error checking of digits
			case_1_checker = 0;

		}//end if else staement

	} while (case_1_checker != 4);

	//This allow the user to access the encrption function but not the decrpytion process
	(*(verify_checked)) = 0;
	//This is so when we check if the code is right or wrong, it will increment the result
	(*(counting_code_check)) = 1;
}//end Enter_code function

/*********************************************************************************************
Function: Enter_code function
Purpose: To get the pin  taken from the user , encrypt it and call another function to compare
it to the access code using pointer notation. Letting the user know the result. If the code
is alraedy encrypted, they cannot do it again
Date started: 24-02-2017
Date finished: 26-02-2017
Error-checking: Yes
*********************************************************************************************/

void Encrypt_and_check (char *encrypt_array, int *verify_good, int *verify_bad, int *verify_checked, int *counting_code_check)
{
	char temp;
	int checker = 0;
	int i;

	//This checks if the user is going striaght into this function without entering a pin or just after going through this function again
	if ((*(verify_checked)) == 1 || (*(verify_checked)) == 2)
	{
		//if thety directly accessing it from home menu or trying to repeat the process again
		puts("The Code cannot be encrypted ");
	}

	//We know the user has either entered a new pin or double checking the decrypted pin
	else
	{
		//They have access this function after decrypting their function or entered a passcode
		puts("Encrypting the code now.");

		/*Starting the encrption process. We do so by swapping first position in arra with third, then swap
		second position with fourth. Once we done this, we add one to each variable */
		//Look inside symbolic names above for POSITION_A etc

		temp = *(encrypt_array + POSITION_A);
		*(encrypt_array + POSITION_A) = *(encrypt_array + POSITION_C);
		*(encrypt_array + POSITION_C) = temp;

		temp = *(encrypt_array + POSITION_B);
		*(encrypt_array + POSITION_B) = *(encrypt_array + POSITION_D);
		*(encrypt_array + POSITION_D) = temp;

		//Now adding one to each digit
		for (i = 0; i < SWAP_CODE; i++)
		{
			(*(encrypt_array + i))++;

			//According to the ascii table, full colong is after nine
			if ((*(encrypt_array + i)) == ':')
			{
				(*(encrypt_array + i)) = '0';

			}//end if statement

		}//end for loop

		puts("Encrption Complete");

		/*Now we are done using the algorithm to encrpyt the access code. We now do a comparison with the original
		access code, and we tell the user if they match or not*/

		check_with_original_access_code(encrypt_array, &checker, verify_good,verify_bad, counting_code_check);

		//Allowing the user to enter decrpytion process but not encryption again
		(*(verify_checked)) = 1;

	}//end if encrption validation if...else statement

}//end of encrypt_and_check function

/**********************************************************************************************************
Function: To compare to the original code to see if it right and return the result to pervious
Date started: 28-02-2017
Date finished: 28-02-2017
Error checking: NO
**********************************************************************************************************/

void check_with_original_access_code(char *encrypt_array, int *checker, int *verify_good, int *verify_bad, int *counting_code_check)
{
	int i;

	for (i = 0; i < SWAP_CODE; i++)
		{
			if (*(encrypt_array + i) == *(access_code + i))
			{
				//This increments only if they are the exact same number
				(*checker)++;

			}//end if statement

		}//end for loop

		//The following checks if all four digits match. If even one does not match, the program will know
		if ((*checker) == 4)
		{
			puts("CORRECT CODE");

			if ((*counting_code_check) == 1)
			{
				(*(verify_good))++;
			}//end if statement
		}

		else
		{
			puts("ERROR CODE");
			if ((*counting_code_check) == 1)
			{
				(*(verify_bad))++;
			}//end if statement

		}//end if else statement

		//This is so the incrementation cannot happen unless the user enters another pin
		(*(counting_code_check)) = 0;

}//end check_with_original_code

/**********************************************************************************************************
Function: To get the code enter by the user and decrypt it. If the passcode is not encrypted a valid output
will be put to the user to let them know what they can and cannot do in this process
Date started: 26-02-2017
Date finished: 26-02-2017
Error checking: Yes
**********************************************************************************************************/

void decrypt_code(char *decrypt_array, int *verify_checked)
{
	char temp;
	int i;

	//This checks if the user has gone into this function immediately or re-entering it after going through it immediately
	if ((*(verify_checked)) == 0 || (*(verify_checked)) == 2)
	{
		puts("Code cannot be decrypted");
	}

	//We know the user has the code encrypted so we are going to decrypted
	else
	{
		puts("Starting the decryption process");

		/*Starting the decrption process. We do so by swapping first position in arra with third, then swap
		second position with fourth. Once we done this, we subtract one to each variable */
		//Look inside symbolic names above for POSITION_A etc

		for (i = 0; i < SWAP_CODE; i++)
		{
			(*(decrypt_array + i))--;

			//according to ascii table, back slash is before zero
			if ((*(decrypt_array + i)) == '/')
			{
				(*(decrypt_array + i)) = '9';
			}//end if statement
		}//end for loop

		temp = *(decrypt_array + POSITION_A);
		*(decrypt_array + POSITION_A) = *(decrypt_array + POSITION_C);
		*(decrypt_array + POSITION_C) = temp;

		temp = *(decrypt_array + POSITION_B);
		*(decrypt_array + POSITION_B) = *(decrypt_array + POSITION_D);
		*(decrypt_array + POSITION_D) = temp;

		puts("Decryption is done");

		(*(verify_checked)) = 0;
	}//end if else statment
}//end decryption process

/*********************************************************************************************************
Funtcion: To tell the user how many times they have entered the code (i) correct and (ii) incorrect
*********************************************************************************************************/
void code_correct_and_uncorrect(int *verify_good, int *verify_bad)
{
	printf("You have entered your code %d times correct and %d times incorrect\n\n",*verify_good,*verify_bad);
}//end code_correct_and_incorrect function
