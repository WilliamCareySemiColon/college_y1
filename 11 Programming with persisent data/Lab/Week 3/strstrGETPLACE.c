#include <stdio.h>
#include <string.h>
#include <stdlib.h>
main ()
{
  char string[55] ="This is a test string for testing";
  char *p;
  p = strstr (string,"test");
  if(p)
  {
    printf("string found\n" );
    printf ("First occurrence of string \"test\" in \"%s\" is"\
           " \"%s\"",string, p);
  }
  else printf("string not found\n" );
  
}