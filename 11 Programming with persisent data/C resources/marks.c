#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  FILE *fp;
  char student[20];
  int mark;
  
  fp = fopen("marks.txt","r");
  if (fp ==NULL) {
    printf("Cannot open file.\n");
    exit(1);
  }
	while (fscanf(fp, "%s" "%i", student , &mark) != EOF) {
		if (mark >= 40) 
			{printf("Student %s got %i and passed!\n", student);}
		else
			{printf("Student %s got %i and failed!\n", student);}		
		}  
	fclose(fp);
  return 0;}


