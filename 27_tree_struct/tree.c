#include "tree.h"

void Init_root(node** root,int input)
{
	*root = (node*)malloc(sizeof(node));
	if(!(*root)){
		exit(-1);
	}
	(*root)->data = input;
	(*root)->lchild = NULL;
	(*root)->rchild = NULL;
}//end init root

bool Insert_tree(node* root,int input)
{

		if(input > root->data && root->rchild == NULL){
			node* pnew = (node*)malloc(sizeof(node));
			if(!pnew){
				return false;
			}
			pnew->data = input;
			pnew->lchild = NULL;
			pnew->rchild = NULL;
			root->rchild = pnew;
		}
		if(input < root->data && root->lchild == NULL){
			node* pnew = (node*)malloc(sizeof(node));
			if(!pnew){
				return false;
			}
			pnew->data = input;
			pnew->lchild = NULL;
			pnew->rchild = NULL;
			root->lchild = pnew;
		}
		if(input > root->data){
			Insert_tree(root->rchild,input);
		}
		if(input < root->data){
			Insert_tree(root->lchild,input);
		}
}//end Insert

void Pre_order(node* root)
{
	if(!root)
		return ;
	else{
		printf("->%d",root->data);
		Pre_order(root->lchild);
		Pre_order(root->rchild);
	}
}//end pre_order

void Mid_order(node* root)
{
	if(!root)
		return;
	else{
		Mid_order(root->lchild);
		printf("->%d",root->data);
		Mid_order(root->rchild);
	}
}//end middle order	

void Rear_order(node* root)
{
	if(!root)
		return;
	else{
		Rear_order(root->lchild);
		Rear_order(root->rchild);
		printf("->%d",root->data);
	}
}//end Rrar order
