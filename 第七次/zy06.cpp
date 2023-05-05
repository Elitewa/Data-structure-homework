#include "stdlib.h"
#include "stdio.h"
#include <stack>
int a[20]={1,2,4,8,0,0,9,0,0,5,0,0,3,6,0,0,7,0,0},a_i=0;
using namespace std;
typedef struct bitree{
	int data,tag;
	struct bitree *lchild,*rchild;
}bitree;
void blhfd(bitree *t)
{
	stack<bitree*> s;
	while(t!=NULL||!s.empty())
	{
		if(t!=NULL)
		{
			t->tag=0;
			s.push(t);
			t=t->lchild;
		}
		else{
			t=s.top();
			s.pop();
			if(t->tag==0)
			{
				t->tag=1;
				s.push(t);
				t=t->rchild;
			}
			else{
				printf("%d ",t->data);
				t=NULL;
			}
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
	blhfd(t);
	freetree(t);
	return 0;		
}
