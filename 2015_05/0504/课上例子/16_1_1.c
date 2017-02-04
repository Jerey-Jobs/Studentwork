#include <stdlib.h>					
#include <stdio.h>					
#include <sys/types.h>					
#include <sys/stat.h>					
#include <string.h>					
								
int main()
{
   int fd[2],cld_pid,len;
   char buf[200];

   if(pipe(fd)==-1)
   {
       perror("");
       exit(1);
   }

   if ((cld_pid = fork()) == 0) {
      close(fd[1]);
      len = read(fd[0],buf,sizeof(buf));
      buf[len] = '\0';
      printf("recv:%s\n",buf);
      exit(0);
   }
   else
   {
      close(fd[0]);
      sprintf(buf,"parent: hello %d",cld_pid);									
      write(fd[1],buf, strlen(buf));
      close(fd[1]); 	
      exit(0);
   }

   return 0;
}
