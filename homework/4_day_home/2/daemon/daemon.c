#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <unistd.h>
#include "msg.h"
#include <sys/stat.h>
#include <fcntl.h>

struct daemon_data{
	int pid;
	char data[512];
};

int main(int argc,char** argv)
{
	int msg_key = get_key(6);
	int msgid = getorcreate_msgget(msg_key);
	if(msgid < 0){
		perror("msgid create");
		exit(-1);
	}	
	FILE* fp;
	pid_t pid  = fork();
	if(pid < 0){
		perror("");
		exit(EXIT_FAILURE);
	}
	else if(pid > 0){
	//	wait(NULL);
		exit(0);
	}
	else if(pid == 0){
#if 1
		setsid();
		chdir("/");
		umask(0);
		int i =0;
		for(i = 0;i < getdtablesize();i++){
			close(i);
		}
#endif
		fp = fopen("/home/zxf/Desktop/test/homework/4_day_home/2/daemon/mydaemon.txt","a");
		struct daemon_data data;
		struct msgbuf msg_buf;
		struct msqid_ds buf;
		while(1){

			get_info(msgid,&buf);
			if(my_msgrcv(msgid,&msg_buf) < 0){
				perror("my_msgrcv");
				exit(-1);
			}

			data.pid=buf.msg_lspid;
			strncpy(data.data,msg_buf.mtext,6);
			if((strncmp(data.data,"ABCD",4) == 0)||(strncmp(data.data,"1234",4) == 0)){	
			fprintf(fp,"pid: %d , data : %s \n",data.pid,data.data);
			fflush(fp);
			//fprintf(stdout,"pid: %d , data : %s \n",data.pid,data.data);
			}
			sleep(1);

			if(strncmp(data.data,"quit",4) == 0){
				break;
			}//end if

		}//while
		(void)delete_msgq(msgid);
		exit(EXIT_SUCCESS);
	}//end if for pid
	return 0;
}
