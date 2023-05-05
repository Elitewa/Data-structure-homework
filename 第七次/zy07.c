#include "stdio.h"
#include "stdlib.h"
typedef struct bitnode{
	int data;
	struct bitnode *lchild,*rchild;
}bitnode;
bitnode *creat()
{
	int d;
	bitnode *T;
	scanf("%d",&d);
	if(d==0)
		T=NULL;
	else{
		T=(bitnode *)malloc(sizeof(bitnode));
		T->data=d;
		T->lchild=creat();
		T->rchild=creat();
	}
	return T;
}
void create(bitnode **T)
{
	int d;
	scanf("%d",&d);
	if(d==0)
		(*T)=NULL;
	else{
		(*T)=(bitnode *)malloc(sizeof(bitnode));
		(*T)->data=d;
		create(&(*T)->lchild);
		create(&(*T)->rchild);
	}
}
int a[17]={1,5,6,0,0,7,0,0,8,0,0},a_i=0;
void creat_sz(bitnode **T)
{
	if(a[a_i]==0)
	{
		(*T)=NULL;
		a_i++;
	}
	else{
		(*T)=(bitnode *)malloc(sizeof(bitnode));
		(*T)->data=a[a_i];
		a_i++;
		creat_sz(&(*T)->lchild);
		creat_sz(&(*T)->rchild);
	}
}
void blx(bitnode *t)
{
	if(t)
	{
		printf("%d ",t->data);
		blx(t->lchild);
		blx(t->rchild);
	}
}
void blz(bitnode *t)
{
	if(t)
	{
		blz(t->lchild);
		printf("%d ",t->data);
		blz(t->rchild);
	}
}
void blh(bitnode *t)
{
	if(t)
	{
		blh(t->lchild);
		blh(t->rchild);
		printf("%d ",t->data);
	}
}
void freetree(bitnode *t)
{
	if(t!=NULL)
	{
		freetree(t->lchild);
		freetree(t->rchild);
		free(t);
	}
}
void main()
{
	bitnode *t=NULL;
	//creat(&t);
	//t=creat();
	creat_sz(&t);
	printf("先序遍历:");
	blx(t);
	printf("\n中序遍历:");
	blz(t);
	printf("\n后序遍历:");
	blh(t);
	printf("\n");
	freetree(t);		
}
