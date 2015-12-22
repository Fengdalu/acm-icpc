#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
#define LL long long
#define ONES(x) __builtin_popcount(x)

int n;
int m;
map<int, int>f;

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    cin >> m;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        x--;
        f[x]++;
    }
    LL tot = 0;
    for(int i = 0; i < (1 << m); i++) if(ONES(i) == 2) {
        LL ans = 1;
        for(int j = 0; j < m; j++) {
            if((1 << j) & i) {
                ans *= f[j];
            }
        }
        tot += ans;
    }
    printf("%I64d\n", tot);
}
