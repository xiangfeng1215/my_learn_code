/*
*
*			receive data of msg
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
	char buffer[BUFSIZ];
	msgid = msgget(ftok("/",25),0666|IPC_CREAT);
	if(msgid < 0){
		fprintf(stderr,"msgget failed with error: %d \n",errno);
		exit(EXIT_FAILURE);
	}
	while(runing){
		printf("Enter some text:");
		fgets(buffer,BUFSIZ,stdin);
		some_data.my_msg_type = 1;
		strcpy(some_data.some_text,buffer);
		if(msgsnd(msgid,(void *)&some_data,BUFSIZ,0) < 0){
			fprintf(stderr,"msgrcv failed with error : %d \n",errno);
			exit(EXIT_FAILURE);
		}
		if(strncmp(some_data.some_text,"end",3) == 0){
			runing = 0;
		}
	}//end while
	exit(EXIT_SUCCESS);
	return 0;
}
