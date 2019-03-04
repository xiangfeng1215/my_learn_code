/*
*  dammon
*
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <signal.h>
#include <time.h>
#define ABFIFO "/tmp/abfifo"
#define DAMMON_TO_AFIFO "/tmp/dammontoafifo"
#define DAMMON_TO_BFIFO "/tmp/dammontobfifo"
#define MAX_SIZE 256
int main(int argc,char** argv)
{
	pid_t pid;
	pid = fork();
	if(pid < 0){
		perror("");
		exit(-1);
	}
	else if(pid > 0)
	{
		printf("parent exit\n");
		exit(0);
	}
	else{
		setsid();
		chdir("/");
		umask(0);
		int i=0;
		for(i = 0;i < getdtablesize(); i++){
			close(i);
		}
		while(1){
			int fd;
			int nread;
			char ch;
			if(access(ABFIFO,F_OK) < 0){
				if(mkfifo(ABFIFO,0666) < 0){
					perror("");
					exit(-1);
				}
			}
			while(1){
				if((fp = open(DAMMONFIFO,O_RDONLY)) < 0){
					perror("open");
					exit(-1);
				}
				while(1){
					if((nread = read(fd,&ch,1)) > 0){
						close(fp);
						if( ch == 'a'){
							fd = open(DAMMONFIFO,O_WRONLY);
							write(fd,);
						}
					}
				}
				close(fd);
			}//end while
			return 0;
		}


	}//end while

}
return 0;
}
