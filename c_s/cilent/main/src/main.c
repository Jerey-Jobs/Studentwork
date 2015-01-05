#include "../../include/myhead.h"

int power = 0;

extern void *read_message(void *arg);

int main(int argc, char *argv[]) 
{ 

	char buffer[1024]; 
	struct sockaddr_in server_addr; 
	struct hostent *host; 
	int nbytes; 

   
	if(argc!=2) 
	{ 
		fprintf(stderr,"Usage:%s hostname \a\n",argv[0]); 
		exit(1); 
	} 

	if((host=gethostbyname(argv[1]))==NULL) 
	{ 
		fprintf(stderr,"Gethostname error\n"); 
		exit(1); 
	} 


	if((sockfd=socket(AF_INET,SOCK_STREAM,0))==-1)
	{ 
		fprintf(stderr,"Socket Error:%s\a\n",strerror(errno)); 
		exit(1); 
	} 

	bzero(&server_addr,sizeof(server_addr)); 	
    server_addr.sin_family=AF_INET;     
    server_addr.sin_port=htons(portnumber);  
		
    server_addr.sin_addr.s_addr=inet_addr(argv[1]); 

	if(connect(sockfd,(struct sockaddr *)(&server_addr),sizeof(struct sockaddr))==-1) 
	{ 
		fprintf(stderr,"Connect Error:%s\a\n",strerror(errno)); 
		exit(1); 
	} 

    pthread_t id;
	pthread_create(&id,NULL,(void *)read_message,(void *)&sockfd);

    int cmd = 0;



    while(1)
	{
        if(msg.state != LINE && msg.state != CHAT_BAN)
        {

            log_menu();

            cmd = check_putin();
        
            switch(cmd)
            {
                case LOG:cilent_log();break;
                case REGIST:cilent_regist();break;
            }    
        }
        else if(((msg.state == LINE) || (msg.state == CHAT_BAN)) && (power == 0))
        {
            
            menu();
            cmd = check_putin();
        
            switch(cmd)
            {
                case SHOW:show();break;
                case CHAT:chat();break;
                case BROAD:broad();break;
                case HI:hi(); break;
                case CPWD:cpwd();break;
                case RNAME: rname();break;
                case LOGOFF:logoff();    break;
                case EXIT: exit(1);break;
            }

        }

        else if((msg.state == LINE) && (power == 1))
        {
            menu_admin();
            cmd = check_putin();
        
            switch(cmd)
            {
                case SHOW:show();break;
                case CHAT:chat();break;
                case BROAD:broad();break;
                case HI:hi(); break;
                case CPWD:cpwd();break;
                case RNAME: rname();break;
                case LOGOFF:logoff();    break;
                case EXIT: exit(1);break;
                case KICK: kick();break;
                case BAN: ban();break;
                case RID_PEOPLE:rid_people();break;
            }
        }

	}

	close(sockfd); 
	exit(0); 
} 
