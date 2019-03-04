#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void* thread_func(void *arg)
{
	int *i = (int*)arg;
	while(*i < 10){
		printf(" %d  you are nice gril\n",*i);
		sleep(1);
		*i = *i +1;
	}
	return NULL;
}//end tread_func

int main(int argc,char** argv)
{
	pthread_t thread;
	int i = 7;
	int *arg = &i;
	int gg = 4;
	(void)pthread_create(&thread,NULL,thread_func,&gg);
	
	int addr;
	void* ptr = &addr;
	i = 9;
	sleep(1);
	printf("gg = %d \n",gg);
	sleep(1);
	printf("gg = %d \n",gg);
	sleep(1);
	printf("gg = %d \n",gg);
	(void)pthread_join(thread,ptr);
	return 0;
}
