/* Description: To take three readings in Fahrenheit,
convert them to celsius and display them both to the user
Author: William Carey
Date: 01-10-2016
*/

#include <stdio.h>

#define array_size 3

int main()
{
    float fanhriet_reading [array_size] = {0,};
    float celsius_reading [array_size] = {0,};
    int counter = 0;

    printf("Please input three readings in fanhriet and I show you both fanhriet and celsius\n");

    for (counter = 0; counter != array_size; counter ++)
    {
        scanf("%f",&fanhriet_reading [counter]);
    } //end inputting for loop

    for (counter = 0; counter != array_size; counter ++)
    {
        celsius_reading [counter] = ((fanhriet_reading [counter] - 32.0)*( 5.0 / 9.0));
    } //end converting for loop

     for (counter = 0; counter != array_size; counter ++)
    {
        printf("\nfanhriet <- %.2f = %.2f -> celcuis\n",fanhriet_reading[counter], celsius_reading[counter]);
    } //end reproducing for loop

    fflush(stdin);
    getchar;
    return(0);
} //end main
