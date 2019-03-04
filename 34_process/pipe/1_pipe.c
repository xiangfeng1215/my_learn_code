#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <string.h>
#include <strings.h>
#include <sys/stat.h>
#include <errno.h>

int main(int argc,char ** argv)
{
	pid_t pid;
	int pipefd[2];
	int pipefd1[2];
	if(pipe(pipefd) < 0){
		perror("pipe");
		exit(-1);
	}
	if(pipe(pipefd1) < 0){
		perror("pipe1");
		exit(-1);
	}
	pid = fork();
	if(pid < 0){
		perror("fork");
		exit(-1);
	}
	else if(pid == 0){
		close(pipefd[0]);//r
		close(pipefd1[1]);
		char str[1024];
		while(1){
			freopen("/dev/pts/1","r",stdin);
			freopen("/dev/pts/1","w",stdout);	
			printf("input chlid:");
			fscanf(stdin,"%s",str);
			write(pipefd[1],str,1024);
			if(strcmp(str,"quit") == 0)
				break;
			bzero(str,sizeof(str));

			
			read(pipefd1[0],str,1024);
			freopen("/dev/pts/5","w",stdout);
			printf("parent: %s\n",str);
			if(strcasecmp(str,"quit") ==0)
				break;
		}
		printf("end chlid\n");
		exit(0);

	}else if(pid >0){
		char str[1024];
		bzero(str,1024);
		close(pipefd[1]);
		close(pipefd1[0]);
		while(1){
			read(pipefd[0],str,1024);
			freopen("/dev/pts/5","w",stdout);
			printf("parent: %s\n",str);
			if(strcasecmp(str,"quit") ==0)
				break;
			
			freopen("/dev/pts/5","r",stdin);
			freopen("/dev/pts/5","w",stdout);
			bzero(str,sizeof(str));
			printf("input parent:");
			fscanf(stdin,"%s",str);
			write(pipefd1[1],str,1024);
			if(strcmp(str,"quit") == 0)
				break;
		}
		exit(0);
		wait(NULL);
	}
	return 0;
}
