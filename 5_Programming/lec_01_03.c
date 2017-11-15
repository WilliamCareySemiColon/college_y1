//Lecure 1st March - array of pointers

#include <stdio.h>

int main()
{
	char *months [12] = {"Jan","Feb","Mar","Apr",
							"may","jun","july",
							"aug", "sep", "oct", 
							"nov", "dec"};

	int i;
	printf("The months are: ");

	for(i = 0; i<12; i++)
	{
		printf("%s\n",months[i] );
	}

	return 0;
}