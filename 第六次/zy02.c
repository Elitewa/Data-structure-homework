#include "stdio.h"
#include "stdlib.h"
#define MAXLEN 100
typedef unsigned char SString[MAXLEN+1];
void StrAssign(SString a,char b[])
{
	int i=0;
	while(b[i]!='\0')
	{
		a[i+1]=b[i];
		i++;
	}
	a[0]=i;
}
int IndexF(SString S,SString T,int pos)
{
	int i=pos,j=1,k=pos;
	while(i<=S[0]&&j<=T[0])
	{
		if(S[i]==T[j])
		{
			++i;
			++j;
		}
		else{
			i=++k;
			j=1;
		}
	}
	if(j>T[0])
		return k;
	else
		return 0;
}
void PrintSS(SString a)
{
	int i;
	for(i=1;i<=a[0];i++)
		printf("%c",a[i]);
	printf("\n");
}
void getnext(SString a,int next[])
{
	int i=1,j=0;
	next[1]=0;
	while(i<a[0])
	{
		if(j==0||a[i]==a[j])
		{
			++i;
			++j;
			next[i]=j;
		}
		else j=next[j];
	}	
}
void getnextval(SString a,int nextval[])
{
	int i=1,j=0;
	nextval[1]=0;
	while(i<a[0])
	{
		if(j==0||a[i]==a[j])
		{
			++j;
			++i;
			if(a[i]!=a[j])
				nextval[i]=j;
			else
				nextval[i]=nextval[j];
		}
		else
			j=nextval[j];
	}
}
int kmp(SString S,SString T,int pos,int next[])
{
	int i=1,j=1;
	while(i<=S[0]&&j<=T[0])
	{
		if(j==0||S[i]==T[j])
		{
			++i;
			++j;
		}
		else
			j=next[j];
	}
	if(j>T[0])
		return i-T[0];
	else
		return 0;
}
void main()
{
	int next[20]={0},nextval[20]={0},i;
	SString a,sub;
	StrAssign(a,"aaaacaaaaba");
	StrAssign(sub,"aaaaba");
	printf("%d\n",IndexF(a,sub,1));
	getnext(sub,next);
	for(i=1;i<=6;i++)
	 	printf("%d ",next[i]);
	printf("\n%d\n",kmp(a,sub,1,next));
	getnextval(sub,nextval);
	for(i=1;i<=6;i++)
		printf("%d ",nextval[i]);
	printf("\n%d\n",kmp(a,sub,1,nextval));
}
