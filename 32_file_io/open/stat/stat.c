#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void)
{
	//int fp = open("./file.txt",O_RDWR);
	struct stat file_info;
	stat("./file.txt",&file_info);
	int size;
	size = file_info.st_size;
	printf("the file size is  %d\n",size);
	printf("the file st_uid is  %d\n",file_info.st_uid);
	printf("the file ctime is  %s\n",ctime(&file_info.st_ctime));
	printf("the file stime is  %s\n",ctime(&file_info.st_atime));
	printf("the file st_ino is  %ld\n",file_info.st_ino);
//	printf("the file dev is  %d\n",file_info.st_dev);
	switch(file_info.st_mode &  S_IFMT)
	{
		case S_IFSOCK:
			printf("this is a sock\n");break;
		case S_IFLNK:
			printf("this is a S_IFLNK\n");break;
		case S_IFREG:
			printf("this is a S_IFREG\n");break;
		case  S_IFBLK:
			printf("this is a  S_IFBLK\n");break;
		case S_IFDIR:
			printf("this is a S_IFDIR\n");break;
		case S_IFCHR:
			printf("this is a S_IFCHR\n");break;

	}//end switch
	//close(fp);
	return 0;
}

