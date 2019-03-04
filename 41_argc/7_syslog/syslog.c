#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <syslog.h>



int main()
{
	openlog("zxf love ch",LOG_PID|LOG_CONS,LOG_USER);
	syslog(LOG_INFO," informatiove message, pid = %d ",getpid());
	return 0;
}
