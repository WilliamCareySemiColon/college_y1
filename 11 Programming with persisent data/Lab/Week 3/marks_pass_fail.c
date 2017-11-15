#include <stdio.h>
#include <stdlib.h>

int main()
{
  FILE *fp;
  FILE *fpass;
  FILE *ffail;

  char student[20];
  int mark;
  
  fp = fopen("marks.txt","r");
  if (fp ==NULL) {
    printf("Cannot open file.\n");
    exit(1);
  }
 
  fpass = fopen("pass.txt","w");
  if (fpass ==NULL) {
    printf("Cannot open file.\n");
    exit(1);
  }
  
  ffail = fopen("fails.txt","w");
  if (ffail ==NULL) {
    printf("Cannot open file.\n");
    exit(1);
  }
    
  
	while (fscanf(fp, "%s" "%i", student , &mark) != EOF) {
		if (mark>=40)
		{fprintf(fpass,"%s \n",student);}
		else
		{fprintf(ffail,"%s \n",student);}
	
		}  //end while
	
	fclose(fp);
	fclose(fpass);
	fclose(ffail);
	
  return 0;}
