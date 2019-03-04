#include "memoryManger.h"

#define MEM_SIZE  8182

void *sharedMemory_write(void)
{
	int shmid_key = sharedMemoryGetKey(22);
	if(shmid_key < 0 ){
		perror("shmid_key");
		exit(EXIT_FAILURE);
	}

	int shmid = sharedMemoryCreateOrGet(shmid_key,MEM_SIZE);
	if(shmid < 0){
		perror("shmid");
		exit(EXIT_FAILURE);
	}

	void* addr = sharedMemoryAttach(shmid);

	return addr;

}//sharedMemory

void Init_mem(memst* m, int mem_size,int data_size_f,int data_size_p)
{
	m->cur_f = 0;
	m->mem_size_f = mem_size/2;
	m->data_size_f = data_size_f;

	m->cur_p = mem_size/2;
	m->mem_size_p = mem_size;
	m->data_size_p = data_size_p;
	printf("mem_size_f : %d ;data_size_f : %d \n",m->mem_size_f,m->data_size_f);

}//end Init_mem

bool Push(void *addr,memst* m,char mode)
{
	if(mode == 'f'){
		if(!Is_full(m,'f')){
			struct flight *data_f;
			data_f = (struct flight *)addr;
			*(data_f + m->cur_f) = m->f;
			m->cur_f = m->cur_f + m->data_size_f;
		}else{
			exit(EXIT_FAILURE);
		}
	}else if(mode == 'p'){
		if(!Is_full(m,'p')){
			struct passenger *data_p;
			data_p = (struct passenger *)addr;
			*(data_p + m->cur_p) = m->p;
			m->cur_p = m->cur_p + m->data_size_p;
		}else{
			exit(EXIT_FAILURE);
		}

	}
}//end Push

bool Pop(void *addr,memst* m,char mode)
{
	if(mode == 'f'){
		if(!Is_empty(m,'f')){
			struct flight *data_f;
			data_f = (struct flight *)addr;

			m->f = *(data_f + m->cur_f);
			m->cur_f = m->cur_f - m->data_size_f;
		}else{
			exit(EXIT_FAILURE);
		}

	}else if(mode == 'p'){
		if(!Is_empty(m,'p')){
			struct passenger *data_p;
			data_p = (struct passenger *)addr;
			m->p = *(data_p + m->cur_p);
			m->cur_p = m->cur_p - m->data_size_p;
		}else{
			exit(EXIT_FAILURE);
		}

	}

}//end Pop

bool Is_empty(memst* m,char mode)
{
	if(mode == 'f'){
		if(m->cur_f == 0)
			return true;
		else
			return false;

	}else if(mode == 'p'){
		if(m->cur_p == m->mem_size_f)
			return true;
		else
			return false;
	}

}//end Is_empty

bool Is_full(memst* m,char mode)
{
	if(mode == 'f'){
		if(m->cur_f == m->mem_size_f)
			return true;
		else
			return false;
	}else if(mode == 'p'){

		if(m->cur_p == m->mem_size_p)
			return true;
		else
			return false;
	}

}//end Is_full


void RW_shared_memorty(struct node *flight_head,struct node_pasger *pasger_head,int mode,struct mem_st *m,void *addr)
{
	struct node *pos1 = NULL;
	struct node_pasger *pos2 = NULL;
	struct node *pos3 = NULL;
	struct node_pasger *pos4 = NULL;
	struct node pos5;
	struct node_pasger pos6;

	struct stat sb; 
	switch(mode){
		case 1://写入共享内存
			list_for_each_entry(pos1,&flight_head->list,list){
				printf("push f\n");
				Push(addr,m,'f');				
			};

			list_for_each_entry(pos2,&pasger_head->list,list){
				printf("push p\n");
				Push(addr,m,'p');
			};		
			break;
		case 2://从共享内存中读出数据
			while(1){//Read fligh msg to list flight
				printf("pop f \n");
				Pop(addr,m,'f');

				pos3 = (struct node*)malloc(sizeof(struct node));
				if(!pos3){
					perror("malloc");
					exit(-1);
				}
				pos3->data=m->f;

				INIT_LIST_HEAD(&pos3->list);
				list_add_tail(&pos3->list,&flight_head->list);				
				if(Is_empty(m,'f'))
					break;
			}//end while

			while(1){//Read pasger msg to list pasger
				printf("pop p\n");
				Pop(addr,m,'p');
				pos4 = (struct node_pasger*)malloc(sizeof(struct node_pasger));
				if(!pos4){
					perror("");
					exit(-1);
				}
				pos4->data = m->p;

				INIT_LIST_HEAD(&pos4->list);
				list_add_tail(&pos4->list,&pasger_head->list);				
				if(Is_empty(m,'p'))
					break;
			}//end while
			break;
	}//end switch
}//end RW_file_init

