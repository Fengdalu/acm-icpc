#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
#define Maxn 1100000

struct node {
    int c;
    int pre;
}nodes[Maxn];
int n, m;
int p[Maxn], p1[Maxn];
int cnt1, cnt2;
char buf[20];

int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    memset(p, -1, sizeof p);
    memset(p1, -1, sizeof p1);
    cnt1 = 0;
    cnt2 = 1;
    for(int i = 0; i < n; i++) {
        scanf("%s", buf);
        if(buf[0] == 'l') {
            int idx, c; scanf("%d%d", &idx, &c);
            int x = cnt1++;
            nodes[x].c = c;
            nodes[x].pre = p[idx];
            p[idx] = x;
        }
        else if(buf[0] == 'r' && buf[1] == 'o') {
            int idx; scanf("%d", &idx);
            int x = cnt1++;
            if(p[idx] == -1) continue;
            nodes[x].c = nodes[p[idx]].c;
            nodes[x].pre = p1[idx];
            p1[idx] = x;
            p[idx] = nodes[p[idx]].pre;
        }
        else if(buf[0] == 'c' && buf[1] == 'l') {
            int idx = ++cnt2, q;
            scanf("%d", &q);
            p[idx] = p[q];
            p1[idx] = p1[q];
        }
        else if(buf[0] == 'r' && buf[1] == 'e') {
            int idx; scanf("%d", &idx);
            int x = cnt1++;
            if(p1[idx] == -1) continue;
            nodes[x].c = nodes[p1[idx]].c;
            nodes[x].pre = -1;
            nodes[x].pre = p[idx];
            p[idx] = x;
            p1[idx] = nodes[p1[idx]].pre;
        }
        else {
            int idx; scanf("%d", &idx);
            if(p[idx] == -1) puts("basic");
            else printf("%d\n", nodes[p[idx]].c);
        }
    }
    return 0;
}
