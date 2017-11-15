/**********************************************************************************************************

Program to get two imputs from the user, one for the side of the square on one for the radius of the circle.
It will take these inputs, transfer the address location of these variables into an separate function,
calculate them in a outside function and return the final answer to the main function.
This program checks for negative inputs for the circle area
William Carey
14-02-17
************************************************************************************************************/

//Header files

#include <stdio.h>

//Symbolic names

#define pie 3.14
#define no_pass 1

//function protypes

float area_of_circle (int *);
int area_of_square (int *);

//main body of code

void main()
{
	//Variables used for two functions
	float circle_area;
	int side_of_sq, rad_of_circle, square_area;
	rad_of_circle = 0;

	//Now getting user to input for square function

	printf("Please enter the side length of the square\n");
	scanf("%d",&side_of_sq);

	//Now getting input for the circle function

	printf("\nPlease enter the length of the radius\n");
	scanf("%d",&rad_of_circle);

	//This only excutes if the user input a number not suitable for the program

	while (rad_of_circle < no_pass)
	{
		printf("\nInvalid number, please type a suitable number\n");
		scanf("%d",&rad_of_circle);
	}//end while loop

	//Calling the functions

	square_area = area_of_square( &side_of_sq );
	circle_area = area_of_circle( &rad_of_circle);

	//printing the answer to the screen

	printf("\nThe area of the square is %d and the area of the circle is %.4f",square_area, circle_area);

	fflush(stdin);

	getchar();
}//end main body


/*Now implementing the function for square calculation. This will be return as an int value to the main body once
done
*/


int area_of_square (int *square_pointer)
{
	int total_area;

	//calculating the area of the square

	total_area = (*square_pointer) * (*square_pointer);

	//returning the value to main

	return(total_area);
}//end area_of_square

/*now  implementing the function for circle calculation. This will return a float value to the main body
*/

float area_of_circle (int *circle_pointer)
{
	float total_area;

	//Calculating the area of the circle

	total_area = (float) (*circle_pointer) * pie;

	//return value back to main

	return(total_area);
}//end area_of_circle
