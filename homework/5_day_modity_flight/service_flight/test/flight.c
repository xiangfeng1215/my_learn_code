#include "flight.h"

typedef struct node node;

void Init_head_flight(node **head_loc)
{
	//malloc space
	(*head_loc) = (node*)malloc(sizeof(node));
	if(!(*head_loc)){
		exit(-1);
	}
	INIT_LIST_HEAD(&(*head_loc)->list);
}//end init_head

bool Create_list_flight(node* head)
{
	struct flight fly;
	/***************************************************航班表输入图形界面设计**********************************************************************/
	printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
	printf(LIGHT_CYAN"*******************************************************************中国航班--录入航班**********************************************************************\n"NONE);
	printf(LIGHT_CYAN"**************************************************************Wecome to airline system*********************************************************************\n"NONE);
	printf(LIGHT_CYAN"** 请输入航   班   号："NONE);
	while(1){
		scanf("%s",fly.number);
		getchar();
		if(strlen(fly.number) < 18 && strlen(fly.number) > 0 )
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
	printf(LIGHT_CYAN"** 请输入从现在起飞机將多久起飞："NONE);
	while(1){
		scanf("%ld",&fly.stime);
		getchar();
		if(235959 >fly.stime >= 0)
			break;
		printf("输入错误，请重新输入！\n");
		printf(LIGHT_CYAN"** 请输入从现在起飞机將多久起飞："NONE);
	}
	fly.stime = fly.stime * 60 + time(NULL);	
	putchar(10);
	printf(LIGHT_CYAN"** 请输入起飞后多久到达目的地："NONE);
	while(1){
		scanf("%ld",&fly.atime);
		getchar();
		if(235959 >fly.atime >= 0)
			break;
		printf("输入错误，请重新输入！\n");
		printf(LIGHT_CYAN"** 请输入起飞后多久到达目的地："NONE);
	}	
	fly.atime = fly.atime * 60 + fly.stime;
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

	char a[10];
	strcpy(a,"aaa");
	while(1){
		struct node* pnew = NULL;
		pnew = (node*)malloc(sizeof(node));
		if(!pnew){
			return false;
		}
		pnew->data = fly;

		INIT_LIST_HEAD(&pnew->list);

		list_add_tail(&pnew->list,&head->list);
		system("clear");
		/***************************************************航班表输入图形界面设计**********************************************************************/
		printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
		printf(LIGHT_CYAN"*******************************************************************中国航班--录入航班**********************************************************************\n"NONE);
		printf(LIGHT_CYAN"**************************************************************Wecome to airline system*********************************************************************\n"NONE);
		printf(LIGHT_CYAN"**                                                                                                                                                         \n"NONE);
		printf(LIGHT_CYAN"**                                                         是否继续录入 ，退出输入quit ! 继续输入非quit字符串                                              \n"NONE);
		printf(LIGHT_CYAN"**                                                                                                                                                         \n"NONE);
		printf(LIGHT_CYAN"** 请输入："NONE);
		while(1){
			scanf("%s",a);
			getchar();
			if(strlen(fly.number) < 10 && strlen(fly.number) > 0 )
				break;
			printf("输入错误，请重新输入！\n");
			printf(LIGHT_CYAN"** 请输入航   班   号："NONE);
		}
		putchar(10);	
		if(strcmp(a,"quit") == 0){
			break;
		}
		printf(LIGHT_CYAN"** 请输入航   班   号："NONE);
		while(1){
			scanf("%s",fly.number);
			getchar();
			if(strlen(fly.number) < 18 && strlen(fly.number) > 0 )
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
		printf(LIGHT_CYAN"** 请输入从现在起飞机將多久起飞："NONE);
		while(1){
			scanf("%ld",&fly.stime);
			getchar();
			if(235959 >fly.stime >= 0)
				break;
			printf("输入错误，请重新输入！\n");
			printf(LIGHT_CYAN"** 请输入从现在起飞机將多久起飞："NONE);
		}	
		putchar(10);
		printf(LIGHT_CYAN"** 请输入起飞后多久到达目的地："NONE);
		while(1){
			scanf("%ld",&fly.atime);
			getchar();
			if(235959 >fly.atime >= 0)
				break;
			printf("输入错误，请重新输入！\n");
			printf(LIGHT_CYAN"** 请输入起飞后多久到达目的地："NONE);
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

	}

}//end create_list

bool Insert_data_flight(node* head,struct flight* input,struct flight key,int mode)
{
	node* pos = NULL;
	node* pnew = NULL;
	switch(mode){
		case 1:
			pnew = (node*)malloc(sizeof(node));
			pnew->data = *input;
			list_for_each_entry(pos,&head->list,list){
				if(strcmp(pos->data.number,key.number)){
					__list_add(&pnew->list,&pos->list,pos->list.next);
					/*list_add(&pnew->list,&pos->list);*/
					return true;
				}
			};break;
		case 2:
			pnew = (node*)malloc(sizeof(node));
			pnew->data = *input;
			list_for_each_entry(pos,&head->list,list){
				if(strcmp(pos->data.staddress,key.staddress)){
					__list_add(&pnew->list,&pos->list,pos->list.next);
					/*list_add(&pnew->list,&pos->list);*/
					return true;
				}
			};break;
		case 3:
			pnew = (node*)malloc(sizeof(node));
			pnew->data = *input;
			list_for_each_entry(pos,&head->list,list){
				if(strcmp(pos->data.arraddress,key.arraddress)){
					__list_add(&pnew->list,&pos->list,pos->list.next);
					/*list_add(&pnew->list,&pos->list);*/
					return true;
				}
			};break;
		case 4:
			pnew = (node*)malloc(sizeof(node));
			pnew->data = *input;
			list_for_each_entry(pos,&head->list,list){
				if(strcmp(pos->data.DATE,key.DATE)){
					__list_add(&pnew->list,&pos->list,pos->list.next);
					/*list_add(&pnew->list,&pos->list);*/
					return true;
				}
			};break;
		case 5:
			pnew = (node*)malloc(sizeof(node));
			pnew->data = *input;
			list_for_each_entry(pos,&head->list,list){
				if(strcmp(pos->data.TYPE,key.TYPE)){
					__list_add(&pnew->list,&pos->list,pos->list.next);
					/*list_add(&pnew->list,&pos->list);*/
					return true;
				}
			};break;
		case 6:
			pnew = (node*)malloc(sizeof(node));
			pnew->data = *input;
			list_for_each_entry(pos,&head->list,list){
				if((pos->data.stime == key.stime)){
					__list_add(&pnew->list,&pos->list,pos->list.next);
					/*list_add(&pnew->list,&pos->list);*/
					return true;
				}
			};break;
		case 7:
			pnew = (node*)malloc(sizeof(node));
			pnew->data = *input;
			list_for_each_entry(pos,&head->list,list){
				if((pos->data.atime == key.atime)){
					__list_add(&pnew->list,&pos->list,pos->list.next);
					/*list_add(&pnew->list,&pos->list);*/
					return true;
				}
			};break;
		case 8:
			pnew = (node*)malloc(sizeof(node));
			pnew->data = *input;
			list_for_each_entry(pos,&head->list,list){
				if((pos->data.value == key.value)){
					__list_add(&pnew->list,&pos->list,pos->list.next);
					/*list_add(&pnew->list,&pos->list);*/
					return true;
				}
			};break;
		case 9:
			pnew = (node*)malloc(sizeof(node));
			pnew->data = *input;
			list_add(&pnew->list,&head->list);
			return true;
		default:	
			return false;
	}//end switch

	return false;
}//end insert_data


#if 0
bool Delete_data_flight(node* head,struct flight key,int mode)
{

	node* pos = NULL;
	switch(mode){
		case 1:
			list_for_each_entry(pos,&head->list,list){
				if(strcmp(pos->data.number,key.number)){
					__list_del(pos->list.prev,pos->list.next);
					//list_del(&pos->list);
					free(pos);
					pos = NULL;
					return true;
				}
			};break;
		case 2:
			list_for_each_entry(pos,&head->list,list){
				if(strcmp(pos->data.staddress,key.staddress)){
					__list_del(pos->list.prev,pos->list.next);
					//list_del(&pos->list);
					free(pos);
					pos = NULL;
					return true;
				}
			};break;
		case 3:
			list_for_each_entry(pos,&head->list,list){
				if(strcmp(pos->data.arraddress,key.arraddress)){
					__list_del(pos->list.prev,pos->list.next);
					//list_del(&pos->list);
					free(pos);
					pos = NULL;
					return true;
				}
			};break;
		case 4:
			list_for_each_entry(pos,&head->list,list){
				if(strcmp(pos->data.DATE,key.DATE)){
					__list_del(pos->list.prev,pos->list.next);
					//list_del(&pos->list);
					free(pos);
					pos = NULL;
					return true;
				}
			};break;
		case 5:
			list_for_each_entry(pos,&head->list,list){
				if(strcmp(pos->data.TYPE,key.TYPE)){
					__list_del(pos->list.prev,pos->list.next);
					//list_del(&pos->list);
					free(pos);
					pos = NULL;
					return true;
				}
			};break;
		case 6:
			list_for_each_entry(pos,&head->list,list){
				if((pos->data.stime == key.stime)){
					__list_del(pos->list.prev,pos->list.next);
					//list_del(&pos->list);
					free(pos);
					pos = NULL;
					return true;
				}
			};break;
		case 7:
			list_for_each_entry(pos,&head->list,list){
				if((pos->data.atime == key.atime)){
					__list_del(pos->list.prev,pos->list.next);
					//list_del(&pos->list);
					free(pos);
					pos = NULL;
					return true;
				}
			};break;
		case 8:
			list_for_each_entry(pos,&head->list,list){
				if((pos->data.value == key.value)){
					__list_del(pos->list.prev,pos->list.next);
					//list_del(&pos->list);
					free(pos);
					pos = NULL;
					return true;
				}
			};break;
		default:return false;

	}//end switch

	return false;
}//end delete_data
#endif


bool Delete_data_flight(node* head,struct flight key,int mode)
{
	char yesno[5];
	bzero(yesno,sizeof(yesno));
	node* pos = NULL;
	switch(mode){
		case 1:
			list_for_each_entry(pos,&head->list,list){
				if(strcmp(pos->data.number,key.number) == 0){
					printf(RED"\t航班号\t出发地点\t目地地点\t日期    \t机型      \t出发时间\t到达时间\t价格    \t总票数  \t余票 \n"NONE);					
					printf(RED"\t%s\t%s\t\t%s\t\t%s\t%s\t\t%ld\t\t%ld\t\t%d\t\t%d\t\t%d\n"NONE,pos->data.number,pos->data.staddress,pos->data.arraddress,pos->data.DATE,pos->data.TYPE,pos->data.stime,pos->data.atime,pos->data.value,pos->data.seat_size,pos->data.poll);
					printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
					printf(LIGHT_CYAN"**是否删除该航班信息(yes or no)："NONE);
					while(1){
						scanf("%s",yesno);
						getchar();
						if(strlen(yesno) < 9 && strlen(yesno)> 0)
							break;
						printf("输入错误，请重新输入！\n");
						printf(LIGHT_CYAN"**是否删除该航班信息："NONE);
					}//end while
					if(strcmp(yesno,"yes") == 0){
						__list_del(pos->list.prev,pos->list.next);
						//list_del(&pos->list);
						free(pos);
						pos = NULL;
						printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
						printf(LIGHT_CYAN"********************************************删除成功，已经您要删除的航班信息，已进入管理员模式*************************************************************\n"NONE);			
						printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
						return true;
					}//end if yes						
				}//end if number
			}//end list_for_each_entry
			printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
			printf(LIGHT_CYAN"**************************查找失败，删除失败所有航班中没有找到您要删除的航班信息或您未确认删除，已进入管理员模式*******************************************\n"NONE);			
			printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
			break;
		case 2:
			list_for_each_entry(pos,&head->list,list){
				if(strcmp(pos->data.staddress,key.staddress)){
					printf(RED"\t航班号\t出发地点\t目地地点\t日期    \t机型      \t出发时间\t到达时间\t价格    \t总票数  \t余票 \n"NONE);					
					printf(RED"\t%s\t%s\t\t%s\t\t%s\t%s\t\t%ld\t\t%ld\t\t%d\t\t%d\t\t%d\n"NONE,pos->data.number,pos->data.staddress,pos->data.arraddress,pos->data.DATE,pos->data.TYPE,pos->data.stime,pos->data.atime,pos->data.value,pos->data.seat_size,pos->data.poll);
					printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
					printf(LIGHT_CYAN"**是否删除该航班信息(yes or no)："NONE);
					while(1){
						scanf("%s",yesno);
						getchar();
						if(strlen(yesno) < 5 && strlen(yesno)> 0)
							break;
						printf("输入错误，请重新输入！\n");
						printf(LIGHT_CYAN"**是否删除该航班信息："NONE);
					}//end while
					if(strcmp(yesno,"yes") == 0){
						__list_del(pos->list.prev,pos->list.next);
						//list_del(&pos->list);
						free(pos);
						pos = NULL;
						printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
						printf(LIGHT_CYAN"********************************************删除成功，已经您要删除的航班信息，已进入管理员模式*************************************************************\n"NONE);			
						printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
						return true;
					}//end if yes
				}//end if staddress
			}//end list_for_each_entry
			printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
			printf(LIGHT_CYAN"**************************查找失败，删除失败所有航班中没有找到您要删除的航班信息或您未确认删除，已进入管理员模式*******************************************\n"NONE);			
			printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
			break;
		case 3:
			list_for_each_entry(pos,&head->list,list){
				if(strcmp(pos->data.arraddress,key.arraddress)){
					printf(RED"\t航班号\t出发地点\t目地地点\t日期    \t机型      \t出发时间\t到达时间\t价格    \t总票数  \t余票 \n"NONE);					
					printf(RED"\t%s\t%s\t\t%s\t\t%s\t%s\t\t%ld\t\t%ld\t\t%d\t\t%d\t\t%d\n"NONE,pos->data.number,pos->data.staddress,pos->data.arraddress,pos->data.DATE,pos->data.TYPE,pos->data.stime,pos->data.atime,pos->data.value,pos->data.seat_size,pos->data.poll);
					printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
					printf(LIGHT_CYAN"**是否删除该航班信息(yes or no)："NONE);
					while(1){
						scanf("%s",yesno);
						getchar();
						if(strlen(yesno) < 9 && strlen(yesno)> 0)
							break;
						printf("输入错误，请重新输入！\n");
						printf(LIGHT_CYAN"**是否删除该航班信息："NONE);
					}//end while
					if(strcmp(yesno,"yes") == 0){
						__list_del(pos->list.prev,pos->list.next);
						//list_del(&pos->list);
						free(pos);
						pos = NULL;
						printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
						printf(LIGHT_CYAN"********************************************删除成功，已经您要删除的航班信息，已进入管理员模式*************************************************************\n"NONE);			
						printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
						return true;
					}//end if yes
				}
			}
			printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
			printf(LIGHT_CYAN"**************************查找失败，删除失败所有航班中没有找到您要删除的航班信息或您未确认删除，已进入管理员模式*******************************************\n"NONE);			
			printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
			break;
		case 4:
			list_for_each_entry(pos,&head->list,list){
				if(strcmp(pos->data.DATE,key.DATE)){
					printf(RED"\t航班号\t出发地点\t目地地点\t日期    \t机型      \t出发时间\t到达时间\t价格    \t总票数  \t余票 \n"NONE);					
					printf(RED"\t%s\t%s\t\t%s\t\t%s\t%s\t\t%ld\t\t%ld\t\t%d\t\t%d\t\t%d\n"NONE,pos->data.number,pos->data.staddress,pos->data.arraddress,pos->data.DATE,pos->data.TYPE,pos->data.stime,pos->data.atime,pos->data.value,pos->data.seat_size,pos->data.poll);
					printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
					printf(LIGHT_CYAN"**是否删除该航班信息(yes or no)："NONE);
					while(1){
						scanf("%s",yesno);
						getchar();
						if(strlen(yesno) < 9 && strlen(yesno)> 0)
							break;
						printf("输入错误，请重新输入！\n");
						printf(LIGHT_CYAN"**是否删除该航班信息："NONE);
					}//end while
					if(strcmp(yesno,"yes") == 0){
						__list_del(pos->list.prev,pos->list.next);
						//list_del(&pos->list);
						free(pos);
						pos = NULL;
						printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
						printf(LIGHT_CYAN"********************************************删除成功，已经您要删除的航班信息，已进入管理员模式*************************************************************\n"NONE);			
						printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
						return true;
					}//end if yes
				}
			}
			printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
			printf(LIGHT_CYAN"**************************查找失败，删除失败所有航班中没有找到您要删除的航班信息或您未确认删除，已进入管理员模式*******************************************\n"NONE);			
			printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
			break;
		case 5:
			list_for_each_entry(pos,&head->list,list){
				if(strcmp(pos->data.TYPE,key.TYPE)){
					printf(RED"\t航班号\t出发地点\t目地地点\t日期    \t机型      \t出发时间\t到达时间\t价格    \t总票数  \t余票 \n"NONE);					
					printf(RED"\t%s\t%s\t\t%s\t\t%s\t%s\t\t%ld\t\t%ld\t\t%d\t\t%d\t\t%d\n"NONE,pos->data.number,pos->data.staddress,pos->data.arraddress,pos->data.DATE,pos->data.TYPE,pos->data.stime,pos->data.atime,pos->data.value,pos->data.seat_size,pos->data.poll);
					printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
					printf(LIGHT_CYAN"**是否删除该航班信息(yes or no)："NONE);
					while(1){
						scanf("%s",yesno);
						getchar();
						if(strlen(yesno) < 9 && strlen(yesno)> 0)
							break;
						printf("输入错误，请重新输入！\n");
						printf(LIGHT_CYAN"**是否删除该航班信息："NONE);
					}//end while
					if(strcmp(yesno,"yes") == 0){
						__list_del(pos->list.prev,pos->list.next);
						//list_del(&pos->list);
						free(pos);
						pos = NULL;
						printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
						printf(LIGHT_CYAN"********************************************删除成功，已经您要删除的航班信息，已进入管理员模式*************************************************************\n"NONE);			
						printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
						return true;
					}//end if yes
				}
			}
			printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
			printf(LIGHT_CYAN"**************************查找失败，删除失败所有航班中没有找到您要删除的航班信息或您未确认删除，已进入管理员模式*******************************************\n"NONE);			
			printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
			break;
		case 6:
			list_for_each_entry(pos,&head->list,list){
				if((pos->data.stime == key.stime)){
					printf(RED"\t航班号\t出发地点\t目地地点\t日期    \t机型      \t出发时间\t到达时间\t价格    \t总票数  \t余票 \n"NONE);					
					printf(RED"\t%s\t%s\t\t%s\t\t%s\t%s\t\t%ld\t\t%ld\t\t%d\t\t%d\t\t%d\n"NONE,pos->data.number,pos->data.staddress,pos->data.arraddress,pos->data.DATE,pos->data.TYPE,pos->data.stime,pos->data.atime,pos->data.value,pos->data.seat_size,pos->data.poll);
					printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
					printf(LIGHT_CYAN"**是否删除该航班信息(yes or no)："NONE);
					while(1){
						scanf("%s",yesno);
						getchar();
						if(strlen(yesno) < 9 && strlen(yesno)> 0)
							break;
						printf("输入错误，请重新输入！\n");
						printf(LIGHT_CYAN"**是否删除该航班信息："NONE);
					}//end while
					if(strcmp(yesno,"yes") == 0){
						__list_del(pos->list.prev,pos->list.next);
						//list_del(&pos->list);
						free(pos);
						pos = NULL;
						printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
						printf(LIGHT_CYAN"********************************************删除成功，已经您要删除的航班信息，已进入管理员模式*************************************************************\n"NONE);			
						printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
						return true;
					}//end if yes
				}
			}
			printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
			printf(LIGHT_CYAN"**************************查找失败，删除失败所有航班中没有找到您要删除的航班信息或您未确认删除，已进入管理员模式*******************************************\n"NONE);			
			printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
			break;
		case 7:
			list_for_each_entry(pos,&head->list,list){
				if((pos->data.atime == key.atime)){
					printf(RED"\t航班号\t出发地点\t目地地点\t日期    \t机型      \t出发时间\t到达时间\t价格    \t总票数  \t余票 \n"NONE);					
					printf(RED"\t%s\t%s\t\t%s\t\t%s\t%s\t\t%ld\t\t%ld\t\t%d\t\t%d\t\t%d\n"NONE,pos->data.number,pos->data.staddress,pos->data.arraddress,pos->data.DATE,pos->data.TYPE,pos->data.stime,pos->data.atime,pos->data.value,pos->data.seat_size,pos->data.poll);
					printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
					printf(LIGHT_CYAN"**是否删除该航班信息(yes or no)："NONE);
					while(1){
						scanf("%s",yesno);
						getchar();
						if(strlen(yesno) < 9 && strlen(yesno)> 0)
							break;
						printf("输入错误，请重新输入！\n");
						printf(LIGHT_CYAN"**是否删除该航班信息："NONE);
					}//end while
					if(strcmp(yesno,"yes") == 0){
						__list_del(pos->list.prev,pos->list.next);
						//list_del(&pos->list);
						free(pos);
						pos = NULL;
						printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
						printf(LIGHT_CYAN"********************************************删除成功，已经您要删除的航班信息，已进入管理员模式*************************************************************\n"NONE);			
						printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
						return true;
					}//end if yes
				}
			}
			printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
			printf(LIGHT_CYAN"**************************查找失败，删除失败所有航班中没有找到您要删除的航班信息或您未确认删除，已进入管理员模式*******************************************\n"NONE);			
			printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
			break;
		case 8:
			list_for_each_entry(pos,&head->list,list){
				if((pos->data.value == key.value)){
					printf(RED"\t航班号\t出发地点\t目地地点\t日期    \t机型      \t出发时间\t到达时间\t价格    \t总票数  \t余票 \n"NONE);					
					printf(RED"\t%s\t%s\t\t%s\t\t%s\t%s\t\t%ld\t\t%ld\t\t%d\t\t%d\t\t%d\n"NONE,pos->data.number,pos->data.staddress,pos->data.arraddress,pos->data.DATE,pos->data.TYPE,pos->data.stime,pos->data.atime,pos->data.value,pos->data.seat_size,pos->data.poll);
					printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
					printf(LIGHT_CYAN"**是否删除该航班信息(yes or no)："NONE);
					while(1){
						scanf("%s",yesno);
						getchar();
						if(strlen(yesno) < 9 && strlen(yesno)> 0)
							break;
						printf("输入错误，请重新输入！\n");
						printf(LIGHT_CYAN"**是否删除该航班信息："NONE);
					}//end while
					if(strcmp(yesno,"yes") == 0){
						__list_del(pos->list.prev,pos->list.next);
						//list_del(&pos->list);
						free(pos);
						pos = NULL;
						printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
						printf(LIGHT_CYAN"********************************************删除成功，已经您要删除的航班信息，已进入管理员模式*************************************************************\n"NONE);			
						printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
						return true;
					}//end if yes
				}
			}
			printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
			printf(LIGHT_CYAN"**************************查找失败，删除失败所有航班中没有找到您要删除的航班信息或您未确认删除，已进入管理员模式*******************************************\n"NONE);			
			printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
			break;
		default:
			printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
			printf(LIGHT_CYAN"**************************查找失败，删除失败所有航班中没有找到您要删除的航班信息或您未确认删除，已进入管理员模式*******************************************\n"NONE);			
			printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
			return false;

	}//end switch

	return false;
}//end delete_data



struct node* Find_node_pos_flight(struct node* head,struct flight key,int mode )
{
	node* pos = NULL;
	node* pnew = NULL;
	switch(mode){
		case 1:
			list_for_each_entry(pos,&head->list,list){
				if(strcmp(pos->data.number,key.number)){
					return pos;
				}
			};break;
		case 2:
			list_for_each_entry(pos,&head->list,list){
				if(strcmp(pos->data.staddress,key.staddress)){
					return pos;
				}
			};break;
		case 3:
			list_for_each_entry(pos,&head->list,list){
				if(strcmp(pos->data.arraddress,key.arraddress)){
					return pos;
				}
			};break;
		case 4:
			list_for_each_entry(pos,&head->list,list){
				if(strcmp(pos->data.DATE,key.DATE)){
					return pos;
				}
			};break;
		case 5:
			list_for_each_entry(pos,&head->list,list){
				if(strcmp(pos->data.TYPE,key.TYPE)){
					return pos;
				}
			};break;
		case 6:
			list_for_each_entry(pos,&head->list,list){
				if((pos->data.stime == key.stime)){
					return pos;
				}
			};break;
		case 7:
			list_for_each_entry(pos,&head->list,list){
				if((pos->data.atime == key.atime)){
					return pos;
				}
			};break;
		case 8:
			list_for_each_entry(pos,&head->list,list){
				if((pos->data.value == key.value)){
					return pos;
				}
			};break;
		default:return NULL;

	}//end switch

	return NULL;
}//end find node position



void Choose_modity_flight(struct node* pos,char *s,int t,long int t1)
{
	/***************************************************航班管理员图形界面设计**********************************************************************/
	printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
	printf(LIGHT_CYAN"*******************************************************************中国航班管理员模式**********************************************************************\n"NONE);
	printf(LIGHT_CYAN"**************************************************************Wecome to airline system*********************************************************************\n"NONE);
	printf(LIGHT_CYAN"**                                                     1.修改该航班的航班号                                                                              **\n"NONE);	
	printf(LIGHT_CYAN"**                                                     2.修改该航班的起点站                                                                              **\n"NONE);	
	printf(LIGHT_CYAN"**                                                     3.修改该航班的终点位置                                                                            **\n"NONE);	
	printf(LIGHT_CYAN"**                                                     4.修改该航班的班期信息                                                                            **\n"NONE);	
	printf(LIGHT_CYAN"**                                                     5.修改该航班的机型信息                                                                            **\n"NONE);			
	printf(LIGHT_CYAN"**                                                     6.修改该航班的起飞时间                                                                            **\n"NONE);					
	printf(LIGHT_CYAN"**                                                     7.修改该航班的达时间                                                                              **\n"NONE);	
	printf(LIGHT_CYAN"**                                                     8.修改该航班的票价信息                                                                            **\n"NONE);	
	printf(LIGHT_CYAN"**                                                     9.退出                                                                                            **\n"NONE);			
	printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
	printf(LIGHT_CYAN"**************************************************************温馨提示已进入管理员模式*********************************************************************\n"NONE);
	printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
	printf(LIGHT_GREEN"**选择修改该航班那条信息："NONE);
	char tmp = '0';
	while(1){
		scanf("%c",&tmp);
		getchar();
		if(tmp <= '9' && tmp > '0')
			break;
		printf("输入错误，请重新输入！\n");
		printf(LIGHT_CYAN"**选择修改该航班那条信息："NONE);
	}//end while
	switch(tmp)
	{
		case '1':
			putchar(10);
			printf(LIGHT_CYAN"** 请输入航   班   号："NONE);
			while(1){
				scanf("%s",s);
				getchar();
				if(strlen(s) < 18 && strlen(s) > 0 )
					break;
				printf("输入错误，请重新输入！\n");
				printf(LIGHT_CYAN"** 请输入航   班   号："NONE);
			}

			strncpy(pos->data.number , s,18);
			printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
			printf(LIGHT_CYAN"********************************************修改成功，已经您要修改的航班信息，已进入管理员模式*************************************************************\n"NONE);			
			printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);	
			printf(RED"\t航班号\t出发地点\t目地地点\t日期    \t机型      \t出发时间\t到达时间\t价格    \t总票数  \t余票 \n"NONE);					
			printf(RED"\t%s\t%s\t\t%s\t\t%s\t%s\t\t%ld\t\t%ld\t\t%d\t\t%d\t\t%d\n"NONE,pos->data.number,pos->data.staddress,pos->data.arraddress,pos->data.DATE,pos->data.TYPE,pos->data.stime,pos->data.atime,pos->data.value,pos->data.seat_size,pos->data.poll);								
			getchar();
			break;
		case '2':
			putchar(10);
			printf(LIGHT_CYAN"** 请输入起   点   站："NONE);
			while(1){
				scanf("%s",s);
				getchar();
				if(strlen(s) < 18 && strlen(s) > 0 )
					break;
				printf("输入错误，请重新输入！\n");
				printf(LIGHT_CYAN"** 请输入起   点   站："NONE);
			}

			strncpy(pos->data.staddress ,s,18);
			printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
			printf(LIGHT_CYAN"********************************************修改成功，已经您要修改的航班信息，已进入管理员模式*************************************************************\n"NONE);			
			printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);	
			printf(RED"\t航班号\t出发地点\t目地地点\t日期    \t机型      \t出发时间\t到达时间\t价格    \t总票数  \t余票 \n"NONE);					
			printf(RED"\t%s\t%s\t\t%s\t\t%s\t%s\t\t%ld\t\t%ld\t\t%d\t\t%d\t\t%d\n"NONE,pos->data.number,pos->data.staddress,pos->data.arraddress,pos->data.DATE,pos->data.TYPE,pos->data.stime,pos->data.atime,pos->data.value,pos->data.seat_size,pos->data.poll);								
			getchar();
			break;
		case '3':
			putchar(10);
			printf(LIGHT_CYAN"** 请输入终   点   站："NONE);
			while(1){
				scanf("%s",s);
				getchar();
				if(strlen(s) < 18 && strlen(s) > 0 )
					break;
				printf("输入错误，请重新输入！\n");
				printf(LIGHT_CYAN"** 请输入终   点   站："NONE);
			}

			strncpy(pos->data.arraddress , s,18);
			printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
			printf(LIGHT_CYAN"********************************************修改成功，已经您要修改的航班信息，已进入管理员模式*************************************************************\n"NONE);			
			printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);	
			printf(RED"\t航班号\t出发地点\t目地地点\t日期    \t机型      \t出发时间\t到达时间\t价格    \t总票数  \t余票 \n"NONE);					
			printf(RED"\t%s\t%s\t\t%s\t\t%s\t%s\t\t%ld\t\t%ld\t\t%d\t\t%d\t\t%d\n"NONE,pos->data.number,pos->data.staddress,pos->data.arraddress,pos->data.DATE,pos->data.TYPE,pos->data.stime,pos->data.atime,pos->data.value,pos->data.seat_size,pos->data.poll);								
			getchar();
			break;
		case '4':
			putchar(10);
			printf(LIGHT_CYAN"** 请输入班      期："NONE);
			while(1){
				scanf("%s",s);
				getchar();
				if(strlen(s) < 18 && strlen(s) > 0 )
					break;
				printf("输入错误，请重新输入！\n");
				printf(LIGHT_CYAN"** 请输入班      期："NONE);
			}

			strncpy(pos->data.DATE , s,12);
			printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
			printf(LIGHT_CYAN"********************************************修改成功，已经您要修改的航班信息，已进入管理员模式*************************************************************\n"NONE);			
			printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);	
			printf(RED"\t航班号\t出发地点\t目地地点\t日期    \t机型      \t出发时间\t到达时间\t价格    \t总票数  \t余票 \n"NONE);					
			printf(RED"\t%s\t%s\t\t%s\t\t%s\t%s\t\t%ld\t\t%ld\t\t%d\t\t%d\t\t%d\n"NONE,pos->data.number,pos->data.staddress,pos->data.arraddress,pos->data.DATE,pos->data.TYPE,pos->data.stime,pos->data.atime,pos->data.value,pos->data.seat_size,pos->data.poll);								
			getchar();
			break;
		case '5':
			putchar(10);
			printf(LIGHT_CYAN"** 请输入机      型："NONE);
			while(1){
				scanf("%s",s);
				getchar();
				if(strlen(s) < 18 && strlen(s) > 0 )
					break;
				printf("输入错误，请重新输入！\n");
				printf(LIGHT_CYAN"** 请输入机      型："NONE);
			}

			strncpy(pos->data.TYPE , s,8);
			printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
			printf(LIGHT_CYAN"********************************************修改成功，已经您要修改的航班信息，已进入管理员模式*************************************************************\n"NONE);			
			printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);	
			printf(RED"\t航班号\t出发地点\t目地地点\t日期    \t机型      \t出发时间\t到达时间\t价格    \t总票数  \t余票 \n"NONE);					
			printf(RED"\t%s\t%s\t\t%s\t\t%s\t%s\t\t%ld\t\t%ld\t\t%d\t\t%d\t\t%d\n"NONE,pos->data.number,pos->data.staddress,pos->data.arraddress,pos->data.DATE,pos->data.TYPE,pos->data.stime,pos->data.atime,pos->data.value,pos->data.seat_size,pos->data.poll);								
			getchar();
			break;
		case '6':
			putchar(10);
			printf(LIGHT_CYAN"** 请输入起飞时间："NONE);
			while(1){
				scanf("%ld",&t1);
				getchar();
				if(t1 < 2147483 && t1> 0 )
					break;
				printf("输入错误，请重新输入！\n");
				printf(LIGHT_CYAN"** 请输入起飞时间："NONE);
			}

			pos->data.stime = t1 * 60 + time(NULL);
			printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
			printf(LIGHT_CYAN"********************************************修改成功，已经您要修改的航班信息，已进入管理员模式*************************************************************\n"NONE);			
			printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);	
			printf(LIGHT_PURPLE"\t航班号\t出发地点\t目地地点\t日期    \t机型      \t出发时间\t到达时间\t价格    \t总票数  \t余票 \n"NONE);					
			printf(RED"\t%s\t%s\t\t%s\t\t%s\t%s\t\t%ld\t\t%ld\t\t%d\t\t%d\t\t%d\n"NONE,pos->data.number,pos->data.staddress,pos->data.arraddress,pos->data.DATE,pos->data.TYPE,pos->data.stime,pos->data.atime,pos->data.value,pos->data.seat_size,pos->data.poll);								
			getchar();
			break;
		case '7':
			putchar(10);
			printf(LIGHT_CYAN"** 请输入到达时间："NONE);
			while(1){
				scanf("%ld",&t1);
				getchar();
				if(t1 < 21474836 && t1 > 0 )
					break;
				printf("输入错误，请重新输入！\n");
				printf(LIGHT_CYAN"** 请输入到达时间："NONE);
			}

			pos->data.atime = t1 * 60 + time(NULL);
			printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
			printf(LIGHT_CYAN"********************************************修改成功，已经您要修改的航班信息，已进入管理员模式*************************************************************\n"NONE);			
			printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);	
			printf(RED"\t航班号\t出发地点\t目地地点\t日期    \t机型      \t出发时间\t到达时间\t价格    \t总票数  \t余票 \n"NONE);					
			printf(RED"\t%s\t%s\t\t%s\t\t%s\t%s\t\t%ld\t\t%ld\t\t%d\t\t%d\t\t%d\n"NONE,pos->data.number,pos->data.staddress,pos->data.arraddress,pos->data.DATE,pos->data.TYPE,pos->data.stime,pos->data.atime,pos->data.value,pos->data.seat_size,pos->data.poll);								
			getchar();
			break;
		case '8':
			putchar(10);
			printf(LIGHT_CYAN"** 请输入航班票价："NONE);
			while(1){
				scanf("%d",&t);
				getchar();
				if(t < 21474836 && t> 0 )
					break;
				printf("输入错误，请重新输入！\n");
				printf(LIGHT_CYAN"** 请输入航班票价："NONE);
			}

			pos->data.value = t;
			printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
			printf(LIGHT_CYAN"********************************************修改成功，已经您要修改的航班信息，已进入管理员模式*************************************************************\n"NONE);			
			printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);	
			printf(LIGHT_PURPLE"\t航班号\t出发地点\t目地地点\t日期    \t机型      \t出发时间\t到达时间\t价格    \t总票数  \t余票 \n"NONE);					
			printf(RED"\t%s\t%s\t\t%s\t\t%s\t%s\t\t%ld\t\t%ld\t\t%d\t\t%d\t\t%d\n"NONE,pos->data.number,pos->data.staddress,pos->data.arraddress,pos->data.DATE,pos->data.TYPE,pos->data.stime,pos->data.atime,pos->data.value,pos->data.seat_size,pos->data.poll);								
			getchar();
			break;
		case '9':
			putchar(10);
			printf(LIGHT_CYAN"** 请输入航班座位数："NONE);
			while(1){
				scanf("%d",&t);
				getchar();
				if(t < 21474836 && t> 0 )
					break;
				printf("输入错误，请重新输入！\n");
				printf(LIGHT_CYAN"** 请输入航班座位数："NONE);
			}

			pos->data.seat_size = t;
			printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
			printf(LIGHT_CYAN"********************************************修改成功，已经您要修改的航班信息，已进入管理员模式*************************************************************\n"NONE);			
			printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);	
			printf(RED"\t航班号\t出发地点\t目地地点\t日期    \t机型      \t出发时间\t到达时间\t价格    \t总票数  \t余票 \n"NONE);					
			printf(RED"\t%s\t%s\t\t%s\t\t%s\t%s\t\t%ld\t\t%ld\t\t%d\t\t%d\t\t%d\n"NONE,pos->data.number,pos->data.staddress,pos->data.arraddress,pos->data.DATE,pos->data.TYPE,pos->data.stime,pos->data.atime,pos->data.value,pos->data.seat_size,pos->data.poll);								
			getchar();
			break;

	}//end switch tmp							
}//Choose_modity_flight



bool My_replace_flight(struct node* head,struct flight key,int mode)
{
	char yesno[5];
	bzero(yesno,sizeof(yesno));
	char s[20];
	bzero(s,sizeof(yesno));
	int t = 0;
	long int t1 = 0;
	node* pos = NULL;
	switch(mode){
		case 1:
			list_for_each_entry(pos,&head->list,list){
				if(strcmp(pos->data.number,key.number) == 0){
					printf(LIGHT_PURPLE"\t航班号\t出发地点\t目地地点\t日期    \t机型      \t出发时间\t到达时间\t价格    \t总票数  \t余票 \n"NONE);					
					printf(RED"\t%s\t%s\t\t%s\t\t%s\t%s\t\t%ld\t\t%ld\t\t%d\t\t%d\t\t%d\n"NONE,pos->data.number,pos->data.staddress,pos->data.arraddress,pos->data.DATE,pos->data.TYPE,pos->data.stime,pos->data.atime,pos->data.value,pos->data.seat_size,pos->data.poll);
					printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
					printf(LIGHT_CYAN"**是否修改该航班信息(yes or no)："NONE);
					while(1){
						scanf("%s",yesno);
						getchar();
						if(strlen(yesno) < 5 && strlen(yesno)> 0)
							break;
						printf("输入错误，请重新输入！\n");
						printf(LIGHT_CYAN"**是否修改该航班信息(yes or no)："NONE);
					}//end while
					if(strcmp(yesno,"yes") == 0){
						Choose_modity_flight(pos,s,t,t1);
						return true;
					}//end if yes						
				}//end if number
			}//end list_for_each_entry
			printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
			printf(LIGHT_CYAN"**************************查找失败，修改失败所有航班中没有找到您要修改的航班信息或您未确认修改，已进入管理员模式*******************************************\n"NONE);			
			printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
			break;
		case 2:
			list_for_each_entry(pos,&head->list,list){
				if(strcmp(pos->data.staddress,key.staddress)){
					printf(RED"\t航班号\t出发地点\t目地地点\t日期    \t机型      \t出发时间\t到达时间\t价格    \t总票数  \t余票 \n"NONE);					
					printf(RED"\t%s\t%s\t\t%s\t\t%s\t%s\t\t%ld\t\t%ld\t\t%d\t\t%d\t\t%d\n"NONE,pos->data.number,pos->data.staddress,pos->data.arraddress,pos->data.DATE,pos->data.TYPE,pos->data.stime,pos->data.atime,pos->data.value,pos->data.seat_size,pos->data.poll);
					printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
					printf(LIGHT_CYAN"**是否修改该航班信息(yes or no)："NONE);
					while(1){
						scanf("%s",yesno);
						getchar();
						if(strlen(yesno) < 5 && strlen(yesno)> 0)
							break;
						printf("输入错误，请重新输入！\n");
						printf(LIGHT_CYAN"**是否修改该航班信息(yes or no)："NONE);
					}//end while
					if(strcmp(yesno,"yes") == 0){
						Choose_modity_flight(pos,s,t,t1);
						return true;
					}//end if yes			
				}//end if staddress
			}//end list_for_each_entry
			printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
			printf(LIGHT_CYAN"**************************查找失败，修改失败所有航班中没有找到您要修改的航班信息或您未确认修改，已进入管理员模式*******************************************\n"NONE);			
			printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
			break;
		case 3:
			list_for_each_entry(pos,&head->list,list){
				if(strcmp(pos->data.arraddress,key.arraddress)){
					printf(RED"\t航班号\t出发地点\t目地地点\t日期    \t机型      \t出发时间\t到达时间\t价格    \t总票数  \t余票 \n"NONE);					
					printf(RED"\t%s\t%s\t\t%s\t\t%s\t%s\t\t%ld\t\t%ld\t\t%d\t\t%d\t\t%d\n"NONE,pos->data.number,pos->data.staddress,pos->data.arraddress,pos->data.DATE,pos->data.TYPE,pos->data.stime,pos->data.atime,pos->data.value,pos->data.seat_size,pos->data.poll);
					printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
					printf(LIGHT_CYAN"**是否修改该航班信息(yes or no)："NONE);
					while(1){
						scanf("%s",yesno);
						getchar();
						if(strlen(yesno) < 5 && strlen(yesno)> 0)
							break;
						printf("输入错误，请重新输入！\n");
						printf(LIGHT_CYAN"**是否修改该航班信息(yes or no)："NONE);
					}//end while
					if(strcmp(yesno,"yes") == 0){
						Choose_modity_flight(pos,s,t,t1);
						return true;
					}//end if yes			
				}
			}
			printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
			printf(LIGHT_CYAN"**************************查找失败，修改失败所有航班中没有找到您要修改的航班信息或您未确认修改，已进入管理员模式*******************************************\n"NONE);			
			printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
			break;
		case 4:
			list_for_each_entry(pos,&head->list,list){
				if(strcmp(pos->data.DATE,key.DATE)){
					printf(RED"\t航班号\t出发地点\t目地地点\t日期    \t机型      \t出发时间\t到达时间\t价格    \t总票数  \t余票 \n"NONE);					
					printf(RED"\t%s\t%s\t\t%s\t\t%s\t%s\t\t%ld\t\t%ld\t\t%d\t\t%d\t\t%d\n"NONE,pos->data.number,pos->data.staddress,pos->data.arraddress,pos->data.DATE,pos->data.TYPE,pos->data.stime,pos->data.atime,pos->data.value,pos->data.seat_size,pos->data.poll);
					printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
					printf(LIGHT_CYAN"**是否修改该航班信息(yes or no)："NONE);
					while(1){
						scanf("%s",yesno);
						getchar();
						if(strlen(yesno) < 5 && strlen(yesno)> 0)
							break;
						printf("输入错误，请重新输入！\n");
						printf(LIGHT_CYAN"**是否修改该航班信息(yes or no)："NONE);
					}//end while
					if(strcmp(yesno,"yes") == 0){
						Choose_modity_flight(pos,s,t,t1);
						return true;
					}//end if yes			
				}
			}
			printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
			printf(LIGHT_CYAN"**************************查找失败，修改失败所有航班中没有找到您要修改的航班信息或您未确认修改，已进入管理员模式*******************************************\n"NONE);			
			printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
			break;
		case 5:
			list_for_each_entry(pos,&head->list,list){
				if(strcmp(pos->data.TYPE,key.TYPE)){
					printf(RED"\t航班号\t出发地点\t目地地点\t日期    \t机型      \t出发时间\t到达时间\t价格    \t总票数  \t余票 \n"NONE);					
					printf(RED"\t%s\t%s\t\t%s\t\t%s\t%s\t\t%ld\t\t%ld\t\t%d\t\t%d\t\t%d\n"NONE,pos->data.number,pos->data.staddress,pos->data.arraddress,pos->data.DATE,pos->data.TYPE,pos->data.stime,pos->data.atime,pos->data.value,pos->data.seat_size,pos->data.poll);
					printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
					printf(LIGHT_CYAN"**是否修改该航班信息(yes or no)："NONE);
					while(1){
						scanf("%s",yesno);
						getchar();
						if(strlen(yesno) < 5 && strlen(yesno)> 0)
							break;
						printf("输入错误，请重新输入！\n");
						printf(LIGHT_CYAN"**是否修改该航班信息(yes or no)："NONE);
					}//end while
					if(strcmp(yesno,"yes") == 0){
						Choose_modity_flight(pos,s,t,t1);
						return true;
					}//end if yes			
				}
			}
			printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
			printf(LIGHT_CYAN"**************************查找失败，修改失败所有航班中没有找到您要修改的航班信息或您未确认修改，已进入管理员模式*******************************************\n"NONE);			
			printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
			break;
		case 6:
			list_for_each_entry(pos,&head->list,list){
				if((pos->data.stime == key.stime)){
					printf(LIGHT_PURPLE"\t航班号\t出发地点\t目地地点\t日期    \t机型      \t出发时间\t到达时间\t价格    \t总票数  \t余票 \n"NONE);					
					printf(RED"\t%s\t%s\t\t%s\t\t%s\t%s\t\t%ld\t\t%ld\t\t%d\t\t%d\t\t%d\n"NONE,pos->data.number,pos->data.staddress,pos->data.arraddress,pos->data.DATE,pos->data.TYPE,pos->data.stime,pos->data.atime,pos->data.value,pos->data.seat_size,pos->data.poll);
					printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
					printf(LIGHT_CYAN"**是否修改该航班信息(yes or no)："NONE);
					while(1){
						scanf("%s",yesno);
						getchar();
						if(strlen(yesno) < 5 && strlen(yesno)> 0)
							break;
						printf("输入错误，请重新输入！\n");
						printf(LIGHT_CYAN"**是否修改该航班信息(yes or no)："NONE);
					}//end while
					if(strcmp(yesno,"yes") == 0){
						Choose_modity_flight(pos,s,t,t1);
						return true;
					}//end if yes			
				}
			}
			printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
			printf(LIGHT_CYAN"**************************查找失败，修改失败所有航班中没有找到您要修改的航班信息或您未确认修改，已进入管理员模式*******************************************\n"NONE);			
			printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
			break;
		case 7:
			list_for_each_entry(pos,&head->list,list){
				if((pos->data.atime == key.atime)){
					printf(LIGHT_PURPLE"\t航班号\t出发地点\t目地地点\t日期    \t机型      \t出发时间\t到达时间\t价格    \t总票数  \t余票 \n"NONE);					
					printf(RED"\t%s\t%s\t\t%s\t\t%s\t%s\t\t%ld\t\t%ld\t\t%d\t\t%d\t\t%d\n"NONE,pos->data.number,pos->data.staddress,pos->data.arraddress,pos->data.DATE,pos->data.TYPE,pos->data.stime,pos->data.atime,pos->data.value,pos->data.seat_size,pos->data.poll);
					printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
					printf(LIGHT_CYAN"**是否修改该航班信息(yes or no)："NONE);
					while(1){
						scanf("%s",yesno);
						getchar();
						if(strlen(yesno) < 5 && strlen(yesno)> 0)
							break;
						printf("输入错误，请重新输入！\n");
						printf(LIGHT_CYAN"**是否修改该航班信息(yes or no)："NONE);
					}//end while
					if(strcmp(yesno,"yes") == 0){
						Choose_modity_flight(pos,s,t,t1);
						return true;
					}//end if yes			
				}
			}
			printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
			printf(LIGHT_CYAN"**************************查找失败，修改失败所有航班中没有找到您要修改的航班信息或您未确认修改，已进入管理员模式*******************************************\n"NONE);			
			printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
			break;
		case 8:
			list_for_each_entry(pos,&head->list,list){
				if((pos->data.value == key.value)){
					printf(LIGHT_PURPLE"\t航班号\t出发地点\t目地地点\t日期    \t机型      \t出发时间\t到达时间\t价格    \t总票数  \t余票 \n"NONE);					
					printf(RED"\t%s\t%s\t\t%s\t\t%s\t%s\t\t%ld\t\t%ld\t\t%d\t\t%d\t\t%d\n"NONE,pos->data.number,pos->data.staddress,pos->data.arraddress,pos->data.DATE,pos->data.TYPE,pos->data.stime,pos->data.atime,pos->data.value,pos->data.seat_size,pos->data.poll);
					printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
					printf(LIGHT_CYAN"**是否修改该航班信息(yes or no)："NONE);
					while(1){
						scanf("%s",yesno);
						getchar();
						if(strlen(yesno) < 5 && strlen(yesno)> 0)
							break;
						printf("输入错误，请重新输入！\n");
						printf(LIGHT_CYAN"**是否修改该航班信息(yes or no)："NONE);
					}//end while
					if(strcmp(yesno,"yes") == 0){
						Choose_modity_flight(pos,s,t,t1);
						return true;
					}//end if yes			
				}
			}
			printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
			printf(LIGHT_CYAN"**************************查找失败，修改失败所有航班中没有找到您要修改的航班信息或您未确认修改，已进入管理员模式*******************************************\n"NONE);			
			printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
			break;
		default:
			printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
			printf(LIGHT_CYAN"**************************查找失败，修改失败所有航班中没有找到您要修改的航班信息或您未确认修改，已进入管理员模式*******************************************\n"NONE);			
			printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
			return false;

	}//end switch

	return false;

}//end my_replace_flight


bool List_add_head_flight(node* head,struct flight pnew)
{
	node* tmp = (node*)malloc(sizeof(node));
	if(!tmp){
		return false;
	}
	tmp->data = pnew;
	INIT_LIST_HEAD(&tmp->list);

	list_add(&tmp->list,&head->list);

	return true;
}//end list_add_head

bool List_empty_flight(node* head)
{
	if(list_empty(&head->list) == true){
		return true;
	}

	return false;
}//end List_empty
#if 0
void Traverse_flight(struct node *head,int mode)
{
	struct node *pos = NULL;
	switch(mode){
		case 1:
			bubble_sort(&head->list,cmp_data_flight,1);
			list_for_each_entry(pos,&head->list,list){
				printf("/t%s/t%s/t%s/t%s/t%s/t%d/t%d/t%d/t%d",pos->data.number,pos->data.staddress,pos->data.arraddress,pos->data.DATE,pos->data.TYPE,pos->data.stime,pos->data.atime,pos->data.value,pos->data.poll);
			};break;
		case 2:
			bubble_sort(&head->list,cmp_data_flight,2);
			list_for_each_entry(pos,&head->list,list){
				printf("/t%s/t%s/t%s/t%s/t%s/t%d/t%d/t%d/t%d",pos->data.number,pos->data.staddress,pos->data.arraddress,pos->data.DATE,pos->data.TYPE,pos->data.stime,pos->data.atime,pos->data.value,pos->data.poll);	

			};break;
		case 3:
			bubble_sort(&head->list,cmp_data_flight,3);
			list_for_each_entry(pos,&head->list,list){
				printf("/t%s/t%s/t%s/t%s/t%s/t%d/t%d/t%d/t%d",pos->data.number,pos->data.staddress,pos->data.arraddress,pos->data.DATE,pos->data.TYPE,pos->data.stime,pos->data.atime,pos->data.value,pos->data.poll);
			};break;
		case 4:
			bubble_sort(&head->list,cmp_data_flight,4);
			list_for_each_entry(pos,&head->list,list){
				printf("/t%s/t%s/t%s/t%s/t%s/t%d/t%d/t%d/t%d",pos->data.number,pos->data.staddress,pos->data.arraddress,pos->data.DATE,pos->data.TYPE,pos->data.stime,pos->data.atime,pos->data.value,pos->data.poll);
			};break;
		default:return;

	}//end switch
	sleep(2);
}//end Traverse_flight
#endif

void Traverse_flight(struct node *head,int mode)
{

	printf(LIGHT_PURPLE"\t航班号\t出发地点\t目地地点\t日期    \t机型      \t出发时间\t到达时间\t价格    \t总票数  \t余票 \n"NONE);
	struct node *pos = NULL;
	switch(mode){
		case 1:
			bubble_sort(&head->list,cmp_data_flight,1);
			list_for_each_entry(pos,&head->list,list){
				printf(RED"\t%s\t%s\t\t%s\t\t%s\t%s\t%16.16s\t%16.16s\t\t%d\t\t%d\t\t%d\n"NONE,pos->data.number,pos->data.staddress,pos->data.arraddress,pos->data.DATE,pos->data.TYPE,ctime(&pos->data.stime),ctime(&pos->data.atime),pos->data.value,pos->data.seat_size,pos->data.poll);
			};break;
		case 2:
			bubble_sort(&head->list,cmp_data_flight,2);
			list_for_each_entry(pos,&head->list,list){
				printf(RED"\t%s\t%s\t\t%s\t\t%s\t%s\t%16.16s\t%16.16s\t\t%d\t\t%d\t\t%d\n"NONE,pos->data.number,pos->data.staddress,pos->data.arraddress,pos->data.DATE,pos->data.TYPE,ctime(&pos->data.stime),ctime(&pos->data.atime),pos->data.value,pos->data.seat_size,pos->data.poll);

			};break;
		case 3:
			bubble_sort(&head->list,cmp_data_flight,3);
			list_for_each_entry(pos,&head->list,list){
				printf(RED"\t%s\t%s\t\t%s\t\t%s\t%s\t%16.16s\t%16.16s\t\t%d\t\t%d\t\t%d\n"NONE,pos->data.number,pos->data.staddress,pos->data.arraddress,pos->data.DATE,pos->data.TYPE,ctime(&pos->data.stime),ctime(&pos->data.atime),pos->data.value,pos->data.seat_size,pos->data.poll);
			};break;
		case 4:
			bubble_sort(&head->list,cmp_data_flight,4);
			list_for_each_entry(pos,&head->list,list){
				printf(RED"\t%s\t%s\t\t%s\t\t%s\t%s\t%16.16s\t%16.16s\t\t%d\t\t%d\t\t%d\n"NONE,pos->data.number,pos->data.staddress,pos->data.arraddress,pos->data.DATE,pos->data.TYPE,ctime(&pos->data.stime),ctime(&pos->data.atime),pos->data.value,pos->data.seat_size,pos->data.poll);
			};break;
		case 5:
			list_for_each_entry(pos,&head->list,list){
				printf(RED"\t%s\t%s\t\t%s\t\t%s\t%s\t\t%16.16s\t%16.16s\t%d\t\t%d\t\t%d\n"NONE,pos->data.number,pos->data.staddress,pos->data.arraddress,pos->data.DATE,pos->data.TYPE,ctime(&pos->data.stime),ctime(&pos->data.atime),pos->data.value,pos->data.seat_size,pos->data.poll);

			};break;

	}//end switch
	sleep(1);
}//end Traverse_flight




void Remind_pasger(struct node_pasger* head)
{
	struct node_pasger *pos = NULL;
	list_for_each_entry(pos,&head->list,list){
		if((pos->data.fmsg.stime -10*60 <= time(NULL))){
			/***************************************************航班登机提醒**********************************************************************/
			printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
			printf(LIGHT_CYAN"*******************************************************************中国航班系统****************************************************************************\n"NONE);
			printf(LIGHT_CYAN"**************************************************************Wecome to airline system*********************************************************************\n"NONE);
			printf(LIGHT_CYAN"**                                                                                                                                                       **\n"NONE);
			printf(LIGHT_CYAN"**                                                                   温馨提醒：                                                                          **\n"NONE);		
			printf(YELLOW"**尊敬的 : %s : 您已购航班号 %s;出发地点  %s ;目地地点 %s;出发时间 %16.16s;到达时间 %16.16s;座位号：%d;请您尽快登机！！\n",pos->data.name,pos->data.fmsg.number,pos->data.fmsg.staddress,pos->data.fmsg.arraddress,ctime(&pos->data.fmsg.stime),ctime(&pos->data.fmsg.atime),pos->data.fmsg.seat_left);	
			sleep(4);
			return;
		}
	};

}//end remind pasger

bool Clean(struct node* head,struct node_pasger* head2)
{	
	struct node_pasger *pos = NULL;
	struct node* pos1 = NULL;
	list_for_each_entry(pos1,&head->list,list){
		if((pos1->data.stime <= time(NULL))){
			printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
			printf(LIGHT_CYAN"***************************************************温馨提示: 以下航班为无效航班，自动清除******************************************************************\n"NONE);
			printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);		
			printf(RED"\t航班号\t出发地点\t目地地点\t日期    \t机型      \t出发时间\t到达时间\t价格    \t总票数  \t余票 \n"NONE);
			printf(RED"\t%s\t%s\t\t%s\t\t%s\t%s\t\t%ld\t\t%ld\t\t%d\t\t%d\t\t%d\n"NONE,pos1->data.number,pos1->data.staddress,pos1->data.arraddress,pos1->data.DATE,pos1->data.TYPE,pos1->data.stime,pos1->data.atime,pos1->data.value,pos1->data.seat_size,pos1->data.poll);
			__list_del(pos1->list.prev,pos1->list.next);
			//list_del(&pos1->list);
			free(pos1);
			pos1 = NULL;
			printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
			printf(LIGHT_CYAN"***************************************************温馨提示: 以下航班为无效航班，清除成功******************************************************************\n"NONE);
			printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);	
			sleep(4);
			return;
		}
	};

	list_for_each_entry(pos,&head2->list,list){
		if((pos->data.fmsg.stime <= time(NULL))){
			printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
			printf(LIGHT_CYAN"***************************************************温馨提示: 以下航班为无效乘客，自动清除******************************************************************\n"NONE);
			printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);		
			printf(RED"\t姓名\t身份证号\t航班号\t出发地点\t目地地点\t日期    \t机型      \t出发时间\t到达时间\t价格    \t总票数  \t余票 \n"NONE);
			printf(RED"\t%s\t%d\t%s\t%s\t\t%s\t\t%s\t%s\t\t%ld\t\t%ld\t\t%d\t\t%d\t\n"NONE,pos->data.name,pos->data.ID,pos->data.fmsg.number,pos->data.fmsg.staddress,pos->data.fmsg.arraddress,pos->data.fmsg.DATE,pos->data.fmsg.TYPE,pos->data.fmsg.stime,pos->data.fmsg.atime,pos->data.fmsg.value,pos->data.fmsg.seat_size);

			__list_del(pos->list.prev,pos->list.next);
			//list_del(&pos->list);
			free(pos);
			pos = NULL;
			printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
			printf(LIGHT_CYAN"***************************************************温馨提示: 以下航班为无效乘客，清除成功******************************************************************\n"NONE);
			printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);	
			sleep(4);
			return;
		}
	};

}//end Clean_pasger



/**************************************************************

  passenger  function
 ************************************************************/

void Init_head_pasger(struct node_pasger **head_loc)
{
	//malloc space
	(*head_loc) = (struct node_pasger*)malloc(sizeof(struct node_pasger));
	if(!(*head_loc)){
		exit(-1);
	}
	INIT_LIST_HEAD(&(*head_loc)->list);
}//end init_head


bool Create_list_pasger(struct node_pasger* head)
{
	struct passenger tmp_p;
	struct flight tmp;
	printf("input data :name ID\n");
	scanf("%s%d",tmp_p.name,&tmp_p.ID);
	printf("input flight data: number staddress arraddress DATE TYPE stime value seate_size pool seat_lef\n");
	scanf("%s%s%s%s%s%ld%ld%d%d%d%d",tmp.number,tmp.staddress,tmp.arraddress,tmp.DATE,tmp.TYPE,&tmp.stime,&tmp.atime,&tmp.value,&tmp.seat_size,&tmp.poll,&tmp.seat_left);
	tmp_p.fmsg = tmp;
	char a[20];

	while(strcmp(a,"quit")){
		struct node_pasger* pnew = NULL;
		pnew = (struct node_pasger*)malloc(sizeof(struct node_pasger));
		if(!pnew){
			return false;
		}
		pnew->data = tmp_p;

		INIT_LIST_HEAD(&pnew->list);

		list_add_tail(&pnew->list,&head->list);
		printf("input data :name ID\n");
		scanf("%s%d",tmp_p.name,&tmp_p.ID);
		printf("input data: number staddress arraddress DATE TYPE stime value seate_size pool seat_lef\n");
		scanf("%s%s%s%s%s%ld%ld%d%d%d%d",tmp.number,tmp.staddress,tmp.arraddress,tmp.DATE,tmp.TYPE,&tmp.stime,&tmp.atime,&tmp.value,&tmp.seat_size,&tmp.poll,&tmp.seat_left);
		printf("**************************************************************************************");
		printf("*************************if exit input quit else contiue******************************");
		scanf("%s",a);
	}

}//end create_list

bool Insert_data_pasger(struct node_pasger* head,struct passenger* input,struct passenger key,int mode)
{
	struct node_pasger* pos = NULL;
	struct node_pasger* pnew = NULL;
	switch(mode){
		case 1:
			pnew = (struct node_pasger*)malloc(sizeof(struct node_pasger));
			pnew->data = *input;
			list_for_each_entry(pos,&head->list,list){
				if(strcmp(pos->data.fmsg.number,key.fmsg.number)){
					__list_add(&pnew->list,&pos->list,pos->list.next);
					/*list_add(&pnew->list,&pos->list);*/
					return true;
				}
			};break;
		case 2:
			pnew = (struct node_pasger*)malloc(sizeof(struct node_pasger));
			pnew->data = *input;
			list_for_each_entry(pos,&head->list,list){
				if(strcmp(pos->data.fmsg.staddress,key.fmsg.staddress)){
					__list_add(&pnew->list,&pos->list,pos->list.next);
					/*list_add(&pnew->list,&pos->list);*/
					return true;
				}
			};break;
		case 3:
			pnew = (struct node_pasger*)malloc(sizeof(struct node_pasger));
			pnew->data = *input;
			list_for_each_entry(pos,&head->list,list){
				if(strcmp(pos->data.fmsg.arraddress,key.fmsg.arraddress)){
					__list_add(&pnew->list,&pos->list,pos->list.next);
					/*list_add(&pnew->list,&pos->list);*/
					return true;
				}
			};break;
		case 4:
			pnew = (struct node_pasger*)malloc(sizeof(struct node_pasger));
			pnew->data = *input;
			list_for_each_entry(pos,&head->list,list){
				if(strcmp(pos->data.fmsg.DATE,key.fmsg.DATE)){
					__list_add(&pnew->list,&pos->list,pos->list.next);
					/*list_add(&pnew->list,&pos->list);*/
					return true;
				}
			};break;
		case 5:
			pnew = (struct node_pasger*)malloc(sizeof(struct node_pasger));
			pnew->data = *input;
			list_for_each_entry(pos,&head->list,list){
				if(strcmp(pos->data.fmsg.TYPE,key.fmsg.TYPE)){
					__list_add(&pnew->list,&pos->list,pos->list.next);
					/*list_add(&pnew->list,&pos->list);*/
					return true;
				}
			};break;
		case 6:
			pnew = (struct node_pasger*)malloc(sizeof(struct node_pasger));
			pnew->data = *input;
			list_for_each_entry(pos,&head->list,list){
				if((pos->data.fmsg.stime == key.fmsg.stime)){
					__list_add(&pnew->list,&pos->list,pos->list.next);
					/*list_add(&pnew->list,&pos->list);*/
					return true;
				}
			};break;
		case 7:
			pnew = (struct node_pasger*)malloc(sizeof(struct node_pasger));
			pnew->data = *input;
			list_for_each_entry(pos,&head->list,list){
				if((pos->data.fmsg.atime == key.fmsg.atime)){
					__list_add(&pnew->list,&pos->list,pos->list.next);
					/*list_add(&pnew->list,&pos->list);*/
					return true;
				}
			};break;
		case 8:
			pnew = (struct node_pasger*)malloc(sizeof(struct node_pasger));
			pnew->data = *input;
			list_for_each_entry(pos,&head->list,list){
				if((pos->data.fmsg.value == key.fmsg.value)){
					__list_add(&pnew->list,&pos->list,pos->list.next);
					/*list_add(&pnew->list,&pos->list);*/
					return true;
				}
			};break;
		case 0:
			pnew = (struct node_pasger*)malloc(sizeof(struct node_pasger));
			pnew->data = *input;
			list_add(&pnew->list,&head->list);
			return true;				
			break;
		default:return false;


	}//end switch

	return false;
}//end insert_data_pasger

bool Delete_data_pasger(struct node_pasger* head,struct passenger key,int mode)
{

	struct node_pasger* pos = NULL;
	struct node_pasger* pnew = NULL;
	switch(mode){
		case 1:
			list_for_each_entry(pos,&head->list,list){
				if(strcmp(pos->data.fmsg.number,key.fmsg.number)){
					__list_del(pos->list.prev,pos->list.next);
					//list_del(&pos->list);
					free(pos);
					pos = NULL;
					return true;
				}
			};break;
		case 2:
			list_for_each_entry(pos,&head->list,list){
				if(strcmp(pos->data.fmsg.staddress,key.fmsg.staddress)){
					__list_del(pos->list.prev,pos->list.next);
					//list_del(&pos->list);
					free(pos);
					pos = NULL;
					return true;
				}
			};break;
		case 3:
			list_for_each_entry(pos,&head->list,list){
				if(strcmp(pos->data.fmsg.arraddress,key.fmsg.arraddress)){
					__list_del(pos->list.prev,pos->list.next);
					//list_del(&pos->list);
					free(pos);
					pos = NULL;
					return true;
				}
			};break;
		case 4:
			list_for_each_entry(pos,&head->list,list){
				if(strcmp(pos->data.fmsg.DATE,key.fmsg.DATE)){
					__list_del(pos->list.prev,pos->list.next);
					//list_del(&pos->list);
					free(pos);
					pos = NULL;
					return true;
				}
			};break;
		case 5:
			list_for_each_entry(pos,&head->list,list){
				if(strcmp(pos->data.fmsg.TYPE,key.fmsg.TYPE)){
					__list_del(pos->list.prev,pos->list.next);
					//list_del(&pos->list);
					free(pos);
					pos = NULL;
					return true;
				}
			};break;
		case 6:
			list_for_each_entry(pos,&head->list,list){
				if((pos->data.fmsg.stime == key.fmsg.stime)){
					__list_del(pos->list.prev,pos->list.next);
					//list_del(&pos->list);
					free(pos);
					pos = NULL;
					return true;
				}
			};break;
		case 7:
			list_for_each_entry(pos,&head->list,list){
				if((pos->data.fmsg.atime == key.fmsg.atime)){
					__list_del(pos->list.prev,pos->list.next);
					//list_del(&pos->list);
					free(pos);
					pos = NULL;
					return true;
				}
			};break;
		case 8:
			list_for_each_entry(pos,&head->list,list){
				if((pos->data.fmsg.value == key.fmsg.value)){
					__list_del(pos->list.prev,pos->list.next);
					//list_del(&pos->list);
					free(pos);
					pos = NULL;
					return true;
				}
			};break;
		default:return false;

	}//end switch

	return false;
}//end delete_data

struct node_pasger* Find_node_pos_pasger(struct node_pasger* head,struct passenger key,int mode )
{
	struct node_pasger* pos = NULL;
	switch(mode){
		case 1:
			list_for_each_entry(pos,&head->list,list){
				if(strcmp(pos->data.fmsg.number,key.fmsg.number)){
					return pos;
				}
			};break;
		case 2:
			list_for_each_entry(pos,&head->list,list){
				if(strcmp(pos->data.fmsg.staddress,key.fmsg.staddress)){
					return pos;
				}
			};break;
		case 3:
			list_for_each_entry(pos,&head->list,list){
				if(strcmp(pos->data.fmsg.arraddress,key.fmsg.arraddress)){
					return pos;
				}
			};break;
		case 4:
			list_for_each_entry(pos,&head->list,list){
				if(strcmp(pos->data.fmsg.DATE,key.fmsg.DATE)){
					return pos;
				}
			};break;
		case 5:
			list_for_each_entry(pos,&head->list,list){
				if(strcmp(pos->data.fmsg.TYPE,key.fmsg.TYPE)){
					return pos;
				}
			};break;
		case 6:
			list_for_each_entry(pos,&head->list,list){
				if((pos->data.fmsg.stime == key.fmsg.stime)){
					return pos;
				}
			};break;
		case 7:
			list_for_each_entry(pos,&head->list,list){
				if((pos->data.fmsg.atime == key.fmsg.atime)){
					return pos;
				}
			};break;
		case 8:
			list_for_each_entry(pos,&head->list,list){
				if((pos->data.fmsg.value == key.fmsg.value)){
					return pos;
				}
			};break;
		default:return NULL;

	}//end switch

	return NULL;
}//end find struct node_pasger position

bool My_replace_pasger(struct node_pasger* head,struct passenger data,struct passenger key,int mode)
{
	struct node_pasger* pos = NULL;
	switch(mode){
		case 1:
			list_for_each_entry(pos,&head->list,list){
				if(strcmp(pos->data.fmsg.number,key.fmsg.number)){
					__list_del(pos->list.prev,pos->list.next);
					//list_del(&pos->list);
					pos->data = data ;
					pos = NULL;
					return true;			
				}
			};break;
		case 2:
			list_for_each_entry(pos,&head->list,list){
				if(strcmp(pos->data.fmsg.staddress,key.fmsg.staddress)){
					__list_del(pos->list.prev,pos->list.next);
					//list_del(&pos->list);
					pos->data = data ;
					pos = NULL;
					return true;			

				}
			};break;
		case 3:
			list_for_each_entry(pos,&head->list,list){
				if(strcmp(pos->data.fmsg.arraddress,key.fmsg.arraddress)){
					__list_del(pos->list.prev,pos->list.next);
					//list_del(&pos->list);
					pos->data = data ;
					pos = NULL;
					return true;			

				}
			};break;
		case 4:
			list_for_each_entry(pos,&head->list,list){
				if(strcmp(pos->data.fmsg.DATE,key.fmsg.DATE)){
					__list_del(pos->list.prev,pos->list.next);
					//list_del(&pos->list);
					pos->data = data ;
					pos = NULL;
					return true;			

				}
			};break;
		case 5:
			list_for_each_entry(pos,&head->list,list){
				if(strcmp(pos->data.fmsg.TYPE,key.fmsg.TYPE)){
					__list_del(pos->list.prev,pos->list.next);
					//list_del(&pos->list);
					pos->data = data ;
					pos = NULL;
					return true;			

				}
			};break;
		case 6:
			list_for_each_entry(pos,&head->list,list){
				if((pos->data.fmsg.stime == key.fmsg.stime)){
					__list_del(pos->list.prev,pos->list.next);
					//list_del(&pos->list);
					pos->data = data ;
					pos = NULL;
					return true;			

				}
			};break;
		case 7:
			list_for_each_entry(pos,&head->list,list){
				if((pos->data.fmsg.atime == key.fmsg.atime)){
					__list_del(pos->list.prev,pos->list.next);
					//list_del(&pos->list);
					pos->data = data ;
					pos = NULL;
					return true;			

				}
			};break;
		case 8:
			list_for_each_entry(pos,&head->list,list){
				if((pos->data.fmsg.value == key.fmsg.value)){
					__list_del(pos->list.prev,pos->list.next);
					//list_del(&pos->list);
					pos->data = data ;
					pos = NULL;
					return true;			

				}
			};break;
		default:return false;
	}//end switch
	return false;

}//end my_replace
bool List_add_head_pasger(struct node_pasger* head,struct passenger pnew)
{
	struct node_pasger* tmp = (struct node_pasger*)malloc(sizeof(struct node_pasger));
	if(!tmp){
		return false;
	}
	tmp->data = pnew;
	INIT_LIST_HEAD(&tmp->list);

	list_add(&tmp->list,&head->list);

	return true;
}//end list_add_head

bool List_empty_pasger(struct node_pasger* head)
{
	if(list_empty(&head->list) == true){
		return true;
	}

	return false;
}//end List_empty

void Traverse_pasger(struct node_pasger *head,int mode)
{
	struct node_pasger *pos = NULL;
	switch(mode){
		case 1:
			bubble_sort(&head->list,cmp_data_pasger,1);
			list_for_each_entry(pos,&head->list,list){
				printf("/t%s/t%d/t%s/t%s/t%s/t%s/t%s/t%ld/t%ld/t%d/t%d",pos->data.name,pos->data.ID,pos->data.fmsg.number,pos->data.fmsg.staddress,pos->data.fmsg.arraddress,pos->data.fmsg.DATE,pos->data.fmsg.TYPE,pos->data.fmsg.stime,pos->data.fmsg.atime,pos->data.fmsg.value,pos->data.fmsg.poll);
			};break;
		case 2:
			bubble_sort(&head->list,cmp_data_pasger,2);
			list_for_each_entry(pos,&head->list,list){
				printf("/t%s/t%d/t%s/t%s/t%s/t%s/t%s/t%ld/t%ld/t%d/t%d",pos->data.name,pos->data.ID,pos->data.fmsg.number,pos->data.fmsg.staddress,pos->data.fmsg.arraddress,pos->data.fmsg.DATE,pos->data.fmsg.TYPE,pos->data.fmsg.stime,pos->data.fmsg.atime,pos->data.fmsg.value,pos->data.fmsg.poll);

			};break;
		case 3:
			bubble_sort(&head->list,cmp_data_pasger,3);
			list_for_each_entry(pos,&head->list,list){
				printf("/t%s/t%s/t%s/t%s/t%s/t%ld/t%ld/t%d/t%d",pos->data.fmsg.number,pos->data.fmsg.staddress,pos->data.fmsg.arraddress,pos->data.fmsg.DATE,pos->data.fmsg.TYPE,pos->data.fmsg.stime,pos->data.fmsg.atime,pos->data.fmsg.value,pos->data.fmsg.poll);
			};break;
		case 4:
			bubble_sort(&head->list,cmp_data_pasger,4);
			list_for_each_entry(pos,&head->list,list){
				printf("/t%s/t%s/t%s/t%s/t%s/t%ld/t%ld/t%d/t%d",pos->data.fmsg.number,pos->data.fmsg.staddress,pos->data.fmsg.arraddress,pos->data.fmsg.DATE,pos->data.fmsg.TYPE,pos->data.fmsg.stime,pos->data.fmsg.atime,pos->data.fmsg.value,pos->data.fmsg.poll);
			};break;
		default:return;

	}//end switch
}//end Traverse_pasger


/************************************************************/
/****************************sort********************************/
/************************************************************/
int  cmp_data_flight(struct list_head *a, struct list_head *b,int mode)
{
	struct node *pa = list_entry(a, struct node, list);
	struct node *pb = list_entry(b, struct node, list);
	switch(mode){
		case 1:return (pa->data.stime - pb->data.stime);break;
		case 2:return (pa->data.atime - pb->data.atime);break;
		case 3:return (pa->data.value - pb->data.value);break;
		case 4:return (pa->data.poll - pb->data.poll);break;
		default:return 0;
	}//end switch
}

int  cmp_data_pasger(struct list_head *a, struct list_head *b,int mode)
{
	struct node_pasger *pa = list_entry(a, struct node_pasger, list);
	struct node_pasger *pb = list_entry(b, struct node_pasger, list);
	switch(mode){
		case 1:return (pa->data.fmsg.stime - pb->data.fmsg.stime);break;
		case 2:return (pa->data.fmsg.atime - pb->data.fmsg.atime);break;
		case 3:return (pa->data.fmsg.value - pb->data.fmsg.value);break;
		case 4:return (pa->data.fmsg.poll - pb->data.fmsg.poll);break;
		case 5:return (pa->data.ID - pa->data.ID);break;
		default:return 0;
	}//end switch
}


void  swap(struct list_head *a, struct list_head *b)
{
	struct  list_head flag = {NULL, NULL};
	__list_add(&flag, b->prev, b);
	list_del(b);
	__list_add(b, a->prev, a);
	list_del(a);
	__list_add(a, flag.prev, &flag);
	list_del(&flag);
}

void  bubble_sort(struct list_head *head, int  (*compar)(struct list_head *, struct list_head *,int),int mode)
{
	struct list_head *start = NULL; 
	struct list_head *end = NULL;   
	list_for_each_reverse(end, head) 
	{   
		list_for_each(start, head) 
		{           
			if (start == end)                       
				break;

			if (compar(start, start->next,mode) > 0) 
			{
				swap(start, start->next);                           
				start = start->prev; //start归位
				if (start == end) 
					end = end->next; //end归位            
			}
		}
	}
}//end buble_sort

void Input_pasger_interface(struct passenger* pasger){
	/***************************************************航班表输入图形界面设计**********************************************************************/
	printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
	printf(LIGHT_CYAN"*******************************************************************中国航班--订票航班**********************************************************************\n"NONE);
	printf(LIGHT_CYAN"**************************************************************Wecome to airline system*********************************************************************\n"NONE);
	printf(LIGHT_CYAN"** 请输入姓        名："NONE);
	while(1){
		scanf("%s",pasger->name);
		getchar();
		if(strlen(pasger->name) < 18 && strlen(pasger->name) > 0 )
			break;
		printf("输入错误，请重新输入！\n");
		printf(LIGHT_CYAN"** 请输入姓        名："NONE);
	}
	putchar(10);
	printf(LIGHT_CYAN"** 请输入身份    证号："NONE);
	while(1){
		scanf("%d",&pasger->ID);
		getchar();
		if( pasger->ID > 0 && pasger->ID <2147483647)
			break;
		printf("输入错误，请重新输入！\n");
		printf(LIGHT_CYAN"** 请输入身份    证号："NONE);
	}
	putchar(10);
	printf(LIGHT_CYAN"** 请输入航   班   号："NONE);
	while(1){
		scanf("%s",pasger->fmsg.number);
		getchar();
		if(strlen(pasger->fmsg.number) < 18 && strlen(pasger->fmsg.number) > 0 )
			break;
		printf("输入错误，请重新输入！\n");
		printf(LIGHT_CYAN"** 请输入航   班   号："NONE);
	}
	putchar(10);
	printf(LIGHT_CYAN"** 请输入起   点   站："NONE);
	while(1){
		scanf("%s",pasger->fmsg.staddress);
		getchar();
		if(strlen(pasger->fmsg.staddress) < 18 && strlen(pasger->fmsg.staddress) > 0)
			break;
		printf("输入错误，请重新输入！\n");
		printf(LIGHT_CYAN"** 请输入起   点   站："NONE);
	}
	putchar(10);
	printf(LIGHT_CYAN"** 请输入终   点   站："NONE);
	while(1){
		scanf("%s",pasger->fmsg.arraddress);
		getchar();
		if(strlen(pasger->fmsg.arraddress) < 18 && strlen(pasger->fmsg.arraddress) > 0)
			break;
		printf("输入错误，请重新输入！\n");
		printf(LIGHT_CYAN"** 请输入终   点   站："NONE);
	}
	putchar(10);
	printf(LIGHT_CYAN"** 请输入班        期："NONE);
	while(1){
		scanf("%s",pasger->fmsg.DATE);
		getchar();
		if(strlen(pasger->fmsg.DATE) < 12 && strlen(pasger->fmsg.DATE) > 0)
			break;
		printf("输入错误，请重新输入！\n");
		printf(LIGHT_CYAN"** 请输入班        期："NONE);
	}
	putchar(10);
	printf(LIGHT_CYAN"** 请输入机        型："NONE);
	while(1){
		scanf("%s",pasger->fmsg.TYPE);
		getchar();
		if(strlen(pasger->fmsg.TYPE) < 8 && strlen(pasger->fmsg.TYPE) > 0)
			break;
		printf("输入错误，请重新输入！\n");
		printf(LIGHT_CYAN"** 请输入机        型："NONE);
	}
	putchar(10);
	printf(LIGHT_CYAN"** 请输入从现在起飞机將多久起飞："NONE);
	while(1){
		scanf("%ld",&pasger->fmsg.stime);
		getchar();
		if(235959 >pasger->fmsg.stime && pasger->fmsg.stime >= 0)
			break;
		printf("输入错误，请重新输入！\n");
		printf(LIGHT_CYAN"** 请输入从现在起飞机將多久起飞："NONE);
	}
	pasger->fmsg.stime = time(NULL) + pasger->fmsg.stime * 60 ;	
	putchar(10);
	printf(LIGHT_CYAN"** 请输入起飞后多久到达目的地："NONE);
	while(1){
		scanf("%ld",&pasger->fmsg.atime);
		getchar();
		if(235959 >pasger->fmsg.atime && pasger->fmsg.atime >= 0)
			break;
		printf("输入错误，请重新输入！\n");
		printf(LIGHT_CYAN"** 请输入起飞后多久到达目的地："NONE);
	}
	pasger->fmsg.atime =  pasger->fmsg.atime * 60 + pasger->fmsg.stime;
	putchar(10);
	printf(LIGHT_CYAN"** 请输入票        价："NONE);
	while(1){
		scanf("%d",&pasger->fmsg.value);
		getchar();
		if(2147483647 >pasger->fmsg.value >= 0)
			break;
		printf("输入错误，请重新输入！\n");
		printf(LIGHT_CYAN"** 请输入票        价："NONE);
	}	
	putchar(10);
	printf(LIGHT_CYAN"** 请输入机舱 座 位数："NONE);
	while(1){
		scanf("%d",&pasger->fmsg.seat_size);
		getchar();
		if(1000 >pasger->fmsg.seat_size >= 0)
			break;
		printf("输入错误，请重新输入！\n");
		printf(LIGHT_CYAN"** 请输入机舱 座 位数："NONE);
	}	
	putchar(10);
	printf(LIGHT_CYAN"** 请输入初始剩余票数："NONE);
	while(1){
		scanf("%d",&pasger->fmsg.poll);
		getchar();
		if(1000 >pasger->fmsg.poll >= 0)
			break;
		printf("输入错误，请重新输入！\n");
		printf(LIGHT_CYAN"** 请输入初始剩余票数："NONE);
	}
	putchar(10);
	printf(LIGHT_CYAN"** 请输入初始座位位置："NONE);
	while(1){
		scanf("%d",&pasger->fmsg.seat_left);
		getchar();
		if(1000 >pasger->fmsg.seat_left >= 0)
			break;
		printf("输入错误，请重新输入！\n");
		printf(LIGHT_CYAN"** 请输入初始剩余票数："NONE);
	}
	putchar(10);
	printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
	printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
	printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);	

}//end input pasger interface

void Input_flight_interface(struct flight* fly){	
	/***************************************************航班表输入图形界面设计**********************************************************************/
	printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
	printf(LIGHT_CYAN"*******************************************************************中国航班--录入航班**********************************************************************\n"NONE);
	printf(LIGHT_CYAN"**************************************************************Wecome to airline system*********************************************************************\n"NONE);
	printf(LIGHT_CYAN"** 请输入航   班   号："NONE);
	while(1){
		scanf("%s",fly->number);
		getchar();
		if(strlen(fly->number) < 18 && strlen(fly->number) > 0 )
			break;
		printf("输入错误，请重新输入！\n");
		printf(LIGHT_CYAN"** 请输入航   班   号："NONE);
	}
	putchar(10);
	printf(LIGHT_CYAN"** 请输入起   点   站："NONE);
	while(1){
		scanf("%s",fly->staddress);
		getchar();
		if(strlen(fly->staddress) < 18 && strlen(fly->staddress) > 0)
			break;
		printf("输入错误，请重新输入！\n");
		printf(LIGHT_CYAN"** 请输入起   点   站："NONE);
	}
	putchar(10);
	printf(LIGHT_CYAN"** 请输入终   点   站："NONE);
	while(1){
		scanf("%s",fly->arraddress);
		getchar();
		if(strlen(fly->arraddress) < 18 && strlen(fly->arraddress) > 0)
			break;
		printf("输入错误，请重新输入！\n");
		printf(LIGHT_CYAN"** 请输入终   点   站："NONE);
	}
	putchar(10);
	printf(LIGHT_CYAN"** 请输入班        期："NONE);
	while(1){
		scanf("%s",fly->DATE);
		getchar();
		if(strlen(fly->DATE) < 12 && strlen(fly->DATE) > 0)
			break;
		printf("输入错误，请重新输入！\n");
		printf(LIGHT_CYAN"** 请输入班        期："NONE);
	}
	putchar(10);
	printf(LIGHT_CYAN"** 请输入机        型："NONE);
	while(1){
		scanf("%s",fly->TYPE);
		getchar();
		if(strlen(fly->TYPE) < 8 && strlen(fly->TYPE) > 0)
			break;
		printf("输入错误，请重新输入！\n");
		printf(LIGHT_CYAN"** 请输入机        型："NONE);
	}
	putchar(10);
	printf(LIGHT_CYAN"** 请输入从现在起飞机將多久起飞："NONE);
	while(1){
		scanf("%ld",&fly->stime);
		getchar();
		if(235959 >fly->stime && fly->stime >= 0)
			break;
		printf("输入错误，请重新输入！\n");
		printf(LIGHT_CYAN"** 请输入从现在起飞机將多久起飞："NONE);
	}
	fly->stime = (fly->stime * 60) + time(NULL);
	printf("stime: %s\n",ctime(&fly->stime));
	putchar(10);
	printf(LIGHT_CYAN"** 请输入起飞后多久到达目的地："NONE);
	while(1){
		scanf("%ld",&fly->atime);
		getchar();
		if(235959 >fly->atime && fly->atime >= 0)
			break;
		printf("输入错误，请重新输入！\n");
		printf(LIGHT_CYAN"** 请输入起飞后多久到达目的地："NONE);
	}
	fly->atime = (fly->atime * 60 ) +  (fly->stime);
	printf("stime: %s\n",ctime(&fly->atime));
	putchar(10);
	printf(LIGHT_CYAN"** 请输入票        价："NONE);
	while(1){
		scanf("%d",&fly->value);
		getchar();
		if(2147483647 >fly->value >= 0)
			break;
		printf("输入错误，请重新输入！\n");
		printf(LIGHT_CYAN"** 请输入票        价："NONE);
	}	
	putchar(10);
	printf(LIGHT_CYAN"** 请输入机舱 座 位数："NONE);
	while(1){
		scanf("%d",&fly->seat_size);
		getchar();
		if(1000 >fly->seat_size >= 0)
			break;
		printf("输入错误，请重新输入！\n");
		printf(LIGHT_CYAN"** 请输入机舱 座 位数："NONE);
	}	
	putchar(10);
	printf(LIGHT_CYAN"** 请输入初始剩余票数："NONE);
	while(1){
		scanf("%d",&fly->poll);
		getchar();
		if(1000 >fly->poll >= 0)
			break;
		printf("输入错误，请重新输入！\n");
		printf(LIGHT_CYAN"** 请输入初始剩余票数："NONE);
	}
	putchar(10);
	printf(LIGHT_CYAN"** 请输入初始座位位置："NONE);
	while(1){
		scanf("%d",&fly->seat_left);
		getchar();
		if(1000 >fly->seat_left >= 0)
			break;
		printf("输入错误，请重新输入！\n");
		printf(LIGHT_CYAN"** 请输入初始剩余票数："NONE);
	}
	putchar(10);
	printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
	printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
	printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);	

}//input flight interface




void Check_list_flight(node* head,struct flight key,int mode)
{
	node* pos = NULL;
	switch(mode){
		case 1:
			list_for_each_entry(pos,&head->list,list){
				if(strcmp(pos->data.number,key.number) == 0){
					printf(RED"\t航班号\t出发地点\t目地地点\t日期    \t机型      \t出发时间\t到达时间\t价格    \t总票数  \t余票 \n"NONE);					
					printf(RED"\t%s\t%s\t\t%s\t\t%s\t%s\t\t%ld\t\t%ld\t\t%d\t\t%d\t\t%d\n"NONE,pos->data.number,pos->data.staddress,pos->data.arraddress,pos->data.DATE,pos->data.TYPE,pos->data.stime,pos->data.atime,pos->data.value,pos->data.seat_size,pos->data.poll);
					printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
				}//end if number
			}//end list_for_each_entry
			printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
			printf(LIGHT_CYAN"**************************查找失败:所有航班中没有找到您要查找的航班信息，已进入管理员模式******************************************************************\n"NONE);			
			printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
			return;
			break;
		case 2:
			list_for_each_entry(pos,&head->list,list){
				if(strcmp(pos->data.staddress,key.staddress)){
					printf(RED"\t航班号\t出发地点\t目地地点\t日期    \t机型      \t出发时间\t到达时间\t价格    \t总票数  \t余票 \n"NONE);					
					printf(RED"\t%s\t%s\t\t%s\t\t%s\t%s\t\t%ld\t\t%ld\t\t%d\t\t%d\t\t%d\n"NONE,pos->data.number,pos->data.staddress,pos->data.arraddress,pos->data.DATE,pos->data.TYPE,pos->data.stime,pos->data.atime,pos->data.value,pos->data.seat_size,pos->data.poll);
					printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
					return;
				}//end if staddress
			}//end list_for_each_entry
			printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
			printf(LIGHT_CYAN"**************************查找失败:所有航班中没有找到您要查找的航班信息，已进入管理员模式******************************************************************\n"NONE);			
			printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
			break;
		case 3:
			list_for_each_entry(pos,&head->list,list){
				if(strcmp(pos->data.arraddress,key.arraddress)){
					printf(RED"\t航班号\t出发地点\t目地地点\t日期    \t机型      \t出发时间\t到达时间\t价格    \t总票数  \t余票 \n"NONE);					
					printf(RED"\t%s\t%s\t\t%s\t\t%s\t%s\t\t%ld\t\t%ld\t\t%d\t\t%d\t\t%d\n"NONE,pos->data.number,pos->data.staddress,pos->data.arraddress,pos->data.DATE,pos->data.TYPE,pos->data.stime,pos->data.atime,pos->data.value,pos->data.seat_size,pos->data.poll);
					printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
					return;
				}
			}
			printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
			printf(LIGHT_CYAN"**************************查找失败:所有航班中没有找到您要查找的航班信息，已进入管理员模式******************************************************************\n"NONE);			
			printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
			break;
		case 4:
			list_for_each_entry(pos,&head->list,list){
				if(strcmp(pos->data.DATE,key.DATE)){
					printf(RED"\t航班号\t出发地点\t目地地点\t日期    \t机型      \t出发时间\t到达时间\t价格    \t总票数  \t余票 \n"NONE);					
					printf(RED"\t%s\t%s\t\t%s\t\t%s\t%s\t\t%ld\t\t%ld\t\t%d\t\t%d\t\t%d\n"NONE,pos->data.number,pos->data.staddress,pos->data.arraddress,pos->data.DATE,pos->data.TYPE,pos->data.stime,pos->data.atime,pos->data.value,pos->data.seat_size,pos->data.poll);
					printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
					return;
				}
			}
			printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
			printf(LIGHT_CYAN"**************************查找失败:所有航班中没有找到您要查找的航班信息，已进入管理员模式******************************************************************\n"NONE);			
			printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
			break;
		case 5:
			list_for_each_entry(pos,&head->list,list){
				if(strcmp(pos->data.TYPE,key.TYPE)){
					printf(RED"\t航班号\t出发地点\t目地地点\t日期    \t机型      \t出发时间\t到达时间\t价格    \t总票数  \t余票 \n"NONE);					
					printf(RED"\t%s\t%s\t\t%s\t\t%s\t%s\t\t%ld\t\t%ld\t\t%d\t\t%d\t\t%d\n"NONE,pos->data.number,pos->data.staddress,pos->data.arraddress,pos->data.DATE,pos->data.TYPE,pos->data.stime,pos->data.atime,pos->data.value,pos->data.seat_size,pos->data.poll);
					printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
					return;
				}
			}
			printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
			printf(LIGHT_CYAN"**************************查找失败:所有航班中没有找到您要查找的航班信息，已进入管理员模式******************************************************************\n"NONE);			
			printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
			break;
		case 6:
			list_for_each_entry(pos,&head->list,list){
				if((pos->data.stime == key.stime)){
					printf(RED"\t航班号\t出发地点\t目地地点\t日期    \t机型      \t出发时间\t到达时间\t价格    \t总票数  \t余票 \n"NONE);					
					printf(RED"\t%s\t%s\t\t%s\t\t%s\t%s\t\t%ld\t\t%ld\t\t%d\t\t%d\t\t%d\n"NONE,pos->data.number,pos->data.staddress,pos->data.arraddress,pos->data.DATE,pos->data.TYPE,pos->data.stime,pos->data.atime,pos->data.value,pos->data.seat_size,pos->data.poll);
					printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
					return;
				}
			}
			printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
			printf(LIGHT_CYAN"**************************查找失败:所有航班中没有找到您要查找的航班信息，已进入管理员模式******************************************************************\n"NONE);			
			printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
			break;
		case 7:
			list_for_each_entry(pos,&head->list,list){
				if((pos->data.atime == key.atime)){
					printf(RED"\t航班号\t出发地点\t目地地点\t日期    \t机型      \t出发时间\t到达时间\t价格    \t总票数  \t余票 \n"NONE);					
					printf(RED"\t%s\t%s\t\t%s\t\t%s\t%s\t\t%ld\t\t%ld\t\t%d\t\t%d\t\t%d\n"NONE,pos->data.number,pos->data.staddress,pos->data.arraddress,pos->data.DATE,pos->data.TYPE,pos->data.stime,pos->data.atime,pos->data.value,pos->data.seat_size,pos->data.poll);
					printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
					return;
				}
			}
			printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
			printf(LIGHT_CYAN"**************************查找失败:所有航班中没有找到您要查找的航班信息，已进入管理员模式******************************************************************\n"NONE);			
			printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
			printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
		break;
default:
printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);
printf(LIGHT_CYAN"**************************查找失败:所有航班中没有找到您要查找的航班信息，已进入管理员模式******************************************************************\n"NONE);			
printf(LIGHT_CYAN"***********************************************************************************************************************************************************\n"NONE);

}//end switch

}//end Check_list_flight

