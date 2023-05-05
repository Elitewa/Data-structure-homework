#include "stdlib.h"
#include "stdio.h"
int a[20]={1,2,4,8,0,0,9,0,0,5,0,0,3,6,0,0,7,0,0},a_i=0;
typedef struct bitree{
	int data,tag;
	struct bitree *lchild,*rchild;
}bitree;
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
int qcs(bitree *t,int n,int cc)
{
	if(t!=NULL)
	{
		if(t->data==n)
			return cc;
		else
		{
			int c1=qcs(t->lchild,n,cc+1);
			int c2=qcs(t->rchild,n,cc+1);
			return c1>c2?c1:c2;
		}
	}
	else return 0;
}
int qsd(bitree *t,int sd)
{
	
	if(t!=NULL)
	{
		int c1=qsd(t->lchild,sd+1);
		int c2=qsd(t->rchild,sd+1);
		return c1>c2?c1:c2;
	}
	return sd;
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
bitree* copytree(bitree* src)
{
    bitree* dst = NULL;

    if (src == NULL)
        return dst;
	dst = (bitree*)malloc(sizeof(bitree));
    dst->data = src->data;
    dst->tag = src->tag;
    dst->lchild = copytree(src->lchild);
    dst->rchild = copytree(src->rchild);

    return dst;
}
void blx(bitree *t)
{
	if(t)
	{
		printf("%d ",t->data);
		blx(t->lchild);
		blx(t->rchild);
	}
}

int main()
{
	bitree *t=NULL;
	int cc=1,sd=1;
	creat_sz(&t);
	cc=qcs(t,8,cc);
	printf("8的层次为:");
	printf("%d ",cc);
	sd=qsd(t,sd);
	printf("\n深度为:");
	printf("%d ",sd);
	bitree *t_copy = copytree(t);
	printf("\n先序遍历一下复制的二叉树\n");
	blx(t_copy);
	freetree(t);
	return 0;		
}
