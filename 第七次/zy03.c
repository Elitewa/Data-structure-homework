#include "stdio.h"
#include "stdlib.h"
typedef struct bitnode{
	int data;
	struct bitnode *lchild,*rchild;
}bitnode;
int a[20]={1,2,4,8,0,0,9,0,0,5,0,0,3,6,0,0,7,0,0},a_i=0,k=0,e=0,i=0;
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
void jzs(bitnode *t)
{

	if(t)
	{
		bitnode *tmp=(bitnode *)malloc(sizeof(bitnode));
		tmp=t->lchild;
		t->lchild=t->rchild;
		t->rchild=tmp;
		jzs(t->lchild);
		jzs(t->rchild);
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
void blkx(bitnode *t)
{
    if(t && k < 5)
    {
        printf("%d ", t->data);
        k++;
        blkx(t->lchild);
        blkx(t->rchild);
        
    }
}
void blkz(bitnode *t)
{
	if(t&&e<=4)
	{
		e++;
		blkz(t->lchild);
		printf("%d ",t->data);
		blkz(t->rchild);
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
void blkh(bitnode *t)
{
	if(t&&i<=4)
	{
		i++;
		blkh(t->lchild);
		blkh(t->rchild);
		printf("%d ",t->data);
	}
}
void main()
{
	bitnode *t=NULL;
	creat_sz(&t);
	jzs(t);
	printf("子树交换后先序遍历为: ");
	blx(t);
	printf("\n先序显示前5个节点");
	blkx(t);
	printf("\n后序显示前5个节点");
	blkh(t);
	printf("\n中序显示前5个节点");
	blkz(t);
	freetree(t);
}
