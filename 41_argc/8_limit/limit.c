#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h>
#include <math.h>
#include <sys/types.h>

void work()
{
	FILE *f;
	int i;
	double x = 4.5;
	
	f = tmpfile();

	for(i = 0; i < 1000; i++){
		fprintf(f,"Do some output\n");
		if(ferror(f)){
			fprintf(stderr,"Error writing to temporary file\n");
			exit(1);
		}//if
	}//for
	for(i = 0; i < 1000000; i++){
			x = log(x*x +3.14);
	}//for
}//work

int main()
{
	struct rusage r_usage;
	struct rlimit r_limit;
	int priority;
	 
	work();
	getrusage(RUSAGE_SELF,&r_usage);
	printf("user CPU time used : %ld.%06ld, system : %ld.%06ld \n",r_usage.ru_utime.tv_sec,r_usage.ru_utime.tv_usec,r_usage.ru_stime.tv_sec,r_usage.ru_stime.tv_usec);
	priority = getpriority(PRIO_PROCESS,getpid());
	printf(" current priority: %d \n",priority);

	getrlimit(RLIMIT_FSIZE,&r_limit);
	printf("soft limit %ld, hard limit %ld \n ",r_limit.rlim_cur,r_limit.rlim_max);

	r_limit.rlim_cur = 2048;
	r_limit.rlim_max = 4096;

	printf("seting a 2k file size limit\n");
	setrlimit(RLIMIT_FSIZE,&r_limit);

	work();
	return 0;
}

