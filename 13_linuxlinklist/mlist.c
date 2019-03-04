#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mlist.h"

struct fox {
	int tail_length;
	int weight;
	struct list_head list_node;
};


struct fox* create_fox(int length, int weight)
{
	struct fox* tmp_fox = (struct fox*)malloc(sizeof(struct fox));
	if (tmp_fox == NULL) {
		return NULL;
	}

	tmp_fox->tail_length = length;
	tmp_fox->weight = weight;

	return tmp_fox;
}

static inline void for_each_fox(const struct list_head* head)
{
	struct list_head *pos;
	struct fox *tmp_fox;

	list_for_each(pos, head) {
		tmp_fox = list_entry(pos, struct fox, list_node);
		printf("fox info: %d --- %d\n", tmp_fox->tail_length, tmp_fox->weight);
	}
}

int main()
{
	struct fox * fox_list = (struct fox *)malloc(sizeof(struct fox));
	struct fox * fox;

	if (fox_list == NULL) {
		printf("malloc failed!");
		return -1;
	}

	// 初始化链表头节点
	struct list_head *head = &(fox_list->list_node);
	INIT_LIST_HEAD(head);
	printf("初始化头节点完成!\n");

	// 插入4个fox
	fox = create_fox(100, 100);
	list_add_tail(&(fox->list_node), head);

	fox = create_fox(105, 105);
	list_add_tail(&(fox->list_node), head);

	fox = create_fox(110, 110);
	list_add_tail(&(fox->list_node), head);

	fox = create_fox(115, 115);
	list_add_tail(&(fox->list_node), head);
	printf("插入4个狐狸节点\n");

	// 遍历
	for_each_fox(head);

	// 移动节点
	list_move_tail(head->next, head);
	printf("将第一个节点移动到末尾\n");
	for_each_fox(head);

	// 删除节点
	list_del(head->next);
	printf("删除当前第一个节点\n");
	for_each_fox(head);


	return 0;
}
