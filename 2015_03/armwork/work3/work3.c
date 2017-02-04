#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    int val;
    int stat;
    pid_t child;
    printf("\ntry to creat new process");
    child = fork();

    switch(child)
    {
    	case -1: 
    	    printf("error fork\n");
    	    exit(EXIT_FAILURE);

    	case 0:
    	    printf("this is child\n");
    	    printf("\tchild pid is %d \n",getpid());
    	    printf("\tchild pid is %d \n",getpid());

    	    exit(EXIT_SUCCESS);

    	default:
    	    waitpid(&child,&stat,0);
    	    printf("This is parent.\n");
    	    printf("\tchild pid is %d\n",getpid());
    	    printf("\tchild ppid is %d \n",getpid());
    	    printf("\t child exited with %d\n",stat);
    } 
    exit(EXIT_SUCCESS);

}


