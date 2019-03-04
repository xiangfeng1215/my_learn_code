#include <stdio.h>
#include <string.h>

int main(void)
{
	FILE* fp = fopen("./4.txt","r");
	FILE* fp1 = fopen("./4new.txt","w");
	if(!fp){
		perror("fp fopen");
		return -1;
	}
	if(!fp1){
		perror("fp2 fopen");
		return -1;
	}
	char ch;
	int i = 0;
	fseek(fp,0,SEEK_END);
	int fp_end = ftell(fp);
	rewind(fp);
	while(fp_end){
		if(feof(fp))
			break;
		ch=fgetc(fp);
		rewind(fp);
		fputc(ch,fp1);
		fp_end--;
		fseek(fp,fp_end,SEEK_SET);
		if(feof(fp))
			break;

	}
	fclose(fp);
	fclose(fp1);
	
	return 0;
}
