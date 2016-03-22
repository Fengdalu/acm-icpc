#include <iostream>
#include <cstdio>
#include<math.h>
#include <cstring>
#include <algorithm>
#include <algorithm>
#include <queue>

const int maxn = 100010;
const int maxp = 20;
int f[maxn][maxp];
int mm[maxn];
int n, w;

int qpow(int x, int p) {
    int ans = 1;
    while(p) {
        if(p & 1) ans *= x;
        x *= x;
        p /= 2;
    }
    return ans;
}

int get(int l, int r) {
    r--;
    int k = mm[r - l + 1];
    //printf("%d %d %d\n",l,r,k);
    return std::max(f[l][k], f[r - qpow(2, k) + 1][k]);
}

bool check(int r) {
    long long tot = 0;
    for(int i = 0; i < n; i += r) {
        tot += get(i, std::min(n, i + r)) + 1;
    }
    return tot - 1 <= (long long)w;
}

int main() {
    mm[0] = -1;
    for(int i = 1; i < maxn; i++) {
        if((i & (i - 1)) == 0) mm[i] = mm[i - 1] + 1;
        else mm[i] = mm[i - 1];
    }
    scanf("%d%d", &n, &w);
    for(int i = 0; i < n; i++) scanf("%d", &f[i][0]);
    for(int j = 0; j < maxp; j++)
        for(int i = 0; i < n; i++)
        if(i + (1 << (j + 1)) <= n) {
            f[i][j + 1] = std::max(f[i][j], f[i + (1 << j)][j]);
        }
    for(int i=1;i<=n;i++)
    {
        if(check(i))
        {
            printf("%d\n",i);
            return 0;
        }
    }
    return 0;
}