#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main()
{
  int f;
  char p[100];
  f = open("a.txt",O_RDWR | O_CREAT | O_APPEND,0644);
  fgets(p,256,stdin);
  if(write(f,p,strlen(p)) < 0)
  {
     perror("write file");
  }
  close(f);
  return 0;
}
