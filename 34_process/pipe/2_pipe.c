#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

int flag = 0;

void sig_A_func(int sig)
{
	flag = 1;
}

int main(void)
{     
	int pipefdA[2];
	int pipefdB[2];
	int pipefdC[2];
	if(pipe(pipefdA) < 0){
		perror("pipe A");
		exit(-1);
	}
	if(pipe(pipefdB) < 0){
		perror("pipe B");
		exit(-1);
	}
	if(pipe(pipefdC) < 0){
		perror("pipe C");
		exit(-1);
	}
	pid_t pid = fork();
	if(pid < 0){
		perror("");
		return -1;
	}
	else if(pid == 0){
		printf("I am father!\n");
		pid_t new_pid = fork();
		if(new_pid < 0){
			printf("new_pid");
			exit(-1);
		}
		else if(new_pid > 0){
			sleep(10);
			kill(pid,SIGALRM);
			printf("send sign OK!\n");
			wait(NULL);
			exit(0);

		}else if(new_pid == 0){

		}	
	}//end pid > 0 
	else if(pid > 0){
		(void)signal(SIGALRM,sig_A_func);
		while(1){
			if(flag){
				while(1){
					printf("hahaha!\n");
					sleep(1);
				}	
			}
			else
				sleep(1);
		}//end while	  
	}

	return 0;
}



