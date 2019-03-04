#include <stdio.h>
#include "list.h" 
#define list_for_each_reverse(pos, head) \
		for (pos = (head)->prev; pos != (head); pos = pos->prev)
struct data_info {
	int data;
	struct list_head list;
};

int  cmp_data(struct list_head *a, struct list_head *b)
{
	struct data_info *pa = list_entry(a, struct data_info, list);
	struct data_info *pb = list_entry(b, struct data_info, list);
	return pa->data - pb->data;
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

void  bubble_sort(struct list_head *head, int (*compar)(struct list_head *, struct list_head *))
{
	struct list_head *start = NULL; 
	struct list_head *end = NULL;
	list_for_each_reverse(end,head)
	{   
		list_for_each(start, head){           
			if (start == end)                       
				break;
			if (compar(start, start->next) > 0) 
			{
				swap(start, start->next);                           
				start = start->prev; //start归位
				if (start == end) 
					end = end->next; //end归位            
			}
		}
	}
}

int main(void)
{
	struct data_info s[] =  {{6}, {4}, {7}, {9}, {2}, {8}, {5}, {1}, {3}};

	LIST_HEAD(head);
	int i;
	for (i = 0; i < sizeof s/ sizeof *s; ++i) 
	{
		list_add_tail(&s[i].list, &head);
	} //尾插，构成链表

	struct data_info *pdata = NULL;
	list_for_each_entry(pdata, &head, list) 
	{
		printf("%d ", pdata->data);
	}
	printf("\n"); //排序之前

	bubble_sort(&head, cmp_data); //进行排序

	list_for_each_entry(pdata, &head, list) 
	{
		printf("%d ", pdata->data);
	}
	printf("\n"); //排序之后
	return 0;
}

