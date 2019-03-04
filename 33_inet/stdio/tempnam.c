#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char *s;
	char *pix = "hello";
	s = tempnam("./",pix);
	printf("temp nam :%s\n",s);
	return 0;
}
