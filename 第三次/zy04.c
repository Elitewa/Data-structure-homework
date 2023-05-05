#include "stdio.h"
#include "stdlib.h"
typedef struct link{
	int data;
	struct link *next;
}ram,*linkp;
linkp ini(linkp L,int a[],int n)
{
    int i=0;
    L=(linkp)malloc(sizeof(ram));
    linkp head = L;
    for(i=0;i<n;i++)
	{
        linkp p = (linkp)malloc(sizeof(ram));
		p->data = a[i];
        head->next = p;
        head = p;
    }
    head->next=NULL;
    return L;
}
linkp dels(linkp hd)
{
	linkp p=hd,o;
	int i,r;
	while(p->next!=NULL)
	{
		i=p->next->data;
		o=p->next;
		while(o->next!=NULL)
		{
			if(o->next->data==i)
			{
				linkp j= (linkp)malloc(sizeof(ram));
				j=o->next;
				o->next=j->next;
				free(j);
			}
			else
				o=o->next;
		}
		p=p->next;
	}
	return hd;
}
void deln(linkp hd)
{
	linkp p=hd,o=NULL,r=NULL;
	int i;
	while(p->next->next)
	{
		i=0;
		o=p->next;
		while(o->next)
		{
			if(o->next->data==p->next->data)
			{
				r=o->next;
				o->next=r->next;
				free(r);
				i=1;
			}
			else
			{
				o=o->next;
			}
		}
		if(i==1)
		{
			r=p->next;
			p->next=r->next;
			free(r);
		}
		else
		{
			p=p->next;
		}
	}
}
void print(linkp p)
{
	
    linkp head = p->next;
    while(head)
	{
        printf("%d ",head->data);
        head=head->next;
    }
    printf("\n");
	
}
void main()
{
	int a[9]={1,2,2,2,3,4,4,5,2};
	linkp la,lb;
	la=ini(la,a,9);
	lb=ini(lb,a,9);
	printf("原链表为：\n");
	print(la);
	printf("去重保留本身为：\n");
	print(dels(la));
	printf("原链表为：\n");
	print(lb);
	printf("去重不保留本身为：\n");
	deln(lb);
	print(lb);
	
}
