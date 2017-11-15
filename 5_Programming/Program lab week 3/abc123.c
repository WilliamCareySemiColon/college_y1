/* Description: To get the user to input three fractional numbers and display them back to the user
Author: William Carey
Date: 04-10-2016 */

#include <stdio.h>

int main()
{
    float frac1 = 0;
    float frac2 = 0;
    float frac3 = 0;
    
        printf("please input any three numbers with decimals\n");
            scanf("%f",&frac1);
            scanf("%f",&frac2);
            scanf("%f",&frac3);
        printf("you entered %.4f,%.3f and %.0f",frac1,frac2,frac3);
    flushall();
    getchar();
    return(0);
} //end main