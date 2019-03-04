#include <stdio.h>
#include <string.h>

int main(void)
{
	FILE* fp1 = fopen("./C.DAT","w+");
	FILE* fp2 = fopen("./SCORE60.DAT","w+");
	char name[8];
	int score;
	int i = 0;
	for(i = 0 ;i < 3; i++){
		printf("input name score\n");
		scanf("%s%d",name,&score);
		fprintf(fp1,"%s%d",name,score);
	}
	while(1){
		fscanf(fp1,"%s%d",name,&score);
		if(score > 60){
			fprintf(fp2,"%s%d",name,score);
		}
		if(feof(fp1))
			break;
	}
	fclose(fp1);
	fclose(fp2);
	return 0;
}
