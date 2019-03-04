#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc,char **argv)
{
	if(argc != 2){
		fprintf(stderr," argument is too few!!");
		exit(EXIT_FAILURE);
	}//if
	char *filename;
	filename = argv[1];
	if(!freopen(filename,"r",stdin)){
		fprintf(stderr,"could not redirect stdin from file\n");
		exit(2);
	}//if

	execl("./2_upper","2_upper",NULL);
	perror("could not exeC ./upperr");
	return 0;
}
