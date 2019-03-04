#include <stdio.h>
#include <stdlib.h>

extern char **environ;

int main(int argc,char **argv)
{
	char **env = environ;

	while(*env){
		printf("%s\n",*env);
		env++;
	}//while

	return 0;
}
