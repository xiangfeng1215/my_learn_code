#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

int main(int argc ,char* argv)
{
	int fp = open("./zxf.txt",O_RDWR|O_CREAT,0666);
	if( fp < 0){
		perror("open failedd");
		return -1;
	}
	char ch[1024];
	bzero(ch,1024);
	dup2(fp,1);
	int i = 0;
//	for(i = 0;i < 4096;i++){
//		printf("c",48);
//	}
	while(1){
		read(0,ch,sizeof(ch));
		if(strncmp(ch,"exit",4) == 0)
			break;
		printf("%s\n",ch);
	}
	close(fp);
	return 0;
}
