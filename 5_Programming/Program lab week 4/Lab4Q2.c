/*Description: To get the user to input an number and to display whether it is a even or odd
Author: William Carey
Date: 11-10-2016 */

#include <stdio.h>

int main()
{
    int div = 0;
    int remainder;
    
    printf("Enter any number between 1 and 100\n");
    scanf("%d",&div);
    
    remainder = div %2;
    
    //Starting if statement
    
    if(remainder == 0)
    {
        printf(" You entered an even number");
    }
    else
    {
        printf(" You entered an odd number");
    }
      //end if statement
    
    
    flushall();
    getchar();
    return(0);
}//End main
            