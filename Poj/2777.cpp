#include<stdio.h>
#include<stdlib.h>
#define Max(a, b) (a > b)? a : b
#define Min(a, b) (a < b)? a : b


struct obj
{
    int a, b;
    struct obj *l, *r;
    int c, s;
};

struct obj *build (int a, int b)
{
    struct obj *tree;
    struct obj std;
    tree = malloc(sizeof(std));

    (*tree).c = 1;
    (*tree).s = 1;
    (*tree).a = a;
    (*tree).b = b;
    (*tree).l = (*tree).r = NULL;

    if (a < b)
    {
        int mid = (a + b) / 2;
        (*tree).l = build(a, mid);
        (*tree).r = build(mid + 1, b);
    }

    return tree;
}

void insert(struct obj *tree, int a, int b, int c)
{
    if(a <= (*tree).a && (*tree).b <= b)
    {
        (*tree).c = c;
        (*tree).s = 1 << (c - 1);
    }
    else
    {
        if ((*tree).c != -1)
        {
            (*((*tree).l)).c = (*((*tree).r)).c = (*tree).c;
            (*((*tree).r)).s = (*((*tree).l)).s = (*tree).s;
        }

        int mid = ((*tree).a + (*tree).b) / 2;
        if (a <= mid) insert((*tree).l, a, b, c);
        if (mid < b) insert((*tree).r, a, b, c);

        if ((*(*tree).l).c == (*(*tree).r).c) (*tree).c = (*(*tree).r).c;
        else (*tree).c = -1;

        (*tree).s = (*(*tree).l).s | (*(*tree).r).s;
    }
}

int count(struct obj *tree, int a, int b)
{
    if(a <= (*tree).a && (*tree).b <= b)
    {
        return (*tree).s;
    }
    else
    {
        int ss;
        ss = 0;

        if ((*tree).c != -1)
        {
            (*((*tree).l)).c = (*((*tree).r)).c = (*tree).c;
            (*((*tree).r)).s = (*((*tree).l)).s = (*tree).s;
        }

        int mid = ((*tree).a + (*tree).b) / 2;
        if (a <= mid) ss = ss | count((*tree).l, a, b);
        if (mid < b) ss = ss | count((*tree).r, a, b);
        return ss;
    }
}

int trans(int s)
{
    int cnt;
    cnt = 0;
    while (s != 0)
    {
        cnt += s % 2;
        s /= 2;
    }

    return cnt;
}

int main()
{


    int l, t, o;
    char ch;
    int a, b, c;
    struct obj *top;




    scanf("%d%d%d\n", &l, &t, &o);

    top = build(1, l);

    while (o--)
    {
        scanf("%c", &ch);
        if (ch == 'C')
        {
            scanf("%d%d%d\n", &a, &b, &c);
            insert(top, Min(a, b),  Max(b, a), c);
        }
        else
        {
            scanf("%d%d\n", &a, &b);
            printf("%d\n", trans(count(top, Min(a, b), Max(b, a))));
        }
    }

    return 0;
}
