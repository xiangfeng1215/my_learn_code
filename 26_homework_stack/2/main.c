#include "stack.h"

int main(void)
{
	printf("statc\n");
	stack s;
	int i=0;
	(void)Init_stack(&s);
	int ai;
	while(1){
		scanf("%d",&ai);
		getchar();
		if(ai != -1)
			Push(&s,ai);
		if(ai == -1)
			Pop(&s);
		(void)Display(s);
	}
	return 0;
}
