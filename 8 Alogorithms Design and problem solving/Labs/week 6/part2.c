#include <stdio.h>

#define size 10

void main()
{
	int array_sorted [size] = {0,1,2,3,4,5,6,7,8,9};
	int count, negative, user_num;
	count = negative = 0;

	puts("Please enter a number you want to be found");
	scanf("%d",&user_num);

	while (count < size)
	{
		if (array_sorted[count] == user_num)
		{
			puts("Number is in the list");
		}
		else
		{
			negative++;
		}//end if..else

		count++;
	}//end while

	if (count == negative)
	{
		puts("Number is not in list");
	}//end if

	fflush(stdin);
	getchar();
}//end main()
