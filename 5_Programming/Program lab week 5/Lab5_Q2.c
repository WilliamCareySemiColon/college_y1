/*Description: To take a positive integer and divide it
by two if it is even, mutiply by three then add one
 if it is odd until the the value is one, then print
 the amount of steps taken to complete the program
 Author: William Carey
 Date: 18-10-2016
 */

 #include <stdio.h>

 int main()
 {
     int value_1 = 0;
     int count = 0;


     printf("Please input a postive number\n");
     scanf("%d",&value_1);

     //To check the user has not inputted a number less than postive 1

     while (value_1 < 1)
     {
         printf("Error, this is not a postive integer. please enter a positive integer\n");
         scanf("%d",&value_1);
     }                                              //End  error checking while statement

     printf("Your first value is %d\n", value_1);

     while ( value_1 != 2)
     {
         if (value_1 % 2 == 1)
         {
             value_1 = (value_1 * 3) + 1 ;

             printf("Next value is %d\n", value_1);

              count ++;
         }                                          //End if statement

         else
         {
             value_1 = value_1 / 2 ;

             printf("Next value is %d\n", value_1);

             count ++;
         }                                         //End else statement


     }                                             //End second while loop

     value_1 = value_1 / 2;
     count ++;

     printf("final value is %d", value_1);
     printf("\n The amount of steps taken are %d",count);


    fflush(stdin);

     getchar();

     return(0);

 }//end main
