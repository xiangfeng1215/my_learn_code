//3、取出/etc/inittab文件的第6行ununtu没有这个文件，改为当前目录下的inittab文件
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

int main(int argc ,char* argv)
{
	int fp = open("./inittab",O_RDONLY);
	if( fp < 0 ){
		perror("open ./inittab");
		return -1;
	}
	char ch;
	char s[1024];
	bzero(s,1024);
	int flat = 0;
	while(1){
		if((read(fp,&ch,1) <= 0))
				break;
		if(ch == '\n')
			flat++;
		if(flat == 5){
			read(fp,s,1024);
			printf("line 6 : %s\n",s);
			break;
		}
	}
	close(fp);
	return 0;
}
