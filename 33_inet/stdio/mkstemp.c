
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>


int main(void)
{
	char s[100];
	char *p;
	strcpy(s,"zxdfdfdfdffile");
	printf("s %s\n",s);
	mkstemp(s);
	printf("temp nam :%s\n",s);
	return 0;
}
