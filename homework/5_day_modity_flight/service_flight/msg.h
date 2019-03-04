#ifndef _MSG_H_
#define _MSG_H_

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>


struct msgbuf{
      long mtype;
      int mtext;
};

key_t get_key(int key)
{
      return ftok("/",key);
}

static inline int comm_msgget(key_t key,int msgflg)
{
      return msgget(key,msgflg);
}

int create_msgget(key_t key)
{
      return comm_msgget(key,0666|IPC_CREAT|IPC_EXCL);
}

int get_msgget(key_t key)
{
      return comm_msgget(key,0666);
}

int my_msgsnd(int msqid,void* msgp)
{
      return msgsnd(msqid,msgp,4,0);
}

int my_msgrcv(int msqid,void* msgp)
{
      return msgrcv(msqid,msgp,4,0,0);
}

static inline int comm_msgctl(int msqid,int cmd,void* buf)
{
      return msgctl(msqid,cmd,(struct msqid_ds*)buf);
}

int delete_msgq(int msqid)
{
      return comm_msgctl(msqid,IPC_RMID,NULL);
}

int get_info(int msqid,void *buf)
{
      return comm_msgctl(msqid,IPC_STAT,buf);
}

#endif
