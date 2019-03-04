#include <stdio.h>
#include <stdlib.h>
#include "sem.h"
#include "shm.h"
#include <unistd.h>
#include <errno.h>
#define MAX_SIZE 4096
int main(int argc,char** argv)
{
	pid_t pid;

	int shmid_key = sharedMemoryGetKey(22);
	int shmid =  sharedMemoryCreate(shmid_key,MAX_SIZE);	
	int semid_key = semGetKey(22);
	int semid = semCreate(semid_key,1);
	

	void *addr = (void*)NULL;

	pid = fork();
	if(pid < 0){
		perror("fork");
		exit(EXIT_FAILURE);
	}else if(pid == 0){
		//child
		sharedMemoryAttach(int shmid);	
	}
	else if(pid > 0){
		//parent


		semDelete(semid);

		wait(0);
	}
	return 0;
}
