#include "pasger.h"

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
	scanf("%s%s%s%s%s%d%d%d%d%d%d",tmp.number,tmp.staddress,tmp.arraddress,tmp.DATE,tmp.TYPE,&tmp.stime,&tmp.atime,&tmp.value,&tmp.seat_size,&tmp.poll,&tmp.seat_left);
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
		scanf("%s%s%s%s%s%d%d%d%d%d%d",tmp.number,tmp.staddress,tmp.arraddress,tmp.DATE,tmp.TYPE,&tmp.stime,&tmp.atime,&tmp.value,&tmp.seat_size,&tmp.poll,&tmp.seat_left);
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
				if(strcmp(pos->data.fmsg.number,key.number)){
					__list_add(&pnew->list,&pos->list,pos->list.next);
					/*list_add(&pnew->list,&pos->list);*/
					return true;
				}
			};break;
		case 2:
			   pnew = (struct node_pasger*)malloc(sizeof(struct node_pasger));
			   pnew->data = *input;
			   list_for_each_entry(pos,&head->list,list){
				   if(strcmp(pos->data.fmsg.staddress,key.staddress)){
					   __list_add(&pnew->list,&pos->list,pos->list.next);
					   /*list_add(&pnew->list,&pos->list);*/
					   return true;
				   }
			   };break;
		case 3:
			   pnew = (struct node_pasger*)malloc(sizeof(struct node_pasger));
			   pnew->data = *input;
			   list_for_each_entry(pos,&head->list,list){
				   if(strcmp(pos->data.fmsg.arraddress,key.arraddress)){
					   __list_add(&pnew->list,&pos->list,pos->list.next);
					   /*list_add(&pnew->list,&pos->list);*/
					   return true;
				   }
			   };break;
		case 4:
			   pnew = (struct node_pasger*)malloc(sizeof(struct node_pasger));
			   pnew->data = *input;
			   list_for_each_entry(pos,&head->list,list){
				   if(strcmp(pos->data.fmsg.DATE,key.DATE)){
					   __list_add(&pnew->list,&pos->list,pos->list.next);
					   /*list_add(&pnew->list,&pos->list);*/
					   return true;
				   }
			   };break;
		case 5:
			   pnew = (struct node_pasger*)malloc(sizeof(struct node_pasger));
			   pnew->data = *input;
			   list_for_each_entry(pos,&head->list,list){
				   if(strcmp(pos->data.fmsg.TYPE,key.TYPE)){
					   __list_add(&pnew->list,&pos->list,pos->list.next);
					   /*list_add(&pnew->list,&pos->list);*/
					   return true;
				   }
			   };break;
		case 6:
			   pnew = (struct node_pasger*)malloc(sizeof(struct node_pasger));
			   pnew->data = *input;
			   list_for_each_entry(pos,&head->list,list){
				   if((pos->data.fmsg.stime == key.stime)){
					   __list_add(&pnew->list,&pos->list,pos->list.next);
					   /*list_add(&pnew->list,&pos->list);*/
					   return true;
				   }
			   };break;
		case 7:
			   pnew = (struct node_pasger*)malloc(sizeof(struct node_pasger));
			   pnew->data = *input;
			   list_for_each_entry(pos,&head->list,list){
				   if((pos->data.fmsg.atime == key.atime)){
					   __list_add(&pnew->list,&pos->list,pos->list.next);
					   /*list_add(&pnew->list,&pos->list);*/
					   return true;
				   }
			   };break;
		case 8:
			   pnew = (struct node_pasger*)malloc(sizeof(struct node_pasger));
			   pnew->data = *input;
			   list_for_each_entry(pos,&head->list,list){
				   if((pos->data.fmsg.value == key.value)){
					   __list_add(&pnew->list,&pos->list,pos->list.next);
					   /*list_add(&pnew->list,&pos->list);*/
					   return true;
				   }
			   };break;
		default:return false;


	}//end switch

	return false;
}//end insert_data

bool Delete_data_pasger(struct node_pasger* head,struct passenger key,int mode)
{

	struct node_pasger* pos = NULL;
	struct node_pasger* pnew = NULL;
	switch(mode){
		case 1:
			list_for_each_entry(pos,&head->list,list){
				if(strcmp(pos->data.fmsg.number,key.number)){
					__list_del(pos->list.prev,pos->list.next);
					//list_del(&pos->list);
					free(pos);
					pos = NULL;
					return true;
				}
			};break;
		case 2:
			list_for_each_entry(pos,&head->list,list){
				if(strcmp(pos->data.fmsg.staddress,key.staddress)){
					__list_del(pos->list.prev,pos->list.next);
					//list_del(&pos->list);
					free(pos);
					pos = NULL;
					return true;
				}
			};break;
		case 3:
			list_for_each_entry(pos,&head->list,list){
				if(strcmp(pos->data.fmsg.arraddress,key.arraddress)){
					__list_del(pos->list.prev,pos->list.next);
					//list_del(&pos->list);
					free(pos);
					pos = NULL;
					return true;
				}
			};break;
		case 4:
			list_for_each_entry(pos,&head->list,list){
				if(strcmp(pos->data.fmsg.DATE,key.DATE)){
					__list_del(pos->list.prev,pos->list.next);
					//list_del(&pos->list);
					free(pos);
					pos = NULL;
					return true;
				}
			};break;
		case 5:
			list_for_each_entry(pos,&head->list,list){
				if(strcmp(pos->data.fmsg.TYPE,key.TYPE)){
					__list_del(pos->list.prev,pos->list.next);
					//list_del(&pos->list);
					free(pos);
					pos = NULL;
					return true;
				}
			};break;
		case 6:
			list_for_each_entry(pos,&head->list,list){
				if((pos->data.fmsg.stime == key.stime)){
					__list_del(pos->list.prev,pos->list.next);
					//list_del(&pos->list);
					free(pos);
					pos = NULL;
					return true;
				}
			};break;
		case 7:
			list_for_each_entry(pos,&head->list,list){
				if((pos->data.fmsg.atime == key.atime)){
					__list_del(pos->list.prev,pos->list.next);
					//list_del(&pos->list);
					free(pos);
					pos = NULL;
					return true;
				}
			};break;
		case 8:
			list_for_each_entry(pos,&head->list,list){
				if((pos->data.fmsg.value == key.value)){
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

struct node_pasger* Find_node_pos(struct node_pasger* head,struct passenger key,int mode )
{
	struct node_pasger* pos = NULL;
	switch(mode){
		case 1:
			list_for_each_entry(pos,&head->list,list){
				if(strcmp(pos->data.fmsg.number,key.number)){
					return pos;
				}
			};break;
		case 2:
			list_for_each_entry(pos,&head->list,list){
				if(strcmp(pos->data.fmsg.staddress,key.staddress)){
					return pos;
				}
			};break;
		case 3:
			list_for_each_entry(pos,&head->list,list){
				if(strcmp(pos->data.fmsg.arraddress,key.arraddress)){
					return pos;
				}
			};break;
		case 4:
			list_for_each_entry(pos,&head->list,list){
				if(strcmp(pos->data.fmsg.DATE,key.DATE)){
					return pos;
				}
			};break;
		case 5:
			list_for_each_entry(pos,&head->list,list){
				if(strcmp(pos->data.fmsg.TYPE,key.TYPE)){
					return pos;
				}
			};break;
		case 6:
			list_for_each_entry(pos,&head->list,list){
				if((pos->data.fmsg.stime == key.stime)){
					return pos;
				}
			};break;
		case 7:
			list_for_each_entry(pos,&head->list,list){
				if((pos->data.fmsg.atime == key.atime)){
					return pos;
				}
			};break;
		case 8:
			list_for_each_entry(pos,&head->list,list){
				if((pos->data.fmsg.value == key.value)){
					return pos;
				}
			};break;
		default:return NULL;

	}//end switch

	return NULL;
}//end find struct node_pasger position

bool My_replace_pasger(struct node* head,struct passenger data,struct passenger key,int mode)
{
	struct node_pasger* pos = NULL;
	switch(mode){
		case 1:
			list_for_each_entry(pos,&head->list,list){
				if(strcmp(pos->data.fmsg.number,key.number)){
					__list_del(pos->list.prev,pos->list.next);
					//list_del(&pos->list);
					pos->data = data ;
					pos = NULL;
					return true;			
				}
			};break;
		case 2:
			list_for_each_entry(pos,&head->list,list){
				if(strcmp(pos->data.fmsg.staddress,key.staddress)){
					__list_del(pos->list.prev,pos->list.next);
					//list_del(&pos->list);
					pos->data = data ;
					pos = NULL;
					return true;			

				}
			};break;
		case 3:
			list_for_each_entry(pos,&head->list,list){
				if(strcmp(pos->data.fmsg.arraddress,key.arraddress)){
					__list_del(pos->list.prev,pos->list.next);
					//list_del(&pos->list);
					pos->data = data ;
					pos = NULL;
					return true;			

				}
			};break;
		case 4:
			list_for_each_entry(pos,&head->list,list){
				if(strcmp(pos->data.fmsg.DATE,key.DATE)){
					__list_del(pos->list.prev,pos->list.next);
					//list_del(&pos->list);
					pos->data = data ;
					pos = NULL;
					return true;			

				}
			};break;
		case 5:
			list_for_each_entry(pos,&head->list,list){
				if(strcmp(pos->data.fmsg.TYPE,key.TYPE)){
					__list_del(pos->list.prev,pos->list.next);
					//list_del(&pos->list);
					pos->data = data ;
					pos = NULL;
					return true;			

				}
			};break;
		case 6:
			list_for_each_entry(pos,&head->list,list){
				if((pos->data.fmsg.stime == key.stime)){
					__list_del(pos->list.prev,pos->list.next);
					//list_del(&pos->list);
					pos->data = data ;
					pos = NULL;
					return true;			

				}
			};break;
		case 7:
			list_for_each_entry(pos,&head->list,list){
				if((pos->data.fmsg.atime == key.atime)){
					__list_del(pos->list.prev,pos->list.next);
					//list_del(&pos->list);
					pos->data = data ;
					pos = NULL;
					return true;			

				}
			};break;
		case 8:
			list_for_each_entry(pos,&head->list,list){
				if((pos->data.fmsg.value == key.value)){
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



