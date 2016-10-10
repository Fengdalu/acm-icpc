#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define cmax(x, y) x = std::max(x, y)
#define mp std::make_pair
typedef long long ll;
typedef std::pair<ll, ll> pii;

const int N = 20000;
struct node {
    int no;
    int id;
} stu[N];
std::vector<int> o[N];
std::vector<int> p[N];
int op[N];
int n, m, k;
ll tot[N];
ll ans[N];
int cur[N];

int cmp(node a, node b) {
    int s1 = op[a.id];
    int s2 = op[b.id];
    if(s1 == s2) return a.no < b.no;
    return s1 < s2;
}

int main() {
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 0; i < n; i++) {
        int P;
        scanf("%d%d%d", &stu[i].no, &op[i], &P);
        stu[i].id = i;
        for(int j = 0; j < P; j++) {
            int a, b;
            scanf("%d%d", &a, &b);
            o[i].push_back(a);
            p[i].push_back(b);
        }
    }
    std::priority_queue<std::pair<ll, pii>,
        std::vector< std::pair<ll, pii> >,
        std::greater< std::pair<ll, pii> > >q;

    for(int i = 0; i < n; i++) {
        int id = stu[i].id;
        ans[id] = op[id];
        q.push(mp(ans[id] + k, mp(stu[id].no, stu[id].id)));
    }
    while(q.size()) {
        std::pair<ll, pii> t = q.top(); q.pop();
        int id = t.second.second;
        int &nt = cur[id];
        ll s = std::max(tot[o[id][nt]], k + ans[id]) + p[id][nt];
        tot[o[id][nt]] = s;
        ans[id] = s;
        nt++;
        if(nt == o[id].size()) continue;
        q.push(mp(ans[id] + k, mp(stu[id].no, id)));
    }
    for(int i = 0; i < n; i++) std::cout << ans[i] << std::endl;
    return 0;
}

