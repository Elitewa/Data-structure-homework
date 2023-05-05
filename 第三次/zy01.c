#include "stdio.h"
#include "stdlib.h"
typedef struct xs{
	int monkey;
	struct xs *next;
}xxs,*LinkList;
LinkList ini(LinkList head,int a[])
{
	head=(LinkList)malloc(sizeof(xxs));
	LinkList p,q=head;
	int i;
	for(i=0;i<20;i++)
	{
		p=(LinkList)malloc(sizeof(xxs));
		p->monkey=a[i];
		q->next=p;
		q=p;
	}
	q->next=head;
	return head;
}
void print(LinkList head)
{
	LinkList q=head->next;
	while(q!=head)
	{
		printf("%d ",q->monkey);
		q=q->next;
	}
}
void choose(LinkList head)
{
	int i=1;
	LinkList q=head,r;
	while(head->next!=head)
	{
		q=q->next; //此处只能等于有效节点，有效节点才能代表猴子序号
		if(q->next==head)
			q=q->next;
		i++;
		if(i==7)
		{
			r=q->next;
			q->next=r->next;
			printf("%d ",r->monkey);
			free(r);
			i=1;
			if(q->next==head)
				q=q->next;
		}
	
	}
	
}
void main()
{
	LinkList king;
	int a[20]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
	king=ini(king,a);
	printf("猴子序号为\n");
	print(king);
	printf("\n");
	printf("淘汰序号依次为（最后一个为King）\n");
	choose(king);
}
