#include "stack.h"

bool Is_empty(stack* s)
{
	return s->top == -1;
}//end is empty

bool Is_full(stack* s)
{
	return s->top == s->size-1;
}//end is _full

static inline bool my_malloc(stack *s)
{
	datatype *new;
	new = (datatype*)malloc(sizeof(datatype)*(s->size + s->incresize));
	if(!new){
		printf("malloc fialed!\n");
		return false;
	}
	int i=0;
	for(;i < s->size;i++){
		new[i] = s->data[i];
	}
	free(s->data);
	s->data = new;

	s->size = s->size + s->incresize;

	return true;
}

void Init_stack(stack* s)
{
	s->top = -1;
	s->size = 10;
	s->incresize = 5;
	s->data = (datatype*)malloc(sizeof(datatype)*s->size);
	if(!s->data){
		exit(-1);
	}
}//end init_stack

bool Push(stack* s,datatype element)
{
	if(Is_full(s)){
		printf("stack is full!\n");
		if(!my_malloc(s)){
			return false;
		}
		printf("increment space!\n");
	}
	
	s->data[++s->top] = element;

	return  true;
}//end push

bool Pop(stack* s)
{
	if(!Is_empty(s)){
		s->top--;
		return true;
	}
	return false;
}//end Pop

void Display(stack s)
{
	if(Is_empty(&s)){
		printf("stack empth!\n");
	}
	int i =0;
	for(;i <= s.top;i++){
		printf("->%c",s.data[i]);
	}
	putchar(10);
}//end display


bool Hui_wen(char *s)
{
	stack* tmp;
	(void)Init_stack(tmp);
	int i =0;
	int len = strlen(s);
	//printf("len: %d\n",len);
	if(!(len%2)){
		//printf("even\n");
		for(i =0;i<(len/2);i++){
			Push(tmp,*s++);
		}
		for(i =0;i<(len/2);i++){
			*s++;
		}
		*s--;
		for(i =0;i <= tmp->top;i++){
			//printf("s[0]:%c , tmp->data[%d] : %c \n",s[0],i,tmp->data[i]);
			if(*s-- != tmp->data[i])
				return false;	
		}
		return true;
	}else{
		//printf("odd");
		for(i =0;i<(int)(len/2);i++){
			Push(tmp,*s++);
		}
		for(i =0;i<(len/2);i++){
			*s++;
		}
		for(i =0;i <= tmp->top;i++){
			if(*s-- != tmp->data[i])
				return false;	
		}
		return true;
	}
}//end hui wen 
