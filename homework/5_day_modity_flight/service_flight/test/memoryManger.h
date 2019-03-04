#ifndef _MEMORYMANAGE_H_
#define _MEMORYMANAGE_H_
#include <stdbool.h>
#include "wrapperMain.h"

#include "flight.h"

typedef struct mem_st{
	int cur_f;
	int mem_size_f;
	int data_size_f;

	int cur_p;
	int mem_size_p;
	int data_size_p;

	struct flight f;
	struct passenger p;
}memst;

extern void Init_mem(memst* m,int mem_size,int data_size_f,int data_size_p);
extern bool Push(void *addr,memst* m,char mode);
extern bool Pop(void *addr,memst* m,char mode);
extern bool Is_empty(memst* m,char mode);
extern bool Is_full(memst* m,char mode);
extern void *sharedMemory_write(void);
extern void RW_shared_memorty(struct node *flight_head,struct node_pasger *pasger_head,int mode,struct mem_st *m,void *addr);

#endif
