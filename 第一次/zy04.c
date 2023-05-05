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
void DestoryList(Sqlist *l)
{
	free(l->elem);
}
void PrintList(Sqlist *l)
{
	int i=0;
	while(i<l->length)
		printf("%d ",l->elem[i++]);
	printf("\n");
}
void ClearList(Sqlist *l)
{
	l->length=0;
}
int ListLength(Sqlist *l)
{
	return l->length;
}
void GetElem(Sqlist *l,int i, int *e)
{
	*e=l->elem[i-1];
}
int LocatElem(Sqlist *l,int e)
{
	int i;
	for(i=0;i<l->length;i++)
		if(l->elem[i]==e)
			return i+1;
	return 0;
}
void ListDelete(Sqlist *l,int k,int *e) /*1=<k<=l->length*/
{
	int i;
	*e=l->elem[k-1];
	for(i=k;i<l->length;i++)
		l->elem[i-1]=l->elem[i];
	l->length--;
}
void main()
{
	Sqlist list;
	int m;
	Initlist_Sq(&list);
	for(m=1;m<=20;m++)
		Listinsert_Sq(&list,m,m*m);
	PrintList(&list);
	ListDelete(&list,19,&m);
	printf("%d\n",m);
	PrintList(&list);
	DestoryList(&list);
}
