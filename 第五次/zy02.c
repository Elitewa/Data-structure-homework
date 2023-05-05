#include <stdio.h>

int fun(int hang, int lie)
{
    if (lie == 1 || lie == hang) 
        return 1;
    else
        return fun(hang - 1, lie - 1) + fun(hang - 1, lie); 
}

int main()
{
    int i, j;
    for (i = 1; i <= 9; i++)
    {
        for (j = 1; j <= i; j++)
            printf("%4d", fun(i, j));
        printf("\n");
    }
    return 0;
}
