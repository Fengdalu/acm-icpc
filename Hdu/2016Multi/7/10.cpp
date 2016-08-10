#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

int a[300020], nt[300020];
int vis[300020];
char op[30];
int ta, ba, tb, bb;
int TL;
int cnt;

int main() {
    int n, cas = 1;
    while(~scanf("%d", &n)) {
        if(n == 0) break;
        int cnt = 0;
        int last = -1;
        TL = -1;
        ta = -1; tb = -1;
        printf("Case #%d:\n", cas++);
        memset(vis, 0, sizeof vis);
        for(int i = 0; i < n; i++) {
            scanf("%s", op);
            if(op[1] == 'u') {
                int x;
                scanf("%s%d", op, &x);
                int r = cnt++;
                a[r] = x;
                nt[r] = -1;
                if(op[0] == 'A') {
                    if(ta == -1) {
                        ta = r;
                        ba = r;
                    }
                    else {
                        nt[r] = ta;
                        ta = r;
                    }
                }
                else {
                    if(tb == -1) {
                        tb = r;
                        bb = r;
                    }
                    else {
                        nt[r] = tb;
                        tb = r;
                    }
                }
            }
            else if(op[1] == 'o') {
                scanf("%s", op);
                if(op[0] == 'A') {
                    if(ta == -1) {puts("baka"); continue;}
                    printf("%d\n", a[ta]);
                    vis[ta] = true;
                    if(ta == last) last = nt[last];
                    ta = nt[ta];
                }
                else {
                    if(tb == -1) {puts("baka"); continue;}
                    printf("%d\n", a[tb]);
                    vis[tb] = true;
                    if(tb == last) last = nt[last];
                    tb = nt[tb];
                }
            }
            else {
                scanf("%s", op);
                if(ta == -1 || tb == -1) {
                    int c = max(ta, tb);
                    ta = tb = -1;
                    if(op[0] == 'A') ta = c;
                    else tb = c;
                    scanf("%s", op); continue;
                }
                int pre = -1;
                int g = -1;
                for(int j = cnt - 1; j > TL; j--) if(!vis[j]) {
                    if(pre != -1) nt[pre] = j;
                    if(g == -1) g = j;
                    pre = j;
                }
                if(pre != -1) nt[pre] = last;
                last = g;
                TL = cnt - 1;
                if(op[0] == 'A') {
                    ta = g;
                    tb = -1;
                }
                else {
                    tb = g;
                    ta = -1;
                }
                scanf("%s", op);
            }
        }
    }
    return 0;
}
