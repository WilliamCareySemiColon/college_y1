/**************************************************************************************************
This programme is going to get a file and scramble it in binary form and and add a .sbl
**************************************************************************************************/

//header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//symbolic names
#define FILE_NAME 21
#define SIZE 100000

//main function
int main()
{
	//File variables to get two files
	FILE *fp_in, *fp_out;
	//Character variables that takes the files name
	char file_name [FILE_NAME], file_name_2[FILE_NAME];
	//int variables
	int length, num, temp[SIZE], temp_2[SIZE], i;

	//getting file from user
	puts("Please enter the file you are looking for to encrypt");
	scanf("%20s",file_name);

	//reading in file in binary
	fp_in = fopen(file_name,"rb");

	//Checking if the file exist
	if (fp_in == NULL)
	{
		puts("File does not exist");
	}

	//File exists, so we persist to create a new encrypted one
	else
	{
		//These will create a new file with the same name but adds an .sbl extension
		strcpy(file_name_2,file_name);
		strcat(file_name_2,".sbl");

		//This will create the new file for us 
		fp_out = fopen(file_name_2,"wb");

		//To find out the size if the file
		fseek(fp_in,0,SEEK_END);
		length = ftell(fp_in);

		//To ensure we start at the begining
		rewind(fp_in);
		rewind(fp_out);

		//If the file size is odd, we will not swap out the last byte
		if (length % 2 == 0)
		{
			//We know the size is an even number, so we swap every byte
			for (i = 0; i < length; i += 2)
			{
				//reading from one file
				fseek(fp_in,(i*sizeof(char)),SEEK_SET);
				fread(&temp[i],1,1,fp_in);
				fseek(fp_in,((i+1)*sizeof(char)),SEEK_SET);
				fread(&temp_2[i],1,1,fp_in);

				//writing into another file
				fseek(fp_out,(i*sizeof(char)),SEEK_SET);
				fwrite(&temp_2[i],sizeof(char),1,fp_out);
				fseek(fp_out,((i+1)*sizeof(char)),SEEK_SET);
				fwrite(&temp[i],sizeof(char),1,fp_out);
			}//end for loop
		}

		else
		{
			//We know the file is an odd number, so we leave the last byte alone
			for (i = 0; i < (length - 1); i += 2)
			{
				//reading from one file
				fseek(fp_in,(i*sizeof(char)),SEEK_SET);
				fread(&temp,1,1,fp_in);
				fseek(fp_in,((i+1)*sizeof(char)),SEEK_SET);
				fread(&temp_2,1,1,fp_in);

				//writing into another file
				fseek(fp_out,(i*sizeof(char)),SEEK_SET);
				fwrite(&temp_2[i],sizeof(char),1,fp_out);
				fseek(fp_out,((i+1)*sizeof(char)),SEEK_SET);
				fwrite(&temp[i],sizeof(char),1,fp_out);
			}//end for loop
		}//end inner if...else statement

		//letting the user know it has been encrypted
		puts("Copy is encrypted");

		//closing the file pointers and the files themselves
		fclose(fp_in);
		fclose(fp_out);
	}//end outer if...else statement

	fflush(stdin);
	getchar();
	return 0;
}//end main
