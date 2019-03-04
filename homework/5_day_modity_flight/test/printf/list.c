#include "sem.h"
#include "shm.h"
#include "list.h"

void InitList(sqlist *l,elemtype* addr)
{
	l->addr = addr;
	l->length = 0;
	l->listsize = SHARED_SIZE/sizeof(struct passenger);
}//initlist


