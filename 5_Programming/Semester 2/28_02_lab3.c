//To display how a character array can be intialised in two different ways

#include <stdio.h>

void main()
{
	char var_1 [] = "Hello";
	char var_2 [] = {'B','y','e','\0'};
	char var_3 [] = {'G','o','o','d'};

	puts(var_1);
	puts(var_2);
	printf("%s",var_3);
	printf("%c",var_2[3]);
}