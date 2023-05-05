#include "stdio.h"
#include "stdlib.h"
typedef struct lb{
	int data;
	struct lb *next;
}lj,*link;
link ini(link ini,int a[])
{
	link lc=(link)malloc(sizeof(lj));
	lc=ini;
	int i;
	for(i=0;i<10;i++)
	{
		link q=(link)malloc(sizeof(lj));
		q->data=a[i];
		lc->next=q;
		lc=q;
	}
	lc->next=NULL;
	return ini;	
}
void print(link lc)
{
	link lv=(link)malloc(sizeof(lj));
	lv=lc->next;
	while(lv)
	{
		printf("%d ",lv->data);
		lv=lv->next;
	}
}
link re(link head)
{
	link p=(link)malloc(sizeof(lj));
	p->next=NULL;
	for(head=head->next;head!=NULL;head=head->next)
	{
			link q=(link)malloc(sizeof(lj));
			q->data=head->data;
			q->next=p->next;
			p->next=q;
		
	}
	return p;
}
void InsertSort(link p){
	if(p->next==NULL||p->next->next==NULL)  //若链表为空或者链表中只有一个元素 返回
		return ;
		link pre=p;  //指向排好序的前驱节点
		link unsort=p->next->next;
		link s=p->next;
		s->next=NULL;
		s=unsort;
		while(s){

			unsort=s->next;

			while(pre->next!=NULL&&pre->next->data<=s->data)
				pre=pre->next;
			s->next=pre->next;
			pre->next=s;
			pre=p;
			s=unsort;
		}
}
void choose(link head)
{	link q,p,r;
	int s;
	for(p=head->next;p!=NULL;p=p->next)
	{
		r=p;
		for(q=p->next;q!=NULL;q=q->next)
		{
			if(r->data>q->data)
			r=q;
		}
		if(r->data!=p->data)
		{
			s=r->data;
			r->data=p->data;
			p->data=s;
		}
	}
	
}

void main()
{
	link la=(link)malloc(sizeof(lj));
	int a[10]={9,5,8,7,6,3,2,1,4,10};
	la=ini(la,a);
	print(la);
	printf("\n");
	print(re(la));
	printf("\n");
	la=ini(la,a);
	InsertSort(la);
	printf("\n");
	print(la);
	la=ini(la,a);
	printf("\n");

	choose(la);
	print(la);
	
}
