#include <bits/stdc++.h>
using namespace std;

#define PII pair<int, int>
#define AA first
#define BB second
#define MP make_pair
int t;
set<PII>s;
set<int>f[300010];

int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    int cnt = 1;
    for(int i = 1; i <= q; i++) {
        int op, t; scanf("%d%d", &op, &t);
        if(op == 1) {
            f[t].insert(cnt);
            s.insert(MP(cnt, t));
            cnt++;
        }
        else if(op == 2) {
            while(f[t].size()) {
                int g = *f[t].begin();
                s.erase(s.find(MP(g, t)));
                f[t].erase(f[t].begin());
            }
        }
        else if(op == 3) {
            while(s.size()) {
                auto x = *s.begin();
                if(x.first <= t) {
                    s.erase(s.begin());
                    f[x.second].erase(f[x.second].find(x.first));
                }
                else break;
            }
        }
        printf("%d\n", s.size());
    }
    return 0;
}
