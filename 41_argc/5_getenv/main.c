#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

int main(int argc,char **argv){
	char *s;
	s = getenv("HOME");
	printf("HOME =  %s \n",s);
	char *string,*val,*value;
	val = argv[1];
	value = argv[2];
	printf("putc %s = %s to env\n",val,value);
	string = (char*)malloc(strlen(val) + strlen(value) + 2);
	if(string == NULL){
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	strcpy(string,val);
	strcat(string,"=");
	strcat(string,value);
	printf("string : %s \n",string);
	if(putenv(string) < 0){
		perror("putenv");
		exit(EXIT_FAILURE);
	}//if
	printf("putenv success\n");
	value = getenv(val);
	printf("getenv :%s \n",value);
	return 0;
}
