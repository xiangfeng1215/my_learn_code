#include "tree.h"

void Init(node** t ,datatype input)
{
	*t = (node*)malloc(sizeof(node));
	if(!(*t)){
		exit(-1);
	}
	(*t)->data = input;
	(*t)->lchild = NULL;
	(*t)->rchild = NULL;
}//end init

bool Insert(node* t,datatype input)
{
	if(input < t->data && t->lchild == NULL)
	{
		node* pnew = (node*)malloc(sizeof(node));
		if(!pnew){
			return false;
		}
		pnew->data = input;
		pnew->lchild = NULL;
		pnew->rchild = NULL;

		t->lchild = pnew;
	}
	if(input > t->data && t->rchild == NULL){
		node* pnew = (node*)malloc(sizeof(node));
		if(!pnew){
			exit(-1);
		}
		pnew->data = input;
		pnew->lchild = NULL;
		pnew->rchild = NULL;

		t->rchild = pnew;
	}

	if(input < t->data){
		Insert(t->lchild,input);
	}
	if(input > t->data){
		Insert(t->rchild,input);
	}
}//end insert

void Pre_traverse(node* t)
{
	if(!t)
		return;
	else{
		printf("->%d",t->data);
		Pre_traverse(t->lchild);
		Pre_traverse(t->rchild);
	}
}//end pre traverse

void Mid_traverse(node* t)
{
	if(!t)
		return;
	else{
		Mid_traverse(t->lchild);
		printf("->%d",t->data);
		Mid_traverse(t->rchild);
	}
}//end mid traverse

void Rear_traverse(node* t)
{
	if(!t){
		return;
	}else{
		Rear_traverse(t->lchild);
		Rear_traverse(t->rchild);
		printf("->%d",t->data);
	}
}//end rear traverse
