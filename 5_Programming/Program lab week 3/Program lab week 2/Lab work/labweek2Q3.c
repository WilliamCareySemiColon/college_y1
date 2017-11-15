/*Description: To Calculate and display the area of a circle with the radius of 4.8
Author: William Carey
Date: 27-09-16*/

#include <stdio.h>

int main()
{
    float formulaB;
    float formulaC;
    
    formulaB=4.8;
    formulaC=3.14;
    
    /*The formula for area of a circle is pie r squared, 
    where r is the raduis of the circle. In this case we will calculate the area of the circle with the 
        radius of 4.8*/
    
    float areaofcircle = formulaB*formulaB*formulaC;
    
    printf("areaofcircle contains %f",areaofcircle);
    
    getchar();
    return(0);
}