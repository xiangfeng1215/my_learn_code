#include <stdio.h>
#include <string.h>

struct gril{
	char name[20];
	int ID;
};

int main(void)
{
	struct gril mm = {"mm",250};
	struct gril mm2 = {"mm2",260};
	struct gril yy;
	FILE* fp = fopen("girl.txt","w+");
	if(!fp){
		perror("fopen");
		return 0;
	}
	if((fwrite(&mm,sizeof(struct gril),1,fp)) <0){
		perror("fwrite");
	}
	if((fwrite(&mm2,sizeof(struct gril),1,fp)) <0){
		perror("fwrite");
	}
	rewind(fp);
	if(fread(&yy,sizeof(struct gril),1,fp) < 0){
		perror("fread");
	}
	printf("%s %d\n",yy.name,yy.ID);
	if(fread(&yy,sizeof(struct gril),1,fp) < 0){
		perror("fread");
	}
	printf("%s %d\n",yy.name,yy.ID);
	fclose(fp);
	return 0;
}
