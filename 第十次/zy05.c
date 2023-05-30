#include <stdio.h>

void shell_sort(int arr[], int n)
 {
    int gap = n / 2;  // 初始化增量为数组长度的一半
    while (gap > 0) 
	{
        for (int i = gap; i < n; i++)
		 {
            int temp = arr[i];
            int j = i - gap;    //在当前组的序号
           		while (j >= 0 && arr[j] > temp) 
				{
                	arr[j + gap] = arr[j];
                	j -= gap;
            	}
            arr[j + gap] = temp;
        }
        gap /= 2;  // 缩小增量
    }
}

int main() {
    int arr[] = {15, 13, 19, 21, 37, 56, 64, 75, 80, 88, 92};
    int n = 11;
    printf("排序前的数列：");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    shell_sort(arr, n);
    printf("\n排序后的数列：");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
