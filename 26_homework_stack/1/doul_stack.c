#include "doul_stack.h"

void Init_doul_stack(doulstack* s)
{

	s->V = (datatype*)malloc(sizeof(datatype)*SIZE);
	if(!s->V){
		perror("init stack malloc");
		exit(-1);
	}
	s->max_size = SIZE;
	s->top[0] = -1;
	s->top[1] = SIZE;
	s->bot[0] = -1;
	s->bot[1] = SIZE;
	s->max_size = SIZE;
}//end push doul stack

bool Is_empty_stack_top(doulstack* s)
{
	return s->bot[0] == s->top[0];
}//end is empty_stack_top

bool Is_full_stack_top(doulstack* s)
{
	return (s->top[0] == s->top[1]-1)||(s->top[0] == s->max_size-1);
}//end is full stack

bool Push_doul_stack_top(doulstack* s,datatype element)
{
	if(Is_full_stack_top(s)){
		printf("doul stack bot is empty!");
		return false;
	}
	s->V[++s->top[0]] = element;
	return true;
}//end Pop doul stack

bool Pop_doul_stack_top(doulstack* s)
{
	if(!Is_empty_stack_top(s)){
		s->top[0]--;
		return true;
	}
	return false;
}//end Pop doul stack

void Display_doul_stack_top(doulstack *s)
{
	int i = 0;
	for(i = s->top[0]; i != s->bot[0];i--){
		printf("->%d",s->V[i]);
	}
	putchar(10);
}//end Display_doul_stack_top

/**************************************************/

bool Is_empty_stack_bot(doulstack* s)
{
	return s->top[1] == s->bot[1];
}//end is empty_stack_bot

bool Is_full_stack_bot(doulstack* s)
{
	return ((s->top[0] == s->top[1]-1)||(s->top[1] == 0));
}//end is full stack

bool Push_doul_stack_bot(doulstack* s,datatype element)
{
	if(!Is_full_stack_bot(s)){
		s->V[--s->top[1]] = element;
		return true;
	}
	return false;
}//end push doul stack

bool Pop_doul_stack_bot(doulstack* s)
{
	if(!Is_empty_stack_bot(s)){
		s->top[1]++;
		return true;
	}
	return false;
}//init doul stack

void Display_doul_stack_bot(doulstack *s)
{
	int i = 0;
	for(i = s->top[1]; i != s->bot[1];i++){
		printf("->%d",s->V[i]);
	}
	putchar(10);
}//end Display_doul_stack_top
