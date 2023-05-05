#include "stdio.h"
#include "stdlib.h"
#define ini_size 100
#define increment 10
typedef struct {
	int *base;
	int *top;
	int size;
}sqstack;
int ini(sqstack *s)
{
	s->base=(int*)malloc(ini_size*sizeof(int));
	s->top=s->base;
	s->size=ini_size;
}
void destory(sqstack *s)
{
	free(s->base);
}
void clear(sqstack *s)
{
	s->top=s->base;
}
int ifempty(sqstack *s)
{
	if(s->top==s->base)
		return 1;
	else 
		return 0;
}
int length(sqstack *s)
{
	return(s->top-s->base);
}
int gettop(sqstack *s,int *e)
{
	if(s->top!=s->base)
	{
		*e=*(s->top-1);
		return 1;
	}
	else 
		return 0;
}
int pop(sqstack *s,int *e)
{
	if(s->top!=s->base)
	{
		*e=*(s->top-1);
		s->top--;
		return 1;
	}
	else
		return 0;
}
int push(sqstack *s,int e)
{
	if(s->top-s->base==s->size)
	{
		s->base=(int*)realloc(s->base,(s->size+increment)*sizeof(int));
		if(!s->base)
			return 0;
		s->size+=increment;	
	}
		*(s->top)=e;
		s->top++;	
		return 1;
	
}
void stacktraverse(sqstack *s)
{
	int *p;
	p=s->top-1;
	while(p>=s->base)
	{
		printf(" %d",*p);
		p--;
	}
	printf("\n");
}
void main()
{
	int i,e;
	sqstack sq;
	ini(&sq);
	for(i=1;i<10;i++)
	{
		push(&sq,i);
	}
	printf("原始栈为:\n");	
	stacktraverse(&sq);
	printf("栈的长度为: %d\n",length(&sq));
	printf("出栈:\n");
	while(!ifempty(&sq))
	{
		pop(&sq,&e);
		printf("*%d*",e);
	}
	clear(&sq);
	destory(&sq);
}
