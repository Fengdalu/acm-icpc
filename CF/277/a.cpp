#include <bits/stdc++.h>
using namespace std;
typedef vector<int> VI;
typedef pair<int, int> PII;
#define MP make_pair
#define PB push_back
vector<PII>q;
vector<PII>ans;
int a[4000];
bool vis[4000];
int n;
int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    for(int i = 0; i < n; i++) q.PB(MP(a[i], i));
    sort(q.begin(), q.end());
    for(int i = 0; i < n; i++) a[i] = lower_bound(q.begin(), q.end(), MP(a[i], i)) - q.begin();
    for(int i = 0; i < n; i++) if(a[i] != i && !vis[i]) {
        int k = a[i];
        while(k != i) {
            ans.PB(MP(i, k));
            vis[k] = true;
            k = a[k];
        }
    }
    printf("%d\n", (int)ans.size());
    for(auto &t: ans) printf("%d %d\n", t.first, t.second);
    return 0;
}
