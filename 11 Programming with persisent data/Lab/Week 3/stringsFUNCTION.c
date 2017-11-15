#include <stdlib.h>
#include <stdio.h>
#include <string.h>

main()
{
	int i;
	char str1[30];
	char str2[30];
	char str6[]="dymamic array, the size is not specified, it is when the string is initialized and it represent a limit for the string!";


	//Initialization of a string, USE strcpy!!
	strcpy(str1,"I am Mary");
	strcpy(str2,"I am John");
	//DO NOT DO : str1="I am Mary" !!!!!!!


	//print using %s
	printf("%s\n", str1);


	printf("%s\n", str6);
	strcpy(str6,"I can assign new text to str6, but not longer than the initialized text!");
	printf("%s\n", str6);


	//len of a string
	i = strlen(str1);
	printf("Len: %i \n",i);

	//Comparison of strings - USE STRCMP
	i = strcmp(str1, str2);  //value is 0 if they are the same!!
	printf("Result of Comparison: %i",i);
	//how to compare two strings
	if(strcmp(str1, "I am Mary")==0)
	{printf("\nThe same!");}
	//DO NOT DO if (str1==str2) OR if (str1=="I am Mary")

	//Copy a string
	//char *strcpy(char *dst, char *src);
	char str3[20];	// need space for chars in str, plus for terminating '\0' char
	strcpy(str3, str2);
	printf ("\nValue of str3: %s",str3);

	strcpy(str3, "I am Mark!!");
	printf ("\nValue of str3: %s",str3);

	//Join 2 strings
	//char *strcat(char *dst, char *src)  // append chars from src to end of dst
	strcat(str1, str2);
	printf ("\nValue after concat: %s \n",str1);

	//Search for substring
	//char *strstr(char *string, char *substr); search for second string into the first string
												// NULL if the string is not found, otherwise a pointer to the position of the substring

	if (strstr(str2,str3)==NULL)  //NULL = no matching
	{ printf("Not found \n");}
	else
	{ printf("found \n");}

	//GET THE position of a substring
	char str4[10];
	strcpy(str4,"Mary");
	char * pos;
	if (strstr(str1,str4)==NULL)  //NULL = no matching
	{ printf("Not found \n");}
	else
	{ pos = strstr(str1,str4);
	printf("found at position %d\n",pos-str1);} //you can subtract 2 pointers


	return 0;}
