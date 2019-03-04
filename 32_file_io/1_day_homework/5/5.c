#include <stdio.h>
#include <string.h>

typedef struct student{
	char number[20];
	char name[20];
	float math;
	float english;
	float language;
}student;


int main(void)
{
	FILE* fp = fopen("./stud","w+");
	if(!fp)
		return -1;
	student s[5];
	int i = 0;
	float avr =0;
	while( i < 5){
		printf("please input data\n");
		printf("number\tname\tmath\tenglish\tlanguage\n");
		scanf("%s%s%f%f%f",s[i].number,s[i].name,&s[i].math,&s[i].english,&s[i].language);
		avr= (s[i].math + s[i].english +s[i].language)/3;
		fprintf(fp,"number:%s;name:%s;math:%f;english:%f;language:%f;avr:%f\n",s[i].number,s[i].name,s[i].math,s[i].english,s[i].language,avr);
		i++;
	}	
	fclose(fp);
	return 0;
}
