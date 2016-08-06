#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;
int main() {
    int _T, n, m;
    scanf("%d", &_T);
    while(_T--) {
        scanf("%d%d", &n, &m);
        long long tot = 0;
        for(int i = 0;i < n; i++) {
            int x;
            scanf("%d", &x); tot += 1ll * x;
        }
        while(m--) {
            ll t; scanf("%I64d", &t);
            if(t > tot) printf("1"); else printf("0");
        }
        printf("\n");
    }
    return 0;
}
