#include "seqlist_humen.h"

int main(void)
{
	struct seqlist list;
	struct humen input[3];
	(void)Init_list(&list);
	int i = 0;
	for(i = 0;i < 3;i++){
		scanf("%s %d",input[i].name,&input[i].age);
		getchar();
		(void)Insert_data(&list,i,input[i]);
	}
	Traverse_list(list);
	return 0;
}
