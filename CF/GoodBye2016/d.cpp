#include <bits/stdc++.h>

using namespace std;
int t[50];
#define AA first
#define BB second
#define MP make_pair
#define PII pair<int, int>

const int V[][2] = {{0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};


int main() {
    int n; scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &t[i]);
    set<PII> ans;
    set<pair< PII, PII> > cur, tot;
    cur.insert(MP(PII(0, 0), PII(0, t[0] - 1)));

   for(int s = 0; s < n; s++) {
        set<pair<PII, PII> > next;
        for(auto &p: cur) {
            int d = p.BB.AA;
            int x = p.AA.AA, y = p.AA.BB;
            ans.insert(MP(x, y));
            for(int j = 0; j < p.BB.BB; j++) {
                x += V[d][0]; y += V[d][1];
                ans.insert(MP(x, y));
            }
            for(int i = -1; i <= 1; i += 2) {
                int nd = d + i;
                nd = nd + 8;
                nd %= 8;
                if(s != n - 1) {
                    auto state = MP(PII(x, y), PII(nd, t[s + 1]));
                    next.insert(state);
                }
            }
        }
        cur = next;
   }
   printf("%d\n", ans.size());
   return 0;
}
