#include "stdlib.h"
#include "stdio.h"
#include <stack>
int a[20]={1,2,4,8,0,0,9,0,0,5,0,0,3,6,0,0,7,0,0},a_i=0;
using namespace std;
typedef struct bitree{
	int data;
	struct bitree *lchild,*rchild;
}bitree;
void blxfd(bitree *t)
{
	stack<bitree*> s;
	while(t!=NULL||!s.empty())
	{
		if(t!=NULL)
		{
			printf("%d ",t->data);
			s.push(t);
			t=t->lchild;
		}
		else{
			t=s.top();
			s.pop();
			t=t->rchild;
		}
		
	}
}
void blzfd(bitree *t)
{
	stack<bitree*> s;
	while(t!=NULL||!s.empty())
	{
		if(t!=NULL)
		{
			s.push(t);
			t=t->lchild;
		}
		else{
			t=s.top();
			s.pop();
			printf("%d ",t->data);
			t=t->rchild;
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
	printf("先序遍历:");
	blxfd(t);
	printf("\n中序遍历:");
	blzfd(t);
	freetree(t);
	return 0;		
}


