#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <set>
#include <map>
#include <queue>
using namespace std;
#define INF (1 << 63)
#define MP(x, y) make_pair(x, y)
#define PLI pair<LL, int>
#define PII pair<int, int>
#define AA first
#define BB second
#define LL long long
const int N = 300000;

int l[N], r[N];
LL c[N];
LL f[N];
int n;
set<PLI> s2;
set<PII> s1;
set<PII>::iterator bg, ed, iter;
template <class T> struct QQ
{
    T buf[N];
    int l, r;
    QQ()
    {
        l = 0; r = -1;
    }
    T top()
    {
        return buf[l];
    }
    void pop()
    {
        l++;
    }
    void add(T x)
    {
        buf[++r] = x;
    }
    void init()
    {
        l = 0; r = -1;
    }

    int size()
    {
        return r - l + 1;
    }
};

QQ<int>q2;

int main()
{
//    freopen("1009.in", "r", stdin);
//    freopen("output.txt", "w", stdout);
    int CASE; scanf("%d", &CASE);
    while(CASE--)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++) scanf("%d", &l[i]);
        for(int i = 0; i < n; i++) scanf("%d", &r[i]);
        for(int i = 0; i < n; i++) scanf("%I64d", &c[i]);
        for(int i = 0; i < n; i++) f[i] = INF;
        f[0] = c[0];
        s2.insert(MP(f[0], 0));
        s1.clear();
        for(int i = 1; i < n; i++) s1.insert(PII(i + 1, i));

        while(s2.size())
        {
            int p = s2.begin()->BB; s2.erase(s2.begin());

            int pos = p + 1; q2.init();
            bg = s1.lower_bound(MP(pos - r[p], -1));
            ed = s1.upper_bound(MP(pos - l[p], 1e9));
            for(iter = bg; iter != ed; iter++)
            {
                f[iter->BB] = f[p] + c[iter->BB];
                q2.add(iter->BB);
                s2.insert(MP(f[iter->BB], iter->BB));
            }

            bg = s1.lower_bound(MP(pos + l[p], -1));
            ed = s1.upper_bound(MP(pos + r[p], 1e9));
            for(iter = bg; iter != ed; iter++)
            {
                f[iter->BB] = f[p] + c[iter->BB];
                s2.insert(MP(f[iter->BB], iter->BB));
                q2.add(iter->BB);
            }

            while(q2.size()) { int x = q2.top(); q2.pop(); s1.erase(s1.find(MP(x + 1, x)));  }
        }
//        cout << CASE << endl;
        for(int i = 0; i < n; i++) { if(i != 0) printf(" "); if(f[i] == INF) printf("-1"); else printf("%I64d", f[i] - c[i]);  } printf("\n");
    }
    return 0;
}
