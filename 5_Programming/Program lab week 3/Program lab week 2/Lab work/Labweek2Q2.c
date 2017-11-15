/*Description: To Calculate the volume and the surface area of a box that is closed
Author: William Carey
Date: 27-09-16*/

#include <stdio.h>

int main()
{
    int height = 10;
    float length= 11.5;
    float width= 2.5;
    
    //The following is the process of calculating the volume of the box
    
    float volume= height*length*width;
    
    printf("volume contains %f\n",volume);
    
    //The following is calculating the surface area of the box 
    
    float sideA= height*width;
    float sideB= length*width;
    
    //Since there is six sides in a box, we must multiply sideA by two and SideB by four
    
    int totalsurfacearea= (sideA*2)+(sideB*4);
    printf("totalsurfacearea contains %d",totalsurfacearea);
    
    getchar();
    return(0);
}