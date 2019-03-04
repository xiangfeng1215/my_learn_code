#include "shm.h"
int sharedMemoryGetKey(int proj_id)
{	

	return ftok("/",proj_id);

}//end sharedMemoryGetKey

int sharedMemoryGet(key_t key, int size)
{

	return shmget(key,size,0666);

}//end sharedMemoryGet

int sharedMemoryCreate(key_t key, int size)
{

	return shmget(key,size,0666|IPC_CREAT);

}//end shardMemoryCreate

void* sharedMemoryAttach(int shmid)
{

	return shmat(shmid,0,0);

}//end shareMemoryAttach

int sharedMemoryDetatch(const void* shmaddr)
{

	return shmdt(shmaddr);

}//end sharedMemoryDetatch

int sharedMemoryDelete(int shmid)
{

	return shmctl(shmid, IPC_RMID, 0);

}


int sharedMemoryCreateOrGet(key_t key, int size)
{
	int shmid;

	/* If memory has already been created.. then just get it: */
	if ((shmid = shmget(key, size, IPC_CREAT | IPC_EXCL | 0666)) == -1)
	{
		if( errno != EEXIST )
			return -1;

		if ((shmid = shmget(key, size, 0666)) == -1)
			return -1;
	}

	return shmid;
}

int sharedMemoryCreateIfGone(key_t key, int size)
{
	int shmid;

	/* If memory has already been created.. then just get it: */
	if ((shmid = shmget(key, size, IPC_CREAT | IPC_EXCL | 0666)) == -1)
		return errno;

	return shmid;
}

int sharedMemoryLock(int shmid)
{
	if( shmctl(shmid, SHM_LOCK, 0) == -1 )
		return errno;

	return 0;
}

int sharedMemoryUnlock(int shmid)
{
	if( shmctl(shmid, SHM_UNLOCK, 0) == -1 )
		return errno;

	return 0;
}
