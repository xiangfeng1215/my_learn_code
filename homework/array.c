#include <stdio.h>
#include <stdlib.h>

char *m;

void modity_array(char *m)
{
	int j;
	for(j = 0; j < 10; j++){
		m[j] = 'B';
	}//for
	for(j = 0; j < 10; j++){
		printf("m[%d] = %d \n",m,m[j]);
	}//for
}

int main(int argc,char **argv)
{
	char *s = (char*)malloc(1024);
	int i = 0;
	for(i = 0 ; i < 10;i++){
		s[i] = 'A';
	}
	for(i = 0;i < 10; i++){
		printf(" s[%d]  =  %d \n",i,s[i]);
	}//for
	m = s;
	(void)modity_array(m);
	for(i = 0;i < 10; i++){
		printf(" s[%d]  =  %d \n",i,s[i]);
	}//for
	return 0;
}
