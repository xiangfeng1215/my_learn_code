#include "liststack.h"

int main(void)
{
	stack* head = NULL;
	(void)Init_head(&head);

	int i=0;
	for(i = 0;i< 10;i++){
		push(head,i);
	}
	(void)Display(head);

	sleep(1);

	return 0;
}
