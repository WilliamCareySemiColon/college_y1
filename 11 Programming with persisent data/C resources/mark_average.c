#include <stdio.h>
#include <stdlib.h>

int main()
{
  FILE *fp;
  char student[20];
  int mark;
  int tot=0;
  int num=0;
  fp = fopen("marks.txt","r");
  if (fp ==NULL) {
    printf("Cannot open file.\n");
    exit(1);
  }
	while (fscanf(fp, "%s" "%i", student , &mark) != EOF) {
		{ 
		   printf("%s got %i \n", student,mark);
		   tot = tot + mark;
		   num++;
		}
		}  //end while
	fclose(fp);
	printf("The average marks is %f",(float)tot/num);
  return 0;}


