// EX.1 - READ A TEXT FILE CHAR BY CHAR
#include <stdio.h>
#include <stdlib.h>

int main()
{
  FILE *fp;   //declare a file pointer variable
  char ch;
  int i;
  int count=0; //counter to count the number of chars (i.e. the size of the file)
  
  fp = fopen("myfile.txt","r");  //open the file, text reading mode
  if (fp ==NULL) {              //test if everything was ok
    printf("Cannot open file.\n");
    exit(1);
  }
  while((ch = fgetc( fp )) != EOF) {
	count++;
	printf("%c", ch);   //print the char just read
  }
  fclose(fp);  //close the file
  printf("\nThe size of the file is: %d",count);
  return 0;
}
