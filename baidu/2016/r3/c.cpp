#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <set>
using namespace std;

const int maxn = 100010;
pair<int, int>f[maxn], g[maxn];
int s1[maxn], s2[maxn];
int h[maxn];
int n;

void cmax(int &a, int b) {
   a = max(a, b);
}

int main() {
    int T;
    scanf("%d", &T);
    for(int ii = 1; ii <= T; ii++) {
        scanf("%d", &n);
        for(int i = 0; i <= 2 * n; i++) s1[i] = s2[i] = 0;
        int cnt1 = 0, cnt2 = 0, cnt3 = 0;
        for(int i = 0; i < n; i++) {
            int x, y, z, d;
            scanf("%d%d%d%d", &x, &y, &z, &d);
            int l = y - z, r = x + z;
            if(l > r) continue;
            r++;
            if(d == -1) {
                f[cnt1].first = l;
                f[cnt1].second = 1;
                cnt1++;
                f[cnt1].first = r;
                f[cnt1].second = -1;
                cnt1++;
            }
            else {
                g[cnt2].first = l;
                g[cnt2].second = 1;
                cnt2++;
                g[cnt2].first = r;
                g[cnt2].second = -1;
                cnt2++;
            }
            h[cnt3++] = l;
            h[cnt3++] = r;
        }
        sort(f, f + cnt1);
        sort(g, g + cnt2);
        sort(h, h + cnt3);
        cnt3 = unique(h, h + cnt3) - h;

        int J;
        int cur;

        J = 0; cur = 0;
        for(int i = 0; i < cnt3; i++) {
            s1[i] = 0;
            while(J < cnt1 && f[J].first <= h[i]) {
                cur += f[J].second;
                J++;
            }
            s1[i] += cur;
        }

        J = 0; cur = 0;
        for(int i = 0; i < cnt3; i++) {
            while(J < cnt2 && g[J].first <= h[i]) {
                cur += g[J].second;
                J++;
            }
            s2[i] += cur;
        }
        //for(int i = 0; i < cnt3; i++) cout << h[i] << " "; cout << endl;
        //for(int i = 0; i < cnt3; i++) cout << s1[i] << " "; cout << endl;
        //for(int i = 0; i < cnt3; i++) cout << s2[i] << " "; cout << endl;
        multiset<int>s;
        multiset<int>::iterator it;
        for(int i = 0; i < cnt3; i++) {
            s.insert(s1[i]);
        }
        printf("Case #%d:\n", ii);
        int ans = 0;
        for(int i = 0; i < cnt3; i++) {
            if(s.size()) {
                it = s.end(); it--;
                cmax(ans, (*it) + s2[i]);
            }
            cmax(ans, s1[i]);
            cmax(ans, s2[i]);
            s.erase(s.find(s1[i]));
        }
        printf("%d\n", ans);
    }
    return 0;
}
