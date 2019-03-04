#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <errno.h>
#include <unistd.h>

static int set_semvalue(void);
static void del_semvalue(void);
static int semphore_p(void);
static int semphore_v(void);

static int sem_id;

union semnu{
	int val;
	struct semid_ds *buf;
	unsigned short *array;
	struct seminfo *__buf;
};

int main(int argc,char ** argv)
{
	int i;
	int pause_time;
	char op_char = '0';
	srand((int)getpid());
	sem_id = semget(ftok("/",33),1,IPC_CREAT|0666);
	if(sem_id < 0){
		perror("sem_id");
		exit(EXIT_FAILURE);
	}//end if
	if(argc > 1){
		if(!set_semvalue()){
			fprintf(stderr,"failied to initialize semaphore!\n");
			exit(EXIT_FAILURE);
		}//end if	
		op_char = 'X';
		sleep(1);
	}//end if

	for(i = 0;i < 10; i++){
		if(!semphore_p()){
			exit(EXIT_FAILURE);
		}//end if	

		printf("%c\n",op_char);
		pause_time = rand()%3;
		sleep(pause_time);
		printf("%c\n",op_char);

		if(!semphore_v()){
			fprintf(stderr,"semphore_v");
			exit(EXIT_FAILURE);
		}//end if

		sleep(pause_time);
	}//end for

	printf("\n %d - finished \n",getpid());
	
	if(argc > 1){
		sleep(10);
		del_semvalue();
	}

	return 0;
}

static int set_semvalue(void)
{
	union semnu sem_union;
	sem_union.val = 1;
	if(semctl(sem_id,0,SETVAL,sem_union) < 0){
		fprintf(stderr,"semctl st_semvalue\n");
		return 0;
	}//end if
	return 1;
}//end set_semvalue

static void del_semvalue(void)
{
	union semnu sem_union;
	if(semctl(sem_id,0,IPC_RMID,sem_union) < 0){
		fprintf(stderr,"semctl del_semphore\n");
	}
}//end del_semvalue

static int  semphore_p(void)
{
	struct sembuf sops;
	sops.sem_num = 0;	
	sops.sem_op = -1;
	sops.sem_flg = SEM_UNDO;

	if(semop(sem_id,&sops,1) < 0){
		fprintf(stderr,"semop for semphore_p\n");
		return 0;
	}
	return 1;
}//end semphore_p

static int semphore_v(void)
{
	struct sembuf sops;
	sops.sem_num = 0;
	sops.sem_op = 1;
	sops.sem_flg = SEM_UNDO;

	if(semop(sem_id,&sops,1) < 0){
		fprintf(stderr,"semop semphore_v\n");
		return 0;
	}//end if
	return 1;
}//end semphore_v

