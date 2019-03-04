#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i=10,j=11;
	int *const p1 = &i;
	int const *p2 = &i;//const int *p;
	int *const* p3 = &i;

	p1 = &j;
	printf("*p1 %d\n",*p1);
	return 0;
}
