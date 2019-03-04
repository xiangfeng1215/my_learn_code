#include "wrapperMain.h"
#include "msg.h"


void my_daemon(void)
{     
	umask(0);

	pid_t new_pid = fork();
	if(new_pid < 0)
		exit(-1);
	if(new_pid > 0)
		exit(0);

	if(setsid() == (pid_t)-1)
		exit(-2);    

	(void)signal(SIGCHLD,SIG_IGN);
	(void)daemon(0,0);
}

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

/***********************线程清理*******************/

int main(void)
{
#if 1
	
	//(void)my_daemon();	



	struct node *head_flight;
	struct node_pasger *head_pasger;
	(void)Init_head_flight(&head_flight);
	(void)Init_head_pasger(&head_pasger);

	/****************读文件信息********************/
	RW_file_init(head_flight,head_pasger,2);

	/****************线程自动清理***********************/
	pthread_t tid;
	thread_data tdata;
	tdata.head_flight = head_flight;
	tdata.head_pasger = head_pasger;
	pthread_create(&tid,NULL,my_Thread,(void*)&tdata);
	/****************线程自动清理***********************/

	void* addr = (void*)0;
    addr = sharedMemory_write();

	struct mem_st m;
	Init_mem(&m, 8192,sizeof(struct flight),sizeof(struct passenger));

	while(1){
		printf("rw_shared_memory\n");
		RW_shared_memorty(head_flight,head_pasger,2,&m,addr);
	    (void)Traverse_flight(head_flight,0);
		printf("end rw_shared_memory\n");
		sleep(2);
	}//end while
	/****************线程自动清理***********************/
	pthread_join(tid,NULL);
	/****************线程自动清理***********************/
	printf("traverse \n");
#endif
	return 0;
}
