#include <stdio.h>

main()
{
	FILE *p;
	char filename [10];

	printf("Please eneter the file you wish to recieve\n");
	gets(filename);

	p = fopen(filename,"r");

	if (p == NULL)
	{
		printf("Error cannot open that file\n");
	}
	else 
	{
		printf("Opened file\n");
		fclose(p);
		printf("Closed file\n");
	}
}