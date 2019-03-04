
#ifndef DEBUG
#define DEBUG 0
#endif
#define BASIC_DEBUG 1
#define EXTRA_DEBUG 2
#define SUPER_DEBUG 4
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc,char **argv)
{
	int i = 0;
	int a[BUFSIZ];
	for(i = 0; i < 10; i++){
		a[i] = i;
#if (DEBUG & BASIC_DEBUG)
		printf("a[%d] = %d \n",i,a[i]);
#endif


#if (DEBUG & EXTRA_DEBUG)
		printf("a[%d] = %d , i = %d \n",i,a[i],i);
#endif


#if (DEBUG & SUPER_DEBUG)
		printf("BUFSIZ: %d ; a[%d] = %d ;i = %d ;in for\n",BUFSIZ,i,a[i],i);
#endif
	}//for
	return 0;
}
