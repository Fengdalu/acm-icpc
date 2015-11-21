#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define cmin(x, y) x = min(x, y)

const int Maxn = 200010;
int c[Maxn];
int n;

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &c[i]);
    sort(c, c + n);
    int J = 0;
    int k = (n) / 2;
    for(int i = 0; i + k < n ; i++) if(c[i + k] - c[i] < c[J + k] - c[J])
        J = i;
    int ans = 1000000000;
    printf("%d", c[J + k] - c[J]);
    return 0;
}
