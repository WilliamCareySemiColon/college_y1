#include <stdio.h>
#include <string.h>

int main (int argc, char *argv[])
{
	int ret;
    FILE *fp;
	char scramble[50];
	char origin[50];
	char ext[] = ".sbl";
	
    printf("Enter a file\n");
    gets(origin);
    
    strcpy(scramble, argv[1]);
    strcpy(origin, argv[1]);
	strcat(scramble, ext);
   
    ret = rename(origin, scramble);
	
    if(ret == 0) 
    {
      printf("File renamed successfully");
    }
    else 
    {
      printf("Error: Unable to rename the file");
    }
   
    return(0);
}
