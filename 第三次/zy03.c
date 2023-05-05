#include "stdio.h"
#include "stdlib.h"
typedef struct node {
	int cs,cf;
	struct node *next;
}listnode,*linkp;
linkp ini()
{
	linkp hd=(linkp)malloc(sizeof(listnode));
	hd->next=NULL;
	return hd;
}
void plus(linkp a,linkp b)
{
	linkp hd1=a,hd2=b;
	while(hd1->next!=NULL)
	{
		while(hd2->next!=NULL)
		{
			if(hd2->next->cf==hd1->next->cf)
			{
				linkp p;
				hd1->next->cs=hd1->next->cs+hd2->next->cs;
				p=hd2->next;
				hd2->next=hd2->next->next;
				free(p);
					
			}
			else
				hd2=hd2->next;
		}
		hd2=b;
		hd1=hd1->next;
		
	}
	if(b->next!=NULL)
	{
		hd1->next=b->next;
	}
}
void creat (linkp hd,listnode fc[],int n)
{
	int i;
	linkp r=hd;
	for(i=0;i<n;i++)
	{
		linkp p=(linkp)malloc(sizeof(listnode));
		p->cs=fc[i].cs;
		p->cf=fc[i].cf;
		r->next=p;
		r=p;
	}
	r->next=NULL;
}
void print(linkp hd)
{
	linkp q=hd->next;
	while(q)
	{
		printf("(%dX^%d) ",q->cs,q->cf);
		q=q->next;
	}
	printf("\n");
}
void main()
{
	linkp hd1,hd2;
	listnode fc1[5]={{5,7},{7,5},{4,3},{3,2},{9,0}};
	listnode fc2[6]={{8,9},{4,7},{3,6},{-3,2},{6,1},{6,0}};
	hd1=ini();
	hd2=ini();
	creat(hd1,fc1,5);
	creat(hd2,fc2,6);
	print(hd1);
	print(hd2);
	plus(hd1,hd2);
	print(hd1);
	
	
}
