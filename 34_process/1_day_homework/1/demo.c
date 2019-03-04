/*
 *  author : zeng xinag feng
 *  content :三个进程打印一个三角形，每次运行都是不同的三角型
 *
 *  time : 2018 - 2 - 21 17:01
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc,char** argv)
{
	pid_t pid;
	pid = fork();
	if(pid < 0){
		exit(-1);
	}else if(pid == 0)
	{
#if 0
		//child
		int i =10;
		while(i){
			printf("*");
			sleep(1);
			i--;
			fflush(stdout);
		}		
#endif
	}else{
		//parent
#if 0
		int i = 10;
		while(i){
			printf("#");
			sleep(1);
			i--;
			fflush(stdout);
		}
		printf("end parent\n");
#endif
		double a = 8,b =8 ,c = 8,p,s,t;
		int h;
		p = (a + b + c)/2;
		s = sqrt(p*(p-a)*(p-b)*(p-c));
		h = (int)((2 * s)/a);
		printf(" h %d\n",h);
		t = (int)sqrt(c * c - h*h);
		printf(" t %d\n",(int)t);
		char tri[h][(int)a];
		int i,j;
		for(i =0 ;i < h ;i++){
			for(j = 0;j < a;j++){
				tri[i][j] = ' ';
			}
		}
		
		for(i = 0; i < a;i++)
			tri[0][i] = '*';

		for(i =1 ;i < h ;i++){
			for(j = 1;j < t;j++){
				if(i == j){
					tri[i][j] = '*';
					printf("i %d j %d %c\n",i,j,tri[i][j]);
				}
			}
		}
		for(i =h-1 ;i > 0;i--)
			for(j = t+1;j < a;j++){
				if((h-i) == (j-t))
				tri[i][j] = '*';
			}
		
		for(i =0 ;i < h ;i++){
			for(j = 0;j < a;j++){
				if(i == 0){
					printf("%c ",tri[i][j]);
				}else{
					printf("%c",tri[i][j]);

				}
			}
			putchar(10);
		}
		waitpid(pid,NULL,0);
	}
	return 0;
}

