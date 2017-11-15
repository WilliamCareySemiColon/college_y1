/* Description: To print all the even numbers from
100 to 1 separated by a comma using a loop
Author : William Carey
Date: 23-10-2016
*/

#include <stdio.h>

int main()
{
    int countdown = 100;
    int checker = 0;

        for (countdown = 100; countdown > 0; countdown --)
        {
            checker = countdown % 2;

                if (checker == 0)
                {
                    if ( countdown > 2)
                    {
                        printf(" %d is even,", countdown);
                    } //End inner if statement that checks if the number is bigger than 2

                    else
                    {
                        printf(" %d is even", countdown);
                    }  //end else staement

                } // End outer if statement for even numbers
        } //End for loop

    fflush(stdin);

    getchar();

    return(0);
} //End main
