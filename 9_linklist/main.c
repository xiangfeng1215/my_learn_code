#include "linklist.h"

typedef struct linklist linklist;

int main(void)
{
	linklist* head = NULL;
	(void)Init_head(&head);
	(void)Create_list(head);
	(void)Traverse_list(head);

	return 0;
}
