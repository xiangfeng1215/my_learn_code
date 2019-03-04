#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

int main(int argc ,char* argv)
{
	int fp1 = open("./zxf.txt",O_RDWR|O_CREAT,0666);
	if( fp1 < 0){
		perror("oepn zxf.txt");
		return -1;
	}
#if 0
	int fp2 = dup(fp1);
	char *buf = "hello world!";
	close(fp1);
	write(fp2,buf,strlen(buf));
	close(fp2);
#endif
#if 0
	int fp2 = open("./new_zxf.txt",O_RDWR|O_CREAT,0666);
	if( fp2 < 0){
		perror("open ./new_zxf.txt");
		return -1;
	}
	dup2(fp2,fp1);
	char *buf = "hello world!";
	write(fp1,buf,strlen(buf));
	char *buf2 = "nice girl";
	write(fp2,buf2,strlen(buf2));
	close(fp2);
	close(fp1);
#endif

#if 1
	int fp2 = open("./new_zxf.txt",O_RDWR|O_CREAT,0666);
	if( fp2 < 0){
		perror("open ./new_zxf.txt");
		return -1;
	}
	dup2(fp1,0);
	char *buf = "hello world!";
	write(fp1,buf,strlen(buf));
	char buf2[100];
	scanf("%s",buf2);
	dup2(fp2,0);
	write(fp2,buf2,strlen(buf2));
	fflush(stdout);
	close(fp2);
	close(fp1);
#endif
	return 0;
}
