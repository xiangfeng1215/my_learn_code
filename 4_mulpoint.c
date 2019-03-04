#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int *p = (int*)malloc(100);
	if(!p){
		printf("malloc failed!\n");
		return -1;
	}
	int **q = NULL;
	*q = (int*)malloc(sizeof(double));
	if(*q == NULL){
		printf("*q = NULL\n");
		return -1;
	}
	return 0;
}

/******
洛必达法则，二级指针依赖于一级指针，同理三级依赖于二级指针，二级再依赖于一级指针
  ******/
