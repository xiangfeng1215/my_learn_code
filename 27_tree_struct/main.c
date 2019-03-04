#include "tree.h"

int main(void)
{
	node* t;
	(void)Init_root(&t,1);
	(void)Insert_tree(t,2);
	(void)Insert_tree(t,3);
	(void)Insert_tree(t,4);
	(void)Insert_tree(t,5);
	(void)Insert_tree(t,6);
	(void)Insert_tree(t,7);
	(void)Pre_order(t);
	putchar(10);

	(void)Mid_order(t);
	putchar(10);

	(void)Rear_order(t);
	putchar(10);
	return 0;
}
