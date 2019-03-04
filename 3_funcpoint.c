#include <stdio.h>
#include <stdlib.h>

typedef void* FUNC_TYPE(void);
typedef void* (*FUNC_POINT)(void);

void* my_malloc(void)
{
	void* p = NULL;
	p = (void*)malloc(100);
}

void* func(void)
{
	return (void*)1;
}

int main(void)
{
	FUNC_TYPE *pf = my_malloc;
	FUNC_POINT a[2] = {my_malloc,func};

	printf("func_ret = %p\n",a[1]());
	void* p = pf();
	
	if(!p)
		printf("malloc failed!\n");
	else
		printf("malloc ok!\n");

	return 0;
}
