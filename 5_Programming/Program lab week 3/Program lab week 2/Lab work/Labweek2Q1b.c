/*Desciption: To calculate and display the average of the float numbers from 1.0 to 2.0
Author: William Carey
Date: 27-09-16 */

#include <stdio.h>
int main()
{
    float top1, top2, top3, top4, top5, top6, top7, top8, top9, top10, top11;
    
    top1= 1.0;
    top2= 1.1;
    top3= 1.2;
    top4= 1.3;
    top5= 1.4;
    top6= 1.5;
    top7= 1.6;
    top8= 1.7;
    top9= 1.8;
    top10= 1.9;
    top11= 2.0;
    
    top11= (top11 + top10 + top9 + top8 + top7 + top6 + top5 + top4 + top3 + top2 + top1)/11;
    
    printf("top11 contains %f",top11);
    
    getchar();
    
    return(0);
}
    