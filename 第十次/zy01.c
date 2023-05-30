#include "stdlib.h"
#include "stdio.h"
int search(int arr[], int n) 
{
    for (int i = 0; i < 11; i++)
	{
        if (arr[i] == n) 
		{
			printf("在第%d个位置",i);
            return 1;  
        }
    }
    return 0; 
}
int main()
{
	int arr[11]={15,13,19,21,37,56,64,75,80,88,92},pos,n;
	printf("请输入数字\n");
	scanf("%d",&n);
	pos=search(arr,n);
	if(pos)
	{
		printf("找到了");
	}
	else{
		printf("没找到");
	}
	return 0;
}
