#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define PB(x) push_back(x)
#define OP begin()
#define ED end()
const int N = 2000010;
struct ST
{
    struct node{
        int l, r;
        int a, b;
        int s;
    }f[N];
    int rt, cnt;
    int bt(int a, int b){
        int x = cnt++;
        f[x].a = a; f[x].b = b;
        f[x].s = 0;
        if(a < b){
            int mid = (a + b) / 2;
            f[x].l = bt(a, mid);
            f[x].r = bt(mid + 1, b);
        }
        return x;
    }

    void add(int x, int a, int b, int c)
    {
        if(a <= f[x].a && f[x].b <= b) f[x].s += c;
        else
        {
            int mid = (f[x].a + f[x].b) / 2;
            if(b <= mid) add(f[x].l, a, b, c);
            else if(a > mid) add(f[x].r, a, b, c);
            else { add(f[x].l, a, b, c); add(f[x].r, a, b, c); }
        }
    }

    int query(int x, int p)
    {
        if(f[x].a == f[x].b) return f[x].s;
        else
        {
            int mid = (f[x].a + f[x].b) / 2;
            if(p <= mid) return f[x].s + query(f[x].l, p);
            else return f[x].s + query(f[x].r, p);
        }
    }
}T;
struct node
{
    int L, R;
    int x;
    node() {}
    node(int L, int R, int x) : L(L), R(R), x(x) {}
    bool operator < (const node &p) const
    {
        return x < p.x;
    }
};
vector<node> line;
int n, m, K;
char op[5];
int L;

int main(){
    //freopen("B.in", "r", stdin);
    int _T; scanf("%d", &_T);
    for(int CAS = 1; CAS <= _T; CAS++)
    {
        scanf("%d%d%d", &n, &m, &K);
        int x = 1, y = 1;
        line.clear();
        for(int i = 0; i < K; i++)
        {
            scanf("%s%d", op, &L);
            if(op[0] == 'R') x += L;
            if(op[0] == 'L') x -= L;
            if(op[0] == 'D') { line.PB(node(y + L, y, x)); y += L; }
            if(op[0] == 'U') { line.PB(node(y - L, y, x)); y -= L; }
        }
        sort(line.OP, line.ED);
        int k = 0;

        T.cnt = 0;
        T.rt = T.bt(1, n);
        long long ans = 0;
        for(int x = 1; x <= m; x++)
        {
            while(k < line.size() && line[k].x <= x)
            {
                if(line[k].L < line[k].R) T.add(T.rt, line[k].L, line[k].R - 1, 1);
                else T.add(T.rt, line[k].R, line[k].L - 1, -1);
                k++;
            }
            for(int y = 1; y <= n; y++){
                long long s = abs(T.query(T.rt, y));
                ans += s * s;
            }
        }
        printf("Case #%d: %lld\n", CAS, ans);
    }
    return 0;
}

