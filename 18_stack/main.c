#include "stack.h"

int main(void)
{
	printf("statc\n");
	stack s;
	int i=0;
	(void)Init_stack(&s);
	char ch;
	while(1){
		printf("**************************************\n");
		printf("***********choose op!*****************\n");
		printf("**************************************\n");
		printf("*****1. i to push data!***************\n");
		printf("*****2. d to poop data!***************\n");
		printf("*****3. q ot Q is quit!***************\n");
		printf("**************************************\n");
		printf("**********please input****************\n");
		printf("**************************************\n");
		scanf("%c",&ch);
		getchar();
		if(ch == 'q'|| ch == 'Q')
			break;
		if(ch == 'i')
			Push(&s,++i);
		if(ch == 'd')
			Pop(&s);
		(void)Display(s);
	}
	return 0;
}
