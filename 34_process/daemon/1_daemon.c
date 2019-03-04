#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <signal.h>

int main(void){
	pid_t pid;
	FILE* fp;
	time_t result;
	pid = fork();
	if(pid < 0 ){
		exit(-1);
	}
	else if(pid == 0 ){
		if(setsid() < 0){
			perror("");
			exit(-1);
		}
		chdir("/home/zxf/Desktop/test/34_process/daemon/");
		(void)signal(SIGCHLD,SIG_IGN);
		umask(0);
		int i;
		for(i = 0;i <getdtablesize();i++){
			close(i);
		}
		while(1){
			result = time(NULL);
			fp = fopen("/home/zxf/Desktop/test/34_process/daemon/time.log","a");
			if(!fp){
				exit(-1);
			}
			fprintf(fp,"%s\n",asctime(localtime(&result)));
			fclose(fp);
			sleep(2);
		}//end while
	}
	else{
		//parent
		exit(1);
	}
	return 0;
}
