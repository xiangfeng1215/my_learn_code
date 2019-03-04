#include "memoryManger.h"

#define MEM_SIZE  8182


int sharedMemory_write(int proj_id)
{
	int shmid_key = sharedMemoryGetKey(proj_id);
	if(shmid_key < 0 ){
		perror("shmid_key");
		exit(EXIT_FAILURE);
	}

	int shmid = sharedMemoryCreateOrGet(shmid_key,MEM_SIZE);
	if(shmid < 0){
		perror("shmid");
		exit(EXIT_FAILURE);
	}

	return shmid;

}//sharedMemory

/**
mode 1 把航班信息写入内存
mode 2 把乘客信息写入内存
mode 3 从内存中把航班信息读出到链表
mode 4 从共享内在中把乘客信息读出到链表
*/
void RW_shared_memorty(struct node *flight_head,struct node_pasger *pasger_head,struct data_cnt *cnt,int mode,struct flight *addr_f,struct passenger *addr_p)
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
			if( !List_empty_flight(flight_head)){
			cnt->flight = 0;
			list_for_each_entry(pos1,&flight_head->list,list){
				*addr_f++ = pos1->data;
				cnt->flight++;				
			};

			}else{
				cnt->flight = -1;
			}
			break;
		case 2:
			if(!List_empty_pasger(pasger_head)){
			cnt->pasger = 0;
			list_for_each_entry(pos2,&pasger_head->list,list){
				printf("push p\n");
				*addr_p++ = pos2->data;
				cnt->pasger++;
			};		
			}else{
				cnt->pasger = -1;
			}
			break;
		case 3://从共享内存中读出数据
			while(cnt->flight >= 0){//Read fligh msg to list flight
			
				pos3 = (struct node*)malloc(sizeof(struct node));
				if(!pos3){
					perror("malloc");
					exit(-1);
				}
				
				pos3->data=addr_f[cnt->flight--];

				INIT_LIST_HEAD(&pos3->list);
				list_add_tail(&pos3->list,&flight_head->list);				
			}//end while
			break;
		case 4:	
			while(cnt->pasger >= 0){//Read pasger msg to list pasger
			
				pos4 = (struct node_pasger*)malloc(sizeof(struct node_pasger));
				if(!pos4){
					perror("");
					exit(-1);
				}
				pos4->data = addr_p[cnt->pasger--];

				INIT_LIST_HEAD(&pos4->list);
				list_add_tail(&pos4->list,&pasger_head->list);				
			}//end while
			break;
	}//end switch
}//end RW_file_init




