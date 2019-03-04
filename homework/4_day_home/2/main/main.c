#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "sem.h"
#include "msg.h"
#include <unistd.h>
#define MAX_SIZE 4096
int main(int argc,char** argv)
{
	int sem_key = semGetKey(22);
	int semid = semCreate(sem_key,1);
	(void)semSetValue(semid,0,1);

	int msgid_key = get_key(6);
	int msgid = get_msgget(msgid_key);
	if(msgid < 0){
		perror("");
		exit(-1);
	}
	struct msgbuf msg_buf;
	
	pid_t pid = fork();

	if(pid < 0){
		perror("");
		exit(EXIT_FAILURE);
	}
	else if(pid == 0){
		printf("this is chlid\n");
		char *ch = "ABCD";
		/**********************/
		int cnt = 0;
		while(cnt < 10){
		//	printf("this is chlid while\n");
			semWait(semid,0);

			strncpy(msg_buf.mtext,ch,5);
			msg_buf.mtype = 10;
			if(my_msgsnd(msgid,&msg_buf) < 0){
				perror("my_msgsnd");
			}
			printf("msg_buf.mtext :%s\n",msg_buf.mtext);
			sleep(1);
			cnt ++;
			semSignal(semid,0);
		}//end while
		/********************/
		exit(0);
	}
	else if(pid > 0){
		char *ch = "1234";
		printf("this is parend \n");
		int cnt = 0;
		while(cnt < 10){
		//	printf("this is parend while \n");
			/**********************/
			semWait(semid,0);

			strncpy(msg_buf.mtext,ch,5);
			msg_buf.mtype = 10;
			if(my_msgsnd(msgid,&msg_buf) < 0){
				perror("");
			}
			printf("msg_buf.mtext :%s\n",msg_buf.mtext);
			sleep(1);
			cnt++;
			semSignal(semid,0);

			/********************/
		}//end while

	}//end if
	return 0;
}
