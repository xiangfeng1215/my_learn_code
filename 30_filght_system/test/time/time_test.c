#include<time.h>
#include<stdio.h>
#include<stdlib.h>
int main(int argc, const char *argv[])
{
	struct tm *gmt, *local;
	time_t tt;
	long int stime = 40;
//	tzset();//void tzset(void);设置时间环境变量-时区
	tt=time(NULL);//等价于time(&tt);
	stime = tt +30*60;
	printf("stime =  %ld\n",stime);
	char *str=ctime(&tt);
	printf("ctime is:%s",str);
	local=localtime(&stime);
	printf("%4d年%02d月%02d日 %d:%d:%d\n",local->tm_year+1900,local->tm_mon+1,local->tm_mday,local->tm_hour,local->tm_min,local->tm_sec);
	printf("lcoaltime is:%s",asctime(local));
	gmt=gmtime(&tt);
	printf("gmtime is:%s",asctime(gmt));
	return 0;
}

