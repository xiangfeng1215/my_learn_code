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

void sig_func(int signo){
	
	exit(1);
}

int main(void){
	printf("wait the signal coming.....\n");
	pid_t pid;
	FILE* fp = fopen("./pid.txt","w+");
	if(!fp){
		perror("fopen");
		exit(-1);
	}
	fprintf(fp,"%d",getpid());
	fclose(fp);
	(void)signal(SIGINT,sig_func);
	while(1){
		printf("i wait the sigint come\n");
		sleep(1);
	}
	return 0;
}
