/* Description: This is to get the modulus of a few different numbers
Author: William Carey
Date: 04-10-2016 */

#include <stdio.h>

int main()
{
    int mode1 = 2;
    int mode2 = 3;
    int mode3 = 5;
    int mode4 = 7; 
    int mode5 = 100;
    int mode6 = 100;
    
    
    //To find the modlus of 2 divided by 2 and to show the modulus
    
    mode1 = mode1%2;
    
    printf("mode1 has %d\n",mode1);
    
    //To find the modulus of 3 divided by 2 and to show the modulus
    
    mode2 = mode2%2;
    
    printf("mode2 has %d\n",mode2);
    
    //To find the modulus of 5 divided by 2 and to show the modulus
    
    mode3 = mode3%2;
    
    printf("mode3 has %d\n",mode3);
    
    //To find the modulus of 7 divided by 3
    
    mode4 = mode4%3;
    
    printf("mode4 has %d\n",mode4);
    
    //To find the modulus of 100 divided by 33 and to show the modulus
    
    mode5 = mode5%33;
    
    printf("mode5 has %d\n",mode5);
    
    //To find the modulus of 100 divided by 7 and to show the modulus
    
    mode6 = mode6%7;
    printf("mode6 has %d",mode6);
    
    getchar();
    return(0);
} //End Main ()