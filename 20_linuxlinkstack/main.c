#include "linuxlinkstack.h"

typedef struct node node;

int main(void)
{
	node *head,*head_pos,*head_dest;
	struct humen element = {"zxf",21,100};
	(void)Init_head(&head);
	(void)Init_head(&head_dest);
	(void)Create_list(head);
	(void)Traverse(head);
#if 1
	char ch;
	printf("chosee option\n");
	scanf("%c",&ch);
	while(1){
		if(ch == 'i')
			(void)Push(head,element);
		if(ch == 'd')
			(void)Pop(head);
		if(ch == 'q' || ch == 'Q')
			break;
		printf("chosee optin\n");
		scanf("%c",&ch);
		getchar();	
	}
#endif

#if 0
	printf("traverse \n");
//	(void)Traverse_reverse(head);
	head_pos = Find_node_pos(head,2);
	(void)Traverse_continue(head,head_pos);
//	(void)Traverse_continue_reverse(head,head_pos);
#endif
#if 0
	printf("my_rotate_left\n");
	(void)My_rotate_left(head);
	(void)Traverse(head);
#endif
#if 0
	printf("my_move (head,3)\n");
	(void)My_move(head,3);
	(void)Traverse(head);
#endif
#if 0
	printf("my_move_tail(head,1)\n");
	(void)My_move_tail(head,1);
	(void)Traverse(head);
#endif
#if 0
	if(List_is_singular(head_pos)){
		printf("the linked list is singel list\n");
	}else{
		printf("the linked list not singel list\n");
	}
#endif
#if 0
	printf("list copy or cut \n");
	List_copy(head,head_dest);
	//List_cut_position(head,head_dest,2);
	(void)Traverse(head_dest);
#endif
#if 0
	printf("create_list head_dest\n");
	(void)Create_list(head_dest);
	printf("list splice\n");
	//List_splice(head,head_dest);
	//List_splice_tail(head,head_dest);
	List_splice_init(head,head_dest);
	//List_splice_tail_init(head,head_dest);
	printf("traverse head_dest\n");
	(void)Traverse(head_dest);
	printf("traverse head\n");
	(void)Traverse(head);
#endif
	return 0;
}
