
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc,char **argv)
{
	int i = 0;
	int a[BUFSIZ];
	for(i = 0; i < 10; i++){
		a[i] = i;
#ifdef DEBUG
		printf("a[%d] = %d \n",i,a[i]);
#endif
	}//for
	return 0;
}
