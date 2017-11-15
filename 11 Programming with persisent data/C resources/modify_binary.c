#include <stdlib.h>
#include <stdio.h>

main()
{
	FILE * f;
	int i =0 ; int k = 0;	
	int buffer[1000];
	int buf30[30];
	
	//create a binary file of numbers and put some data in it with a loop
	
	if((f=fopen("numbers.bin","wb"))==NULL){
		fprintf(stderr, "open read file error.\n");
		exit(1);
	}
	
	for (i=0;i<110;i++)
	{
		fwrite(&i,sizeof(int),1,f);    
	}

	fclose(f);
	/********************************/
	
	//open in reading / writing
	if((f=fopen("numbers.bin","r+wb"))==NULL){
		fprintf(stderr, "open read file error.\n");
		exit(1);
	}
	
	//Read the file 1 variable by 1 (each time an int variable)
	//display the content as well
	while (feof(f)==0)
	{
		fread(&i,sizeof(int),1,f);    
		printf("	Num: %d\n",i);
	}
	
	// read all the file in one instruction (well, 
	// actually read 1000 int variables, but the file in our example is less than 1000 int
	fseek(f,0,SEEK_SET); //rewind
	i = fread(buffer,sizeof(int),1000,f);    // i is the number of element reads from the disk
	printf("	Elements Read: %d\n",i);    //i is 110 (actual number of elements on the disk!) not 1000!

	
	//read the file with an array of 30 int variables
	//at each step it reads 30 variables
	//since the file has 110 int variables, last step of the loop reads only 20 variables
	fseek(f,0,SEEK_SET);  //rewind
	while (feof(f)==0)
	{
	i = fread(buf30,sizeof(int),30,f);    // i is the number of element reads from the disk 
	printf("	Elements Read: %d\n",i);  //this will be 30,30,30,20 (30+30+30+20=110)
	}
	
	//change the 5th element 
	fseek(f, 4*sizeof(int)  ,SEEK_SET);
	i=20;
	fwrite(&i,sizeof(int) , 1, f);
	

	printf("	The fifth element should be 20\n"); 
	//print the first 10 numbers, number 5 should be equal to 20	
	for (i=0;i<10;i++)
	{
		fread(&k,sizeof(int),1,f);    
		printf("	Num: %d\n",k);
	}
	
	//multiply by 3 the third number
	fseek(f, 2*sizeof(int) ,SEEK_SET);  //move he pointer before the 3rd element
	fread(&k,sizeof(int),1,f);
	k = k *3 ;
	fseek(f, -sizeof(int) , SEEK_CUR);
	fwrite(&k,sizeof(int),1,f);
	
	printf("	The third should have been multiplied by 3 (2*3=6) \n"); 
	//print the first 10 numbers, the third should have been multiplied by 3	
	fseek(f,0,SEEK_SET); //rewind
	for (i=0;i<10;i++)
	{
		fread(&k,sizeof(int),1,f);    
		printf("	Num: %d\n",k);
	}

	
	return 0;
}