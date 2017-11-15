/* description: A program that use a while loop
    to print the the numbers 1-10 in a descending order
    Author: William Carey
    Date:18-10-2016
*/

#include <stdio.h>

int main()
{
    int first_num_1 = 10;

    //loop to demonstrate the descending order of numbers from 10 to 1

    while (first_num_1 != 0) //While the variable does not equal to zero
    {
        if(first_num_1 != 1)
        {
            printf("%d,",first_num_1);
        }
        else
        {
            printf("%d",first_num_1);
        }

        first_num_1 -- ;             //this decreases the value of first_num_1 by one each time it is repeated

    } //End loop

    getchar();

    return(0);
} //end main
