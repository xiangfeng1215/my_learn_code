#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <errno.h>

#define TEXT_SZ 2048

struct shared_use_st{
	int written_by_you;
	char some_text[TEXT_SZ];
};

int main(int argc,char** argv)
{
	int running = 1;
	void *shared_memmory = (void*)0;
	struct shared_use_st *shared_stuff;
	int shmid,shmkey;
	srand((unsigned int)getpid());
	shmkey = ftok("/",22);
	shmid = shmget(shmkey,sizeof(struct shared_use_st),0666|IPC_CREAT);
	if(shmid < 0){
		perror("shmid");
		exit(EXIT_FAILURE);
	}
	shared_memmory = shmat(shmid,(void*)0,0);
	if(shared_memmory < 0){
		perror("shared memmory");
		exit(EXIT_FAILURE);	
	}
	printf("Memmory attached at : %X \n",(int )shared_memmory);
	shared_stuff = (struct shared_use_st *)shared_memmory;
	shared_stuff->written_by_you = 0;
	while(running){
		if(shared_stuff->written_by_you){
			printf("you wrote: %s \n",shared_stuff->some_text);
			//sleep(rand() % 4);

			shared_stuff->written_by_you=0;
			if(strncmp(shared_stuff->some_text,"end",3) == 0){
				running = 0;
			}//end if
		}
	}//end while
	if(shmdt(shared_memmory) < 0){
		perror("shmdt")	;
		exit(EXIT_FAILURE);
	}//end if
	if(shmctl(shmid,IPC_RMID,0) < 0){
		perror("shmctl :");
		exit(EXIT_FAILURE);
	}//end if
	return 0;
}
