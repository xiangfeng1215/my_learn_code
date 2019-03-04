#include "seqqueue.h"

int main(void)
{
	queue* q;
	(void)Init_q(q);

	int input;
	printf("input data:\n");
	scanf("%d",&input);
	while(input != -1)
	{
		entry_queue(q,input);
		scanf("%d",&input);
		getchar();
	}


	return 0;
}
