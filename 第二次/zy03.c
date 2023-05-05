#include "stdio.h"
#include "stdlib.h"
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
typedef struct
{
	int *elem;
	int length;
	int listsize;
}Sqlist,*jiao;
void PrintList(Sqlist *l)
{
	int i=0;
	while(i<l->length)
		printf("%d ",l->elem[i++]);
	printf("\n");
}
int Initlist_Sq(Sqlist *l)
{
	l->elem=(int*)malloc(LIST_INIT_SIZE*sizeof(int));
	if(!l->elem)
		return 0;
	l->length=0;
	l->listsize=LIST_INIT_SIZE;
	return 1;
}
jiao Qjji(Sqlist *lista,Sqlist *listb,jiao jj)
{
	int j,i;
	for(i=0;i<=listb->length-1;i++)
	{
		for(j=0; j<=lista->length-1;j++)
		{	if(lista->elem[j]==listb->elem[i])
		
			{
				jj->elem[jj->length++]=listb->elem[i];
				break;
			}
		}
	
	}
	return jj;
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
void main()
{
	Sqlist lista,listb,jj;
	int m;
	Initlist_Sq(&lista);
	Initlist_Sq(&listb);
	Initlist_Sq(&jj);
	for(m=1;m<=10;m++)
		Listinsert_Sq(&lista,m,m*m);
	for(m=1;m<=10;m++)
		Listinsert_Sq(&listb,m,2*m);
	PrintList(&lista);
	PrintList(&listb);
	PrintList(Qjji(&lista,&listb,&jj));

}
