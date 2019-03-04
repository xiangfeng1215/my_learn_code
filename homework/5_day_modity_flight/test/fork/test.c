#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc,char *argv)
{
	int ch;
	pid_t pid;
	while(1){
		ch = getchar();
		if( ch == 'a')
			pid=fork();
		if(pid < 0){
			exit(-1);
		}
		else if(pid == 0){
			execl("./main","./main",NULL,NULL);
		}else if(pid > 0){
			while(1){
				ch   = getchar();
					if(ch == 'a'){
						pid = fork();
						if(pid == 0){
							execl("./main","./main",NULL,NULL);

						}
					}
			}//end while
		}//end if

		else if(ch == 'q'){
			break;
		}//end if
	}
	return 0;
}
