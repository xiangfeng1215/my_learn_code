#include <stdio.h>
#include <string.h>
struct gril{
	char name[20];
	int ID;
};
int main(void)
{
	FILE* fp = fopen("./struct.txt","w+");
	if(!fp)
		return -1;

	struct gril mm = {"lili",520};

	fprintf(fp,"name : %s ;ID : %d ;\n",mm.name,mm.ID);
	rewind(fp);
	struct gril yy;
	fscanf(fp,"name : %s ;ID : %d ;\n",yy.name,&yy.ID);
	printf("name : %s;id %d\n",yy.name,yy.ID);
	fclose(fp);
	return 0;
}

