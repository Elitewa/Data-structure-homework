#include "stdio.h"
#include "stdlib.h"
typedef struct xs{
	int cj;
	struct xs *next;
}xxs,*LinkList;
void InsertSort(LinkList p){
	if(p->next==NULL||p->next->next==NULL)  //若链表为空或者链表中只有一个元素 返回
		return ;
		LinkList pre=p;  //指向排好序的前驱节点
		LinkList unsort=p->next->next;
		LinkList s=p->next;
		s->next=NULL;
		s=unsort;
		while(s){

			unsort=s->next;

			while(pre->next!=NULL&&pre->next->cj<=s->cj)
				pre=pre->next;
			s->next=pre->next;
			pre->next=s;
			pre=p;
			s=unsort;
		}
}
void chooses(LinkList head) //选择排序
{	 
	LinkList q,p,r;
	int s;
	for(p=head->next;p!=NULL;p=p->next)
	{
		r=p;
		for(q=p->next;q!=NULL;q=q->next)
		{
			if(q->cj<r->cj)
			{	 
				r=q;      //一一比较，r存最小值的结点指针，最后进行数据互换
			}
		}
		if(r->cj!=p->cj)
		{
			s=r->cj;
			r->cj=p->cj;		//将两数位置互换，小的到前面，大的到后面	
			p->cj=s;
		}
	} 
}
LinkList InitList(LinkList L,int n,int a[])
{
    int cj;
    L = (LinkList)malloc(sizeof(xxs));
    L->next = NULL;
    LinkList head = L;
    head->next=L->next;

    for(int i = 0;i<n;i++)
	{
        LinkList p = (LinkList)malloc(sizeof(xxs));
		p->cj = a[i];
        p->next = L->next;
        L->next = p;
        L=L->next;
    }

    return head;
}
LinkList re(LinkList la)
{
	LinkList ld,lz;
	ld = (LinkList)malloc(sizeof(xxs));
	lz=la->next;
	ld->next = NULL;
	while(lz)
	{
		LinkList lj = (LinkList)malloc(sizeof(xxs));
		lj->cj=lz->cj;
		lj->next=ld->next;
		ld->next=lj;
		lz=lz->next;	
	}
	return ld;
	
}
void print(xxs *p)
{
	
    LinkList head = p->next;
    while(head)
	{
        printf("%d ",head->cj);
        head=head->next;
    }
    printf("\n");
	
}
void main()
{
	int n=10;
	int a[10]={6,5,4,9,8,7,1,2,3,10};
	LinkList la;
	la=InitList(la,10,a);
	printf("翻转前:\n");
	print(la);
	printf("翻转后:\n");
	print(re(la));
	printf("插入式排序:\n");
	InsertSort(la);
	print(la);
	printf("选择式排序:\n");
	la=InitList(la,10,a);
	la=re(la);
	chooses(la);
	print(la);
	printf("\n");
}
