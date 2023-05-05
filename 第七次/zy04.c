#include "stdlib.h"
#include "stdio.h"
int a[20]={1,2,4,8,0,0,9,0,0,5,0,0,3,6,0,0,7,0,0},a_i=0;
#define max 8
typedef struct bitree{
	int data,tag;
	struct bitree *lchild,*rchild;
}bitree;
void ccbl(bitree *t)
{
	bitree *dl[max],*p=NULL;
	int f=0,r=0;
	if(t!=NULL)
	{
		dl[r]=t;
		r++;
	}
	while(f!=r)
	{
		p=dl[f];
		f++;
		printf("%d ",p->data);
		if(p->lchild!=NULL)
		{
			dl[r]=p->lchild;
			r++;
		}
		if(p->rchild!=NULL)
		{
			dl[r]=p->rchild;
			r++;
		}
	}
}
void creat_sz(bitree **T)
{
	if(a[a_i]==0)
	{
		(*T)=NULL;
		a_i++;
	}
	else{
		(*T)=(bitree *)malloc(sizeof(bitree));
		(*T)->data=a[a_i];
		a_i++;
		creat_sz(&(*T)->lchild);
		creat_sz(&(*T)->rchild);
	}
}
void freetree(bitree *t)
{
	if(t!=NULL)
	{
		freetree(t->lchild);
		freetree(t->rchild);
		free(t);
	}
}
int main()
{
	bitree *t=NULL;
	creat_sz(&t);
	printf("ºóĞò±éÀú:");
	ccbl(t);
	freetree(t);
	return 0;		
}
