/*Description: A program that takes two intergers and see
if the first can be divisable by the second
Author: William Carey
Date: 13-10-2016
*/

#include <stdio.h>

int main()
{
    int input1 = 0;
    int input2 = 0;
    int answer;

    printf("please enter two whole numbers\n");
    scanf("%d",&input1);
    scanf("%d",&input2);

    //The following is to dertimine if the equation can be evenly divisible(ie-give no remainder)

    answer = input1%input2;

    if (answer == 0)
    {
        printf("your equation gave no remainder, meaning it was divisible");
    } //End "If"" part

    else
    {
        printf("your equation gave a remainder of %d, making the equation inapporiate");
    } //End "Else" part



    getchar();
    return(0);
    }//End Main
