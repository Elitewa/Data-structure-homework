#include "stdio.h"
#define N 9
int a[N],bz[N],t;
void fun(int wz)
{
	if(wz==t)
	{
		for(int i=0;i<wz;i++)
			printf("%d",a[i]);
		printf("\n");
	}
	else
	{
		for(int i=1;i<=t;i++)
		{
			if(bz[i-1]==0)
			{
				a[wz]=i;
				bz[i-1]=1;
				fun(wz+1);
				bz[i-1]=0;
			}
		}
	}
}
void main()
{
	scanf("%d",&t);
	fun(0);
}
