#include "wrapperMain.h"
#include "msg.h"

struct data_cnt count_fp;
struct data_cnt *addr_c;
struct flight *addr_f;
struct passenger *addr_p;
/******************线程清理**************************/
typedef struct thread_data{
	struct node* head_flight;
	struct node_pasger* head_pasger;
}thread_data;

void *my_Thread(void *arg)
{
	while(1){
		thread_data *tdata = (thread_data *)arg;
		Remind_pasger(tdata->head_pasger);
		Clean(tdata->head_flight,tdata->head_pasger);
		//pthread_exit(NULL);
		sleep(3);
	}
}
void *my_Thread_Count_fp(void *arg)
{
	while(1){
		struct data_cnt *addr_c = (struct data_cnt *)arg;
		addr_c[0] = count_fp;
	 	printf("count_fp.flight: %d ,count_fp.pasger :%d \n",count_fp.flight,count_fp.pasger);	
		//pthread_exit(NULL);
		sleep(3);
	}   
}


void *my_Thread_Read_shm(void *arg)
{
	while(1){
		thread_data *tdata = (thread_data *)arg;
		RW_shared_memorty(tdata->head_flight,tdata->head_pasger,&count_fp,3,addr_f,addr_p);
		RW_shared_memorty(tdata->head_flight,tdata->head_pasger,&count_fp,4,addr_f,addr_p);
		//RW_file_init(tdata->head_flight,tdata->head_pasger,1);
		//pthread_exit(NULL);
		sleep(3);
	}
}

void *my_Thread_Write_shm(void *arg)
{
	while(1){
		thread_data *tdata = (thread_data *)arg;
		RW_shared_memorty(tdata->head_flight,tdata->head_pasger,&count_fp,1,addr_f,addr_p);
		RW_shared_memorty(tdata->head_flight,tdata->head_pasger,&count_fp,2,addr_f,addr_p);
		//RW_file_init(tdata->head_flight,tdata->head_pasger,1);
		//pthread_exit(NULL);
		sleep(3);
	}
}

/***********************线程清理*******************/

int main(void)
{
#if 1

	struct node *head_flight;
	struct node_pasger *head_pasger;
	(void)Init_head_flight(&head_flight);
	(void)Init_head_pasger(&head_pasger);
	/****************读文件信息********************/
	//RW_file_init(head_flight,head_pasger,2);
	Traverse_flight(head_flight,0);

	int shmid_c;
	shmid_c= sharedMemory_write(21);
	addr_c= sharedMemoryAttach(shmid_c);

	count_fp = addr_c[0];

	int shmid_f;
	shmid_f= sharedMemory_write(22);
	addr_f= sharedMemoryAttach(shmid_f);
	int shmid_p;
	shmid_p = sharedMemory_write(23);
	addr_p = sharedMemoryAttach(shmid_p);

	RW_shared_memorty(head_flight,head_pasger,&count_fp,3,addr_f,addr_p);
	RW_shared_memorty(head_flight,head_pasger,&count_fp,4,addr_f,addr_p);
	/****************线程自动清理***********************/
	pthread_t tid[5];
	thread_data tdata;
	tdata.head_flight = head_flight;
	tdata.head_pasger = head_pasger;
	//pthread_create(&tid[0],NULL,my_Thread,(void*)&tdata);
    //pthread_create(&tid[1],NULL,my_Thread_Count_fp,(void*)&addr_c);
	pthread_create(&tid[2],NULL,my_Thread_Read_shm,(void*)&tdata);
	//pthread_create(&tid[3],NULL,my_Thread_Write_shm,(void*)&tdata);


	/****************线程自动清理***********************/
	//pthread_join(tid,NULL);
	/***************************************/
	Show(250000);
	printf("初始化中..................\n");
	//(void)Create_list_flight(head_flight);
	//(void)Traverse_flight(head_flight,0);
	//(void)Traverse_flight(head_flight,1);
	//int seat;
	//seat=Seat_show(head_pasger,"5");
	//printf("your choose seat is %d\n",seat);

	sleep(1);
	while(1){
		system("clear");
		Menu_interface(head_flight,head_pasger);
		char mode;
		printf(LIGHT_CYAN"**  请输入您的要进入的模式："NONE);
		while(1){	
			scanf("%c",&mode);
			getchar();
			if( '3'>= mode && mode >='1')
				break;
			printf("输入错误，请重新输入！\n");
			printf(LIGHT_CYAN"**                                    温馨提示   ：  您输入有误，请重新输入，谢谢    ^~^  ^~^ ^~^                                                        **\n"NONE);
			printf(LIGHT_CYAN"**  请输入您的要进入的模式："NONE);
		}
		switch(mode){
			case '1':
				Admin_interface(head_flight,head_pasger);
				;break;
			case '2':
				User_interface(head_flight,head_pasger);
				;break;
			case '3':
				//RW_file_init(head_flight,head_pasger,1);
				exit(0);
				;break;
			default:
				printf(LIGHT_CYAN"**                                    温馨提示   ：  您输入有误，请重新输入，谢谢    ^~^  ^~^ ^~^                                                        **\n"NONE);
				;
		}//end switch
	}//end while
	/****************线程自动清理***********************/
	pthread_join(tid[0],NULL);
	/****************线程自动清理***********************/
	printf("traverse \n");
#endif
	return 0;
}
