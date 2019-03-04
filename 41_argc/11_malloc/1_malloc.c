#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <errno.h>

int main(int argc,char **argv)
{
	char *s;
	s = (char*)malloc(sizeof(1024));
	if(s == NULL){
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	s[0] = 0;
	char *m;
//	m = s;
	m[3] = 'h';
//	strcpy(m,"hello");
//	int i = 1;
//	while(i--){
//		m[i] = 'A';
//	}
	printf("m[333] = %c \n",m[335]);
	printf("s[1] =  %c ,s[1024] = %c\n",s[0],s[1024]);
	return 0;
}
