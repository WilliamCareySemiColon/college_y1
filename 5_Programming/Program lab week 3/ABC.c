/* Description: To get the user to input three different numbers and to display them on the screen
Author: William Carey
Date: 04-10-2016  */

#include <stdio.h>
int main()
{
    int num1 = 0;
    int num2 = 0;
    int num3 = 0;
    
        printf("enter three whole numbers\n");
            scanf("%d",&num1);
            scanf("%d",&num2);
            scanf("%d",&num3);
        printf("you entered %d,%d and %d",num1, num2, num3);
    flushall();
    getchar();
    return(0);
} //end main