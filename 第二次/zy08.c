#include <stdio.h>
#include <malloc.h>
 
typedef struct Node 
{
    int data;
    struct Node *next;
}LNode,*LinkList;
 
LinkList InitList(LinkList L,int n)
{
    LinkList p,r;
    L = (LinkList)malloc(sizeof(LNode));
    r=L;
	for(int i = 1;i <= n;i++)
	{
        LinkList p = (LinkList)malloc(sizeof(LNode));
		p->data = i*i;
        r->next = p;
        r= p;
    }
    r->next=NULL;

    return L;
}
LinkList InitList1(LinkList L,int n)
{
    LinkList p,r;
    L = (LinkList)malloc(sizeof(LNode));
    r=L;
	for(int i = 1;i <= n;i++)
	{
        LinkList p = (LinkList)malloc(sizeof(LNode));
		p->data = 2*i;
        r->next = p;
        r= p;
    }
    r->next=NULL;

    return L;
}
LinkList MutualAgg(LinkList A,LinkList B)
 { 
    LinkList C,pa,pb,pc,qc;
    C = pc = (LinkList)malloc(sizeof(LNode));
    pa = A->next;
    while(pa) {
        pb = B->next;
        while(pb) {
            if(pb->data == pa->data) {
                qc = (LinkList)malloc(sizeof(LNode));
                qc->data = pb->data;
                pc->next = qc;
                pc = qc;
            }
            pb = pb->next;
        }
        pa = pa->next;
    }
    pc->next = NULL;
    return C;
}
 
 
 
void print(LinkList p)
{
	
    LinkList head = p->next;
    while(head)
	{
        printf("%d ",head->data);
        head=head->next;
    }
    printf("\n");
	
}
 
int main() 
{
    LinkList A,B,C,D,E;
    A = InitList(A,10);
    print(A);
    B = InitList1(B,10);
    print(B);
    C = MutualAgg(A,B);
    print(C);
    return 0;
}
