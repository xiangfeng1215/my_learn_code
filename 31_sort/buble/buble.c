#include <stdio.h>

int main(void)
{
	int a[10] = {1,2,34,4,3,67,9,78,43,43};
	int i =0;
	int j =0;
	for(i =0; i < 10 ;i++){
		for(j =0;j < 9;j++){
			if(a[j] > a[j+1]){
				a[j]^= a[j+1];
				a[j+1]^= a[j];
				a[j]^= a[j+1];
			}
		}
	}
	for(i =0;i < 10;i++)
	{

			printf("->%d",a[i]);
	}
	return 0;
}
