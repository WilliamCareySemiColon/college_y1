/*****************************************************************************************************
This program will copy in two files, both are the same except one file has not been modified, where as
the second one has the third number and tenth number modified. Both files will combine into one
Date: 17-02-2017
William Carey & Chris Clake
*****************************************************************************************************/

//header files
#include <stdio.h>
#include <stdlib.h>

//Symbolic names
#define lesser_size 1000
#define double_size 2000

//Main body
void main()
{
	//File variables
	FILE *fp_1, *fp_2;
	fp_1 = fopen("num1000.bin","rb+");
	fp_2 = fopen("num1000_copy.bin","ab+");

	//Variables for the program
	int zero, i, j;
	zero = i = j = 0;
	int nums[lesser_size];
	int double_nums [double_size];

	//checking to make sure we can access the file

	if (fp_1 == NULL || fp_2 == NULL)
	{
		puts("Cannot find file!!!");
	}//end if statement

	else
	{
	    puts("Pre-Modified Number set");
	    fread(nums, 1, sizeof(nums), fp_1);
        for (i = 0; i < lesser_size; i++)
        {
            printf("%d ",nums [i]);
        }//end for loop

        printf("\n\n\n");

        //This willl seek the 3rd and tenth position of the code
        fseek(fp_1, (2 * sizeof(int)), SEEK_SET);
        fwrite(&zero, sizeof(int), 1, fp_1);
        fseek(fp_1, (9 * sizeof(int)), SEEK_SET);
        fwrite(&zero, sizeof(int), 1, fp_1);

        //This will write one document into another
        fseek(fp_1, 0, SEEK_SET);
        fread(nums, 1, sizeof(nums),fp_1);

        puts("Post-Modified Number set");
         for (i = 0; i < lesser_size; i++)
        {
            printf("%d ",nums [i]);
        }//end for loop

        fseek(fp_2, 0, SEEK_END);
        fwrite(nums, 1, sizeof(nums),fp_2);

		//Closing the files
		fclose(fp_1);
		fclose(fp_2);

	}//end if else statement
}//end main body
