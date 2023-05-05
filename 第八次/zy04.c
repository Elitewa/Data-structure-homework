#include "stdio.h"
#include "stdlib.h"
#define MAX 999
typedef struct bitnode
{
	int data,szcc;
	struct bitnode *lchild,*rchild;
}bitnode,*bitree;
int a[30]={8,3,2,1,0,0,2,0,0,7,3,0,0,0,6,4,0,4,0,0,0}, a_i = 0;
bitree pre;
void create(bitree *T) 
{
    if (a[a_i] == 0) 
	{
        (*T) = NULL;
        a_i++;
    } 
	else 
	{
        (*T) = (bitnode*) malloc(sizeof(bitnode));
        (*T)->data = a[a_i];
        a_i++;
        create(&(*T)->lchild);
        create(&(*T)->rchild);
    }
}
void ccbl(bitree t)
{
	bitnode *dl[MAX],*p=NULL;
	int f=0,r=0,he=0,cc=1;
	t->szcc=1;
	dl[r]=t;
	int max=t->data,maxcc=1;
	r++;
	while(f!=r)
	{
		p=dl[f];
		if(p->szcc!=cc)  //f+到下一行，换层时执行一次
		{
			if(he>max)  //求完所有和到下一行初时执行
			{
				max=he;
				maxcc=cc;
			}
			he=0;   //刚到新一行的时候执行
			cc=p->szcc;
		}
		he=he+p->data;
		f++;
		if(p->lchild!=NULL)
		{
			p->lchild->szcc=p->szcc+1;
			dl[r]=p->lchild;
			r++;	
		}
		if(p->rchild!=NULL)
		{
			p->rchild->szcc=p->szcc+1;
			dl[r]=p->rchild;
			r++;
		}
	}
	printf("最大层次%d\n最大层次和%d",maxcc,max);
}
int main(void) {
    bitree t = NULL;
    create(&t);
    ccbl(t);
    printf("\n");
}
