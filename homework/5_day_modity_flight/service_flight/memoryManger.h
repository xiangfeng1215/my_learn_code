#ifndef _MEMORYMANGER_H_
#define _MEMORYMANGER_H_
#include "flight.h"
#define DEBUG 0
extern int sharedMemory_write(int proj_id);
extern void RW_shared_memorty(struct node *flight_head,struct node_pasger *pasger_head,int mode,struct flight *addr_f,struct passenger *addr_p);

#endif
