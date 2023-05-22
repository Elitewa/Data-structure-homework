#include <stdio.h>
#include <stdlib.h>

#define ini_size 100
#define increment 10

typedef struct {
    int *base;
    int front;
    int rear;
    int size;
} sqqueue;

int ini(sqqueue *q) {
    q->base = (int *) malloc(ini_size * sizeof(int));
    if (!q->base) {
        printf("内存分配失败\n");
        return 0;
    }
    q->front = q->rear = 0;
    q->size = ini_size;
    return 1;
}

void destory(sqqueue *q) {
    free(q->base);
    q->base = NULL;
}

void clear(sqqueue *q) {
    q->front = q->rear = 0;
    printf("队列已清空。\n");
}

int ifempty(sqqueue *q) {
    return (q->front == q->rear) ? 1 : 0;
}

int length(sqqueue *q) {
    return (q->rear - q->front + q->size) % q->size;
}

int getfront(sqqueue *q, int *e) {
    if (ifempty(q)) {
        printf("队列为空，无法获取队头元素。\n");
        return 0;
    }
    *e = q->base[q->front];
    printf("队头元素为：%d\n", *e);
    return 1;
}

int dequeue(sqqueue *q, int *e) {
    if (ifempty(q)) {
        printf("队列为空，无法进行出队列操作。\n");
        return 0;
    }
    *e = q->base[q->front];
    q->front = (q->front + 1) % q->size;
    printf("出队元素为：%d\n", *e);
    return 1;
}

int enqueue(sqqueue *q, int e) {
    if ((q->rear + 1) % q->size == q->front) {
        int *newbase = (int *) realloc(q->base, (q->size + increment) * sizeof(int));
        if (!newbase) {
            printf("内存分配失败，无法进行入队列操作。\n");
            return 0;
        }
        q->base = newbase;
        if (q->rear < q->front) {
            int i;
            for (i = q->rear; i < q->size; i++) {
                q->base[i + q->size] = q->base[i];
            }
            q->rear += q->size;
        }
        q->size += increment;
        printf("队列已扩容。\n");
    }
    q->base[q->rear] = e;
    q->rear = (q->rear + 1) % q->size;
    printf("入队元素为：%d\n", e);
    return 1;
}

void queuetraverse(sqqueue *q) {
    if (ifempty(q)) {
        printf("队列为空，无法进行队列遍历操作。\n");
        return;
    }
    printf("队列元素为：");
    int i;
    for (i = q->front; i != q->rear; i = (i + 1) % q->size) {
        printf(" %d", q->base[i]);
    }
    printf("\n");
}

void main() {
    int i, e;
    sqqueue q;
    ini(&q);
    printf("队列已初始化为一个空队列。\n");
    for (i = 9; i >=1 ; i--) {
        enqueue(&q, i);
    }
    printf("原始队列为:\n");
    queuetraverse(&q);
    printf("队列的长度为: %d\n", length(&q));
    getfront(&q, &e);
    printf("执行获取队头元素操作后，");
    printf("队列的长度为: %d\n", length(&q));
    printf("出队列:\n");
    while (!ifempty(&q)) {
        dequeue(&q, &e);
    }
    clear(&q);
    destory(&q);
    printf("队列已销毁。\n");
}
