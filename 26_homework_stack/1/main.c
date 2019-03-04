#include "doul_stack.h"

int main(void)
{
	doulstack s;
	(void)Init_doul_stack(&s);
#if 1
	printf("stack top\n");
	(void)Push_doul_stack_top(&s,1);
	(void)Push_doul_stack_top(&s,2);
	(void)Push_doul_stack_top(&s,3);
	(void)Push_doul_stack_top(&s,4);
	(void)Display_doul_stack_top(&s);
	(void)Pop_doul_stack_top(&s);
	(void)Display_doul_stack_top(&s);
	
	printf("stack bot\n");
	(void)Push_doul_stack_bot(&s,10);
	(void)Push_doul_stack_bot(&s,20);
	(void)Push_doul_stack_bot(&s,30);
	(void)Push_doul_stack_bot(&s,40);
	(void)Display_doul_stack_bot(&s);
	(void)Pop_doul_stack_bot(&s);
	(void)Display_doul_stack_bot(&s);
#endif
	return 0;
}
