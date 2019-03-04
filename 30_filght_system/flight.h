#pragma once 

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"
#include <time.h>
#include "print.h"
#include <string.h>
#include <strings.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include "fly.h"

struct flight{
	char number[18];
	char staddress[18];
	char arraddress[18];
	char DATE[12];
	char TYPE[8];
    long int stime;
	long int atime;
	int value;
	int seat_size;
	int poll;
	int seat_left;
};
typedef struct flight data_type;
struct node{
	data_type data;
	struct list_head list;	
};
/**************************************************************************/


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
extern bool List_empty_pasger(struct node_pasger* head);

extern bool My_replace_pasger(struct node_pasger *head,struct passenger data,struct passenger key,int mode);


extern void Traverse_pasger(struct node_pasger *head,int mode);
extern void Remind_pasger(struct node_pasger* head);
extern bool Clean(struct node* head,struct node_pasger* head2);
extern void Input_pasger_interface(struct passenger* pasger);

/*************************************************************************/
extern void Init__head_flight(struct node **head_loc);
extern bool Create_list_flight(struct node *head);
extern bool List_add_head_flight(struct node* head,struct flight pnew);
extern bool Insert_data_flight(struct node *head,struct flight *input,struct flight key,int mode);
extern bool Delete_data_flight(struct node *head,struct flight key,int mode);
extern struct node* Find_node_pos_flight(struct node* head,struct flight key,int mode);
extern bool List_empty_flight(struct node* head);
extern void Choose_modity_flight(struct node* pos,char *s,int t,long int t1);
extern bool My_replace_flight(struct node *head,struct flight key,int mode);
extern void Traverse_flight(struct node *head,int mode);
extern void Remind_flight(struct node *head);
extern bool Clean_flight(struct node *head);
extern void Input_flight_interface(struct flight* fly);
extern void Check_list_flight(struct node* head,struct flight key,int mode);

/****************************************************************************/
/***************************sort*********************************************/
/****************************************************************************/
extern int cmp_data_flight(struct list_head *a,struct list_head *b,int mode);
extern int cmp_data_pasger(struct list_head *a,struct list_head *b,int mode);
extern void swap(struct list_head *a,struct list_head *b);
extern void bubble_sort(struct list_head* head,int (*compar)(struct list_head*,struct list_head*,int),int mode);

