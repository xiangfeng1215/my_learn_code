

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <stdlib.h>
#include <signal.h>

int flat = 0;

void my_func(int sign_no){
	if(sign_no = SIGINT){
		printf("signint coming here.\n");
	}
	(void)signal(SIGINT,SIG_DFL);
}

int main(void){
	printf("wait the signal coming.....\n");
	struct sigaction act,oldact;
	
	pid_t pid;
	pid = fork();
	if(pid < 0){
		exit(-1);
	}else if(pid == 0)
	{
		//child
		printf("start child\n");
		sigaction(SIGINT,&act,&oldact);
		sleep(10);
		//signal(SIGINT,my_func);
		//alarm(5);
		//pause();//系统默认动作为终止该进程，程序之后的内容是不打印的
		printf("end child\n");
		exit(0);
	}else if(pid > 0){
		//parent
		freopen("/dev/pts/5","w",stdout);
		printf("parent\n");
		printf("i start sleep\n");
		sleep(5);
		printf("i had sleep 5 s\n");
		kill(pid,SIGINT);
		wait(NULL);
		printf("end parent\n");
		exit(1);
	}
	printf("hello\n");
	return 0;
}
