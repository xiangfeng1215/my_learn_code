/*
 *  author : zeng xinag feng
 *  content : 父进程向一个文件中输入一段字符，子进程中将文件读出并输出到另一个文件中。
 *
 *  time : 2018 - 2 - 21 17:01
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc,char** argv)
{
	pid_t pid;
	pid = fork();
	if(pid < 0){
		exit(-1);
	}else if(pid == 0)
	{
		//child
		sleep(10);
		printf("chlid\n");
		FILE* fp1 = fopen("./zxf.txt","r");
		FILE* fp2 = fopen("./newzxf.txt","w");;
		char ch;
		int i= 0;
		int flat = 1;
		fseek(fp1,i,SEEK_END);
		int size = ftell(fp1);
		printf("size %d\n",(size/2 + size%2));
		if(size%2){
			printf("enve\n");
			while(i < (size/2)){
					fseek(fp1,i,SEEK_SET);
					ch = fgetc(fp1);
					printf("start ch %c i %d\n",ch,i);
					fputc(ch,fp2);
					rewind(fp1);
					fseek(fp1,size-i-2,SEEK_SET);
					ch = fgetc(fp1);
					printf("end ch %c i %d\n",ch,i);
					fputc( ch, fp2);
					rewind(fp1);
					i++;
			}//end while

		}else{
			printf("odd\n");
			while(i < (size/2 + size%2)){
				if(i == (size/2 + size%2 -1)){
				fseek(fp1,i,SEEK_SET);
				ch = fgetc(fp1);
				printf("start ch %c i %d\n",ch,i);
				fputc(ch,fp2);
				rewind(fp1);
				break;
				}else{
				fseek(fp1,i,SEEK_SET);
				ch = fgetc(fp1);
				printf("start ch %c i %d\n",ch,i);
				fputc(ch,fp2);
				rewind(fp1);
				fseek(fp1,size-i-2,SEEK_SET);
				ch = fgetc(fp1);
				printf("end ch %c i %d\n",ch,i);
				fputc( ch, fp2);
				rewind(fp1);
				i++;
				}
			}//end while
		}
		fclose(fp1);
		fclose(fp2);
		printf("exit chlid\n");
		exit(0);
	}else if(pid > 0){
		//parent
#if 1
		printf("praent\n");
		FILE* fp = fopen("./zxf.txt","w");
		if( !fp ){
			perror("fopen");
			exit(-1);
		}
		char ch;
		while(1){
			ch = getchar();
			fputc(ch,fp);
			fflush(stdin);
			if(ch == '0')
				break;
		}//end while
		printf("end input\n");
		fclose(fp);
#endif
		waitpid(pid,NULL,0);
		exit(0);
	}
	return 0;
}

