//no comments

#include <stdio.h>
#include <string.h>

#define size 11

void main()
{
	//char name [] = {'r','o','b','e','r','t'}; - should be null terminated
	char name [size] = {'r','o','b','e','r','t','\0'};

	puts(name);

	printf("please enter your name.\n");
	scanf("%s",name);
	strcpy(name,"Philip");
	*(name + 5) = 'a';
	

	//puts(name); - array is not null - terminated, leading to potential crash
	//scanf("%s",&name); the array itself is not null terminated and where is the printf function before it
	//strcpy(name,"Philip"); - may not have enough space to store all the characters in this word
	//*(name + 5) = "a"; - a single character is in single quatoation marks
	//name - "Philip"; you cannot take out strings from other strings by ninus them out

}