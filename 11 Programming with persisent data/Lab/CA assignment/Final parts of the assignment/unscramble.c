/**************************************************************************************************
This programme is going to get a file and unscramble it in binary form and and remove the .sbl
extension
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
	FILE *fp_in, *fp_out;
	char file_name [FILE_NAME], file_name_2[FILE_NAME], *p;
	int length, num, temp[SIZE], temp_2[SIZE], i;

	//Getting the file from the user
	puts("Please enter the file you are looking for to decrypt");
	scanf("%20s",file_name);

	//reading in the file
	fp_in = fopen(file_name,"rb");
	
	//Checking if the file exist
	if (fp_in == NULL)
	{
		puts("File does not exist");
	}

	else
	{

		//Getting the file and starting the decryption process
		strcpy(file_name_2,file_name);

		//Getting the charcter postion of where the ".sbl" extension starts
		p = strstr(file_name_2,".sbl");

		//removing the extension
		for (i = 0; i < (strlen(".sbl")); i++)
		{
			*(p+i) = '\0';
		}//end for loop

		//Creating the new file
		fp_out = fopen(file_name_2,"wb");


		//To find out the size if the file
		fseek(fp_in,0,SEEK_END);
		length = ftell(fp_in);

		//Ensuring we start at the begining of each file
		rewind(fp_in);
		rewind(fp_out);

		//checking if the file is an even or odd size
		if (length % 2 == 0)
		{
			//We knw the file is an even size, so we swap every byte
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
			//WE know the file size is odd, so we leave the lastv byte alone
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

		//letting the user know it has been decrypted
		puts("Copy is decrypted");

		fclose(fp_in);
		fclose(fp_out);
	}//end outer if...else statement

	fflush(stdin);
	getchar();
	return 0;
}//end main
