#include "stdio.h"
#include "string.h"
#include "math.h"
#define N 81
char map[N][N],t;
void fun(int x,int y,int n)
{
	if(n==1)
	 	map[x][y]='X';
	else{
		int k=(int)pow(3,n-2);
		fun(x,y,n-1);
		fun(x,y+2*k,n-1);
		fun(x+k,y+k,n-1);
		fun(x+2*k,y,n-1);
		fun(x+2*k,y+2*k,n-1);
		
	}
}
void main()
{
	int i,j,k;
	scanf("%d",&t);
	memset(map,' ',sizeof(map));
	fun(0,0,t);
	k=(int)pow(3,t-1);
	for(i=0;i<k;i++)
	{
		for(j=k-1;j>=0;j--)
			if(map[i][j]=='X')
				break;
		map[i][j+1]=0;
	}
	for(i=0;i<k;i++)
		printf("%s\n",map[i]);
}
