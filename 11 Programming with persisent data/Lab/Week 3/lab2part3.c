/* Program description: Lab2 Part3
    by: Chris Clarke and Will Carey
*/

#include <stdio.h>
#include <string.h>

//Header files
#define SIZE 100
#define DOUBLE 200

int main()
{
    //File variable for reading in a file name given
    FILE *fp;
    //Strings for reading in a document name, a word in it 
    char file_name [SIZE], word [SIZE], line [SIZE];
    int count = 1;
    int counting = 0;
    int position = 1;
    int error_message  = 1;
   
    printf("Please enter the file's name\n");
    gets(file_name);

    fp = fopen(file_name,"r");

    if (fp == NULL)
    {
        printf("Can't open file.\n");
    }//end if

    else
    {
        //get user input
        printf("Please name the word you want to find in this file.\n");
        scanf("%s",word);

        while (fgets(line, SIZE, fp) != NULL)
        {
            //We found the word we have been looking for
            if (strstr(line,word))
            {
                printf("The word you are looking for is in the line ");
                puts(line);
                printf("and it is in line number %d",count);
                //Getting the postion of the word in the word
                while (word [1] != line [counting])
                    {   
                        //Making sure we get the postion right
                        if (line [counting] == ' ')
                        {
                            position++;
                        }
                        //so we can check each character
                        counting++;
                    }//end while loop
                    
                printf(" position %d\n\n",position);
                //reseting the variables so they can continue to do the function repeatly
                position = 1;
                counting = 0;
                //Making sure the error message is not displayed
                error_message--;
            }//end if statement
            count++;
            error_message++;
        }//end while
        
        //Displaying error message if the word is not found
        if (error_message == count)
        {
            printf("Word \"%s\" is not in this document",word);
        }
        
     
        fclose(fp);

    }//end else
    flushall();
  

    getchar();
    
    return 0;

}//end main()