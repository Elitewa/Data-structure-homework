#include "stdio.h"
#define maxsize 100
typedef struct{
	int i,j;
	int e;
}triple;
typedef struct{
	triple data[maxsize+1];
	int mu,nu,tu;
}tsmat;
void cjsyzSZ(tsmat *s,int a[][7],int h,int l)
{
	int i,j,k=1;
	s->mu=h;
	s->nu=l;
	for(i=0;i<=h-1;i++)
		for(j=0;j<=l-1;j++)
		{
			if(a[i][j]!=0)
			{
				s->data[k].i=i+1;
				s->data[k].j=j+1;
				s->data[k].e=a[i][j];
				k++;
			}
		}
	s->tu=k-1;
}
void psyz(tsmat *s)
{
	int i;
	printf("hs; %d ls:%d flgs:%d\n",s->mu,s->nu,s->tu);
	printf("syz: \n");
	for(i=1;i<=s->tu;i++)
		printf("   %d   %d  %d\n",s->data[i].i,s->data[i].j,s->data[i].e);
		
}
void syzzz(tsmat *s,tsmat *k)
{
	k->mu=s->nu;
	k->nu=s->mu;
	k->tu=s->tu;                //以原三元组的列遍历，循环新三元组的行，如果列等于行则录入新三元组，然后行加一，继续遍历
	if(s->tu>0)
	{
		int q=1,m,p;
		for(m=1;m<=s->nu;m++)
			for(p=1;p<=s->tu;p++)
				if(s->data[p].j==m)
				{
					k->data[q].i=s->data[p].j;
					k->data[q].j=s->data[p].i;
					k->data[q].e=s->data[p].e;
					q++;
					
				}
	}
}
void syzzzd(tsmat *s,tsmat *k)
{
	int num[maxsize]={0},i,copt[maxsize],col,q;
	k->mu=s->nu;
	k->nu=s->mu;
	k->tu=s->tu;
	if(s->tu>0)
	{
		for(i=1;i<=s->tu;i++)
			num[s->data[i].j]++;  //每列有几个非0
		copt[1]=1;
		for(i=2;i<=s->nu;i++)
			copt[i]=copt[i-1]+num[i-1];
		for(i=1;i<=s->tu;i++)
		{
			col=s->data[i].j;
			q=copt[col];
			k->data[q].i=s->data[i].j;
			k->data[q].j=s->data[i].i;
			k->data[q].e=s->data[i].e;
			copt[col]++;
		}
	}
}
void main()
{
	int s[6][7]={0,1,9,0,0,0,0,6,0,0,0,0,0,3,0,0,0,0,4,0,0,0,2,0,0,0,0,0,8,0,0,0,0,0,5,0,0,7,0,0,0};
	tsmat a,k,p;
	cjsyzSZ(&a,s,6,7);
	psyz(&a);
	syzzz(&a,&p);
	psyz(&p);
	syzzzd(&a,&k);
	psyz(&k);
}
