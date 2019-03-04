#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

char arr[20];


void* thread_func(void *arg)
{
	pthread_mutex_t *mutex = (pthread_mutex_t *)arg;
	pthread_mutex_lock(mutex);
	while(1){
		scanf("%s",arr);
		printf("thread arr  = %s \n",arr);
		if(strncmp(arr,"quit",4) == 0)
			break;
	}//end if
	pthread_mutex_unlock(mutex);
	return NULL;
}//end tread_func

int main(int argc,char** argv)
{
	pthread_t thread;
	pthread_mutex_t mutex;
	pthread_mutex_init(&mutex,NULL);
	(void)pthread_create(&thread,NULL,thread_func,&mutex);

	pthread_mutex_lock(&mutex);	
	while(1){
		scanf("%s",arr);
		printf("main arr %s \n",arr);
		if(strncmp(arr,"quit",4) == 0)
			break;
	}//end while
	pthread_mutex_unlock(&mutex);
	pthread_join(thread,NULL);
	pthread_mutex_destroy(&mutex);
	return 0;
}
