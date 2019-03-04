#include "hash.h"

int main(void)
{
	//ARRAT_TYP arr;
	node* arr[10];
	(void)Init_hash(arr,10);

	int input;
	scanf("%d",&input);
	while(input != -1){
		if(!Add_hash(arr,input))
			break;
		scanf("%d",&input);
		getchar();
	}
	(void)Traverse(arr,10);
	(void)Delete_hash(arr,2);
	(void)Traverse(arr,10);
	return 0;
}
