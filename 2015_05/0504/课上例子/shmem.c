#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 2048

int main()
{
    pid_t pid;
    int shmid;
    char *shm_addr;
    char flag[] = "WROTE";
    char buff[100] = {0};

    //create share memory
    if ((shmid = shmget(IPC_PRIVATE, BUFFER_SIZE, 0666)) < 0)
    {
        perror("shmget");
        exit(1);
    }

  //  system("ipcs -m");

    pid = fork();
    if (pid == 0) 
    {
       //map share memory
       if ((shm_addr = shmat(shmid, 0, 0)) == (void*)-1)
       {
           perror("Child: shmat");
           exit(1);
       }
  
       /* 通过检查在共享内存的头部是否标志字符串"WROTE"来确认父进程已经向共享内存写入有效数据 */
       while (strncmp(shm_addr, flag, strlen(flag)))
       {
           printf("Child: Wait for enable data...\n");
           sleep(5);
       }

       strcpy(buff, shm_addr + strlen(flag));
       printf("Child: Shared-memory :%s\n", buff);  

       if ((shmdt(shm_addr)) < 0)
       {
           perror("shmdt");
           exit(1);
       }
  
       //delete share memory
       if (shmctl(shmid, IPC_RMID, NULL) == -1)
       {
           perror("Child: shmctl(IPC_RMID)\n");
           exit(1);
       }
       printf("child process end!\n");
     //  system("ipcs -m");
    }
    else //parent process
    {
        if ((shm_addr = shmat(shmid, 0, 0)) == (void*)-1)
        {
            perror("Parent: shmat");
            exit(1);
        }

        sleep(1);
        printf("\nInput some string:\n");
     	fgets(buff, BUFFER_SIZE, stdin);
        strncpy(shm_addr + strlen(flag), buff, strlen(buff));
        strncpy(shm_addr, flag, strlen(flag)); 

        if ((shmdt(shm_addr)) < 0)
        {
            perror("Parent: shmdt");
            exit(1);
        }

    //    system("ipcs -m");
        waitpid(pid, NULL, 0);        
        printf("Finished\n");
   }
}
