/*Description: To write a program that takes in five
numbers from the user and places them into one array
then copy them and place them into another array
Author: William Carey
Date: 01-10-2016
*/

#include <stdio.h>

#define array_size 5
#define starting_point 0
#define numerical_called_1 1

int main()
{
    int input_1 [array_size] = {starting_point,};
    int array_copied [array_size] = {starting_point,};
    int inputted_1_by_1 = numerical_called_1;

    printf("Please enter five numbers\n");

    for (inputted_1_by_1 = starting_point; inputted_1_by_1 != (array_size - numerical_called_1); inputted_1_by_1 ++)
    {
        scanf("%d",&input_1[inputted_1_by_1]);

    }//end first for loop


    for (inputted_1_by_1 = starting_point; inputted_1_by_1 != (array_size - numerical_called_1); inputted_1_by_1 ++)
    {
        array_copied [inputted_1_by_1]= input_1[inputted_1_by_1];

    }//end  second for loop



    fflush(stdin);
    getchar();
    return(0);
}//End main
