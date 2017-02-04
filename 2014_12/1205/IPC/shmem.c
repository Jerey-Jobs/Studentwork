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
/* �����ڴ� */

int main(int argc,char **argv) 
{ 
	int shmid; 
	char *p_addr,*c_addr; 
	
	if(argc!=2) 
	{ 
		fprintf(stderr,"Usage:%s\n\a",argv[0]); 
		exit(1); 
	}

	/* ���������ڴ� */	
	if((shmid=shmget(IPC_PRIVATE,1024,PERM))==-1) 
	{ 
		fprintf(stderr,"Create Share Memory Error:%s\n\a",strerror(errno)); 
		exit(1); 
	} 

	/* �����ӽ��� */
	if(fork()) // ������д
	{ 
		p_addr=shmat(shmid,0,0); 
		memset(p_addr,'\0',1024); 
		strncpy(p_addr,argv[1],1024);
		wait(NULL); // �ͷ���Դ,��������ֹ״̬
		exit(0); 
	} 
	else       // �ӽ��̶�
	{ 
		sleep(1); // ��ͣ1��		
		c_addr=shmat(shmid,0,0); 
		printf("Client get %p\n",c_addr); 
		exit(0); 
	} 
} 
