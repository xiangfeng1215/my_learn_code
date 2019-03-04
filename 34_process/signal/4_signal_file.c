
/*
*
*
*/

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void sig_func(int signo){
	
	exit(1);
}

int main(void){
	printf("wait the signal coming.....\n");
	pid_t pid;
	FILE* fp = fopen("./pid.txt","r");
	if(!fp){
		printf("open pid.txt failed\n");
		while(!fp){
			sleep(1);
			fp = fopen("./pid.txt","r");
		}
	}
	fscanf(fp,"%d",&pid);
	fclose(fp);
	kill(pid,SIGINT);
	return 0;
}
