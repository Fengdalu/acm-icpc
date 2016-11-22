#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int a[1000];
int n;
int m;

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    cin >> m;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    reverse(a, a + n);
    int tot = 0;
    for(int i = 0; i < n; i++) {
        tot++;
        m -= a[i];
        if(m <= 0) break;
    }
    printf("%d\n", tot);
}
