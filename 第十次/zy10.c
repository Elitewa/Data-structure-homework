#include <stdio.h>
#include <stdlib.h>

// 获取数组中最大的值
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// 对数组进行基数排序
void radixSort(int arr[], int n) {
    // 获取数组中最大的数以确定处理次数
    int max = getMax(arr, n);
    
    // 从个位开始，对数组按位进行排序
    for (int exp = 1; max / exp > 0; exp *= 10) {
        int output[n]; // 临时存储排序后的结果
        int count[10] = {0}; // 存储每个数字出现的次数
        
        // 统计每个数字出现的次数
        for (int i = 0; i < n; i++) {
            count[(arr[i] / exp) % 10]++;
        }
        
        // 计算每个数字排序后的位置
        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }
        
        // 将数字按照排序后的位置存储到输出数组中
        // 注意：这里从后往前遍历原始数组是为了保证排序的稳定性
        for (int i = n - 1; i >= 0; i--) {
            output[count[(arr[i] / exp) % 10] - 1] = arr[i];
            count[(arr[i] / exp) % 10]--;
        }
        
        // 将排序后的结果复制回原始数组中
        for (int i = 0; i < n; i++) {
            arr[i] = output[i];
        }
    }
}

// 测试
int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("排序前的数组：");
	for (int i = 0; i < n; i++) {
	    printf("%d ", arr[i]);
	}
    
    // 对数组进行基数排序
    radixSort(arr, n);
    
    printf("\n排序后的数组：");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}
