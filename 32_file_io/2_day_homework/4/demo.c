//4、每隔一秒钟向文件输出一条时间信息
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

int main(int argc ,char* argv)
{
	time_t result;

	result = time(NULL);
	int fp = open("./time_log.txt",O_RDWR|O_CREAT,0666);
	if(fp < 0){
		perror("open ./time_log.txt");
		return -1;
	}
	char t[50];
	while(1){
		strcmp(t,asctime(localtime(&result)));
		if(write(fp,t,50) <= 0){
			perror("write failed");
			exit(1);
		}
		printf("%s write time_log.txt success\n",asctime(localtime(&result)));
		if(read(fp,t,50) <= 0){
			perror("read failed");
			exit(1);
		}
		printf("%s read time_log.txt success\n",t);
		sleep(1);
	}
	close(fp);
	return 0;
}
