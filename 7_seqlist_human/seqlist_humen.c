#include "seqlist_humen.h"

typedef struct seqlist seqlist;

void Init_list(seqlist* list)
{
	list->data = (struct humen*)malloc(sizeof(struct humen)*INIT_SIZE);
	if(!list->data){
		printf("list malloc failed!\n");
		exit(-1);
	}
	list->last = -1;
	list->size = INIT_SIZE;
	list->incresize = INCRESIZE;
}//end init_list

static inline bool increment(seqlist* list)
{
	struct humen* tmp = (struct humen*)malloc(sizeof(struct humen)*(list->size+list->incresize));
	if(!tmp){
		return false;
	}
	int i = 0;
	for(;i<=list->last;i++){
		tmp[i]=list->data[i];
	}
	free(list->data);

	return true;
}//end increment


bool Insert_data(struct seqlist* list,int loc,struct humen input)
{
	if(loc <0 || loc >list->last+1){
		printf("insert ill");
		return false;
	}
	if(list->last == list->size -1){
		printf("list full\n");
		if(increment(list)){
			printf("increment success");
		}else{
			return false;
		}
	}
	int i = list->last;
	for(;i >=loc;i--){
		list->data[i+1] = list->data[i];
	}
	list->data[loc] = input;
	list->last = list->last + 1;

	return true;
}//insert data

void Traverse_list(struct seqlist list)
{
	int i = 0;
	for(;i <= list.last;i++){
		printf("name:%s \n age:%d\n",list.data[i].name,list.data[i].age);
	}
}//end traverse list

bool Delete_list(struct seqlist* list,int loc)
{
	if(loc > 0 && loc<= list->last){
		int i=loc;
		for(;i <= list->last; i++){
			list->data[i] = list->data[i+1];
		}
		list->last--;
	}else{
		printf("delete failed!\n");
		return false;
	}
}//end delete_list

bool Change_list(struct seqlist* list,int key,struct humen input)
{
	int i = 0;
	for(;i <= list->last;i++){
		if(list->data[i].age == key){
			list->data[i] = input;
			printf("change list success!\n");
			return true;
		}
	}
	printf("change list failed!\n");
	return false;
}//end change_list


bool Search_list(struct seqlist list,int key)
{
	int i = 0;
	for(;i <= list.last;i++){
		if(list.data[i].age == key){
			printf("find data !\nname:%s  age:%d\n",list.data[i].name,list.data[i].age);
			return true;
		}
	}
	printf("can't find \n");
	return false;
}//end search list

bool Destory_list(struct seqlist* list)
{
	free(list->data);
	list->last = -1;
	list->data = NULL;
	list->size = 0;
	list->incresize = 0;
}//end destory list

