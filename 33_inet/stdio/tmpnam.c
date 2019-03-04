#include <stdio.h>

int main(void)
{
	char buf[L_tmpnam];
	if(!tmpnam(buf)){
		perror("");
		return -1;
	}
	printf("tmp nam = %s\n",buf);
	FILE* fp = fopen(buf,"w+");
	if(!fp){
		perror("");
		return -1;
	}else{
		printf("open tmpfile ok!\n");
		return 0;
	}
	return 0;
}
