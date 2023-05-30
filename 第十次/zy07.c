#include <stdio.h>

void quick_sort(int arr[], int left, int right) {
    if (left >= right) return;  // 递归结束条件

    int i = left, j = right, pivot = arr[left];  // 基准元素取最左边的元素
    while (i < j) {
        while (i < j && arr[j] >= pivot) j--;  // 从右往左找到第一个小于基准元素的位置
        if (i < j) arr[i++] = arr[j];

        while (i < j && arr[i] <= pivot) i++;  // 从左往右找到第一个大于基准元素的位置
        if (i < j) arr[j--] = arr[i];
    }
    arr[i] = pivot;  // 将基准元素归位

    quick_sort(arr, left, i - 1);   // 对左侧子序列进行递归调用
    quick_sort(arr, i + 1, right);  // 对右侧子序列进行递归调用
}

int main() {
    int arr[] = {15, 13, 19, 21, 37, 56, 64, 75, 80, 88, 92};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("排序前的数列：");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    quick_sort(arr, 0, n - 1);
    printf("\n排序后的数列：");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
