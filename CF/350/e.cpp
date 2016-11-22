#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

const int maxn = 500010;
char op[maxn];
char s[maxn];
int cp[maxn];
int l[maxn], r[maxn];
int main() {
    int n, m, p;
    scanf("%d%d%d", &n, &m, &p);
    scanf("%s", s + 1);
    scanf("%s", op);
    stack<int>q;
    for(int i = 1; i <= n; i++) {
        if(s[i] == '(') q.push(i);
        else {  cp[i] = q.top(); cp[q.top()] = i; q.pop(); }
    }
    for(int i = 0; i <= n + 1; i++) l[i] = i - 1;
    for(int i = 0; i <= n + 1; i++) r[i] = i + 1;
    for(int i = 0; i < m; i++) {
        char t = op[i];
        if(t == 'L') {  if(l[p] != 0) p = l[p]; }
        else if(t == 'R')  { if(r[p] != n + 1) p = r[p]; }
        else {
            int x = p, y = cp[p];
            if(x > y) swap(x, y);
            x = l[x]; y = r[y];
            r[x] = y; l[y] = x;
            p = max(p, cp[p]);
            if(y > n) p = x;
            else p = y;
        }
    }
    p = 0;
    while(p != n + 1) {
        if(p != 0) printf("%c", s[p]);
        p = r[p];
    }
    return 0;
}

