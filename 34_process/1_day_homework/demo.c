/*
 *  author : zeng xinag feng
 *  content :
 *
 *  time : 2018 - 2 - 21 17:01
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>


int main(int argc,char** argv)
{
#if 1
	pid_t pid;
	pid = fork();
	if(pid < 0){
		exit(-1);
	}else if(pid>0)
	{
		//child
		char ch;
		ch = getchar();
		getchar();
		printf("child :%c \n",ch);
		printf("end child\n");
		exit(0);	
	}else{
		//parent
		char ch;
		ch =getchar();
		getchar();
		printf("praent :%c \n",ch);
		printf("end praent\n");
		waitpid(pid,NULL,0);
		exit(0);
	}
#endif
	return 0;
}

