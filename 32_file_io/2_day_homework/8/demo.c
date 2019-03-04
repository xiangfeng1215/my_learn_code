#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

void swp(int *p1, int *p2)  //交换函数
{
	int tmp;
	tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void sort(int *p) //数组排序函数
{
	int i, j,*tmp;
	for(i = 0; i < 10; i++) {
		for(j = i; j < 10; j++)
			if(p[i] < p[j])
			swp(&p[i], &p[j]);
	}   
}


int main(int argc ,char* argv)
{
	int fp1 = open("./zxf.txt",O_RDONLY);
	if( fp1 < 0){
		perror("open zxf.txt");
		return -1;
	}
	int fp2 = open("./new.txt",O_RDWR|O_CREAT,0666);
	if( fp2 < 0){
		perror("open ./new.txt");
		return -1;
	}
	dup2(fp1,0);
	dup2(fp2,1);
	int i = 0;
	int a[10];
	for(i = 0; i < 10; i++ ){
		scanf("%d",&a[i]);
	}
//	sort(a);
	int j;
	for(i = 0;i < 10; i++){
		for(j = i; j < 10 ;j++){
			if(a[i] > a[j]){
				a[j] ^= a[i];
				a[i] ^= a[j];
				a[j] ^= a[i];
			}

		}
	}
	for(i = 0; i < 10; i++){
		printf("%d\n",a[i]);
	}
	close(fp1);
	close(fp2);
	return 0;
}
