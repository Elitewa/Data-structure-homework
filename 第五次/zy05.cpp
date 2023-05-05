#include <stdio.h>
#include <stack>
using namespace std;
void tranfExp(char* exp,char* postexp)
{
	stack<char> op;
	int i=0,j=0;
	while(exp[i]!='\0')
	{
		if(exp[i]>='0'&&exp[i]<='9')
			postexp[j++]=exp[i];
		else if(exp[i]=='(')
			op.push(exp[i]);
		else if(exp[i]==')')
		{
			while(!op.empty())
			{
				if(op.top()=='(')
				{
					op.pop();
					break;
				}
				else
				{
					postexp[j++]=op.top();
					op.pop();
				}
			}
		}
	else if(exp[i]=='+'||exp[i]=='-')
	{
		while(!op.empty())
		{
			char ch=op.top();
			if(ch=='+'||ch=='-'||ch=='*'||ch=='/')
			{
				postexp[j++]=ch;
				op.pop();
			}
			else
				break;
		}
		op.push(exp[i]);
	}
	else if(exp[i]=='*'||exp[i]=='/')
	{
		while(!op.empty())
		{
			char ch=op.top();
			if(ch=='/'||ch=='*')
			{
				postexp[j++]=ch;
				op.pop();
			}
			else break;
		}
		op.push(exp[i]);
	}
	i++;
}
while(!op.empty())
{
	postexp[j++]=op.top();
	op.pop();
}
postexp[j]=0;
}
int calcExp(char* postexp)
{
	stack<int> cal;
	int i=0,m,n;
	while(postexp[i]!='\0')
	{
		if(postexp[i]>='0'&&postexp[i]<='9')
			cal.push(postexp[i]-'0');
		else
		{
			m=cal.top();cal.pop();
			n=cal.top();cal.pop();
			switch(postexp[i])
			{
				case '-':cal.push(n-m);break;
				case '+':cal.push(n+m);break;
				case '*':cal.push(n*m);break;
				case '/':cal.push(n/m);break;
			}
		}
		i++;
	}
	return cal.top();
}
int main()
{
	char exp[1000]="5*(4-2+1)+8/4";
	char postexp[1000];
	tranfExp(exp,postexp);
	printf("%s\n",postexp);
	printf("%d\n",calcExp(postexp));
}
