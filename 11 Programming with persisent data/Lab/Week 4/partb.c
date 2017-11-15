/*Program to do lab three week four working with binary files. This is part b of the lab work.
Chris Clarke & William Carey
28-02-2017
*/


//Header files
#include <stdio.h>
#include <stdlib.h>

//Symbolic names
#define size 1000

int main()
{

	//Files pointers
	FILE *fp = fopen("num1000.bin", "rb");

	//variables for program
	int number[size];
    int myarray[sizeof(number)];
    int i;

	//Checking if the file exists

	if (fp == NULL)
	{
		puts("Error on getting the file");
	}//end if statement

	else
	{
        fread(&number, 1, sizeof(number), fp);
        //Reading and displaying the array from the file now
        for(i=0; i<sizeof(number); i++)
        {
           printf("%i ",myarray[i]);
        }//end for loop

		//Closing the file

		fclose(fp);

	}//end else statement

	fflush(stdin);

	getchar();

	return 0;
}//end main