#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
typedef long long ll;

char s[1000100];
bool check(char a, char b, char c) {
    if(a == 'y' && b == 'r' && c == 'x') return true;
    if(a == 'x' && b == 'r' && c == 'y') return true;
    return false;
}

int main() {
    int T; scanf("%d", &T);
    while(T--) {
        scanf("%s", s);
        int n = strlen(s);
        int ans = 0;
        for(int i = 0; i < n; i++) {
            ll j = 2;
            while(true) {
                if(1ll * j * j * (i + 1) - 1 >= n) break;
                int nt = (i + 1) * j - 1;
                int ntt = (i + 1) * j * j - 1;
                if(check(s[i], s[nt], s[ntt])) {
                    ans++;
                }
                j++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
