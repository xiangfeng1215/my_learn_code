#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>

int main(int argc,char **argv)
{
	int i = 0;
	pid_t pid;
	pid = fork();
	if(pid < 0){
		perror("fork");
		exit(EXIT_FAILURE);
	}
	printf("good i = %d\n",i);
	sleep(2);
	printf("nice\n");
	i = 100;
	if(pid == 0){
		i = 24;
		sleep(2);
		printf("child i = %d  \n",i);
	}
		i = 88;
		sleep(2);
		printf("parent i = %d \n",i);
	printf("how are you i = %d  \n",i);
	return 0;
}
