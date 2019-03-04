#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc,char** argv)
{
	int opt;
	while((opt = getopt(argc,argv,"if:lr")) != -1){
		switch(opt){
			case 'i':
			case 'l':
			case 'r':
				printf(" option : %c \n",opt);
				break;
			case 'f':
				printf("filename : %s \n",optarg);
				break;
			case ':':
				printf(" option needs a value \n");
			case '?':
				printf("unknown option : %c \n",optopt);
				break;
		}//end switch
	}//while
	for(; optind < argc; optind++){
		printf("argument : %s \n",argv[optind]);
	}//for
	return 0;
}
