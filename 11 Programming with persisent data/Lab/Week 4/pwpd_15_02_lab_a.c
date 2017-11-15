/*********************************************************************************************
Program to do lab three week four working with binary files. To do part a of the lab work
Have two weeks to complete
Part b,c and e are to be completed by Chris Clake
William Carey
02-12-2017
********************************************************************************************/


//Header files
#include <stdio.h>
#include <stdlib.h>

//Symbolic names
#define size 1000

int main()
{

	//Files pointers
	FILE *fp = fopen("num1000.bin", "w+b");

	//varaiables for program
	int number[size], count;

	//Checking if the file exists

	if (fp == NULL)
	{
		puts("Error on getting the file");
	}//end if statement

	else
	{
		//Setting the seed to zero
		srand(0);

		//Intialising the array to have loads of numbers in binary form
        for (count = 0; count < size; count++)
        {
            number[count] = rand() % 100;
            printf("%d ",number[count]);
        }//end for loop

        //Writing the array into the file now

		fwrite(&number, 1, sizeof(number), fp);

		//Closing the file

		fclose(fp);

	}//end else staement

	fflush(stdin);

	getchar();

	return 0;
}//end main
