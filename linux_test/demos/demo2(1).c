#include <stdio.h>

#include <sys/msg.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <unistd.h>

struct msg_buf
{
    int mtype;
    char data[255];
};

int main()
{
    key_t key;
    int msgid;
    
    struct msg_buf msgbuf;

    key = ftok("/tmp/4", 'b');
    msgid = msgget(key, IPC_CREAT|0666);

    msgbuf.mtype = 1;
    strcpy(msgbuf.data, "no message!");

    if(fork())
    {
        int count = 0;

        while(1)
        {
            count = msgrcv(msgid, &msgbuf, sizeof(msgbuf.data), 1, IPC_NOWAIT);
            msgbuf.data[count] = '\0';
            printf("%drecv msg = %s\n", count, msgbuf.data);
            sleep(2);
        }
    }
    else
    {
        int ret = 0;
        while(1)
        {
            scanf("%s", msgbuf.data);
            msgbuf.mtype = 1;
            ret = msgsnd(msgid, &msgbuf, sizeof(msgbuf.data), IPC_NOWAIT);
            printf("send = %d\n", ret);
        }
    }

    return 0;
}
