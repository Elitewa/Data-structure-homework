#include "stdio.h"
#include <stack>
using namespace std;
void conversion(int n,int jz,char s[])
{
	int e,i=0;
	stack<int> z;
	while(n)
	{
		z.push(n%jz);
		n=n/jz;
	}
	while(!z.empty())
	{
		e=z.top();
		z.pop();
		if(e<=9)
			s[i]=e+'0';
		else
			s[i]='A'+e-10;
		i++;
	}
	s[i]='\0';
}
int main()
{
	char c[200];
	int n;
	scanf("%d",&n);
	printf("您输入的十进制数：%d\n",n);
	conversion(n,8,c);
	printf("八进制：%s\n",c);
	conversion(n,2,c);
	printf("二进制：%s\n",c);
	conversion(n,16,c);
	printf("十六进制：%s\n",c);
	
}
