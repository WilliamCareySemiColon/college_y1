/*Description: To get the user to input a character and to display back whether it is a vowel or not
Author: William Carey
Date: 11-10-2016 */

#include <stdio.h>

int main()
{
    char let = '0';
    
    printf("Enter any charcter from the keyboard\n");
    let = getchar();
    //Starting the switch statement
    
    switch(let)
    {
        case'a':
        case'A':
        {
            printf("you entered an a, an vowel\n");
            break;
        } // End of case a
       
        case 'e':
        case 'E':
        {
            printf ("you entered an e, an vowel\n");
            break;
        }    //End of case e
        
        case 'i':
        case 'I':
        {
            printf("you entered an i, an vowel\n");
            break;
        }    //End of case i
        
        case 'o':
        case'O':
        {
            printf("you entered an o, an vowel\n");
            break;
        }  //End of case o
        
        case 'u':
        case'U':
        {
            printf("you entered an u, an vowel\n");
            break;
        }   //End of case u
        
        default:
        { 
            printf("you input an non-vowel\n");
            break;
        } //End default
    
    } //End Switch
    
    flushall();
    getchar();
    return(0);
}// End main
            
            
            
            
            
            
            
            