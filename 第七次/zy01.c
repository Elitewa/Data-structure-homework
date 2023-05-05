#include "stdio.h"
#include "stdlib.h"
typedef struct bitnode{
	int data;
	struct bitnode *lchild,*rchild;
}bitnode;
int a[20]={1,2,4,8,0,0,9,0,0,5,0,0,3,6,0,0,7,0,0},a_i=0,count=0,sum=0;
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
void blx(bitnode *t,int *max,int *min)
{

	if(t)
	{
		sum+=t->data;
		count++;
		if(*max<t->data)
			*max=t->data;
		if(*min>t->data)
			*min=t->data;
		blx(t->lchild,max,min);
		blx(t->rchild,max,min);
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
	creat_sz(&t);
	int max=t->data,min=t->data;
	blx(t,&max,&min);
	printf("结点个数为: %d",count);
	printf("\n结点和为: %d",sum);
	printf("\n最大值为%d,最小值为%d",max,min);	
	freetree(t);		
}
