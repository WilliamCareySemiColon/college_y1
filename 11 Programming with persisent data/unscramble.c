#include <stdio.h>
#include <string.h>

int main (int argc, char *argv[])
{
	int ret;
	int length;
    int i;
	
	char scramble[50];
	char origin[50];
	
    strcpy(scramble, argv[1]);
	strcpy(origin, argv[1]);
	length = strlen(scramble);
	
	for(i = 0; i < 4; i++)
	{
		scramble[length - i] = NULL;
	}
	
   
    ret = rename(origin, scramble);
	
    if(ret == 0) 
    {
      printf("File renamed successfully");
    }
    else 
    {
      printf("Error: unable to rename the file");
    }
   
    return(0);
}
