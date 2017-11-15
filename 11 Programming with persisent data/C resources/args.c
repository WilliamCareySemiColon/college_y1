#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <string.h>

int main(int argc, char *argv[])
{
   int c;
   
	printf("Number of command line parameters %d\n", argc);
	printf("First parameter: %s\n",argv[0]);
	
	for (c=0; c<argc ; c++)
	{
	printf(" parameter %d: %s\n",c,argv[c]);
		
	}
 	
}
	