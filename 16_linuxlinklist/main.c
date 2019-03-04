#include "linuxlinklist.h"

int main(void)
{
	node *head = Init_ret_head();
	(void)Create_list(head);
	(void)Traverse(head);
	printf("list_move_tail 3\n");
	(void)List_move_tail(3,head);
	(void)Traverse(head);	
	return 0;
}
