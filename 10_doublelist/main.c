#include "doublelist.h"

int main(void)
{
	dlist *head = Init_ret_head();
	(void)Create_list(head);
	(void)Traverse_list(head);
	return 0;
}
