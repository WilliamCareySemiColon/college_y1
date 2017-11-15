/**************************************************************
This program copies the contents of one file and puts it into a new file
Both are binaries files and should look weird
William Carey & Chris clake
16-02-2017
**************************************************************/

//header files
#include <stdio.h>
#include <stdlib.h>

//Symbolic name
#define size 1000

//main body

int main()
{
	//File variables
	FILE *fp_in, *fp_out;
	fp_in = fopen("num1000.bin","r+b");
	fp_out = fopen("num1000_copy.bin","w+b");

	//Variables for the program
	int number[size], i;

	//Checking if the file exists

	if (fp_in == NULL || fp_out == NULL)
	{
		puts("Cannot find the files");
	}//end if statement

	//Reading one file and placing it into another

	else
	{
		fread(&number, 1, sizeof(number), fp_in);

		for (i = 0; i < size; i++)
        {
            printf("%d ",number [i]);
        }
		fwrite(&number, 1, sizeof(number), fp_out);

		//closing the files

		fclose(fp_in);
		fclose(fp_out);
	}//end else staement

	fflush(stdin);

	getchar();

	return 0;
}
