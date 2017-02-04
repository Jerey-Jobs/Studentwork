#include <stdio.h>   
#include <utmp.h>   
#include <fcntl.h>   
#include <unistd.h>   
#include <stdlib.h>   
#include <time.h>   
  
#define SHOWHOST   
 
void showtime(long);  
void show_info(struct utmp *utbufp);  

int main()  
{  
    struct utmp  utbuf;        // read info into here   
    int          utmpfd;       // read from this descriptor   
  
    if( (utmpfd = open(UTMP_FILE,O_RDONLY)) == -1)  
    {  
        perror(UTMP_FILE);     //UTMP_FILE is in utmp.h   
        exit(1);  
    }  

    while( read( utmpfd,&utbuf,sizeof(utbuf)) == sizeof(utbuf))  
        show_info(&utbuf);  

    close(utmpfd);  
    return 0;  
}  

void show_info(struct utmp *utbufp)  
{  
    if(utbufp->ut_type != USER_PROCESS)  
        return ;  

    printf("%-8.8s",utbufp->ut_user);  
    printf(" ");  
    printf("%-8.8s",utbufp->ut_line);  
    printf(" ");  
  //  showtime( utbufp->ut_time);  
    printf("%12.12s",ctime(&(utbufp->ut_tv).tv_sec)+4);   
    printf(" ");  

#ifdef SHOWHOST   
    if(utbufp->ut_host[0] != '\0')  
	printf("(%s)",utbufp->ut_host);  
#endif   
    printf("\n");  
}  

void showtime(long timeval)  
{  
    char *cp;  
    cp = ctime(&timeval);  
    printf("%12.12s",cp + 4);  
} 
