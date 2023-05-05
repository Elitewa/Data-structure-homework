#include <stdio.h>
int fun(int n)
{
	printf("%d",n%10);
	if(n/10!=0)
		fun(n/10);
}
int main()
{
	int a;
	scanf("%d",&a);
	fun(a);
}
