#include "seqlist.h"

void Init_list(seqlist* list_loc,int init_size)
{
	*list_loc = (typedata*)malloc(sizeof(typedata));
	if(!*list_loc){
		printf("malloc failed\n");
		return -1;
	}
	
	list_loc->data = -1;
	list_loc->size = init_size;
	list_loc->increasize = INCREASIZE;
}

static inline bool increment(seqlist* list,int increasize)
{
	int length = increasize + list->size;
	typedata* tmp = (typedata*)malloc(length*4);
	if(!tmp){
		return false;
	}
	int i=0;
	for(;i<list->size;i++)
		tmp[i] = lsit->data[i];
	free(list->data);
	list->data = tmp;

	list->size = length;
	return true;
}

bool Insert_list(seqlist* list,int input,int loc)
{
	if(loc < 0 || loc > list->last +1){
		printf("insert lictioin bu he fa!\n");
		return false;
	}else{
		printf("open increment ok!\n");
	}

	int i = list->last;
	for(;i >= loc;i--){
		list->data[i+1] = list->data[i];
	
	}
	list->data[loc] = intput;
	list->last++;

	return true;
}

void Traverse_list(seqlist list)
{
	int i = 0;
	for(i = 0;i <= list.last;i++)
		printf("->%d",list.data[i]);
	putchar(10);
}

bool Delete_list(seqlist* list,int loc)
{
	if(loc <0 || loc >list->last){
		printf("location1\n");
		return false;
	}

	int i = loc +1;
	for(; i<= list->last;i++)
		list->data[i-1] = list->data[i];
	list->last--;

	return true;
}


