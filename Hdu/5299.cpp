#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <algorithm>
#include <set>
#include <cmath>
#include <vector>
#include <map>
using namespace std;
#define PII pair<int, int>
#define AA first
#define BB second
#define MP(x, y) make_pair(x, y)
#define PII pair<int, int>
#define N 20005
#define PB(x) push_back(x)

int x[N], y[N], r[N];
PII f[2 * N];
int n;
int J;
vector<int>to[N];
int fa[N];


inline int sqr(int x)
{
    return x * x;
}

bool same(double a, double b)
{
    return fabs(a - b) < 1e-9;
}

struct pt
{
    int id, up;
    pt(){}
    pt(int i, int u){id = i; up = u;}

    double h() const
    {
        return y[id] + up * sqrt(sqr(r[id]) - sqr(x[id] - J));
    }
    bool operator < (const pt& b) const
    {
        double p = h();
        double q = b.h();
        return same(p, q) ? up < b.up : p < q;
    }
};
set<pt>s;
set<pt>::iterator iter;

int dfs(int x)
{
//    cout << "R: " << x << endl;
    int sg = 0;
    for(int k = 0; k < to[x].size(); k++)
        sg ^= dfs(to[x][k]);
    return ++sg;
}

int main()
{
    //freopen("input.in", "r", stdin);
    int CASE; scanf("%d", &CASE);
    while(CASE--)
    {
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) scanf("%d%d%d", &x[i], &y[i], &r[i]);
        for(int i = 1; i <= n; i++) f[i] = MP(x[i] - r[i], i);
        for(int i = 1; i <= n; i++) f[i + n] = MP(x[i] + r[i], -i);

        for(int i = 1; i <= n; i++) fa[i] = -1;
        sort(f + 1, f + 2 * n + 1);
        s.clear();
        for(int i = 1; i <= 2 * n; i++)
        {
            J = f[i].AA;
            int id = f[i].BB;
//            if(id > 0) cout << "OOXX" << endl;
//            cout << "IT: "; for(iter = s.begin(); iter != s.end(); iter++) cout << iter->h() << " "; cout << endl;
            if(id > 0)
            {
                s.insert(pt(id, 1));
                iter = s.find(pt(id, 1));
                iter++;
                if(iter == s.end()) fa[id] = -1;
                else { if(iter->up > 0) fa[id] = iter->id; else fa[id] = fa[iter->id]; }

                s.insert(pt(id, -1));
            }
            else
            {
                s.erase(pt(-id, 1));
                s.erase(pt(-id, -1));
            }
        }
        for(int i = 1; i <= n; i++) to[i].clear();
        for(int i = 1; i <= n; i++) if(~fa[i]) to[fa[i]].PB(i);
//        cout << "BOY NEXT DOOR" << endl;
//        for(int i = 1; i <= n; i++) cout << fa[i] << endl; cout << endl;

        int sg = 0;
        for(int i = 1; i <= n; i++) if(fa[i] == -1) sg ^= dfs(i);

        if(sg) printf("Alice\n");
        else printf("Bob\n");
    }
    return 0;
}
