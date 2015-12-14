#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define PII pair<int, int>
#define AA first
#define BB second
#define MP(x, y) make_pair(x, y)
#define SZ size()
#define PB(x) push_back(x)
#define OP begin()
#define ED end()
#define CLR clear()

struct node {
    int l, r;
    bool flg;
}f[30000 * 50];
int cnt;

int Node() {
    f[cnt].l = f[cnt].r = -1;
    f[cnt].flg = false;
    return cnt++;
}
int n;
vector<PII>ans;

void dfs(int x, PII s) {
    if(x == -1) {
        ans.PB(s);
        return;
    }
    if(f[x].flg) return;
    if(f[x].l == -1 && f[x].r == -1) {
        ans.PB(s);
    }
    dfs(f[x].l, PII(s.AA, s.BB + 1));
    dfs(f[x].r, PII(s.AA | (1 << (31 - s.BB)), s.BB + 1));
}
char buf[100];

int main() {
    //freopen("I.in", "r", stdin);
    int T;
    scanf("%d", &T);
    for(int _C = 1; _C <= T; _C++) {
        scanf("%d", &n);
        cnt = 0;
        int rt = Node();
        int a, b, c, d, e;
        for(int i = 0; i < n; i++) {
            scanf("%s", buf);
            if(!strcmp(buf, "0.0.0.0")) {
                a = b = c = d = e = 0;
            } else
            sscanf(buf, "%d.%d.%d.%d/%d", &a, &b, &c, &d, &e);
            unsigned ip = (a << 24) + (b << 16) + (c << 8) + d;
            int pos = 31;
            int x = rt;
            for(int j = 0; j < e; j++) {
                if(ip & (1 << pos)) {
                    if(f[x].r == -1) f[x].r = Node();
                    x = f[x].r;
                }else {
                    if(f[x].l == -1) f[x].l = Node();
                    x = f[x].l;
                }
                pos--;
            }
            f[x].flg = true;
        }

        ans.CLR;
        dfs(rt, PII(0, 0));
        unsigned mask = 255;
        printf("Case #%d:\n", _C);
        if(n == 0) {
            printf("1\n");
            printf("0.0.0.0/0\n");
            continue;
        }
        printf("%d\n", ans.SZ);
        for(int i = 0; i < ans.SZ; i++) {
            unsigned ip = ans[i].AA;
            int a, b, c, d;
            d = ip & mask;
            ip >>= 8;
            c = ip & mask;
            ip >>= 8;
            b = ip & mask;
            ip >>= 8;
            a = ip;
            printf("%d.%d.%d.%d/%d\n", a, b, c, d, ans[i].BB);
        }
    }
    return 0;
}
