#include <stdlib.h>
#include <stdio.h>
#include <time.h>
main()
{
  clock_t begin, end;
  double time_spent;
	FILE * filer;
	FILE * filew;
	int numr,numw;
	char buffer[100]; // used to read the data, size 100 bytes

  begin = clock(); //start the clock

	// Open the source file for reading
	if((filer=fopen("C:\\PPD2015\\text.txt","rb"))==NULL){
		printf("open read file error.\n");
		exit(1);}
	// Open the destination file for writing
	if((filew=fopen("C:\\PPD2015\\big_text_bin.txt","wb"))==NULL){
		printf("open write file error.\n");
		exit(1);}
	while(feof(filer)==0){	  // while not end of file for the source file
		numr=fread(buffer,1,100,filer);     //read 100 bytes
		numw=fwrite(buffer,1,numr,filew);   //write 100 bytes
		if(numw!=numr){		        //check if any error writing
			printf("write file error.\n");
			exit(1);}
	}	
	fclose(filer); fclose(filew);	
  end = clock(); //stop the clock
//compute the number of seconds. CLOCKS_PER_SEC is a constant in time.h
  time_spent = (double)(end - begin) / CLOCKS_PER_SEC; 
  printf("%f",time_spent); 
//if you want to print the time (in seconds), remember it is a float
  return 0;}