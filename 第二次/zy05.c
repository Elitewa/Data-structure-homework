#include "stdio.h"
#include "stdlib.h"
int ans;
typedef struct xs{
	int cj;
	struct xs *next;
}xxs,*LinkList;
LinkList InitList(LinkList L,int n)
{
    int cj;
    L = (LinkList)malloc(sizeof(xxs));
    L->next = NULL;
    LinkList head = L;
    head->next=L->next;

    for(int i = 1;i <= n;i++)
	{
        LinkList p = (LinkList)malloc(sizeof(xxs));
		p->cj = i*i;
        p->next = L->next;
        L->next = p;
        L=L->next;
    }

    return head;
}
LinkList InitList1(LinkList L,int n)
{
    int cj;
    L = (LinkList)malloc(sizeof(xxs));
    L->next = NULL;
    LinkList head = L;
    head->next=L->next;

    for(int i = 1;i <= n;i++)
	{
        LinkList p = (LinkList)malloc(sizeof(xxs));
		p->cj = 2*i;
        p->next = L->next;
        L->next = p;
        L=L->next;
    }

    return head;
}
int Searchvalue(LinkList L,int cj)
{
    LinkList head = L->next;
    while(head)
	{
        if(head->cj == cj)
		{
            return 1;
        }
        head = head->next;
    }
    return 0;

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
LinkList insert(LinkList head,int i,int x)//把x插入i位置 ,从头结点开始遍历 
{
	LinkList p;
	p=head;//p指向头结点
	int m=0;
	while(m<i-1)//遍历到i-1位 
	{
		p=p->next;
		m++;
	}
	LinkList q = (LinkList)malloc(sizeof(xxs));
	q->next=p->next;
	p->next=q; 
	q->cj=x;
}
LinkList Unionset(LinkList L1,LinkList L2)
{
    LinkList p = L1->next,q = L2->next;
    LinkList uni = (LinkList)malloc(sizeof(xxs));
    uni->next = NULL;

    LinkList head_un = uni;
	ans = ans+1;
    while(p){
        LinkList tmp = (LinkList)malloc(sizeof(xxs));
        tmp->cj = p->cj;
        tmp->next = uni->next;
        uni->next = tmp;
        p = p->next;
        uni = uni->next;
    }
    while(q){
        if(!Searchvalue(L1,q->cj))
		{
		
            insert(head_un,ans,q->cj);
            ans ++;
        }
        q = q->next;
    }
    return head_un;

}
void main()
{
	int n;
	LinkList la;
	LinkList lb;
	LinkList lc;
	n=10;
	ans=n;
	la=InitList(la,n);
	print(la);
	lb=InitList1(lb,10);
	print(lb);
	print(Unionset(la,lb));
	printf("\n");
}
