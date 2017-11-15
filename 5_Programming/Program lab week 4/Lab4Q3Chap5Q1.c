/* Description: To write an massive if-else statement as a switch statement
Author: William Carey
Date: 11-10-2016 */

#include <stdio.h>

int main()
{
    char marriage_status;
    
    printf("Please enter your status\n");
    
    marriage_status = getchar();
    
    //Starting the marriage switch
    
    switch(marriage_status)
    {
        case 's':
        case 'S':       //Single statement
        {
            printf("Single");
            break;
        } //End single statement
        
        case 'm':
        case 'M':      //Married statement
        {
            printf("Married");
            break;
        }   //End married statement
        
        case 'w':
        case 'W':      //Widowed statement
        {
            printf("Widowed");
            break;
        }     //End widowed statement
        
        case 'e':
        case 'E':      //Seperated statement
        {
            printf("Separated");
            break;
        }     //End Separated statement
        
        case 'd':
        case 'D':    //Divorced statement
        {
            printf("Divorced");
            break;
        }   // End divorced statement
        
        default:
        {
            printf("error: invalid code");
        }
    }    //End switch statement
    flushall();
    getchar();
    return(0);
} //End Main