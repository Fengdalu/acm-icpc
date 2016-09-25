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

#define Maxn 101111

int a[Maxn], b[Maxn], n;
int ap[Maxn], bp[Maxn];
int value[Maxn], status[Maxn];
int ans[Maxn];

struct node {
    int u, v, n, next;
}e[Maxn * 2];
int tot, last[Maxn];
map<int, int> S1, S2;

void adde(int u, int v) {
    e[tot].u = u; e[tot].v = v; e[tot].next = last[u]; last[u] = tot++;
}

int getans(int x) {
    //printf("\n\ngetans x %d\n", x);
    int ret = Maxn;
    int i, j, k, u, v, w;
    PII tp;
    if(S1.BG != S1.ED) {
        tp = *(S1.BG);
        cmin(ret, tp.AA - x);
        //printf("getans x %d S1 %d\n", x, ret);
    }
    if(S2.BG != S2.ED) {
        tp = *(S2.BG);
        cmin(ret, tp.AA + x);
        //printf("getans x %d S2 %d\n", x, ret);
    }
    ans[x] = ret;
    return ret;
}

void del(map<int, int> &S, int w) {
    S[w]--;
    if(S[w] == 0) S.erase(w);
}

void change(int x) {
    int i, j, k, u, v, w;
    for(j = last[x]; j != -1; j = e[j].next) {
        v = e[j].v;
        w = value[v];
        if(status[v] == 1) {
            del(S1, w);
            value[v] = -x;
            S2[value[v]]++;
        }
        else {
            del(S2, w);
            //value[v] = 
            S1[value[v]]++;
        }
        status[v] *= -1;
        //printf("0 -> %d status %d value %d\n", v, status[v], value[v]);
    }
    if(status[b[x]] == 1) {
        del(S1, value[b[x]]);
    }
    else if(status[b[x]] == -1){
        del(S2, value[b[x]]);
    }
    bp[b[x]] = n - 1;
    if(ap[b[x]] <= bp[b[x]]) {
       value[b[x]] = x + 1 + bp[b[x]] - ap[b[x]];
       S1[value[b[x]]]++;
       status[b[x]] = 1;
       //printf("tail -> %d status %d value %d\n", b[x], status[b[x]], value[b[x]]);
    } 
}

int main() {
    int i, j, k, u, v, w;

    while(cin >> n) {
        for(i = 0; i < n; i++) {
            cin >> a[i];
            a[i]--;
            ap[a[i]] = i;
        }
        for(i = 0; i < n; i++) {
            cin >> b[i];
            b[i] --;
            bp[b[i]] = i;
        }
        memset(last, -1, sizeof(last));
        tot = 0;
        memset(status, 0, sizeof(status));
        S1.clear(); S2.clear();
        for(i = 0; i < n; i++) {
            if(ap[i] <= bp[i]) {
                adde(bp[i] - ap[i], i);
                value[i] = abs(bp[i] - ap[i]);
                S1[value[i]]++;
                status[i] = 1;
            }
            else {
                adde(n - (ap[i] - bp[i]), i);
                value[i] = abs(bp[i] - ap[i]);
                S2[abs(value[i])]++;
                status[i] = -1;
            }            
        }
        for(i = 0; i < n; i++) {
            getans(i);
            change(i);
        }
        for(i = 0; i < n; i++) printf("%d\n", ans[i]);

    }
    return 0;
}
