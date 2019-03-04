#include "stack.h"

int main(void)
{
	char a[100];
	printf("input string:\n");
	scanf("%s",a);
	printf("input string: %s\n",a);
	if(Hui_wen(a)){
		printf("it is hui wen \n");
	}else{
		printf("it is not hui wen\n");
	}
	return 0;
}
