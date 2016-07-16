#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

const int maxn = 10010;
int ind[maxn];
int to[maxn * 2], nt[maxn * 2], c[maxn * 2];
int cnt;

int n, k;

void add(int a, int b, int w) {
    to[cnt] = b;
    nt[cnt] = ind[a];
    c[cnt] = w;
    ind[a] = cnt++;
}

int main() {
    while(~scanf("%d%d", &n, &k) && n && k) {
        for(int i = 0; i < n; i++) ind[i] = -1;
        cnt = 0;
        for(int i = 0; i < n - 1; i++) {
            int x, y, z;
            scanf("%d%d%d", &x, &y, &z); x--; y--;
            add(x, y, z); add(y, x, z);
        }

    }
}

