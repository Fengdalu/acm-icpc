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

#define Maxn 111111

vector<double> X, Y;
struct rect{
    double x1, x2, y1, y2;
}R[Maxn];
int n;
map<double, int> mp;

struct treenode {
    double sum;
    int cnt;
}tree[Maxn << 2];

#define Left p<<1,pl,mid
#define Right p<<1|1,mid+1,pr

void build(int p, int pl, int pr) {
    int mid = (pl + pr) >> 1;
    tree[p].sum = 0;
    tree[p].cnt = 0;
    if(pl == pr) return;
    build(Left);
    build(Right);
}

void refresh(int p, int pl, int pr, int l, int r) {
    //printf("refresh %d %d %d %d %d\n", p, pl, pr, l, r);
    int mid = (pl + pr) >> 1;
    if(tree[p].cnt) return;
    if(l <= pl && pr <= r) {
        tree[p].cnt = 1;
        tree[p].sum = Y[pr] - Y[pl - 1];
        return;
    }
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
    //printf("refresh %d %d %d %d %d %.f\n", p, pl, pr, l, r, tree[p].sum);
}

int main() {
    int i, j, k, u, v, w;
    int ca = 1;
    while(scanf("%d", &n) != EOF && n) {
        X.clear();
        Y.clear();
        mp.clear();
        for(i = 0; i < n; i++) {
            scanf("%lf%lf%lf%lf", &R[i].x1, &R[i].y1, &R[i].x2, &R[i].y2);
            X.PB(R[i].x1); X.PB(R[i].x2);
            Y.PB(R[i].y1); Y.PB(R[i].y2);
        }
        sort(X.BG, X.ED);
        sort(Y.BG, Y.ED);
        X.erase(unique(X.BG, X.ED), X.ED);
        Y.erase(unique(Y.BG, Y.ED), Y.ED);
        //for(i = 0; i < X.SZ; i++) printf("%f ", X[i]); printf("\n");
        //for(i = 0; i < Y.SZ; i++) printf("%f ", Y[i]); printf("\n");
        for(i = 0; i < Y.SZ; i++) {
            mp[Y[i]] = i;
        }
        double ans = 0;
        for(i = 1; i < X.SZ; i++) {
            build(1, 1, Y.SZ);
            for(j = 0; j < n; j++) {
                if(R[j].x1 <= X[i - 1] && X[i] <= R[j].x2) {
                    refresh(1, 1, Y.SZ, mp[R[j].y1] + 1, mp[R[j].y2]);
                }
            }
            ans += (X[i] - X[i - 1]) * tree[1].sum; 
            //printf("i ans %f %f %f %f\n", ans, X[i - 1], X[i], tree[1].sum);
        }
        printf("Test case #%d\n", ca);
        printf("Total explored area: %.2f\n\n", ans); 
        ca++;
    }

    return 0;
}
