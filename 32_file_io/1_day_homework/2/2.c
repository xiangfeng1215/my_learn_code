#include <stdio.h>
#include <string.h>

int main(void)
{
	FILE* fp1 = fopen("./love.jpg","w+");
	FILE* fp2 = fopen("./gril.jpg","r");
	char ch;
	while(1){
		ch = fgetc(fp2);
		if(feof(fp2))
			break;
		if(ferror(fp2))
			return -1;
		fputc(ch,fp1);
	}
	printf("copy ok!\n");
	fclose(fp1);
	fclose(fp2);
	return 0;
}
