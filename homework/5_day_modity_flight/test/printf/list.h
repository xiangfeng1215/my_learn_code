#ifndef _LIST_H_
#define _LIST_H_

#define LIST_INIT_SIZE 8912
#define SHARED_SIZE 8192
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
/**************************************************************************/
struct passenger{
	char name[20];
	int ID;
	struct flight fmsg;
};


typedef struct passenger elemtype;

typedef struct{
	elemtype* addr;
	int length;
	int listsize;
}sqlist;

extern void InitList(sqlist *l,elemtype* addr);



#endif
