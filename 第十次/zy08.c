#include <stdio.h>

#define LEFT(i) (2 * i + 1)
#define RIGHT(i) (2 * i + 2)

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void max_heapify(int arr[], int i, int heap_size) {
    int l = LEFT(i);
    int r = RIGHT(i);
    int largest = i;

    if (l < heap_size && arr[l] > arr[largest])
        largest = l;
    if (r < heap_size && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        max_heapify(arr, largest, heap_size);
    }
}

void build_max_heap(int arr[], int heap_size) {
    for (int i = heap_size / 2 - 1; i >= 0; i--)
        max_heapify(arr, i, heap_size);
}

void heap_sort(int arr[], int heap_size) {
    build_max_heap(arr, heap_size);

    for (int i = heap_size - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        max_heapify(arr, 0, i);
    }
}

int main() {
    int arr[] = {15, 13, 19, 21, 37, 56, 64, 75, 80, 88, 92};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("排序前的数列：");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    heap_sort(arr, n);
    printf("\n排序后的数列：");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
