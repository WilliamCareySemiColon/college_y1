#include <stdlib.h>
#include <stdio.h>
#include <time.h>
main()
{
  clock_t begin, end;
  double time_spent;
	FILE *filew;
	FILE *filer;
	char ch;

  begin = clock(); //start the clock


	filer = fopen("copy_bin_time.c","r");

	if (filer == NULL)
	{
		printf("Cannot open file.\n");
		exit(1);
	}

	filew = fopen("fseek_ffelt_example.c","w");

	if (filew ==NULL)
	{
		printf("Cannot open file.\n");
		exit(1);
	}
	//copy char by char
	while((ch = fgetc( filer )) != EOF)
	{
		fputc(ch,filew);
	}

	fclose(filer);
	fclose(filew);

	end = clock(); //stop the clock

	//compute the number of seconds. CLOCKS_PER_SEC is a constant in time.h
	 time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	 printf("%f",time_spent);
	//if you want to print the time (in seconds), remember it is a float
  return 0;
}
