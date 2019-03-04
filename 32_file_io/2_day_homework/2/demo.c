//2、显示/var/log目录下某个文件的内容类型？
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

int main(int argc ,char* argv)
{
	char *s = "/var/log";
	system("ls /var/log");
	putchar(10);
	printf("请输入你要查看的文件:\n");
	char d[100];
	scanf("%s",d);
	strcpy(d,s);
	struct stat buf;
	if (stat(d, &buf) == -1) {
		perror("stat");
		return -1;
	}

	printf("File type:                ");

	switch (buf.st_mode & S_IFMT) {
		case S_IFBLK:  printf("block device\n");            break;
		case S_IFCHR:  printf("character device\n");        break;
		case S_IFDIR:  printf("directory\n");               break;
		case S_IFIFO:  printf("FIFO/pipe\n");               break;
		case S_IFLNK:  printf("symlink\n");                 break;
		case S_IFREG:  printf("regular file\n");            break;
		case S_IFSOCK: printf("socket\n");                  break;
		default:       printf("unknown?\n");                break;
	}

	printf("I-node number:            %ld\n", (long) buf.st_ino);

	printf("Mode:                     %lo (octal)\n",
			(unsigned long) buf.st_mode);

	printf("Link count:               %ld\n", (long) buf.st_nlink);
	printf("Ownership:                UID=%ld   GID=%ld\n",
			(long) buf.st_uid, (long) buf.st_gid);

	printf("Preferred I/O block size: %ld bytes\n",
			(long) buf.st_blksize);
	printf("File size:                %lld bytes\n",
			(long long) buf.st_size);
	printf("Blocks allocated:         %lld\n",
			(long long) buf.st_blocks);

	printf("Last status change:       %s", ctime(&buf.st_ctime));
	printf("Last file access:         %s", ctime(&buf.st_atime));
	printf("Last file modification:   %s", ctime(&buf.st_mtime));

	return 0;
}
