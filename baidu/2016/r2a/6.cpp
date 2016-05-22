#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

const int maxn = 100010;
const int maxm = 200010;
int ind[maxn];
int in[maxn];
int to[maxm], nt[maxm];
int cnt;

void add(int a, int b) {
    to[cnt] = b;
    nt[cnt] = ind[a];
    in[b]++;
    ind[a] = cnt++;
}

int main() {
    int T;
    scanf("%d", &T);
    for(int ii = 1; ii <= T; ii++) {
        int n, m;
        scanf("%d%d", &n, &m);
        cnt = 0;
        for(int i = 1; i <= n; i++) ind[i] = -1;
        for(int i = 1; i <= n; i++) in[i] = 0;
        for(int i = 0; i < m; i++) {
            int a, b;
            scanf("%d%d", &a, &b);
            add(a, b);
        }
        priority_queue<pair<int, int> >q;
        for(int i = 1; i <= n; i++)
        if(in[i] == 0) q.push(make_pair(i, i));
        long long tot = 0;
        int ans = 1e9;
        while(q.size()) {
            int x = q.top().second;
            ans = min(ans, x);
            tot += ans;
            q.pop();
            for(int k = ind[x]; k != -1; k = nt[k]) {
                in[to[k]]--;
                if(in[to[k]] == 0) q.push(make_pair(to[k], to[k]));
            }
        }
        cout << tot << endl;
    }
    return 0;
}
