#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
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
	void* ptr;
	int i = 5;
	int *arg = &i;
	pthread_attr_t attr;
	(void)pthread_attr_init(&attr);
//	(void)pthread_attr_destroy(&attr);
	(void)pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);
	(void)pthread_create(&thread,&attr,thread_func,arg);
	int ret = pthread_join(thread,&ptr);
	if( ret != 0){
		fprintf(stderr,"main thread is recycle\n");
	}
	return 0;
}
