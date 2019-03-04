#include <stdio.h>
#include <string.h>

int main(void)
{
	FILE* fp = fopen("./3.txt","r");
	char *b="abcdefghigklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int conut[48];
	memset(count,0,sizeof(int)*48);
	if(!fp)
		return -1;
	char ch;
	flat = 0;
	while(1){
		if(feof(fp))
			break;
		ch = fgetc(ch,fp);

		while(*b != '\0'&& *b != ch){
			flat ++;
		}
		count[flat]++;
		flat = 0;
	}
	int i =0;
	for(i = 0;i<48;i++){
		switch(i){
			case 1: 
				printf("a(%d) ",count[i]);break;
			case 2: 
				printf("a(%d) ",count[i]);break;
			case 3: 
				printf("a(%d) ",count[i]);break;
			case 4: 
				printf("a(%d) ",count[i]);break;
			case 5: 
				printf("a(%d) ",count[i]);break;
			case 6: 
				printf("a(%d) ",count[i]);break;
			case 7: 
				printf("a(%d) ",count[i]);break;
			case 8: 
				printf("a(%d) ",count[i]);break;
			case 9: 
				printf("a(%d) ",count[i]);break;
			case 10: 
				printf("a(%d) ",count[i]);break;
			case 1: 
				printf("a(%d) ",count[i]);break;
			case 1: 
				printf("a(%d) ",count[i]);break;
			case 1: 
				printf("a(%d) ",count[i]);break;
			case 1: 
				printf("a(%d) ",count[i]);break;
			case 1: 
				printf("a(%d) ",count[i]);break;
			case 1: 
				printf("a(%d) ",count[i]);break;
			case 1: 
				printf("a(%d) ",count[i]);break;
			case 1: 
				printf("a(%d) ",count[i]);break;
			case 1: 
				printf("a(%d) ",count[i]);break;
			case 1: 
				printf("a(%d) ",count[i]);break;
			case 1: 
				printf("a(%d) ",count[i]);break;
			case 1: 
				printf("a(%d) ",count[i]);break;
			case 1: 
				printf("a(%d) ",count[i]);break;
			case 1: 
				printf("a(%d) ",count[i]);break;
			case 1: 
				printf("a(%d) ",count[i]);break;
			case 1: 
				printf("a(%d) ",count[i]);break;
			case 1: 
				printf("a(%d) ",count[i]);break;
			case 1: 
				printf("a(%d) ",count[i]);break;
			case 1: 
				printf("a(%d) ",count[i]);break;
			case 1: 
				printf("a(%d) ",count[i]);break;
			case 1: 
				printf("a(%d) ",count[i]);break;
			case 1: 
				printf("a(%d) ",count[i]);break;
			case 1: 
				printf("a(%d) ",count[i]);break;
			case 1: 
				printf("a(%d) ",count[i]);break;
			case 1: 
				printf("a(%d) ",count[i]);break;
			case 1: 
				printf("a(%d) ",count[i]);break;
			case 1: 
				printf("a(%d) ",count[i]);break;
			case 1: 
			case 1: 
				printf("a(%d) ",count[i]);break;
			case 1: 
				printf("a(%d) ",count[i]);break;
				printf("a(%d) ",count[i]);break;
		}//end switch
	}
	fclose(fp);
	return 0;
}

