/* program to count the number of character in a that represents digits (‘0’,’1’,...,’9’).
and the aplhabetical letter order
08-02-2017
William Carey
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> //This allows us to check each individual character

int main()
{
	FILE *fpoint = fopen("num_let.txt","r");
	char file_got = '0';
	int numbers, characters, total; //Variables to count every time we come across an letter or number. It also counts the total amount of characters including whitespace
	numbers = characters = total = 0;

	//Assuming the file does not exist

	if (fpoint == NULL)
	{
		printf("Cannot open that file\n");
	}

	//File does exist, so we can check each single character now

	else
	{
		//Will keep going till we get to the end of the file

		while ((file_got = fgetc(fpoint)) != EOF)
		{
			//Checking if the character is a number

			if (isdigit(file_got))
			{
				numbers++; //we know it is a number, so we count it as one
			}

			//Checking if the character is a letter

			else if (isalpha(file_got))
			{
				characters++; //We know it is a letter, so we count it as one
			}

			total++; //Counting the total number of characters

		}//end of while statement

		printf("Total number of characters is %d, Total numbers of alphabetically characters is %d and total number of numbers is %d\n",total, characters, numbers);

		//To see if the amount of number is greater than 20% of the entire document

		if (numbers > (total / 5))
		{
			printf("There are too many numbers!!!");
		}

	}//end of if...else statement

	fflush(stdin);

	getchar();

	return 0;
}//end of main
