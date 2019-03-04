#include "wrapperMain.h"
#include "msg.h"

struct flight *addr_f;
struct passenger *addr_p;


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

void *my_Thread_Read_shm(void *arg)
{
	while(1){
		thread_data *tdata = (thread_data *)arg;
		RW_shared_memorty(tdata->head_flight,tdata->head_pasger,3,addr_f,addr_p);
		RW_shared_memorty(tdata->head_flight,tdata->head_pasger,4,addr_f,addr_p);
		RW_file_init(tdata->head_flight,tdata->head_pasger,1);
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


	Traverse_flight(head_flight,0);


	int shmid_f;
	shmid_f= sharedMemory_write(22);
	addr_f= sharedMemoryAttach(shmid_f);
	int shmid_p;
	shmid_p = sharedMemory_write(23);
	addr_p = sharedMemoryAttach(shmid_p);

	/****************线程自动清理***********************/
	pthread_t tid[4];
	thread_data tdata;
	tdata.head_flight = head_flight;
	tdata.head_pasger = head_pasger;
	pthread_create(&tid[0],NULL,my_Thread,(void*)&tdata);
	pthread_create(&tid[2],NULL,my_Thread_Read_shm,(void*)&tdata);
	
	/****************线程自动清理***********************/
	while(1){
	//	printf("rw_shared_memory\n");
		RW_shared_memorty(head_flight,head_pasger,1,addr_f,addr_p);
		RW_shared_memorty(head_flight,head_pasger,2,addr_f,addr_p);
	//	printf("end rw_shared_memory\n");
		sleep(10);
	}//end while
	/****************线程自动清理***********************/
	pthread_join(tid[0],NULL);
	pthread_join(tid[2],NULL);
	/****************线程自动清理***********************/
	printf("traverse \n");
#endif
	return 0;
}
