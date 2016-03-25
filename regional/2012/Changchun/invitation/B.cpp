#include <iostream>
#include <cstdio>
#include <set>
#include <map>
#include <vector>
#include <algorithm>

const int maxn = 200000;
std::pair<int, int>a[maxn], b[maxn];
std::multiset<int>s;
typedef std::multiset<int>::iterator itt;
int n;

int main() {
    int T;
    scanf("%d", &T);
    for(int Case = 1; Case <= T; Case++) {
        scanf("%d", &n);
        for(int i = 0; i < n; i++) scanf("%d%d", &a[i].first, &a[i].second);
        for(int i = 0; i < n; i++) scanf("%d%d", &b[i].first, &b[i].second);
        std::sort(a, a + n);
        std::sort(b, b + n);
        s.clear();
        int j = n - 1;
        int ans = 0;
        for(int i = n - 1; i > -1; i--) {
            while(j > -1 && a[j].first >= b[i].first) s.insert(a[j--].second);
            itt it = s.lower_bound(b[i].second);
            if(it != s.end() && *it >= b[i].second) {
                ans++;
                s.erase(it);
            }
        }
        printf("%d\n", ans);
    }
}
