/* Author: Tomas Tunys
 * Solution: O(N^2*log(N)), N = max{S, M, D}
 */
#include <stdio.h>
#include <stdlib.h>
 
#define MAXITEMS 5000
 
 
int cmp(const void * x, const void *y)
{
    return (*(int*)x) - (*(int*)y);
}
 
int find(int *a, int l, int r, int w)
{
    int m;
 
    while (l < r)
    {
        m = (l + r) / 2;
 
        if (a[m] <= w)
            l = m + 1;
        else
            r = m - 1;
    }
 
    return (r < 0) ? 0 : r + (a[r] <= w);
}
 
/* Swap the array pointers and corresponding array sizes
 * such that ``a`` has shorter length than ``b``.
 */
void swap(int **a, int *sa, int **b, int *sb)
{
    int *c, sc;
 
    if (*sb < *sa)
    {
        c  = *a;
        sc = *sa;
        *a  = *b;
        *sa = *sb;
        *b  = c;
        *sb = sc;
    }
}
 
int i, j, L, S, M, D, B, *s, *m, *d, *b;
int p[4 * MAXITEMS], pp[2][MAXITEMS * MAXITEMS], npp[2];
long long ans;
 
int main(void)
{
    /* Forever... :) */
    while (1)
    {
        /* Read the budget and sizes of individual sets of meals. */
        scanf("%d %d %d %d %d", &L, &S, &M, &D, &B);
 
        /* "EOF" reached? */
        if(L == 0 && S == 0 && M == 0 && D==0 && B==0)
            break;
 
        /* Prepare the answer for the current test case. */
        ans = 0;
 
        /* Read the prices of individual meals. */
        for (i = 0; i < S + M + D + B; i++)
            scanf("%d", &p[i]);
 
        /* Use auxiliary array pointers to sort the sets
         * of meals by their cardinalities.
         */
        s = p;
        m = s + S;
        d = m + M;
        b = d + D;
 
        /* Sort the sets such that the number of pairs
         * S * M + D * B is smallest possible.
         */
        swap(&s, &S, &m, &M);
        swap(&m, &M, &d, &D);
        swap(&d, &D, &b, &B);
        swap(&s, &S, &m, &M);
        swap(&m, &M, &d, &D);
        swap(&s, &S, &m, &M);
        swap(&m, &M, &b, &B);
 
        npp[0] = S * M;
        for (i = 0; i < S; i++)
            for (j = 0; j < M; j++)
                pp[0][i * M + j] = s[i] + m[j];
 
        npp[1] = D * B;
        for (i = 0; i < D; i++)
            for (j = 0; j < B; j++)
                pp[1][i * B + j] = d[i] + b[j];
 
        /* Sort the prices of the pairs of meals... */
        qsort(pp[1], npp[1], sizeof(int), cmp);
 
        /* ... and find out how many prices of quadruples of meals
         * fall under the given budget.
         */
        for (i = 0; i < npp[0]; i++)
            ans = (ans + find(pp[1], 0, npp[1] - 1, L - pp[0][i]));
 
        printf("%lld\n", ans);
    }
 
    return 0;
}
