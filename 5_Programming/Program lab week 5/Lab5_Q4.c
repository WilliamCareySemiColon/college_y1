/* Description: An operator that counts from 10 to 1
or 1 to 10, and prints out the number as it progress
through the numbers
Author: William Carey
Date: 23-10-2016
*/

#include <stdio.h>

int main ()
{
    int round_10 = 10;

    //The following loops counts from ten to one

    while ( round_10 >0)
    {
        printf("This number is %d\n",round_10);

        round_10 --;
    } //End Loop

    fflush(stdin);
    getchar();
    return(0);
} //End Main
