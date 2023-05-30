#include <stdio.h>

// 合并两个已排序子序列
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    // 创建临时数组
    int left_arr[n1], right_arr[n2];
    
    // 将数据复制到临时数组中
    for (i = 0; i < n1; i++)
        left_arr[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        right_arr[j] = arr[mid + 1 + j];
    
    // 合并临时数组中的元素到原数组中
    i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (left_arr[i] <= right_arr[j]) {
            arr[k] = left_arr[i];
            i++;
        } else {
            arr[k] = right_arr[j];
            j++;
        }
        k++;
    }
    
    // 将未合并的剩余元素复制到原数组中
    while (i < n1) {
        arr[k] = left_arr[i];
        i++, k++;
    }
    while (j < n2) {
        arr[k] = right_arr[j];
        j++, k++;
    }
}

// 归并排序递归函数
void merge_sort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        
        // 分割
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        
        // 合并
        merge(arr, left, mid, right);
    }
}

// 测试
int main() {
    int arr[] = {5, 9, 3, 1, 2, 8, 4, 7, 6},q;
    printf("排序前的序列：");
    for(q=0;q<9;q++)
    {
		printf("%d ",arr[q]);
	}
	printf("\n");
    int n = sizeof(arr) / sizeof(arr[0]);
    int i;
    
    merge_sort(arr, 0, n - 1);
    
    printf("排序后的序列: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    
    return 0;
}
