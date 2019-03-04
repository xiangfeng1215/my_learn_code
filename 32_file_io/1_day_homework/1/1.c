#include <stdio.h>
#include <string.h>

int main(void)
{
	FILE* fp1 = fopen("./love.jpg","wb+");
	FILE* fp2 = fopen("./gril.jpg","rb");
	fseek(fp2,0,SEEK_END);
	int count = ftell(fp2);
	printf("count :%d\n",count);
	char buf[100];
	rewind(fp2);
	int size;
	while(1){
		size = fread(buf,sizeof(char),100,fp2);
		fwrite(buf,sizeof(char),size,fp1);
		if(!size)
			break;
	}
	fclose(fp1);
	fclose(fp2);
	return 0;
}

