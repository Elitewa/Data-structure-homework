#include "stdio.h"
#define M 7
#define N 7
#define MaxSize (M-2)*(N-2)

struct
{
    int x, y;
    int pre;
} Que[MaxSize];

struct
{
    int dx, dy;
} wy[4] = {0, 1, 1, 0, 0, -1, -1, 0};

void printpath(int);
void MazePath(int mg[M][N], int x1, int y1, int x2, int y2)
{
    int front = -1, rear = 0;
    int x, y, find = 0, di;
    Que[rear].x = x1;
    Que[rear].y = y1;
    Que[rear].pre = -1;
    mg[x1][y1] = 2;
    while (front != rear && !find)
    {
        find = 0;
        front++;
        x = Que[front].x;
        y = Que[front].y;
        if (x == x2 && y == y2)
        {
            find = 1;
            printf("success!\n");
            printpath(front);
            break;
        }
        for (di = 0; di <= 3; di++)
        {
            x = Que[front].x + wy[di].dx;
            y = Que[front].y + wy[di].dy;
            if (mg[x][y] == 0)
            {
                rear++;
                Que[rear].x = x;
                Que[rear].y = y;
                Que[rear].pre = front;
                mg[x][y] = 2;
            }
        }
    }
    if (find == 0)
        printf("no success!\n");
}

void printpath(int front)
{
    int k = front, pre;
    while (k != 0)
    {
        pre = Que[k].pre;
        Que[k].pre = -1;
        k = pre;
    }

    printf("Â·¾¶ÈçÏÂ£º\n");
    k = 0;
    while (k <= front)
    {
        if (Que[k].pre == -1)
            printf("%d %d\n", Que[k].x, Que[k].y);
        k++;
    }
}

int main()
{
    int maze[M][N] = {
        {1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 1, 0, 1},
        {1, 0, 1, 1, 1, 0, 1},
        {1, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 0, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1}};
    MazePath(maze, 1, 1, 5, 5);
    return 0;
}
