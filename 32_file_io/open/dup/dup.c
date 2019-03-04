

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
#include <strings.h>
#include <math.h>

int main(int argc,char *argv)
{
	int fp = open("./zxf.txt",O_RDWR,0666);
	dup2(fp,
	close(fp);
	return 0;
}
