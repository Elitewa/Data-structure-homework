#include <stdio.h>

void selection_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_index = i; 
        for (int j = i + 1; j < n; j++) 
		{
            if (arr[j] < arr[min_index]) {
                min_index = j;  
            }
        }//循环找最小下标        这个是向后找比它最小的，如果小就换
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;// 将未排序部分的最小元素交换到已排序部分的末尾
    }
}

int main() {
    int arr[] = {15, 13, 19, 21, 37, 56, 64, 75, 80, 88, 92};
    int n = 11;
    printf("排序前的数列：");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    selection_sort(arr, n);
    printf("\n排序后的数列：");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
