/* for linux , semtimedop() declaration */
#include "sem.h"

key_t semGetKey(int proj_id)
{
	return ftok("/",proj_id);
}//end semGetKey

/* Create num_of_sem semaphores assoc. with the path. */
/* Returns the semid */
int semCreate(key_t key, int num_of_sem)
{
	return semget(key,num_of_sem,0666|IPC_CREAT);
}//end semCreate

/* Returns the semaphore ID for the path specified */
int semGet(key_t key, int number_of_sem)
{
	return semget(key,number_of_sem,0666);
}//semGet

/* Delete the semaphores associated with semid */
int semDelete(int semid)
{
	union semun arg;
	return semctl(semid,0,IPC_RMID,arg);
}//semDelete

/* Sets semaphore_number assoc. with the semid to value */
int semSetValue(int semid, int semaphore_number, int value)
{
	union semun arg;
	arg.val = value;
	return semctl(semid,semaphore_number,SETVAL,arg);
}//semSetValue

/* Gets the semaphore value from semaphore_number assoc. with the semid */
int semGetValue(int semid, int semaphore_number)
{
	union semun arg;
	return semctl(semid,semaphore_number,GETVAL ,arg);

}//semGetValue

/* Increment semaphore value by one */
int semSignal(int semid, int semaphore_number)
{
	struct sembuf sops;
	sops.sem_num = semaphore_number;
	sops.sem_op = 1;
	sops.sem_flg = SEM_UNDO;
	return semop(semid, &sops, 1);
}//semSignal

int semIncrement(int semid, int semaphore_number, int incrementBy)
{
	struct sembuf sops;
	sops.sem_num = semaphore_number;
	sops.sem_op = incrementBy;
	sops.sem_flg = SEM_UNDO;
	return semop(semid,&sops,1);
}//semIncrement

/* Decrement semaphore value by one */
int semWait(int semid, int semaphore_number)
{
	struct sembuf sops;
	sops.sem_num = semaphore_number;
	sops.sem_op = -1;
	sops.sem_flg = SEM_UNDO;

	return semop(semid,&sops,1);
}//semWait
int semDecrement(int semid, int semaphore_number, int decrementBy)
{
	struct sembuf sops;
	sops.sem_num = semaphore_number;
	sops.sem_op = decrementBy;
	sops.sem_flg = SEM_UNDO;

	return semop(semid,&sops,1);
}//semDecrement


/* Increment semaphore value by one */                     
int semSignal_timeout(int semid, int semaphore_number, long usecs)
{
	struct sembuf sops;
	struct timespec timeout;

	sops.sem_num = semaphore_number;
	sops.sem_op = 1;
	sops.sem_flg = SEM_UNDO;

	timeout.tv_sec = 0;
	timeout.tv_nsec = usecs*1000;

	return semtimedop(semid, &sops, 1, &timeout);
}

int semIncrement_timeout(int semid, int semaphore_number, int incrementBy, long usecs)
{
	struct sembuf sops;
	struct timespec timeout;

	sops.sem_num = semaphore_number;
	sops.sem_op = incrementBy;
	sops.sem_flg = SEM_UNDO;

	timeout.tv_sec = 0;
	timeout.tv_nsec = usecs*1000;

	return semtimedop(semid, &sops, 1, &timeout);
}

/* Decrement semaphore value by one */      
int semWait_timeout(int semid, int semaphore_number, long usecs)
{
	struct sembuf sops;
	struct timespec timeout;

	sops.sem_num = semaphore_number;
	sops.sem_op = -1;
	sops.sem_flg = SEM_UNDO;

	timeout.tv_sec = 0;
	timeout.tv_nsec = usecs*1000;

	return semtimedop(semid, &sops, 1, &timeout);
}

int semDecrement_timeout(int semid, int semaphore_number, int decrementBy, long usecs)
{
	struct sembuf sops;
	struct timespec timeout;

	sops.sem_num = semaphore_number;
	sops.sem_op = decrementBy;
	sops.sem_flg = SEM_UNDO;

	timeout.tv_sec = 0;
	timeout.tv_nsec = usecs*1000;

	return semtimedop(semid, &sops, 1, &timeout);
}

