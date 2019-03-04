#include "linklist.h"

int main(void)
{
	linklist* f = Init_head();
	(void)Create_list(f);
	(void)Traverse_list(f);	
	printf("Max_number=%d\n",Max_number(f));
	printf("Inode_number=%d\n",Inode_number(f));
	printf("Average=%2.3f\n",Average_list(f)/Inode_number(f));
	return 0;
}
