#include "stdio.h"
#include "stdlib.h"
#include "string.h"
typedef struct node
{
	char c;
	int qz;
	char bm[30];
	struct node *lchild,*rchild,*next,*nt;
}hnode;
hnode *tjzf(char *a)
{
	hnode *hd=(hnode*)malloc(sizeof(hnode));
	int i=0;
	
	hd->next=NULL;
	hd->lchild=NULL;
	hd->rchild=NULL;
	hd->nt=NULL;
	while(a[i]!='\0')
	{
		hnode *p=hd->next;
		while(p!=NULL)
		{
			if(p->c==a[i])
			{
				p->qz++;
				break;
			}
			p=p->next;
		}
		if(p==NULL)
		{
			hnode *t=(hnode*)malloc(sizeof(hnode));
			t->c=a[i];
			t->qz=1;
			t->lchild=NULL;
			t->rchild=NULL;
			t->bm[0]='\0';
			t->next=hd->next;
			hd->next=t;
			t->nt=hd->nt;
			hd->nt=t;
		}
		i++;		
	 }
	return hd;
}
void select(hnode *hd)
{
	while(hd->next->next!=NULL)
	{
		hnode *m=hd,*p=m->next,*min1,*min2;
		while(p->next!=NULL)
		{
			if(p->next->qz < m->next->qz)
				m=p;
			p=p->next;
		}
		min1=m->next;
		m->next=min1->next;
		
		m=hd,p=m->next;
		while(p->next!=NULL)
		{
			if(p->next->qz < m->next->qz)
				m=p;
			p=p->next;
		}
		min2=m->next;
		m->next=min2->next;
		
		m=(hnode*)malloc(sizeof(hnode));
		m->qz=min1->qz+min2->qz;
		m->lchild=min1;
		m->rchild=min2;
		m->next=hd->next;
		m->bm[0]='\0';
		hd->next=m;
	}
}
void blx(hnode *hd,char cc[30],int t)
{
	if(hd!=NULL)
	{
		if(t==0)
		{
			strcat(hd->bm,cc);
			strcat(hd->bm,"0");
		}
		else if(t==1)
		{
			strcat(hd->bm,cc);
			strcat(hd->bm,"1");
		}
		blx(hd->lchild,hd->bm,0);
		blx(hd->rchild,hd->bm,1);
	}
}
void freetree(hnode *t)
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
	char a[200]="adffaflasdasasaaaaasssasasdasadsdasdasdlakaflakqew";
	hnode *head,*p,*hd=(hnode*)malloc(sizeof(hnode));
	head=tjzf(a);
	hd->nt=head->nt;
	select(head);
	blx(head->next,head->bm,-1);
	p=hd->nt;
	while(p!=NULL)
	{
		printf("%c:%d:%s\n",p->c,p->qz,p->bm);
		p=p->nt;
	}
	freetree(head->next);
	free(head);
	free(hd);
	
}
