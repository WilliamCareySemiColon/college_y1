/*This file gets population.txt and display the sum of all the cities of each of countries population,
to the screen, display the highest population to the screen and to create a text file with the name of
the cities assiocated with Ireland contained in it
09-02-2017
William Carey
*/

//header files

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//symboloic names

#define max_size 20

int main()
{
	//File pointers

	FILE *fp, *file_out;
	fp = fopen("populations.txt","r");
	file_out = fopen("ireland.txt","w");

	// character variables for the program

	char country [max_size];
	char cities_2 [max_size];
	char cities [max_size];
	char population [max_size];

	//integers variables for the program
	int total, max;

	max = total = 0;




	if (fp == NULL)
	{
		printf("File does not exist!!!");
		exit(0);
	}//end if statement

	else
	{
		while ((fscanf(fp,"%s %s %s",country,cities,population)) != EOF)
		{
			//Getting cities of ireland into a new file

			if ( (strcmp(country,"ireland")) == 0)
			{
				fprintf(file_out, "%s ",cities);
			}//end if



			//Getting total population of the country

			 total = total + atoi(population);

			 if (max < (atoi(population)))
			 {
			 	max = atoi(population);
			 	strcpy(cities_2,cities);
			 }

		}//end testing while loop

		printf("%d is the total population\n\n",total);

		printf("The city with the biggest population is %s with the population of %d\n\n", cities_2, max);

		//end getting total population

		fclose(fp);
		fclose(file_out);
	}//end else statement

    fflush(stdin);

	getchar();

	return 0;
}
