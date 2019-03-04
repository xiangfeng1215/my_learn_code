#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
static int debug;

int main(int argc,char **argv)
{
	int opt;
	while((opt = getopt(argc,argv,":d:")) != -1){
		switch(opt){
			case 'd':
				debug = atoi(optarg);
				printf("debug = %d \n",debug);
				break;
			case ':':
					printf("return :\n");
				break;
			case '?':
				printf("return ? \n");
				break;
		}//switch
	}//while

	int i = 0;
	int a[BUFSIZ];
	for(i = 0; i < 10; i++){
		a[i] = i;
		if(debug){
			fprintf(stderr,"a[%d] = %d \n",i,a[i]);

		}//if

	}//for
	return 0;
}
