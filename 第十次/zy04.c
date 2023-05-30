#include <stdio.h>

void insertion_sort(int arr[], int n) 
{
    for (int i = 1; i < n; i++) 
	{
        int j = i;
        int temp = arr[j];  //这个是向前找小的（在已排好的数组里），如果小就换
        while (j > 0 && temp < arr[j - 1]) 
		{
            arr[j] = arr[j - 1];  // 将已排序元素依次后移
            j--;
        }
        arr[j] = temp;  // 将待插入元素插入到正确的位置
    }
}

int main() {
    int arr[] = {15, 13, 19, 21, 37, 56, 64, 75, 80, 88, 92};
    int n = 11;
    printf("排序前的数列：");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    insertion_sort(arr, n);
    printf("\n排序后的数列：");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
