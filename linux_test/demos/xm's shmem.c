#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define PERM S_IRUSR|S_IWUSR

int main(int argc,char **argv) 
{ 
	int shmid; 
	char *p_addr,*c_addr; 

	if((shmid=shmget(IPC_PRIVATE,1024,PERM))==-1) 
	{ 
		fprintf(stderr,"Create Share Memory Error:%s\n\a",strerror(errno)); 
		exit(1); 
	} 

	if(fork())
	{ 
        char buf[1024];

		p_addr = shmat(shmid,0,0); 
        
		memset(p_addr,'\0',1024); 

        while(1)
        {
            scanf("%s",buf);

		    strncpy(p_addr,buf,1024);
        }

		wait(NULL);
		exit(0); 
	} 
	else    
	{ 
		sleep(1); 

		c_addr=shmat(shmid,0,0);

		while(1)
        {
            printf("buf = %s\n",c_addr); 
            sleep(2);
        }
	} 
} 
