#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;
#define LL long long
#define N 200010
#define PII pair<int, int>
#define MP(x, y) make_pair(x, y)
#define AA first
#define BB second

int A[N], a[N];
int nn, n;
int pk[N];
PII q[N];
set<int>s;
set<int>::iterator iter;

void manacher()
{
    int mx = 0;
    int p;
    for(int i = 0; i < n; i++)
    {
        if(i < mx) pk[i] = min(pk[2 * p - i], mx - i);
        else pk[i] = 1;
        while(i + pk[i] < n && i - pk[i] > -1 && a[i + pk[i]] == a[i - pk[i]]) pk[i]++;
        if(i + pk[i] > mx) { p = i; mx = i + pk[i]; }
    }
}

int main()
{
    freopen("D:/ACM/5371/1003.in", "r", stdin);
    freopen("D:/ACM/5371/output.txt", "w", stdout);

    int CASE; scanf("%d", &CASE);
    for(int T = 1; T <= CASE; T++)
    {
        scanf("%d", &nn);
        for(int i = 0; i < nn; i++) scanf("%d", &A[i]);

        n = 2 * nn + 1;
        for(int i = 0; i < n; i++)
        if(i & 1) a[i] = A[i >> 1];
        else a[i] = -1;

        manacher();
        for(int i = 0; i < n; i++) q[i] = MP(i + pk[i], i);
        sort(q, q + n);

        s.clear();
        int ans = 0;
        int k = 0;
        for(int i = 0; i < n; i++)
        {
            while(k < n && q[k].AA == i) { s.erase(q[k].BB); k++; }
            if(s.size())
            {
                iter = s.lower_bound(i - pk[i] + 1);
                if(iter != s.end() && *iter >= i - pk[i] + 1) ans = max(ans, (i - *iter) / 2 * 3);
            }
            s.insert(i);
        }
        printf("Case #%d: %d\n", T, ans);
    }
    return 0;
}
