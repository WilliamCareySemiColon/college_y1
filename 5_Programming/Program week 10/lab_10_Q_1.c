/*A program that uses a pointer notation to read in a radius for the calculation of a circle. The
program will also use pointer notation for the diameter and the area of the circle. Assume pie is
3.14
Date: 29-11-2start16
Author: William Carey
*/

#include <stdio.h>

#define pie_numerical 3.14
#define start 0


int main()
{
	//All these variables are in place for the calculation of a circle
	float radius = start;
	float diameter = start;
	float area = start;
	float pie = pie_numerical;

	//All these pointers hold the addresses of their corresponding variables
	float *radius_address = &radius;
	float *diameter_address = &diameter;
	float *area_address = &area;

	//Taking in the radius from the user
	printf("Please enter the radius of the circle and I will show you it's area and diameter\n");
	scanf("%f",&*radius_address);

	//Now calculating the diameter and showing it to user

	*diameter_address = 2*(*radius_address);
	printf("\n%.2f is the diameter of your circle\n",*diameter_address);

	//Now calculating the area and showing it to user
	*area_address = ((*radius_address)*(*radius_address))*(pie);
	printf("\nThe area of your circle is %.2f square metres",*area_address);

	fflush(stdin);

	getchar();

	return start;
}
