/* Description: To get the user to input two characters and to display the numbers back to the user
Author: William Carey
Date: 04-10-2016 */

#include <stdio.h>

int main()
{
    char var1 = '0';
    char var2 = '0';
    
        printf("Please enter any two characters\n");
          
            scanf("%1s",&var1);
            scanf("%1s",&var2);
        
    printf("you entered %c,%c", var1,var2);
   
    flushall();
    getchar();
    return(0);
} //End Main