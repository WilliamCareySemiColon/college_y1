/*Description: This program is to dertermine
if three numbers input can form a valid triangle
Author: William Carey
Date: 17-10-2016
*/

#include <stdio.h>

int main()
{
    int side_1 = 0;
    int side_2 = 0;
    int side_3 = 0;

    int valid_1 = 0;
    int valid_2 = 0;
    int valid_3 = 0;

    printf("Please input three numbers\n");
    scanf("%d",&side_1);
    scanf("%d",&side_2);
    scanf("%d",&side_3);

    valid_1 = side_1 + side_2;
    valid_2 = side_2 + side_3;
    valid_3 = side_1 + side_3;

   if (valid_1 > side_3)
   {
       printf("You have a side %d, another side %d and the last side %d", side_1, side_2, side_3);

   }  //End first check for validation of triangle

   else if ( valid_2 > side_1)
   {
       printf("You have a side %d, another side %d and the last side %d", side_1, side_2, side_3);
   }  //End second check for validation of triangle

   else if ( valid_3 > side_2)
   {
       printf(" You have a side %d, another side %d and the last side %d", side_1, side_2, side_3);
   }  //End last check for validation for triangle

   else
   {
       printf("Your numbers are not sufficient to form a triangle");
   }  //End if....else statement


    return(0);
}//End main
