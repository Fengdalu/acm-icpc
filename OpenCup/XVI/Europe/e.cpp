#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;

const int maxn = 3e5 + 10;
struct bit {
    int c[maxn];
    int lowbit(int x) { return x & (-x); }
    void insert(int x, int p) {
        while(x < maxn) {
            c[x] += p;
            x += lowbit(x);
        }
    }

    int get(int x) {
        int tot = 0;
        while(x > 0) {
            tot += c[x];
            x -= lowbit(x);
        }
        return tot;
    }
}c1, c2;
int n, m;
vector<int>g[maxn];
typedef vector<int>::reverse_iterator RIT;
int count(const vector<int> &g, int v) {
    return upper_bound(begin(g), end(g), v) - lower_bound(begin(g), end(g), v);
}

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        x--; y--;
        g[x].push_back(z);
        g[y].push_back(z);
        c2.insert(z + 1, 1);
    }
    for(int i = 0; i < n; i++) sort(g[i].begin(), g[i].end());
    for(int i = 0; i < n; i++)
    if(g[i].size()) {
        int x = *g[i].rbegin();
        cout << "big " << i << " " << x << endl;
        c1.insert(x + 1, 1);
    }
    for(int i = 0; i < n; i++)
    if(g[i].size() >= 2){
        RIT it = g[i].rbegin();
        int y = *(it);
        int x = *(++it);
        cout << i + 1 << " " << x << " " << y << endl;
        if(count(g[i], x) == 1 && count(g[i], y) == 1) {
            int l, r = x;
            if(g[i].size() == 2) l = 0;
            else l = *(++it);
            cout << "bound " << l << " " << r << endl;
            c1.insert(l + 1, 1);
            c1.insert(r, -1);
            c2.insert(l + 1, 1);
            c2.insert(r, -1);
        }
    }
    int sn = 0;
    for(int i = 0; i < n; i++)
    if(g[i].size()) sn++;
    int nq;
    scanf("%d", &nq);
    for(int i = 0; i < nq; i++) {
        int x;
        scanf("%d", &x);
        printf("%d %d\n", sn - c1.get(x), m - c2.get(x));
    }
    return 0;
}

