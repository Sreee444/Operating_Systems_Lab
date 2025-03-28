#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include<stdio.h>
#include<stdlib.h>

void main()
 {
    pid_t childpid = fork();
     
    if(childpid == 0)
     {
       printf("This is the Child Process\n");
       printf("The Child process ID is : %d \n", getpid());
       printf("The Parent process ID is : %d\n\n",getppid());
     }
     
    if(childpid > 0)
     {
       printf("This is the Parent process \n");
       printf("The Parent process ID is : %d\n",getpid());
       printf("The Child process ID is : %d \n\n", childpid);
       
       wait(NULL);
       
     }
     
    if ( childpid < 0)
     {
       printf("Child Process Creation is Unsuccessfull\n");
     }
     
    exit(0);
 }
