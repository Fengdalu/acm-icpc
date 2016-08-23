#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int a[1000], b[1000];
bool vis[1000];
int n;
inline bool check(vector< pair<int, int> >&q) {
    sort(begin(q), end(q));
    int n = q.size();
    int cur = 0;
    for(int i = 0; i < n; i++) {
        cur = max(cur, q[i].first);
        if(cur > q[i].second) return false;
        cur++;
    }
    return true;
}

inline int run() {
    if(scanf("%d", &n) != 1) return 0;
    memset(vis, 0, sizeof vis);
    for(int i = 0; i < n; i++) scanf("%d%d", &a[i], &b[i]);
    for(int i = n - 1; i >= 0; i--) {
        vector<pair<int, int> >q;
        vis[i] = true;
        for(int j = i; j < n; j++)
        if(vis[j])  q.push_back(make_pair(a[j], b[j]));
        if(check(q)) vis[i] = true;
        else vis[i] = false;
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(vis[i]) ans++;
    }
    memset(vis, 0, sizeof vis);
    for(int i = 0; i < n; i++) {
        vector< pair<int, int> >q;
        for(int j = 0; j < i; j++) {
            if(vis[j]) q.push_back(make_pair(a[j], b[j]));
        }
        for(int j = i + 1; j < n; j++) {
            vector<pair<int, int> >q0 = q;
            q0.push_back(make_pair(a[j], b[j]));
            if(check(q0)) q.push_back(make_pair(a[j], b[j]));
        }
        if(q.size() != ans) vis[i] = true;
        else vis[i] = false;
    }
    printf("%d\n", ans);
    bool flag = false;
    for(int i = 0; i < n; i++) if(vis[i])  {
        if(flag) printf(" %d", i + 1);
        else printf("%d", i + 1);
        flag = true;
    }
    printf("\n");
    return 1;
}

int main() {
    int _T; scanf("%d", &_T);
    while(_T--) run();
    return 0;
}

