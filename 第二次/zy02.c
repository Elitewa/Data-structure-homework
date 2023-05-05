#include "stdio.h"
#include "stdlib.h"
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
typedef struct
{
	int *elem;
	int length;
	int listsize;
}Sqlist;
int Initlist_Sq(Sqlist *l)
{
	l->elem=(int*)malloc(LIST_INIT_SIZE*sizeof(int));
	if(!l->elem)
		return 0;
	l->length=0;
	l->listsize=LIST_INIT_SIZE;
	return 1;
}
int Listinsert_Sq(Sqlist *l,int k,int e) /*1<=k<=length+1*/
{
	int  *p,*q;
	if(k<1||k>l->length+1)
		return 0;
	if(l->length>=l->listsize)
	{
		int i,*newelem=(int*)malloc((l->listsize+LISTINCREMENT)*sizeof(int));
		if(!newelem)
			return 0;
		for(i=0;i<l->length;i++)
			newelem[i]=l->elem[i];
		free(l->elem);
		l->elem=newelem;
	}
	q=&(l->elem[k-1]);
	for(p=&(l->elem[l->length-1]);p>=q;p--)
		*(p+1)=*p;
	*q=e;
	l->length++;
	return 1;
}
void fdjhb(Sqlist *la,Sqlist *lb,Sqlist *lc)
{
	int i=0,j=0;
	while(i<=la->length-1&&j<=lb->length-1)
	{
		if(la->elem[i]<=lb->elem[j])
			lc->elem[lc->length++]=la->elem[i++];
		else
			lc->elem[lc->length++]=lb->elem[j++];
	}
	while(i<=la->length-1)
		lc->elem[lc->length++]=la->elem[i++];
	while(j<=lb->length-1)
		lc->elem[lc->length++]=lb->elem[j++];
}
void PrintList(Sqlist *l)
{
	int i=0;
	while(i<l->length)
		printf("%d ",l->elem[i++]);
	printf("\n");
}
void main()
{
	Sqlist la,lb,lc;
	int m;
	Initlist_Sq(&la);
	Initlist_Sq(&lb);
	Initlist_Sq(&lc);
	for(m=1;m<=6;m++)
		Listinsert_Sq(&la,m,m*m);
	for(m=1;m<=10;m++)
		Listinsert_Sq(&lb,m,2*m);
	fdjhb(&la,&lb,&lc);
	PrintList(&la);
	PrintList(&lb);
	PrintList(&lc);
}
