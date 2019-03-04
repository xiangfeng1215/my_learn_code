#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>

#define _GNU_SOURCE

int main(int argc,char **argv)
{
	int opt;
	struct option longopts[]= {
		{"list",0,NULL,'l'},
		{"file",1,NULL,'f'},
		{"install",0,NULL,'i'},
		{"help",0,NULL,'h'},
		{0,0,0,0}
	};
	while((opt = getopt_long(argc,argv,":lf:ih",longopts,NULL)) != -1){
		switch(opt){
			case 'i':
			case 'l':
			case 'h':
				printf("option : %c \n",opt);
				break;
			case 'f':
				printf("file name :%s \n",optarg);
				break;
			case ':':
				printf("option needs a value\n");
				break;
			case '?':
				printf("unknown option : %c \n",optopt);
				break;
		}//switch
		for(; optind < argc ; optind++){
				printf("argument : %s \n",argv[optind]);
		}//for
	}//while
	return 0;
}
