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
#define NAME ""

#define Maxn 101111
#define Step 20

int n, m, q;
int ls[Maxn * Step], rs[Maxn * Step], sum[Maxn * Step];
int newnode;
int root[Maxn];
int org[Maxn], des[Maxn];

void build(int & r, int lt, int rt) {
    r = newnode++;
    sum[r] = 0;
    if(lt == rt) return;
    int mid = (lt + rt) >> 1;
    build(ls[r], lt, mid);
    build(rs[r], mid + 1, rt);
}

void refresh(int & r, int pre, int lt, int rt, int pos) {
    r = newnode++;
    ls[r] = ls[pre];
    rs[r] = rs[pre];
    sum[r] = sum[pre] + 1;
    if(lt == rt) return;
    int mid = (lt + rt) >> 1;
    if(pos <= mid) refresh(ls[r], ls[pre], lt, mid, pos);
    else refresh(rs[r], rs[pre], mid + 1, rt, pos);
}

int query(int l, int r, int lt, int rt, int k) {
    if(lt >= rt) return lt;
    int cnt = sum[ls[r]] - sum[ls[l]];
    int mid = (lt + rt) >> 1;
    if(cnt >= k) return query(ls[l], ls[r], lt, mid, k);
    else return query(rs[l], rs[r], mid + 1, rt, k - cnt);
}

void printtree(int root, int r, int lt, int rt) {
    printf("root %d r %d [%d, %d] sum %d\n", root, r, lt, rt, sum[r]);
    if(lt == rt) return;
    int mid = (lt + rt) >> 1;
    printtree(root, ls[r], lt, mid);
    printtree(root, rs[r], mid + 1, rt);
}

void debugtree() {
    for(int i = 0; i <= n; ++i) {
        printf("tree %d\n", i);
        printtree(i, root[i], 1,  m);
    }
}
int main() {
    int i,j,k,u,v,w;

    //freopen(NAME".in", "r", stdin);
    //freopen(NAME".out", "w", stdout);
    while(scanf("%d%d", &n, &q) != EOF) {
        for(i = 1; i <= n; ++i) {
            scanf("%d", &org[i]);
            des[i] = org[i];
        }
        sort(des + 1, des + n + 1);
        m = unique(des + 1, des + n + 1) - des - 1;
        newnode = 0;
        build(root[0], 1, m);
        for(i = 1; i <= n; ++i) {
            u = lower_bound(des + 1, des + m + 1, org[i]) - des;
            refresh(root[i], root[i - 1], 1, m, u);
        }
        //debugtree();
        for(i = 0; i < q; ++i) {
            scanf("%d%d%d", &u, &v, &k);
            if(u > v) swap(u, v);
            printf("%d\n", des[query(root[u - 1], root[v], 1, m, k)]);
        }
    }

    return 0;
}
