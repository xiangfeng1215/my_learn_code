#include <stdio.h>
#include <stdlib.h>

typedef int ARRAY[2][3];

int main(void)
{
	int a[2][3] = {1,2,3,4,5,6};
	ARRAY* pa = &a;
	printf("pa +1  = %p  \n",pa+1);
	printf("(*)pa[3] = %d\n",(*pa)[1][1]);
	return 0;
}
