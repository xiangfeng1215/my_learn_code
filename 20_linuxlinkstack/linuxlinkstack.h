#pragma once 

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"

struct humen
{
	char name[20];
	int age;
	int number;
};

struct node{
	struct humen data;
	struct list_head list;	
};

extern void Init_head(struct node **head_loc);
extern bool Insert_data(struct node *head,int num,struct humen *input);
extern bool Insert_data_tail(struct node *head,int num,struct humen *input);
extern bool Delete_data(struct node *head,int num);
extern struct node* Find_node_pos(struct node* head,int num);
extern void Traverse(struct node *head);
extern void Traverse_reverse(struct node *head);
extern void Traverse_continue(struct node* head,struct node* pos);
extern void Traverse_continue_reverse(struct node* head,struct node* pos);
extern bool My_replace(struct node *head,int num,struct humen tmp);
extern bool My_move(struct node* head,int num);
extern bool My_move_tail(struct node* head,int num);
extern bool My_rotate_left(struct node* head);
extern bool List_add_head(struct node* head,struct humen pnew);
extern bool List_empty(struct node* head);
extern bool List_is_singular(struct node* head);
extern bool Liat_is_last(struct node* head,struct node* pos);
extern void List_copy(struct node* head_src,struct node* head_dest);
extern bool List_cut_position(struct node* head_src,struct node* head_dest,int num);
extern void List_splice_tail(struct node* head_src,struct node* head_dest);
extern void List_splice(struct node* head_src,struct node* head_dest);
extern void List_splice_init(struct node* head_src,struct node* head_dest);
extern void List_splice_tail_init(struct node* head_src,struct node* head_dest);

extern bool Push(struct node* head,struct humen element);
extern bool Pop(struct node* headd);



