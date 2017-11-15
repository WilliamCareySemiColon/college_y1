#include <stdio.h>
#include <stdlib.h>

void main()
{
	int i, *my_arr, num, min, max;

	puts("How many numbers do you want to test this program on?");
	scanf("%d",&num);

	my_arr = calloc(num, sizeof(int));

	if (my_arr == NULL)
	{
		puts("\nSorry cannot alloacate that amount of numbers");
	}//end if

	else
	{
		puts("Successfully allocated that amount of memory");

		srand(0);

		for (i = 0; i < num; i++)
		{
			(*(my_arr + i)) = (rand() % 100);
		}//end intialise array

		max = min = *my_arr;

		for (i = 0; i < num; i++)
		{
			//Finding the smallest value
			if (min > (*(my_arr + i)))
			{
				min = (*(my_arr + i));
			}//end min if

			//finding the largest value
			if (max < (*(my_arr + i)))
			{
				max = (*(my_arr + i));
			}//end min if

		}//end for loop

		printf("The biggest number is %d and the smallest number is %d in an unsorted array",max,min);
		free(my_arr);

	}//end else statement

	fflush(stdin);
	getchar();
	exit(0);
} //end main

