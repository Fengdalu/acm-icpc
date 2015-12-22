#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define LL long long

int n;
int a[500010];


int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    sort(a, a + n);
    for(int i = 0; i < n; i++) {
        printf("%d\n", a[i]);
    }
    return 0;
}
