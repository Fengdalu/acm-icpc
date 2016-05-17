#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int n;
int main() {
    int ans = 1e9;
    scanf("%d", &n);
    long long sum = 0;
    map<long long, int>d;
    for(int i = 0; i < n; i++) {
        int x; scanf("%d", &x);
        sum += x;
        d[sum]++;
        ans = min(ans, n - d[sum]);
    }
    cout << ans << endl;
    return 0;
}
