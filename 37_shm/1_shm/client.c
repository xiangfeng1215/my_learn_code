/*
 *		
 *   	client for share memmory 
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <errno.h>

#define TEXT_SZ BUFSIZ

struct shared_use_st{
	int written_by_you;
	char some_text[TEXT_SZ];
};

int main(int argc,char** argv)
{
	int running = 1;
	char chart[6][13] = {"     *      ","    ***     ","   *****    ","  *******   "," *********  ","end"};
	void *shared_memmory = (void*)0;
	struct shared_use_st* shared_stuff;
	char buffer[BUFSIZ];
	int shmid;
	shmid = shmget(ftok("/",22),sizeof(struct shared_use_st),0666|IPC_CREAT);
	if(shmid < 0){
		perror("shmid");
		exit(EXIT_FAILURE);
	}//end if
	shared_memmory = shmat(shmid,(void*)0,0);
	if(shared_memmory < 0){
		perror("shmat");
		exit(EXIT_FAILURE);
	}//end if
	printf("Memmory attached at : %X\n",(int)shared_memmory);
	shared_stuff = (struct shared_use_st *)shared_memmory;
	int i = 0;
	while(running){
		while(shared_stuff->written_by_you == 1){
			sleep(1);
			printf("waiting for client... \n");
		}//end while
		printf("Enter some text:");
		//fgets(buffer,BUFSIZ,stdin);
		strncpy(buffer,chart[i],13);
		i++;
		strncpy(shared_stuff->some_text,buffer,TEXT_SZ);
		shared_stuff->written_by_you = 1;
		if(strncmp(buffer,"end",3) == 0){
			running = 0;
		}//end if
	}//end running
	if(shmdt(shared_memmory)< 0){
		perror("shmdt ");
		exit(EXIT_FAILURE);
	}//end shmdt
	return 0;
}
