#include <stdio.h>

__attribute__((weak)) void hello();

int main(void)
{
	if(hello)
		hello();
	return 0;
}
