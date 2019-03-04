#pragma once 
#include "flight.h"

struct passenger{
	char name[20];
	int ID;
	struct flight fmsg;
};

struct node_pasger{
	struct passenger data;
	struct list_head list;	
};

extern void Init_head_pasger(struct node_pasger **head_loc);
extern bool Create_list_pasger(struct node_pasger* head);
extern bool List_add_head_pasger(struct node_pasger* head,struct passenger pnew);
extern bool Insert_data_pasger(struct node_pasger *head,struct passenger *input,struct passenger key,int mode);
extern bool Delete_data_pasger(struct node_pasger *head,struct passenger key,int mode);
extern struct node_pasger* Find_node_pos_pasger(struct node_pasger* head,struct passenger key,int mode);
extern void Traverse_pasger(struct node_pasger *head,struct passenger key,int mode);
extern bool List_empty_pasger(struct node_pasger* head);

extern bool My_replace_pasger(struct node_pasger *head,struct passenger data,struct passenger key,int mode);



