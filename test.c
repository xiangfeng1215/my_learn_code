#include <stdio.h>
#include <stdlib.h>

typedef int ARRAY[5];

int main(void)
{
	int a[5] = {1,2,3,4,5};
	ARRAY* pa = NULL;
	int *qa = a;
	pa = &a;

	printf("qa= %p \n",qa);
	printf("a = %p \n",a);
	printf("pa = %p  \n",pa);
	printf("qa +1 = %p \n",qa+1);
	printf("a +1 = %p \n",a+1);
	printf("pa +1  = %p  \n",pa+1);
	printf("(*)pa[3] = %d\n",(*pa)[3]);
	return 0;
}
