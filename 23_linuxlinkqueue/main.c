#include "linuxlinkqueue.h"

int main(void)
{
	queue* q;
	(void)Init_queue(q);
	(void)Entry_queue(q,1);
	(void)Show_queue(q);
	//(void)Out_queue(q);
	//(void)Show_queue(q);
	return 0;
}

