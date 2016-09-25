//#include <bits/stdc++.h>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
using namespace std;

typedef long long LL;
typedef pair<int,int> PII;
#define MP make_pair
#define PB push_back
#define SZ size()
#define AA first
#define BB second
#define BG begin()
#define ED end()
#define SQ(x) ((x)*(x))
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)

#define Maxn 1011
struct treenode {
    int sum, cnt;
}tree[Maxn << 2];
vector<int> X, Y;
struct rect{
    int x1, x2, y1, y2;
}r[Maxn];
int mp[555555];
int n;

#define Left p<<1,pl,mid
#define Right p<<1|1,mid+1,pr

void build(int p, int pl, int pr) {
    tree[p].sum = tree[p].cnt = 0;
    if(pl == pr) return;
    int mid = (pl + pr) >> 1;
    build(Left);
    build(Right);
}

void refresh(int p, int pl, int pr, int l, int r) {
    //printf("refresh %d %d %d %d %d\n", p, pl, pr, l, r);
    if(tree[p].cnt) return;
    if(l <= pl && pr <= r) {
        tree[p].cnt = 1;
        tree[p].sum = Y[r] - Y[l - 1];
        return;
    }
    int mid = (pl + pr) >> 1;
    if(r <= mid) {
        refresh(Left, l, r);
    }
    else if(l > mid) {
        refresh(Right, l, r);
    }
    else {
        refresh(Left, l, mid);
        refresh(Right, mid + 1, r);
    }
    tree[p].sum = tree[p<<1].sum + tree[p<<1|1].sum;
    //printf("refresh %d %d %d %d %d %d\n", p, pl, pr, l, r, tree[p].sum);
}

int main() {
    int i, j, k, u, v, w;
    while(true) {
        n = 0;
        while(true) {
            scanf("%d%d%d%d", &i, &j, &u, &v);
            if(i == -1 && j == -1 && u == -1 && v == -1) {
                break;
            }
            r[n].x1 = i; r[n].y1 = j;
            r[n].x2 = u; r[n].y2 = v;
            n++;
        }
        if(n == 0) break;
        X.clear(); Y.clear();
        for(i = 0; i < n; i++) {
            X.PB(r[i].x1); X.PB(r[i].x2);
            Y.PB(r[i].y1); Y.PB(r[i].y2);
        }
        sort(X.BG, X.ED);
        sort(Y.BG, Y.ED);
        X.erase(unique(X.BG, X.ED), X.ED);
        Y.erase(unique(Y.BG, Y.ED), Y.ED);
        //for(i = 0; i < X.SZ; i++) printf("%d ", X[i]); printf("\n");
        //for(i = 0; i < Y.SZ; i++) printf("%d ", Y[i]); printf("\n");
        for(i = 0; i < Y.SZ; i++) mp[Y[i]] = i;
        LL ans = 0;
        for(i = 1; i < X.SZ; i++) {
            build(1, 1, Y.SZ);
            for(j = 0; j < n; j++) {
                if(r[j].x1 <= X[i - 1] && X[i] <= r[j].x2) {
                    refresh(1, 1, Y.SZ, mp[r[j].y1] + 1, mp[r[j].y2]);
                }
            }
            ans += 1LL * (X[i] - X[i - 1]) * tree[1].sum;
        }
        cout << ans << endl;
    }
    return 0;
}
