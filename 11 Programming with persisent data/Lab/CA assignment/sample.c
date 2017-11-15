#include <stdio.h>
#include <string.h>

void main()
{
	char message [] = "Hello world";
	char *sub_message = strstr(message,"world");

	printf("Two messages are \"%s\" and \"%s\" and that is all",message, sub_message);
}
