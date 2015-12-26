#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
using namespace std;
#define LL long long

vector<int>g;

int main() {
    int T; scanf("%d", &T);
    while(T--) {
        LL n, m;
        scanf("%I64d%I64d", &n, &m);
        int q = n;
        g.clear();
        while(m != 0) {
            if(n % 2 == 1) {
                g.push_back(0);
            }
            else {
                g.push_back(m % 2);
                m /= 2;
            }
            n /= 2;
        }
        LL ans = 0;
        reverse(g.begin(), g.end());
        for(int i = 0; i < g.size(); i++) {
            ans *= 2;
            ans += g[i];
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
