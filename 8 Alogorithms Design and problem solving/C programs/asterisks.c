/*This is to print out a christmas tree version in c language. It will use
a triple for loop within a while loop
05-02-2017
William Carey
*/

#include <stdio.h>

int main()
{
	int count_for_for_loop, stars, number_of_stars, number_of_stars_1;
	int stars_1 = 1;

	printf("On a scale of two onwards, how big do you want a christmas tree\n");
	scanf("%d",&number_of_stars);

	//Extra varaiable so the for loop can be performed again

	number_of_stars_1 = number_of_stars;

	while (number_of_stars > 0)
	{
		for (count_for_for_loop = 1; count_for_for_loop < number_of_stars; count_for_for_loop++)
		{
			printf(" ");
		}//end first for loop

		for (stars = 0; stars < stars_1; stars++)
		{
			printf("*");
		}//end second for loop

		for (count_for_for_loop = 1; count_for_for_loop < number_of_stars; count_for_for_loop++)
		{
			printf(" ");
		}//end third for loop

		printf("\n");

		number_of_stars--;

		stars_1 = stars_1 + 2;

	}//end  while loop

	//Just finishing up with the trunk of the tree now

	stars_1 = 1;

	if (number_of_stars_1 > 0)
	{
		for (count_for_for_loop = 1; count_for_for_loop < number_of_stars_1; count_for_for_loop++)
		{
			printf(" ");
		}//end first for loop

		for (stars = 0; stars < stars_1; stars++)
		{
			printf("*");
		}//end second for loop

		for (count_for_for_loop = 1; count_for_for_loop < number_of_stars_1; count_for_for_loop++)
		{
			printf(" ");
		}//end third for loop

	}//end if staement

		fflush(stdin);

		getchar();

		return 0;
} //end main
