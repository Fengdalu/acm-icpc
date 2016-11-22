#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;

int cnt[600000];
map<int, int>f, g;
map<int, int>::iterator it;
int tot;
int n, k;

int main() {
    while(~scanf("%d%d", &n, &k)) {
        memset(cnt, 0, sizeof cnt);
        tot = 0;
        for(int i = 0; i < n; i++) {
            int x; scanf("%d", &x);
            if(f.find(x) != f.end()) {
                cnt[f[x]]++;
            }
            else {
                f[x] = tot++;
                cnt[f[x]]++;
            }
            if(cnt[f[x]] == k) cnt[f[x]] = 0;
        }
        for(it = f.begin(); it != f.end(); it++) {
            if(cnt[it->second]) {
                printf("%d\n", it->first);
            }
        }
    }
    return 0;
}
