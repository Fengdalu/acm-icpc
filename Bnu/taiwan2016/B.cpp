#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

struct node {
    int L, R;
    int w;
} T[10000000];
int cnt = 0;
const int N = 1e5+100;
const int DEEP = 30;
int n;
typedef long long ll;

int newNode() {
    cnt++;
    T[cnt].L = T[cnt].R = -1;
    return cnt;
}

void insert(int &p, int d, int w) {
    if(p == -1) {
        p = newNode();
    }
    if(d == -1) {
        T[p].w = w;
        return ;
    }
   if((~w >> d) & 1) insert(T[p].L, d - 1, w);
    else insert(T[p].R, d - 1, w);
}

int TL;
int a[N];
void go(int &p, int d) {
    if(p == -1) return;
    if(d == -1) {
        a[TL++] = T[p].w;
        return;
    }
    go(T[p].L, d - 1);
    go(T[p].R, d - 1);
}

const int INF = 1 << 30;
ll cal(int &p, int d, int w) {
    node &P = T[p];
    if(P.R == -1 && P.L == -1) {
        return w ^ P.w;
    }
    if(w >> d & 1) {
        if(P.R != -1) return cal(P.R, d - 1, w);
        else return cal(P.L, d - 1, w);
    }
    else {
        if(P.L != -1) return cal(P.L, d - 1, w);
        else return cal(P.R, d - 1, w);
    }
}

ll ans;
void solve(int &p, int d) {
    if(p == -1) return ;
    node &P = T[p];
    solve(P.L, d - 1);
    solve(P.R, d - 1);
    TL= 0;
    if(P.R == -1) return;
    go(P.L, d - 1);
    if(!TL)  return;
    ll T = 1 << 30;
    for(int i = 0; i < TL; i++) {
        T = std::min(T, cal(P.R, d - 1, a[i]));
    }
    ans += T;
}

int main() {
    int n; scanf("%d", &n);
    int rt = -1;
    while(n--) {
        int x; scanf("%d", &x);
        insert(rt, DEEP, x);
    }
    ans = 0;
    solve(rt, DEEP);
    printf("%lld\n", ans);
    return 0;
}
