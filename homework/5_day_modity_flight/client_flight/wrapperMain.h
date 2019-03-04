#ifndef _WRAPPERMAIN_H_
#define _WRAPPERMAIN_H_

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

#include "flight.h"
#include "shm.h"
#include "sem.h"
#include "memoryManger.h"
extern char *admin;
extern char *password;


void Menu_interface(struct node* head_flight,struct node_pasger* head_pasger);
void Admin_interface(struct node* head_flight,struct node_pasger* head_pasger);
void User_interface(struct node* head_flight,struct node_pasger* head_pasger);
/******************flight************************/
void Add_flight(struct node *head_flight);
void Delete_flight(struct node* head_flight);
void Modity_flight(struct node* head_flight);
void Check_flight(struct node* head_flight);
void Show_flight(struct node* head_flight);
void Show_pasger(struct node_pasger* head_pasger);
/******************flight************************/

/*******************pasger*****************************/
int Seat_show(struct node_pasger* head_pasger,char* number);
void Book_ticket(struct node* head_flight,struct node_pasger* head_pasger);
void Ticket_changing(struct node* head_flight,struct node_pasger* head_pasger);
void Refund_ticket(struct node_pasger* head_pasger);
void Check_ticket(struct node_pasger* head_pasger);
/**********************pasger**********************/

/*===========================RW file init================================
 *  mode : 1 is to w ,2 is to r
 =============================RW file init=================================*/

void RW_file_init(struct node *flight_head,struct node_pasger *pasger_head,int mode);


#endif
