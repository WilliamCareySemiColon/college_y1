/* Description: To take a number from the number set
1-5 and to see if the number set 1-20 can be divisible
by the number set given
Author: William Carey
Date: 23-10-2016
*/

# include <stdio.h>

int main()
{
    int counter_20 = 20;
    int answer = 0;
    int given_number = 0;
    int checker = 0;
ww
























































    printf("Please input a number between one and five in numerical form\n");
    scanf("%d",&given_number);


    /*The following "If Statement" is for the user entering "1" as the input,
    whereas the else statement is for if the user inputs "2, 3, 4 or 5"
    */


        if ( given_number == 1)
        {

               while ( counter_20 != 0)
               {
                    answer = counter_20 / given_number;

                    /*Anything divided by one gives itself, so we know there will be no remainder
                    which is why the integer "checker" is not used here but used later
                    */

                    printf("\n%d divided by %d gives %d", counter_20, given_number, answer);

                    counter_20 --;

               }//En while loop inside first if statement
        }  //End if statement


       else
           {

               while ( counter_20 != 0)
               {

                    /*The following integer finds if there is a remainder
                  in the folowing code. If there is, it will not be printed
                  out as the requeat is to print out numbers that do't have
                  a remainder
                  */

                   checker = counter_20 % given_number;   //This finds the remainder of the following equation


                    if ( checker == 0)
                           {
                               answer = counter_20 / given_number;

                            printf("\n%d divided by %d gives %d", counter_20, given_number, answer);
                           }  //End  If statement inside else statement



                    counter_20 --;

               } //End second while loop
           }  //End else statement

    fflush(stdin);

    getchar();

    return(0);
} //End main
