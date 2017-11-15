/*Program to illustrate fgetc() & fputc. The two functions gets characters from one file and place into a new file 
08-02-2017
William Carey
*/

#include <stdio.h>

main ()
{
	FILE *fp_IN, *fp_OUT; //two files to be used, one to be used and one to be created as a copy of the contents = two pointers
	int c_IN; //This varaible will be used to get each character in byte sizes for storage purpose

	//Checking if file exist

	if ((fp_IN = fopen("num_let.txt","r")) == NULL) //This is reading the file if it exists
	{
		puts("Error: Can't open that file"); //this means the file does not exist
	} //end if

	/*Now we know the file exists, so we are going to copy its contents and put in into a new file
	The variable "c_IN" will get each varaible and store it temporary until it is saved into a new file
	*/

	else if ((fp_OUT = fopen("new_file_1.txt","w")) != NULL) //This create the new file
	{

		//This will loop around until we get to the end of the file

		while ((c_IN = fgetc(fp_IN)) != EOF)
		{
			fputc(c_IN, fp_OUT); //this is the process of putting the content into the new file
		}//end while

		fclose(fp_IN); //These will close the files
		fclose(fp_OUT);
		puts("Copy completed");
	}//end else...if

	else
	{
		puts("Error in opening new file");
	}//end else
}//end main
