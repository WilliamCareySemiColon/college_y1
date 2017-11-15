#include <stdlib.h>
#include <stdio.h>

main()
{
	FILE * f;
	long  width;
	long  heigth;
	
	if((f=fopen("image.bmp","rb"))==NULL){
		printf("open read file error.\n");
		exit(1);
	}

	//reading the header
	fseek(f,18,SEEK_CUR);
	fread(&width,  sizeof(long),1, f); 
	fread(&heigth, sizeof(long),1, f); 
	
	printf("Heigth: %d , width: %d \n",heigth,width);
	fclose(f);
	
	return 0;
}