#include <stdio.h>
#include <string.h>

int main(void)
{
	FILE* fp = fopen("./txt.txt","w+");
	if(!fp)
		return -1;
#if 0
	int i =0;
	while(i < 5){
		fseek(fp,1000,SEEK_CUR);
		i++;
		fputs("aaa",fp);
	}
#endif
	fputs("hello",fp);
	fseek(fp,1,SEEK_SET);
	char s[100];
	fgets(s,100,fp);
	printf("%s\n",s);
	fclose(fp);
	return 0;
}
