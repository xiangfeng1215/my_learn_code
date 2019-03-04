//1、将/etc/issue文件的内容转换为大写保存到/tmp/issue.out文件中
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

char translate(char ch)
{
	if(ch>='a' && ch<='z')
		return ch-=32;
	else return ch;
}

int main(int argc ,char* argv)
{
	int fp = open("/etc/issue",O_RDONLY);
	if(fp < 0){
		perror("open /etc/issue");
		return -1;
	}
	int fp2 = open("/tmp/issue.out",O_RDWR|O_CREAT,0666);
	if( fp2 <0){
		perror("open /tmp/issue.out");
	}
	int lefp_size = 0;
	char ch;
	while(1){
		if(read(fp,&ch,1) <= 0)
			break;
		ch = translate(ch);
		write(fp2,&ch,1);
	}
	close(fp);
	close(fp2);
	return 0;
}
