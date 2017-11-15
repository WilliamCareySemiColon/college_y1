/*Description: To take a number from the number set 1 - 5
from the user and display the numbers from the number set
 1 - 20 that can be divided evenly by the number given to us
 Author: William Carey
 Date: 18-10-2016
 */

 #include <stdio.h>

 int main()
 {
     int given_number = 0;
     int counter_20 = 20;
     int answer = 0;
     int checker = 0;

     printf("Please input a number between one and five in numerical form\n");
     scanf("%d",&given_number);

    switch (given_number)
    {
    case 1:
        {
            while ( counter_20 != 0)
            {
                answer = counter_20 / given_number;

                printf("\n%d divided by %d gives %d",counter_20,given_number,answer);

                counter_20 --;
            } //End while loop for given_number = 1
        } //End case 1
    case 2:
        {
            while ( counter_20 != 0)
            {
                checker = counter_20 % given_number;

                if (checker == 0)
                {
                    answer = counter_20 / given_number;

                printf("\n%d divided by %d gives %d",counter_20,given_number,answer);

                } //End if statement
                counter_20 --;
            } // End while loop
        } //End case 2
    case 3:
        {

            while ( counter_20 != 0)
            {
                checker = counter_20 % given_number;

                if (checker == 0)
                {
                    answer = counter_20 / given_number;

                printf("\n%d divided by %d gives %d",counter_20,given_number,answer);
                } //End if statement
                counter_20 --;
            }//end while loop
        }//case 3

    case 4:
        {

            while ( counter_20 != 0)
            {
                checker = counter_20 % given_number;
                if (checker == 0)
                {
                    answer = counter_20 / given_number;

                printf("\n%d divided by %d gives %d",counter_20,given_number,answer);
                } //End if  statement
                counter_20 --;
            } //end while loop
        } //end case 4

        case 5:
        {
            while ( counter_20 != 0)
            {
                checker = counter_20 % given_number;
                if (checker == 0)
                {
                    answer = counter_20 / given_number;

                printf("\n%d divided by %d gives %d",counter_20,given_number,answer);
                } //End if statement
                counter_20 --;
            }//end while loop
        }//end case 5
    } //End switch statement



    fflush(stdin);
    getchar();
     return(0);
 }//End Main
