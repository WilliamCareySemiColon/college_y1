/*This file will retrieve two files and merge them in together as merged.txt file. If either of the file does not exist,
we cannot create the file merged.txt file. This will be done by indenting a if...else statement within an if...else
staement. This is version number 1
09-02-2017
*/

#include <stdio.h>
#include <stdlib.h>

#define size 100

int main()
{
	FILE *file_get_1, *file_get_2, *file_out;
	file_out = fopen("merged.txt","w");

    char file_name [size], file_name_2 [size];

    printf("Please enter the first file's name\n");
    gets(file_name);

    printf("Please enter the second file's name\n");
    gets(file_name_2);

    file_get_1 = fopen(file_name,"r");
    file_get_2 = fopen(file_name,"r");

	int count_file_1, count_file_2;
	count_file_1 = count_file_2 = 0;

	if (file_get_1 == NULL)
	{
		printf("File number 1 does not exist");
	}//end outer if statement

	else
	{
		if (file_get_2 == NULL)
		{
			printf("File number 2 does not exist");
		}//end inner if statement

		else
		{
			while ((count_file_1 = fgetc(file_get_1)) != EOF)
			{
				fputc(count_file_1, file_out);
			}//end while one

			while ((count_file_2 = fgetc(file_get_2)) != EOF)
			{
				fputc(count_file_2, file_out);
			}//end while two

			printf("Copy is completed\n");
		}//end inner else statement

	}//end outer else statement

	fflush(stdin);

	getchar();

	return 0;
}//end main
