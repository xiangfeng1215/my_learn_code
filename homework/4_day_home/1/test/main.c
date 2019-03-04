#include <stdio.h>
#include <stdlib.h>
#include "shm.h"
#include <strings.h>
#include <string.h>

#define MAX_SIZE 4096
int main(int argc,char** argv)
{
	char *s = "123456789abcdefghigklmnopq";
	int shm_key = sharedMemoryGetKey(23);
	int shmid = sharedMemoryCreateOrGet(shm_key,MAX_SIZE);

	printf("this is parend \n");
	char* addr_parent;
	addr_parent = sharedMemoryAttach(shmid);

	strncpy(addr_parent,s,strlen(s));
	printf("addr_parent: %s \n",addr_parent);
	printf("s : %s \n",s);
	//sharedMemoryDetatch(addr_parent);
	
	return 0;
}
