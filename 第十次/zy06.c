#include <stdio.h>

void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int flag = 0;  // 标记本轮是否发生了交换
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = 1;
            }
        }
        if (flag == 0) break;  // 如果本轮没有发生交换，则已经有序，可以提前结束
    }
}

int main() {
    int arr[] = {15, 13, 19, 21, 37, 56, 64, 75, 80, 88, 92};
    int n = 11;
    printf("排序前的数列：");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    bubble_sort(arr, n);
    printf("\n排序后的数列：");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
