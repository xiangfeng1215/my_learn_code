//5、复制一个文件，只复制奇数行
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
	int fp1 = open("./zxf.txt",O_RDONLY);
	if( fp1 <  0){
		perror("open ./zxf.txt");
		return -1;
	}
	int fp2 = open("./new_zxf.txt",O_RDWR|O_CREAT,0666);
	if( fp2 < 0){
		perror("copy failed when open new_zxf.txt");
		return -1;
	}
#if 0
	char ch;
	int flat = 1;
	while(1){
		if(read(fp1,&ch,1) <= 0)
			break;
		if(flat){
		if(write(fp2,&ch,1) <= 0){
			perror("copy failed");
			return -1;
		}
		}
		if(ch == '\n')
			flat = !flat;
	}
#endif

#if 1
	char ch;
	int flat = 1;
	while(1){
		if(read(fp1,&ch,1) <= 0)
			break;
		if(flat){
		if(write(fp2,&ch,1) <= 0){
			perror("copy failed");
			return -1;
		}
		}
		if(ch == '\n')
			flat = !flat;
	}


#endif
	putchar(10);
	printf("copy ok!!\n");
	putchar(10);
	printf("cat zxtxt\n");
	system("cat zxf.txt");
	putchar(10);
	printf("cat  new_zxf.txt\n");
	system("cat ./new_zxf.txt");
	close(fp1);
	close(fp2);
	return 0;
}
