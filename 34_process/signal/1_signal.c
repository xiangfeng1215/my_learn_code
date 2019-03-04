#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <stdlib.h>
#include <signal.h>

void my_func(int sign_no){
	if(sign_no = SIGINT){
		printf("signint coming here.\n");
	}
	(void)signal(SIGINT,SIG_DFL);
}

int main(void){
	printf("wait the signal coming.....\n");
	signal(SIGINT,my_func);
	pause();
	while(1);
	return 0;
}
