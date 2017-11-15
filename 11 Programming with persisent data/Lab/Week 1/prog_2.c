#include <stdio.h>

main()
{
	FILE *p = fopen("prog_1.c","r");

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
