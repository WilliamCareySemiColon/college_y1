/* Descrtion: The following is to calculate the sum of the intergers from one to five.
Author: William Carey
Date: 27-09-2016
*/

#include <stdio.h>

int main()
{
    int denom1;
    int denom2;
    int denom3;
    int denom4;
    int denom5;
    
    denom1 = 1;
    denom2 = 2;
    denom3 = 3;
    denom4 = 4;
    denom5 = 5;
   
    denom5 = denom1 + denom2 + denom3 + denom4 + denom5;
    
    printf("denom5 contains %d",denom5);
    
    getchar();
    
    return(0);
}