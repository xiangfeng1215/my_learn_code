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
void RW_shared_memorty(struct node *flight_head,struct node_pasger *pasger_head,int mode,struct flight *addr_f,struct passenger *addr_p)
{
	struct node *pos1 = NULL;
	struct node_pasger *pos2 = NULL;
	struct node *pos3 = NULL;
	struct node_pasger *pos4 = NULL;
	struct node pos5;
	struct node_pasger pos6;

	struct stat sb; 
	int i = 0;
	switch(mode){
		case 1://写入共享内存
			if( !List_empty_flight(flight_head)){
				//清空共享内存
				bzero(addr_f,MEM_SIZE);

				list_for_each_entry(pos1,&flight_head->list,list){
					*addr_f++ = pos1->data;		
					if(DEBUG){
						struct flight test_f;
						test_f = *addr_f;
						printf(RED"\t%s\t%s\t\t%s\t\t%s\t%s\t%16.16s\t%16.16s\t\t%d\t\t%d\t\t%d\n"NONE,test_f.number,test_f.staddress,test_f.arraddress,test_f.DATE,test_f.TYPE,ctime(&test_f.stime),ctime(&test_f.atime),test_f.value,test_f.seat_size,test_f.poll);

					}	
				};

			}else{
				bzero(addr_f,MEM_SIZE);
			}
			break;
		case 2:
			if(!List_empty_pasger(pasger_head)){
				bzero(addr_p,MEM_SIZE);
				list_for_each_entry(pos2,&pasger_head->list,list){
					*addr_p++ = pos2->data;
					if(DEBUG){	
						struct passenger test_p;
						test_p = *addr_p;
						printf("/t%s/t%d/t%s/t%s/t%s/t%s/t%s/t%ld/t%ld/t%d/t%d",test_p.name,test_p.ID,test_p.fmsg.number,test_p.fmsg.staddress,test_p.fmsg.arraddress,test_p.fmsg.DATE,test_p.fmsg.TYPE,test_p.fmsg.stime,test_p.fmsg.atime,test_p.fmsg.value,test_p.fmsg.poll);
					}//end fi

				};		
			}else{
				bzero(addr_p,MEM_SIZE);
			}
			break;
		case 3://从共享内存中读出数据
			//清空链表
			pos1 = NULL;
			list_for_each_entry(pos1,&flight_head->list,list){
				if((pos1->data.stime >= 0)&&(pos1->data.value >= 0)){
					__list_del(pos1->list.prev,pos1->list.next);
					//free(pos1);
				}
			}//end list
			pos1 = NULL;
			while((addr_f[i].value != 0)){//Read fligh msg to list flight

				pos3 = (struct node*)malloc(sizeof(struct node));
				if(!pos3){
					perror("malloc");
					exit(-1);
				}

				pos3->data=addr_f[i++];
				
				INIT_LIST_HEAD(&pos3->list);
				list_add_tail(&pos3->list,&flight_head->list);				
			}//end while
			break;
		case 4:	
			//清空链表
			pos2 = NULL;
			list_for_each_entry(pos2,&pasger_head->list,list){
				if((pos2->data.fmsg.stime >= 0)&&(pos2->data.fmsg.value >= 0)){
				__list_del(pos2->list.prev,pos2->list.next);
				free(pos2);
				}
			}//end list
			pos2 = NULL;

			while((addr_p[i].ID != 0)){//Read fligh pasgenger msg to list flight

				pos4 = (struct node_pasger*)malloc(sizeof(struct node_pasger));
				if(!pos4){
					perror("");
					exit(-1);
				}
				pos4->data = addr_p[i++];

				INIT_LIST_HEAD(&pos4->list);
				list_add_tail(&pos4->list,&pasger_head->list);				
			}//end while
			break;
	}//end switch
}//end RW_file_init




