#include <stdio.h>
#include <stdlib.h>

int a[70];
int n;
int per;
int sum;

int swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int dfs(int left, int x)
{
    if (left == 0 && x == 0) return 1;
    if (left == 0) return dfs(per, x - 1);

    int i;
    for (i = 0; i < n; i++)
    {
        if (a[i] > 0 && a[i] <= left)
        {
            a[i] = -a[i];
            int k = dfs(left + a[i], x);
            if ((k) == 1) return 1;
            else if (k == 0)
            {
                a[i] = -a[i];
                if (a[i] == left || left == per) break;
                while (i + 1 < n && a[i + 1] == a[i]) i++;
                if (i == 0) return -1;
            }
            else if(k == -1)
                return -1;
        }
    }

    return 0;
}

int main()
{
    int i, j, k;
    while (1)
    {
        int l = 0;
        int r = 0;
        sum = 0;

        scanf("%d", &n);
        if (n == 0) break;
        for (i = 0; i < n; i++) {scanf("%d", &a[i]); sum += a[i];}

        for (i = 0; i < n - 1; i++)
            for (j = i + 1; j < n; j++)
                if (a[i] < a[j]) swap(&a[i], &a[j]);

        for (per = 1; per <= sum; per++)
            if ((sum % per) == 0 && (dfs(per, sum / per - 1) == 1)) break;

        printf("%d\n", per);
    }

    return 0;
}
