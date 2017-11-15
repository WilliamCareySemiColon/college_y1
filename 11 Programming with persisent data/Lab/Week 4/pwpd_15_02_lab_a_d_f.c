/*Program to do lab three week four working with binary files. To do part a of the lab work
Have two weeks to complete
William Carey
02-12-2017
*/


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

	if (fp == NULL)
	{
		puts("Error on getting the file");
	}//end if statement

	else
	{
        for (count = 0; count < size; count++)
        {
            number[count] = rand();
        }

		fwrite(&number, 1, sizeof(number), fp);

		fclose(fp);

	}//end if else staement

	fflush(stdin);

	getchar();

	return 0;
}//end main
