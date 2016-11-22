#include <bits/stdc++.h>
using namespace std;

pair<int, int>f[200];
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &f[i].first);
    for(int i = 0; i < n; i++) f[i].second = i + 1;;
    sort(f, f + n);
    for(int i = 0; i < n / 2; i++) printf("%d %d\n", f[i].second, f[n - i - 1].second);
    return 0;

}
