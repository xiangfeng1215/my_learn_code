#include <stdio.h>
#include <string.h>
int main(void)
{
	FILE* fp;
	fp = fopen("./txt.txt","w+");
	if(!fp){
		perror("fopen txt.txt");
		return -1;
	}
	char *s = "hello";
	if(fwrite(s,12,1,fp)){
		perror("fwrite ");
		return -1;
	}
	char w[20];
	bzero(w,20);
	fgets(w,20,fp);

	printf("%s\n",w);
	fclose(fp);
	return 0;
}
