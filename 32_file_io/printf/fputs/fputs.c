#include <stdio.h>
#include <string.h>

int main(void)
{
	FILE* fp,*fp1;
	fp = fopen("./txt.txt","r+");
	fp1 = fopen("./txx2.txt","w+");
	if(!fp){
		return -1;
	}
	if(!fp1){
		return -1;
	}
	char buf[50];
	bzero(buf,50);

	while(1){
		(void)fgets(buf,50,fp);
		printf("%d\n",feof(fp));
		if(feof(fp))
			break;
		if(ferror(fp))
			return -1;
		(void)fputs(buf,fp1);
	}

	fclose(fp);
	fclose(fp1);

	return 0;
}
