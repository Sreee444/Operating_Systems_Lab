#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

void main()
 {
   char*args[] = {"./exec",NULL};
   execvp(args[0],args);
   printf("\n END");
 }
