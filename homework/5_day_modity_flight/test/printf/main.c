#include <stdio.h>
#include <stdlib.h>
#include "print.h"
#include <time.h>
#include <string.h>
#include <strings.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "sem.h"
#include "shm.h"
#include "list.h"




int main(void)
{
	struct flight fly = {"1901","shenha","baijin","2019-02-05","big-520",839,900,222,100,98,98};
	//struct flight fly;
	struct passenger pasger = {"zxf",1315,fly};

	void* addr = (void*)0;
	int shmid_key = sharedMemoryGetKey(11);
	if(shmid_key < 0){
		perror("shmid_key");
		exit(EXIT_FAILURE);
	}
	int shmid = sharedMemoryCreateOrGet(shmid_key,SHARED_SIZE);
	if(shmid < 0){
		perror("shmid");
		exit(EXIT_FAILURE);
	}
	addr =  sharedMemoryAttach(shmid);
	if(addr == NULL){
		perror("sharedMemoryAttach");
		exit(EXIT_FAILURE);
	}

	sqlist list_f;
	struct passenger* addr_p;
	addr_p = (struct passenger*)addr;
	InitList(&list_f,addr);

	pid_t pid = fork();
	if(pid < 0 ){
		perror("pid");
		exit(EXIT_FAILURE);
	}
	else if(pid == 0){
		printf("child\n");
		strcpy(pasger.name,"mylove");
		//bzero(&pasger,sizeof(pasger));
		addr_p[0] = pasger;
		strcpy(pasger.name,"myfeeling");
		addr_p[1] = pasger;
		exit(EXIT_SUCCESS);
	}else if(pid > 0){
		printf("parent\n");
		struct passenger pasger_read = addr_p[0];	
		printf(LIGHT_RED"\t姓名\t身份证号\t航班号\t出发地点\t目地地点\t日期    \t机型      \t出发时间\t到达时间\t价格    \t座位 \n"NONE);
		printf(LIGHT_GREEN"\t%s\t%d\t\t%s\t%s\t\t%s\t\t%s\t%s\t\t%ld\t\t%ld\t\t%d\t\t%d\n"NONE,\
				pasger_read.name,pasger_read.ID,pasger_read.fmsg.number,pasger_read.fmsg.staddress,pasger_read.fmsg.arraddress,pasger_read.fmsg.DATE,pasger_read.fmsg.TYPE,pasger_read.fmsg.stime,pasger_read.fmsg.atime,pasger_read.fmsg.value,fly.seat_left);
		pasger_read = addr_p[1];	
		printf(LIGHT_RED"\t姓名\t身份证号\t航班号\t出发地点\t目地地点\t日期    \t机型      \t出发时间\t到达时间\t价格    \t座位 \n"NONE);
		printf(LIGHT_GREEN"\t%s\t%d\t\t%s\t%s\t\t%s\t\t%s\t%s\t\t%ld\t\t%ld\t\t%d\t\t%d\n"NONE,\
				pasger_read.name,pasger_read.ID,pasger_read.fmsg.number,pasger_read.fmsg.staddress,pasger_read.fmsg.arraddress,pasger_read.fmsg.DATE,pasger_read.fmsg.TYPE,pasger_read.fmsg.stime,pasger_read.fmsg.atime,pasger_read.fmsg.value,fly.seat_left);
		wait(NULL);
	}


#if 0
	FILE* fp = fopen("./flight.txt","a+");
	//fprintf(stdout,"%s %s %s %s %s %ld %ld %d %d %d\n",\
	fly.number,fly.staddress,fly.arraddress,fly.DATE,fly.TYPE,fly.stime,fly.atime,fly.value,fly.seat_size,fly.poll);
	fprintf(fp,"%s %s %s %s %s %ld %ld %d %d %d\n",\
			fly.number,fly.staddress,fly.arraddress,fly.DATE,fly.TYPE,fly.stime,fly.atime,fly.value,fly.seat_size,fly.poll);

	struct stat sb;
	if (stat("./flight.txt", &sb) == -1) {
		perror("stat");
		exit(-1);
	}
	printf("File size:                %lld bytes\n",(long long) sb.st_size);

	if(sb.st_size > 0){

		fscanf(fp,"%s %s %s %s %s %ld %ld %d %d %d\n",\
				fly.number,fly.staddress,fly.arraddress,fly.DATE,fly.TYPE,&fly.stime,&fly.atime,&fly.value,&fly.seat_size,&fly.poll);

		fprintf(stdout,"%s %s %s %s %s %ld %ld %d %d %d\n",\
				fly.number,fly.staddress,fly.arraddress,fly.DATE,fly.TYPE,fly.stime,fly.atime,fly.value,fly.seat_size,fly.poll);
	}else{
		printf("file is empty!\n");
	}

	fclose(fp);
#if 0
	system("clear");


	/***************************************************航班表输入图形界面设计**********************************************************************/
	printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
	printf(LIGHT_CYAN"*******************************************************************中国航班--录入航班**********************************************************************\n"NONE);
	printf(LIGHT_CYAN"**************************************************************Wecome to airline system*********************************************************************\n"NONE);
	printf(LIGHT_CYAN"** 请输入航   班   号："NONE);
	while(1){
		scanf("%s",fly.number);
		getchar();
		if(strlen(fly.number) < 18 && strlen(fly.number) > 0)
			break;
		printf("输入错误，请重新输入！\n");
		printf(LIGHT_CYAN"** 请输入航   班   号："NONE);
	}
	putchar(10);
	printf(LIGHT_CYAN"** 请输入起   点   站："NONE);
	while(1){
		scanf("%s",fly.staddress);
		getchar();
		if(strlen(fly.staddress) < 18 && strlen(fly.staddress) > 0)
			break;
		printf("输入错误，请重新输入！\n");
		printf(LIGHT_CYAN"** 请输入起   点   站："NONE);
	}
	putchar(10);
	printf(LIGHT_CYAN"** 请输入终   点   站："NONE);
	while(1){
		scanf("%s",fly.arraddress);
		getchar();
		if(strlen(fly.arraddress) < 18 && strlen(fly.arraddress) > 0)
			break;
		printf("输入错误，请重新输入！\n");
		printf(LIGHT_CYAN"** 请输入终   点   站："NONE);
	}
	putchar(10);
	printf(LIGHT_CYAN"** 请输入班        期："NONE);
	while(1){
		scanf("%s",fly.DATE);
		getchar();
		if(strlen(fly.DATE) < 12 && strlen(fly.DATE) > 0)
			break;
		printf("输入错误，请重新输入！\n");
		printf(LIGHT_CYAN"** 请输入班        期："NONE);
	}
	putchar(10);
	printf(LIGHT_CYAN"** 请输入机        型："NONE);
	while(1){
		scanf("%s",fly.TYPE);
		getchar();
		if(strlen(fly.TYPE) < 8 && strlen(fly.TYPE) > 0)
			break;
		printf("输入错误，请重新输入！\n");
		printf(LIGHT_CYAN"** 请输入机        型："NONE);
	}
	putchar(10);
	printf(LIGHT_CYAN"** 请输入起 飞  时 间："NONE);
	while(1){
		scanf("%ld",&fly.stime);
		getchar();
		if(235959 >fly.stime >= 0)
			break;
		printf("输入错误，请重新输入！\n");
		printf(LIGHT_CYAN"** 请输入起 飞  时 间："NONE);
	}	
	putchar(10);
	printf(LIGHT_CYAN"** 请输入到 达  时 间："NONE);
	while(1){
		scanf("%ld",&fly.atime);
		getchar();
		if(235959 >fly.atime >= 0)
			break;
		printf("输入错误，请重新输入！\n");
		printf(LIGHT_CYAN"** 请输入到 达  时 间："NONE);
	}	
	putchar(10);
	printf(LIGHT_CYAN"** 请输入票        价："NONE);
	while(1){
		scanf("%d",&fly.value);
		getchar();
		if(2147483647 >fly.value >= 0)
			break;
		printf("输入错误，请重新输入！\n");
		printf(LIGHT_CYAN"** 请输入票        价："NONE);
	}	
	putchar(10);
	printf(LIGHT_CYAN"** 请输入机舱 座 位数："NONE);
	while(1){
		scanf("%d",&fly.seat_size);
		getchar();
		if(1000 >fly.seat_size >= 0)
			break;
		printf("输入错误，请重新输入！\n");
		printf(LIGHT_CYAN"** 请输入机舱 座 位数："NONE);
	}	
	putchar(10);
	printf(LIGHT_CYAN"** 请输入初始剩余票数："NONE);
	while(1){
		scanf("%d",&fly.poll);
		getchar();
		if(1000 >fly.poll >= 0)
			break;
		printf("输入错误，请重新输入！\n");
		printf(LIGHT_CYAN"** 请输入初始剩余票数："NONE);
	}
	putchar(10);
	printf(LIGHT_CYAN"** 请输入初始座位位置："NONE);
	while(1){
		scanf("%d",&fly.seat_left);
		getchar();
		if(1000 >fly.seat_left >= 0)
			break;
		printf("输入错误，请重新输入！\n");
		printf(LIGHT_CYAN"** 请输入初始剩余票数："NONE);
	}
	putchar(10);
	printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
	printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
	printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);	


	//	printf(LIGHT_RED"\033[10C航班号\033[4C出发地点\033[4C目地地点\033[4C日期\033[4C机型\033[4C出发时间\033[4C到达时间\033[4C价格\033[4C总票数\033[4C余票 \n"NONE);
	//	printf(LIGHT_GREEN"\033[10C%s\033[4C%s\033[4C%s\033[4C%s\033[4C%s\033[4C%ld\033[4C%ld\033[4C%d\033[4C%d\033[4C%d\n"NONE,\
	fly.number,fly.staddress,fly.arraddress,fly.DATE,fly.TYPE,fly.stime,fly.atime,fly.value,fly.seat_size,fly.poll);

	/***************************************************航班表图形界面设计**********************************************************************/
	printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
	printf(LIGHT_CYAN"*******************************************************************中国航班系统****************************************************************************\n"NONE);
	printf(LIGHT_CYAN"**************************************************************Wecome to airline system*********************************************************************\n"NONE);
	printf(LIGHT_CYAN"**                                                                                                                                                       **\n"NONE);
	printf(LIGHT_CYAN"**                                                                                                                                                       **\n"NONE);

	printf(LIGHT_RED"**\t航班号\t出发地点\t目地地点\t日期    \t机型      \t出发时间\t到达时间\t价格    \t总票数  \t余票 \n"NONE);
	printf(LIGHT_GREEN"**\t%s\t%s\t\t%s\t\t%s\t%s\t\t%ld\t\t%ld\t\t%d\t\t%d\t\t%d\n"NONE,\
			fly.number,fly.staddress,fly.arraddress,fly.DATE,fly.TYPE,fly.stime,fly.atime,fly.    value,fly.seat_size,fly.poll);
	printf(LIGHT_CYAN"**                                                                                                                                                       **\n"NONE);
	printf(LIGHT_CYAN"**                                                                                                                                                       **\n"NONE);
	printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
	printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
	printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);	


	/**************************************************************************************************************/
	/*************************************************************************************************************/


	sleep(2);

	/***************************************************航班表输入图形界面设计**********************************************************************/
	printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
	printf(LIGHT_CYAN"*******************************************************************中国航班--订票航班**********************************************************************\n"NONE);
	printf(LIGHT_CYAN"**************************************************************Wecome to airline system*********************************************************************\n"NONE);
	printf(LIGHT_CYAN"** 请输入姓        名："NONE);
	while(1){
		scanf("%s",pasger.name);
		getchar();
		if(strlen(pasger.name) < 18 && strlen(pasger.name) > 0 )
			break;
		printf("输入错误，请重新输入！\n");
		printf(LIGHT_CYAN"** 请输入姓        名："NONE);
	}
	putchar(10);
	printf(LIGHT_CYAN"** 请输入身份    证号："NONE);
	while(1){
		scanf("%d",&pasger.ID);
		getchar();
		if( pasger.ID > 0 && pasger.ID <2147483647)
			break;
		printf("输入错误，请重新输入！\n");
		printf(LIGHT_CYAN"** 请输入身份    证号："NONE);
	}
	putchar(10);
	printf(LIGHT_CYAN"** 请输入航   班   号："NONE);
	while(1){
		scanf("%s",pasger.fmsg.number);
		getchar();
		if(strlen(pasger.fmsg.number) < 18 && strlen(fly.number) > 0 )
			break;
		printf("输入错误，请重新输入！\n");
		printf(LIGHT_CYAN"** 请输入航   班   号："NONE);
	}
	putchar(10);
	printf(LIGHT_CYAN"** 请输入起   点   站："NONE);
	while(1){
		scanf("%s",pasger.fmsg.staddress);
		getchar();
		if(strlen(pasger.fmsg.staddress) < 18 && strlen(pasger.fmsg.staddress) > 0)
			break;
		printf("输入错误，请重新输入！\n");
		printf(LIGHT_CYAN"** 请输入起   点   站："NONE);
	}
	putchar(10);
	printf(LIGHT_CYAN"** 请输入终   点   站："NONE);
	while(1){
		scanf("%s",pasger.fmsg.arraddress);
		getchar();
		if(strlen(pasger.fmsg.arraddress) < 18 && strlen(pasger.fmsg.arraddress) > 0)
			break;
		printf("输入错误，请重新输入！\n");
		printf(LIGHT_CYAN"** 请输入终   点   站："NONE);
	}
	putchar(10);
	printf(LIGHT_CYAN"** 请输入班        期："NONE);
	while(1){
		scanf("%s",pasger.fmsg.DATE);
		getchar();
		if(strlen(pasger.fmsg.DATE) < 12 && strlen(pasger.fmsg.DATE) > 0)
			break;
		printf("输入错误，请重新输入！\n");
		printf(LIGHT_CYAN"** 请输入班        期："NONE);
	}
	putchar(10);
	printf(LIGHT_CYAN"** 请输入机        型："NONE);
	while(1){
		scanf("%s",pasger.fmsg.TYPE);
		getchar();
		if(strlen(pasger.fmsg.TYPE) < 8 && strlen(pasger.fmsg.TYPE) > 0)
			break;
		printf("输入错误，请重新输入！\n");
		printf(LIGHT_CYAN"** 请输入机        型："NONE);
	}
	putchar(10);
	printf(LIGHT_CYAN"** 请输入起 飞  时 间："NONE);
	while(1){
		scanf("%ld",&pasger.fmsg.stime);
		getchar();
		if(235959 >pasger.fmsg.stime >= 0)
			break;
		printf("输入错误，请重新输入！\n");
		printf(LIGHT_CYAN"** 请输入起 飞  时 间："NONE);
	}	
	putchar(10);
	printf(LIGHT_CYAN"** 请输入到 达  时 间："NONE);
	while(1){
		scanf("%ld",&pasger.fmsg.atime);
		getchar();
		if(235959 >pasger.fmsg.atime >= 0)
			break;
		printf("输入错误，请重新输入！\n");
		printf(LIGHT_CYAN"** 请输入到 达  时 间："NONE);
	}	
	putchar(10);
	printf(LIGHT_CYAN"** 请输入票        价："NONE);
	while(1){
		scanf("%d",&pasger.fmsg.value);
		getchar();
		if(2147483647 >pasger.fmsg.value >= 0)
			break;
		printf("输入错误，请重新输入！\n");
		printf(LIGHT_CYAN"** 请输入票        价："NONE);
	}	
	putchar(10);
	printf(LIGHT_CYAN"** 请输入机舱 座 位数："NONE);
	while(1){
		scanf("%d",&pasger.fmsg.seat_size);
		getchar();
		if(1000 >pasger.fmsg.seat_size >= 0)
			break;
		printf("输入错误，请重新输入！\n");
		printf(LIGHT_CYAN"** 请输入机舱 座 位数："NONE);
	}	
	putchar(10);
	printf(LIGHT_CYAN"** 请输入初始剩余票数："NONE);
	while(1){
		scanf("%d",&pasger.fmsg.poll);
		getchar();
		if(1000 >pasger.fmsg.poll >= 0)
			break;
		printf("输入错误，请重新输入！\n");
		printf(LIGHT_CYAN"** 请输入初始剩余票数："NONE);
	}
	putchar(10);
	printf(LIGHT_CYAN"** 请输入初始座位位置："NONE);
	while(1){
		scanf("%d",&pasger.fmsg.seat_left);
		getchar();
		if(1000 >pasger.fmsg.seat_left >= 0)
			break;
		printf("输入错误，请重新输入！\n");
		printf(LIGHT_CYAN"** 请输入初始剩余票数："NONE);
	}
	putchar(10);
	printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
	printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
	printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);	


	/*******************************************************航班乘客图形设计******************************************************************************/
	printf(LIGHT_RED"\t姓名\t身份证号\t航班号\t出发地点\t目地地点\t日期    \t机型      \t出发时间\t到达时间\t价格    \t座位 \n"NONE);
	printf(LIGHT_GREEN"\t%s\t%d\t\t%s\t%s\t\t%s\t\t%s\t%s\t\t%ld\t\t%ld\t\t%d\t\t%d\n"NONE,\
			pasger.name,pasger.ID,pasger.fmsg.number,pasger.fmsg.staddress,pasger.fmsg.arraddress,pasger.fmsg.DATE,pasger.fmsg.TYPE,pasger.fmsg.stime,pasger.fmsg.atime,pasger.fmsg.value,fly.seat_left);
	//	system("clear");
#endif
	/*
	   printf(fore1"***********************\n"NONE);
	   printf(fore2"***********************\n"NONE);
	   printf(fore3"***********************\n"NONE);
	   printf(fore4"***********************\n"NONE);
	   printf(fore5"***********************\n"NONE);
	   printf(fore6"***********************\n"NONE);
	   printf(fore7"***********************\n"NONE);
	   printf(fore8"***********************\n"NONE);

	   printf(back1"***********************\n");
	   printf(back2"***********************\n");
	   printf(back3"***********************\n");
	   printf(back4"***********************\n");
	   printf(back5"***********************\n");
	   printf(back6"***********************\n");
	   printf(back7"***********************\n");
	   printf(back8"***********************\n"NONE);
	 */
#endif

#if 0
	int i1,i2,i3,i4,i,j,n = 6;
	for(i = 11,j = 0; j < n; i--,j++){
		for(i1 = 0;i1 <= i-2*j;i1++){
			printf(RIGHT RED"#"NONE);
			fflush(stdout);
			usleep(100000);
		}
		for(i2=0;i2 <= i-2*j-1;i2++){
			printf(LEFT1 DOWN BLUE"#"NONE);
			fflush(stdout);
			usleep(100000);
		}
		for(i3 = 0;i3 <= i-2*j-1;i3++){
			printf(LEFT GREEN"#"NONE);
			fflush(stdout);
			usleep(100000);
		}
		for(i4=0; i4 < i-2*j;i4++){
			printf(LEFT1 UP YELLOW"#"NONE);
			fflush(stdout);
			usleep(100000);
		}
		printf(DOWN RIGHT);
	}
#endif
	/*
	   printf(UP"####################\n");
	   printf("***********************\n");
	   printf(RIGHT"***********************\n");
	   printf(LEFT "***********************\n");
	   printf(F3 "***********************\n");
	   printf(CLEAR"***********************\n");
	   printf(CLEAN"***********************\n");
	   printf(F4"***********************\n");
	   printf(F5"***********************\n");
	   printf(F6"***********************\n");
	   printf(F7"***********************\n");
	 */
#if 0
	printf(LIGHT_RED"***********************\n"NONE);
	printf(GREEN"***********************\n"NONE);
	printf(LIGHT_GREEN "***********************\n"NONE);
	printf(BLUE"***********************\n"NONE);
	printf(LIGHT_BLUE"***********************\n"NONE);
	printf(DARY_GRAY"***********************\n"NONE);
	printf(CYAN"***********************\n"NONE);
	printf(LIGHT_CYAN"***********************\n"NONE);
	printf(PURPLE"***********************\n"NONE);
	printf(LIGHT_PURPLE"***********************\n"NONE);
	printf(BROWN"***********************\n"NONE);
	printf(YELLOW"***********************\n"NONE);
	printf(LIGHT_GRAY "***********************\n"NONE);

	printf(WHITE "***********************\n"NONE);
	printf(HIGH "***********************\n"NONE);
	printf(LINE "***********************\n"NONE);
	printf(LIGHT"***********************\n"NONE);
	printf(F1"***********************\n"NONE);
	printf(F2"***********************\n"NONE);

#endif
#if 0
	system("clear");
	printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);	
	printf(LIGHT_CYAN"**********                             ..  .                    .. .         ..                      ...            ..  .                                  \n"NONE);
	printf(LIGHT_CYAN"**********                              .                   ..  .             .   E##D            ..  .              .                                     \n"NONE);
	printf(LIGHT_CYAN"**********                               .                  ..                  ##i  #W.          ..                  .                                    \n"NONE);
	printf(LIGHT_CYAN"**********                                                .                    WE     ##        . .                                                        \n"NONE);
	printf(LIGHT_CYAN"**********                                                   .                #        W           .                                                       \n"NONE);
	printf(LIGHT_CYAN"**********                                                                   ######    ##                                                                  \n"NONE);
	printf(LIGHT_CYAN"**********                                                                 #W##W#    ####                                                                  \n"NONE);
	printf(LIGHT_CYAN"**********                                      .                         W        KKW.Wf                                  .                               \n"NONE);
	printf(LIGHT_CYAN"**********                                   ... .                      #i         ...G#                                WKWW# .                            \n"NONE);
	printf(LIGHT_CYAN"**********                                .                   ..   .  W      .#W#    .K             ..   .          .# W     W                             \n"NONE);
	printf(LIGHT_CYAN"**********                                 .                    .    ####W##G    #WL ##            .. .             #t# .    W                             \n"NONE);
	printf(LIGHT_CYAN"**********                             . .             ,W########G: ##      ##W#   ##WE           ...         ###   # W      K                             \n"NONE);
	printf(LIGHT_CYAN"**********                                         ####i  .   ..  i###W##D      #W#  W          . . ..       W :#W## #L      #                             \n"NONE);
	printf(LIGHT_CYAN"**********                                       ##G     ... .          :###W##;   ##W           . .         #W#, K# W      ##                             \n"NONE);
	printf(LIGHT_CYAN"**********                                     ##        中国航班系统  .       t######D.         .           #    # EG      W                              \n"NONE);
	printf(LIGHT_CYAN"**********                                    ##   Wecome to airline system           f###WW####E;           W   .# #      .#                              \n"NONE);
	printf(LIGHT_CYAN"**********                                   #K                                                  :jK######WWWW#### G#      #E                              \n"NONE);
	printf(LIGHT_CYAN"**********                                 ##WEW:   温馨提示：请选择登录模式：                                  #  #      K#                               \n"NONE);
	printf(LIGHT_CYAN"**********                                 ##; #K#                                                                        #                                \n"NONE);
	printf(LIGHT_CYAN"**********                                #:#   .#W##.          1.输入1进入管理员模式；                                   #                                \n"NONE);
	printf(LIGHT_CYAN"**********                               ###.    . .j#K         2.输入2进入用户模式；                                     #.  .                            \n"NONE);
	printf(LIGHT_CYAN"**********                              L#G#W,.       K#        3.输入3进入退出系统；                  .                 # .                               \n"NONE);
	printf(LIGHT_CYAN"**********                              Ki#.;W#i    .#K                                               . .               .# .                               \n"NONE);
	printf(LIGHT_CYAN"**********                             ##, .                 . WWE;    ;K##WK##. .                 .             W# ... . #.                               \n"NONE);
	printf(LIGHT_CYAN"**********                               ##               .  ##                 #W              ..  .##W#EK##E      ##GWt GW##                             \n"NONE);
	printf(LIGHT_CYAN"**********                                 #W##              L#                 #W#####WWW#######WW##t                #W#,    #                            \n"NONE);
	printf(LIGHT_CYAN"**********                                   #######G:      :fK                 KW##WW####Wj.                          ;W#    #                            \n"NONE);
	printf(LIGHT_CYAN"**********                                     #W#;:D########EW                fW#                                       ####K;                            \n"NONE);
	printf(LIGHT_CYAN"**********                                     .               KW##j.  ,G##W#tW#   . .                                     ..                              \n"NONE);
	printf(LIGHT_CYAN"**********                             ..                      K;.           W#  .                    ..            ..  .                                  \n"NONE);
	printf(LIGHT_CYAN"**********                              .  .                 . WL            W   .                 .  .              .  .                                  \n"NONE);
	printf(LIGHT_CYAN"**********                                                     ##     j##W#LK                                                                              \n"NONE);
	printf(LIGHT_CYAN"**********                                  ...  .              W          W      ...  .                                  ..  .                            \n"NONE);
	printf(LIGHT_CYAN"**********                                 .  .                 #.        ##     .  .                                  ..  .                               \n"NONE);
	printf(LIGHT_CYAN"**********                                ....                   #.       K     ....                    .               ...                                \n"NONE);
	printf(LIGHT_CYAN"**********                                .                    . #L.     W#   . .                   ..   .             .                                   \n"NONE);
	printf(LIGHT_CYAN"**********                              .  .                  . . K     ##    .  .                  . .              .  .                                  \n"NONE);
	printf(LIGHT_CYAN"**********                             . .                  ...    W###K#    . .                  ...               . .                                    \n"NONE);
	printf(LIGHT_CYAN"**********                                                .   .     t#ft                        .  ..                                                      \n"NONE);
	/***************************************************航班表图形登录界面设计**********************************************************************/
	printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
	int i;
	for(i = 0; i < 8; i++){
		printf(DOWN"[ ] [ ]  [ ][ ]");
	}
	putchar(10);
#endif
#if 0
	int key = 1;
	printf(RED"["NONE);
	if(key == 1)
		printf(PURPLE"1"NONE);
	else{
		printf(PURPLE"0"NONE);
	}
	printf(RED"]["NONE);
	if(key == 1)
		printf(PURPLE"1"NONE);
	else{
		printf(PURPLE"0"NONE);
	}
	printf(RED"]   ["NONE);
	if(key == 1)
		printf(PURPLE"1"NONE);
	else{
		printf(PURPLE"0"NONE);
	}
	printf(RED"]["NONE);
	if(key == 1)
		printf(PURPLE"1"NONE);
	else{
		printf(PURPLE"0"NONE);
	}
	printf(RED"]"NONE);
#endif
#if 0
	int i,j,r,c,m,n;
	int b[12];
	for(i=0;i<12;i++){
		b[i]= i+1;
		printf("b[%d] = %d ; ",i,b[i]);
	}
	putchar(10);
	for(i=0;i<12;i++){
		printf("b[%d] = %d ",i,b[i]);
	}
	int a[6][4];
	for(r =0; r <6;r++){
		for(c=0;c <4;c++){
			a[r][c] = 0;
			printf("a[%d][%d]=%d",r,c,a[r][c]);
		}
		putchar(10);
	}
	int tmp;
	for(i=0;i<12;i++){
		tmp = b[i];
		printf("b[%d] = %d ;",i,b[i]);
		m = (tmp%4)-1;
		n = (int)(tmp/4);
		a[n][m] = tmp;
		printf("a[%d][%d] = %d ; ",n,m,a[n][m]);
		putchar(10);
	}
	for(r =0; r <6;r++){
		for(c=0;c <4;c++){
			printf("a[%d][%d]=%d\t",r,c,a[r][c]);
		}
		putchar(10);
	}
#endif

#if 0

	printf("***********************\n");
	printf("***********************\n");
	printf("***********************\n");
	printf("***********************\n");
	printf("***********************\n");
	printf("***********************\n");
	printf("***********************\n");
	printf("***********************\n");
	printf("***********************\n");
	printf("***********************\n");
	printf("***********************\n");
	printf("***********************\n");
	char s ='0';
	while(1){
		s=getchar();
		if(s == 'w' || s == 'W')
			printf(UP2 F7 F4);
		if(s == 'a' || s == 'A')
			printf(LEFT2 UP F7 F4);
		if(s == 's' || s == 'S')
			printf(DOWN F7 F4);
		if(s == 'd' || s == 'D')
			printf(RIGHT2 UP F7 F4);
		else if(s == 'q' || s == 'Q')
		{
			break;
		}
	}
#endif
	return 0;
}

