#include <stdio.h>
void fun(int n)
{
	int i;
	if(n!=0)
	{
		fun(n-1);
			for(i=1;i<=n;i++)
			printf("%3d",n);
		printf("\n");
	}
}
int main()
{
	int a;
	scanf("%d",&a);
	fun(a);
}
