#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define MAX 999999
typedef struct snode
{
	char c;
	int qz;
	char bm[30];
	int lchild,rchild,bz;
}snode;
typedef struct sz
{
	snode *arr;
	int num_yz;
}hfms;
typedef struct cnode
{
	char c;
	int qz;
	struct cnode *next;
}hcnode;
void tjzf(char *a,hfms *s)
{
	int i=0;
	hcnode *hd=(hcnode *)malloc(sizeof(hcnode)),*p;
	hd->next=NULL;
	while(a[i]!='\0')
	{
		p=hd->next;
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
			hcnode *t=(hcnode *)malloc(sizeof(hcnode));
			t->c=a[i];
			t->qz=1;
			t->next=hd->next;
			hd->next=t;
		}
		i++;
	}
	i=0;
	p=hd->next;
	while(p!=NULL)
	{
		i++;
		p=p->next;
	}
	s->num_yz=i;
	s->arr=(snode *)malloc(sizeof(snode)*(s->num_yz*2-1));
	p=hd->next;
	i=0;
	while(p!=NULL)
	{
		s->arr[i].c=p->c;
		s->arr[i].qz=p->qz;
		strcpy(s->arr[i].bm," ");
		s->arr[i].lchild=-1;
		s->arr[i].rchild=-1;
		s->arr[i].bz=1;
		p=p->next;
		i++;
	}
	for(;i<s->num_yz*2-1;i++)
	{
		s->arr[i].c='\0';
		s->arr[i].qz=0;
		strcpy(s->arr[i].bm," ");
		s->arr[i].lchild=-1;
		s->arr[i].rchild=-1;
		s->arr[i].bz=0;
	}
	p=hd->next;
	while(p!=NULL)
	{
		hd->next=p->next;
		free(p);
		p=hd->next;
	}
	free(hd);
}
void js(hfms s)
{
	int i,min1xb,min2xb,minxb,minz,k;
	for(k=s.num_yz;k<s.num_yz*2-1;k++)
	{
		minxb=-1;
		minz=MAX;
		for(i=0;i<s.num_yz*2-1;i++)
		{
			if(s.arr[i].bz==1&&s.arr[i].qz<minz)
			{
				minz=s.arr[i].qz;
				minxb=i;
			}
		}
		min1xb=minxb;
		s.arr[min1xb].bz=0;
		minxb=-1;
		minz=MAX;
		for(i=0;i<s.num_yz*2-1;i++)
			if(s.arr[i].bz==1&&s.arr[i].qz<minz)
			{
				minz=s.arr[i].qz;
				minxb=i;
			}
		min2xb=minxb;
		s.arr[min2xb].bz=0;
		
		s.arr[k].qz=s.arr[min1xb].qz+s.arr[min2xb].qz;
		s.arr[k].bz=1;
		s.arr[k].lchild=min1xb;
		s.arr[k].rchild=min2xb;
	}
}
void bm(hfms s,int xb,char cc[30],int t)
{
	if(t==0)
	{
		strcat(s.arr[xb].bm,cc);
		strcat(s.arr[xb].bm,"0");
	}
	else if(t==1)
	{
		strcat(s.arr[xb].bm,cc);
		strcat(s.arr[xb].bm,"1");
	}
	if(s.arr[xb].lchild!=-1)
		bm(s,s.arr[xb].lchild,s.arr[xb].bm,0);
	if(s.arr[xb].rchild!=-1)
		bm(s,s.arr[xb].rchild,s.arr[xb].bm,1);
}
void main()
{
	int i;
	char a[200]="abbccccdddddddddd";
	hfms s;
	tjzf(a,&s);
	js(s);
	bm(s,s.num_yz*2-1-1," ",-1);
	for(i=0;i<=s.num_yz-1;i++)
	{
		printf("%c:%d:%s\n",s.arr[i].c,s.arr[i].qz,s.arr[i].bm);
	}
	free(s.arr);
}
