#include <stdio.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <unistd.h>

struct msg_buf
    {
        int mtype;
        char data[100];
    };
 
int main()
{
        key_t key;
        int msgid;
        int ret;
 
        key=ftok("/tmp/2",'a');
        msgid = msgget(key,IPC_CREAT|0666); 

        if(msgid == -1)
        {
                printf("create error\n");
                return -1;
        }
 
        if(fork())
        {
            char buf[100] = {0};
            struct msg_buf tmp;
            
            tmp.mtype = 1;
            while(1)
            {
                scanf("%s",buf);

                strcpy(tmp.data,buf);

                ret = msgsnd(msgid,&tmp,sizeof(tmp.data),IPC_NOWAIT);
                
                if(ret == -1)
                {
                    printf("send message err\n");
                    return -1;
                }
            }
        }
        else
        {   
             struct msg_buf r_buf;
             memset(&r_buf,0,sizeof(r_buf));
             while(1)
             {
                 ret = msgrcv(msgid,&r_buf,sizeof(r_buf.data),1,IPC_NOWAIT);
                    
                 printf("recv msg =[%s]\n",r_buf.data);
                 sleep(2);
             }
        }
}
