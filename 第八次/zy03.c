#include <stdio.h>
#include <stdlib.h>
typedef struct bithrnode {
    int data;
    int ltag, rtag;
    struct bithrnode *lchild, *rchild;
} bithrnode, *bithree;

int a[20] = {1, 2, 4, 0, 0, 5, 0, 0, 3, 6, 0, 0, 7, 0, 0}, a_i = 0;
bithree pre;

void create(bithree *T) {
    if (a[a_i] == 0) 
	{
        (*T) = NULL;
        a_i++;
    } 
	else 
	{
        (*T) = (bithrnode*) malloc(sizeof(bithrnode));
        (*T)->data = a[a_i];
        a_i++;
        (*T)->ltag = 0;
        (*T)->rtag = 0;
        create(&(*T)->lchild);
        create(&(*T)->rchild);
    }
}

void blz(bithree t) 
{
    if (t) 
	{
        blz(t->lchild);
        printf("%d ", t->data);
        blz(t->rchild);
    }
}

void inthreading(bithree p) {
    if (p != NULL) {
        inthreading(p->lchild);
        if (p->lchild == NULL) {
            p->ltag = 1;
            p->lchild = pre;
        }
        if (pre->rchild == NULL) {
            pre->rtag = 1;
            pre->rchild = p;
        }
        pre = p;
        inthreading(p->rchild);
    }
}

void blzxs(bithree T) {
    bithree p = T->lchild;
    while (p != T) {
        while (p->ltag == 0) {
            p = p->lchild;
        }
        printf("%d ", p->data);
        while (p->rtag == 1 && p->rchild != T) {
            p = p->rchild;
            printf("%d ", p->data);
        }
        p = p->rchild;
    }
}

void blzxs_nx(bithree T) {
    bithree p = T->rchild;
    while (p != T) {
        printf("%d ", p->data);
        if (p->ltag == 1) {
            p = p->lchild;
        } else {
            p = p->lchild;
            while (p->rtag == 0) {
                p = p->rchild;
            }
        }
    }
}

int main(void) {
    bithree t = NULL, s = NULL;
    create(&t);
    blz(t);
    printf("\n");

    s = (bithree) malloc(sizeof(bithrnode));
    s->ltag = 0;
    s->rtag = 1;
    s->rchild = s;
    if (t == NULL)
        s->lchild = s;
    else {
        s->lchild = t;
        pre = s;
        inthreading(t);
        pre->rchild = s;
        pre->rtag = 1;
        s->rchild = pre;
    }

    blzxs(s);
    printf("\n");
    blzxs_nx(s);
    printf("\n");

    return 0;
}
