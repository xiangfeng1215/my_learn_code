#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <signal.h>
#include <time.h>
#define ABFIFO "/tmp/abfifo"
#define DAMMONFIFO "/tmp/dammonfifo"
#define MAX_SIZE 20
int main(int argc,char** argv)
{
	int fd;
	int fp;
	int nread;
	char buf[256];
	if(access(ABFIFO,F_OK) < 0){
		if(mkfifo(ABFIFO,0666) < 0){
			perror("");
			exit(-1);
		}
	}

	if(access(ABFIFO,F_OK) < 0){
		if(mkfifo(DAMMONFIFO,0666) < 0){
			perror("");
			exit(-1);
		}
	}
	while(1){
		if((fp = open(DAMMON,O_WRONLY)) < 0){
			perror("");
			exit(-1);
		}
		if(write(fp,"0",1) < 0){
			print("write dammon failed\n");
		}
		close(fp);
		if(flat == 0){
			if((fd = open(ABFIFO,O_RDONLY)) < 0){
				perror("open");
				exit(-1);
			}
			while(1){
				memset(buf,0,sizeof(buf));
				if((nread = read(fd,buf,MAX_SIZE)) > 0){
					printf("a read :%s\n",buf);
				}
			}
			close(fd);
		}
		else if(flat == 1) {
			if((fd = open(ABFIFO,O_WRONLY)) < 0){
				perror("open");
				exit(-1);
			}
			while(1){
				memset(buf,0,sizeof(buf));
				strcpy(str,"aaaaaaaaaaaaaaa");
				if((nread = write(fd,buf,MAX_SIZE)) > 0)
					printf("a read :%s\n",buf);
				}
			}
			close(fd);
		}//end if
		if((fp = open(DAMMON,O_WRONLY)) < 0){
			perror("");
			exit(-1);
		}
		if(write(fp,"1",1) < 0){
			print("write dammon failed\n");
		}
		close(fp);

	}//end while
	return 0;
}
