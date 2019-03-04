#include <stdio.h>
#include <stdlib.h>
#include "sem.h"
#include "shm.h"
#include <unistd.h>
#define MAX_SIZE 4096
int main(int argc,char** argv)
{
	int sem_key = semGetKey(21);
	if(sem_key< 0){
		perror("");
		exit(-1);
	}
	int semid = semCreate(sem_key,1);
	if(semid < 0){
		perror("semCreate");
		exit(-1);
	}
	if(semSetValue(semid,0,1) < 0){
		perror("semsetvalue");
		exit(-1);
	}

	int shm_key = sharedMemoryGetKey(23);
	int shmid = sharedMemoryCreateOrGet(shm_key,MAX_SIZE);

	pid_t pid = fork();
	if(pid < 0){
		perror("");
		exit(EXIT_FAILURE);
	}
	else if(pid == 0){
	//	printf("this is chlid\n");
		char* addr_chlid;
		int flag = 0;
		char ch = '0';
		/**********************/
		while(ch != 'q'){
			//printf("this is chlid while\n");
			addr_chlid = sharedMemoryAttach(shmid);
			if(addr_chlid < 0){
				perror("sharedmemoryattach");
				exit(0);
			}
			if(semWait(semid,0) < 0){
				perror("semWait");
				exit(EXIT_FAILURE);
			}

			ch = *(addr_chlid+flag);
			printf("c: %c ;",*(addr_chlid+flag));
			fflush(stdout);
			//printf("this is chlid ch: %c",ch);
			flag++;
			sleep(1);
			if(semSignal(semid,0) < 0){
				perror("semsignal");
				exit(-1);
			}
			sharedMemoryDetatch(addr_chlid);
		}//end while
		putchar(10);
		/********************/
		exit(0);
	}
	else if(pid > 0){
		pid_t new_pid = fork();
		if(new_pid < 0){
			perror("new_pid");
		}
		else if(new_pid == 0){
			int flag = 0;
			char ch = '0';
		//	printf("this is new pid for child\n");
			char* addr_parent_child;
			/**********************/
			while(ch != 'q'){
			//	printf("this is new_pid for child while\n");
				addr_parent_child = sharedMemoryAttach(shmid);
				if(semWait(semid,0) < 0){
					perror("semwait");
					exit(-1);
				}
				ch = *(addr_parent_child+flag);
			//	printf("nc :%c ;",ch);
				printf("nc: %c ;",*(addr_parent_child+flag));
				fflush(stdout);
				flag++;
				sleep(1);
				if(semSignal(semid,0) < 0){
					perror("semsignal");
					exit(-1);
				}
				sharedMemoryDetatch(addr_parent_child);
			}//end while
			/********************/
			putchar(10);
			exit(0);

		}
		else if(new_pid > 0){
			int flat = 0;
			char ch = '0';
		//	printf("this is parend \n");
			char* addr_parent;
			while(ch != 'q'){
			//	printf("this is parend while \n");
				/**********************/
				addr_parent = sharedMemoryAttach(shmid);
				if(semWait(semid,0) < 0){
					perror("semwait");
					exit(-1);
				}
				ch = *(addr_parent+flat);
				printf("p: %c ;",*(addr_parent+flat));
				fflush(stdout);
				//printf("pc: %c \n",ch);
				flat ++;
				sleep(1);
				if(semSignal(semid,0) < 0){
					perror("semsignal");
					exit(-1);
				}
				sharedMemoryDetatch(addr_parent);
				/********************/
			}//end while
			putchar(10);
			wait(NULL);
		}
		wait(NULL);
	}//end if
	return 0;
}

