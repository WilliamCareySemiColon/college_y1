/*Description :To print out the contents of array
postion number 9 and to diplay it after two for loops
Author : William Carey
Date: 08-11=2016
*/

# include <stdio.h>

#define array_size 10
#define starting_point 9

int main()
{
    int a [array_size] = {0,};
    int i = 0;

    for (i = 0; i < array_size; i++ )
    {
        a[i] = starting_point - i;
    } //end first for loop

    //Time to reassign each variable in the arrays

    for (i = 0; i < array_size; i++)
    {
        a [i] = a [a [i] ];
    } //end second for loop

    printf("%d is the number in the nineth postion of the array",a[8]);

    fflush(stdin);

    getchar();

    return(0);
} //end main
