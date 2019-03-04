/*
*
*			send data of msg
*
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <errno.h>
#include <unistd.h>
struct my_msg_st{
	long int my_msg_type;
	char some_text[BUFSIZ];
};

int main(int argc,char **argv)
{
	printf("BUFSIZ: %d\n",BUFSIZ);
	int runing = 1;
	int msgid;
	struct my_msg_st some_data;
	long int msg_to_receive = 0;
	msgid = msgget(ftok("/",25),0666|IPC_CREAT);
	if(msgid < 0){
		fprintf(stderr,"msgget failed with error: %d \n",errno);
		exit(EXIT_FAILURE);
	}
	while(runing){
		if(msgrcv(msgid,(void *)&some_data,BUFSIZ,msg_to_receive,0) < 0){
			fprintf(stderr,"msgrcv failed with error : %d \n",errno);
			exit(EXIT_FAILURE);
		}
		printf("you wrote: %s \n",some_data.some_text);
		if(strncmp(some_data.some_text,"end",3) == 0){
			runing = 0;
		}
	}//end while
	if(msgctl(msgid,IPC_RMID,0) < 0){
		fprintf(stderr,"msgctl ipc_rmid failed!\n");
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
	return 0;
}
