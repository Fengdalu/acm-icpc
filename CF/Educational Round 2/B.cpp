#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
#define LL long long

int a[200010], b[200020];
int n, m;

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];
    sort(a, a + n);
    for(int i = 0; i < m; i++) cout << (upper_bound(a, a + n, b[i]) - a) << " ";
    return 0;
}
