 /*Program that reads one file and prints all the contents into two new files -
all the odd lines into odd text and all the even lines in even text
08-02-2017
William Carey
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 200

int main()
 {
 	FILE *file, *odd, *even; //Three files are going to be needed = 3 pointers

 	file = fopen("num_let.txt","r"); //The files which the pointers are pointing at
 	odd = fopen("odd.txt","w");
 	even = fopen("even.txt","w");

 	int count = 1; //This is needed for spliitng the file into two new ones
 	char file_line [MAX_SIZE]; //So we can read each line that we neeed to read

 	//Checking if the file exist

 	if (file == NULL)
 	{
 		printf("Cannot get document needed"); //This tells us the file does not exist
 	}

 	/*We know the file exist if the above if does not get executed. This means we can procede with creating the new
 	files using a counter
 	*/

 	else
 	{

		while (fgets(file_line, MAX_SIZE, file) != NULL) //This reads line by line in the original file
 		{
 			//If the text is on an odd line it goes into the odd.txt file

 			if ( count % 2 == 1)
 			{
 				fputs(file_line, odd);
 			}//end if

 			//If the file is on a even file it goes into the even.txt file

 			else
 			{
 				fputs(file_line, even);
 			}// end else

 			count++;//This makes sure every line gets put into the right file

 			//the following makes sure the files are closed

 			fclose(file);
 			fclose(odd);
 			fclose(even);
 		}//end of inner while

 		printf("Successful");
 	}//end else statement

 	fflush(stdin);

 	getchar();

 	return 0;
 }
