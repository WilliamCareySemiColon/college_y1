/*Program to get a file and read the amount of chracters displayed from it
William
06-02-2017
*/

#include <stdio.h>

main ()
{
	FILE *fp;
	int count,counter, c_IN;
	counter = count = 0;

	if ((fp = fopen("num_let_1.txt","r")) == NULL)
	{
		puts("Error: Can't open that file");
	} //end if

	else
	{
		while ((c_IN = fgetc(fp)) != EOF)
		{
			count ++;
		}//end while

		printf("There are %d characters in this file\n",count);
	} //end else

	fclose(fp);
}
