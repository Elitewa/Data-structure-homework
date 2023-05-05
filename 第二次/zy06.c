#include "stdio.h"
#include "stdlib.h"
typedef struct xs{
	int cj;
	struct xs *next;
}xxs,*LinkList;
LinkList InitList(LinkList L,int n)
{
    int cj;
    L = (LinkList)malloc(sizeof(xxs));
    LinkList  head=L;
    for(int i = 1;i <= n;i++)
	{
        LinkList p = (LinkList)malloc(sizeof(xxs));
		p->cj = i*i;
        head->next =p;
        head = p;
    }
	head->next=NULL;
    return L;
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
        head->next =p;
        head = p;
    }
	head->next=NULL;
    return L;
}
LinkList MergeList(LinkList La,LinkList Lb) 
{
    LinkList pa, pb, pc, q; 
    pa=La->next;
    pb=Lb->next;
    pc=(LinkList)malloc(sizeof(xxs));
	LinkList pc1=pc;                 
    while (pa != NULL && pb != NULL) 
    {
        if (pa->cj <= pb->cj) 
        {
			 LinkList px=(LinkList)malloc(sizeof(xxs));
			 px->cj=pa->cj;
			 pc1->next=px;
			 pc1=px;
			 pa=pa->next;	 
        }
        else if (pa->cj > pb->cj) 
        {
			 LinkList px=(LinkList)malloc(sizeof(xxs));
			 px->cj=pb->cj;
			 pc1->next=px;
			 pc1=px;	
			 pb=pb->next;
        }
    }
    while(pb != NULL)
    {
		LinkList px=(LinkList)malloc(sizeof(xxs));
		px->cj=pb->cj;
		pc1->next=px;
		pc1=px;	
		pb=pb->next;
	}
    while(pa != NULL)
    {
		LinkList px=(LinkList)malloc(sizeof(xxs));
		px->cj=pa->cj;
		pc1->next=px;
		pc1=px;	
		pa=pa->next;
	}
	pc1->next =NULL;
    return pc;
}
 
void DestroyList(LinkList L) {
	LinkList p;
 
	while (L) {
		p = L;
		L = L->next;
		free(p);
	}
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
	int n;
	LinkList la;
	LinkList lb;
	LinkList lc;
	n=10;
	la=InitList(la,n);
	print(la);
	lb=InitList1(lb,10);
	print(lb);
	print(MergeList(la,lb));
	printf("\n");
}
