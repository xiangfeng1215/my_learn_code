#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int main(void){
	pid_t pid;
	pid = fork();
	if(pid < 0){
		exit(-1);
	}else if(pid == 0 ){
		printf(" pid :%d ppid : %d  \n",getpid(),getppid());
		//execlp("./a.out","./a.out",NULL);
		printf("end child pid : %d \n",getpid());
		FILE* fp;
		fp = fopen("./exec.txt","w+");
		char ch  = '0';
		while(1){
			ch = fgetc(stdin);
			fputc(ch,fp);
			if(ch == 'q'){
				break;
			}
		}
		fclose(fp);
		printf("write success!\n");
		exit(0);
	}
	else{
		int status;
		printf("child pid : %d \n",pid);
		printf("my pid :%d \n",getpid());
		waitpid(pid,&status,0);
		FILE* fp;
		fp = fopen("./exec.txt","r");
		char ch  = '0';
		while(1){
			ch = fgetc(fp);
			if(feof(fp)){
				break;
			}
			printf("%c",ch);
		}
		putchar(10);
		fclose(fp);
		printf("readed !!!\n");
		printf("child exit wifexited status: %d \n",WIFEXITED(status));
		printf("child exit wexitstatus status: %d \n",WEXITSTATUS(status));
		sleep(3);
		printf("parent end !\n");
	}
	return 0;
}
