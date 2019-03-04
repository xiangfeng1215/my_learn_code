#include "hash.h"

void Init_hash(node* arr[],int len)
{
	bzero(arr,len*4);
}//end init hash

int Hash_func(int element)
{
	return element%10;
}//end hash func

bool Add_hash(node* arr[],int element)
{
	int loc = Hash_func(element);
	if(!arr[loc]){
		arr[loc] = (node*)malloc(sizeof(node));
		if(!arr[loc]){
			return false;
		}

		arr[loc]->data = element;
		arr[loc]->next = NULL;
		return true;
	}

	node* pcur = arr[loc];
	while(pcur->next != NULL){
		pcur = pcur->next;
	}

	node* pnew = (node*)malloc(sizeof(node));
	if(!pnew){
		return false;
	}
	pnew->data = element;
	pnew->next = NULL;

	pcur->next = pnew;
	pnew->next = NULL;

	return true;

}//end add hash

void Traverse(node* arr[],int len)
{
	int i =0;
	node* pcur = NULL;
	for(i =0;i <len;i++){
		printf("hash[%d]->",i);
		pcur = arr[i];
		while(pcur != NULL){
			printf("%d-<",pcur->data);
			pcur = pcur->next;
		}
		putchar(10);
	}
}//end traverse

bool Delete_hash(node* arr[],int key)
{
	int loc = Hash_func(key);
	
	node* pcur = arr[loc];
	node* ppre = arr[loc];

	while(pcur != NULL && pcur->data != key){
		pcur = pcur->next;
	}

	if(pcur == arr[loc]){
		ppre = arr[loc];
		arr[loc]->next = ppre->next;
		ppre->next = NULL;
		free(ppre);
		return true;
	}else{

		while(ppre != NULL && ppre->next != pcur){
			ppre = ppre->next;
		}

		ppre->next = pcur->next;
		pcur->next = NULL;
		free(pcur);

		return true;
	}
}//end delete data

bool Search_hash(node* arr[],int key,int len)
{
	int i = 0;
	node* pcur = NULL;
	for(i = 0;i <len; i++){
		printf("Hash[%d]->",i);
		pcur = arr[i];
		while(pcur != NULL){
			if(pcur->data == key){
				printf("find it %d,",pcur->data);
				return true;
			}
		}
	}
	return false;
}//end search_hash

bool Modify_hash(node* arr[],int key,int len)
{
	int i =0;
	node* pcur = NULL;
	for(i =0;i <len;i++){
		printf("hasd[%d]->",i);
		pcur = arr[i];
		while(pcur != NULL){
			if(pcur->data == key){
				pcur->data = key;
				printf("modity success!\n");
				return true;
			}
		}
	}
	return false;
}//end modify_hash
