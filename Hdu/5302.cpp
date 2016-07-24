#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
using namespace std;
#define PII pair<int, int>
#define PII pair<int, int>
#define MP(a, b) make_pair(a, b)
#define PB(x) push_back(x)
#define AA first
#define BB second
#define N 300000
vector<PII>edges;
int vis[N];
int w[3], b[3];
int f1[10], f2[10];
int n;

template<class T> struct QUE
{
    T buf[3000000];
    int l, r;
    QUE() { l = 0; r = -1; }
    void add(T x)
    {
        buf[++r] = x;
    }
    T pop()
    {
        return buf[l++];
    }
    int size()
    {
        return r - l + 1;
    }
    void clear()
    {
        l = 0; r = -1;
    }

    T operator [] (int x) const
    {
        return buf[x];
    }
};

QUE< pair<PII, int> >q;

struct step
{
    int i, s;
    step(int ss): s(ss) { i = 1; }
    int get() { return i; }
    void next()
    {
        i += s;
        if(i > n) i = 2;
    }

    int nt()
    {
         static int j;
         j = i + s;
         if(j > n) j = 2;
         return j;
    }
    int nn()
    {
        static int j;
        j = i + s;
        if(j > n) j = 2;
        j += s;
        if(j > n) j = 2;
        return j;

    }
};

bool dfs(int p)
{
    if(p == edges.size())
    {
        // cout << "ED" << endl;
        int c1[3], c2[3];
        memset(c1, 0, sizeof c1);
        memset(c2, 0, sizeof c2);
        memset(f1, 0, sizeof f1);
        memset(f2, 0, sizeof f2);
        for(int i = 0; i < edges.size(); i++)
        {
            if(vis[i] == -1) continue;
            if(vis[i] == 1) { f1[edges[i].AA]++; f1[edges[i].BB]++; }
            if(vis[i] == 2) { f2[edges[i].AA]++; f2[edges[i].BB]++; }
        }
        for(int i = 1; i <= n; i++)
            if(f1[i] == 0) c1[0]++;
            else if(f1[i] == 1) c1[1]++;
            else if(f1[i] == 2) c1[2]++;

        for(int i = 1; i <= n; i++)
            if(f2[i] == 0) c2[0]++;
            else if(f2[i] == 1) c2[1]++;
            else if(f2[i] == 2) c2[2]++;

//        for(int i = 0; i < 3; i++) cout << c1[i] << " "; cout << endl;
//        for(int i = 0; i < 3; i++) cout << c2[i] << " "; cout << endl;
//        cout << endl;

        for(int i = 0; i < 3; i++) if(c1[i] != w[i]) return false;
        for(int i = 0; i < 3; i++) if(c2[i] != b[i]) return false;
        return true;
    }
    else
    {
        vis[p] = -1;
        if(dfs(p + 1)) return true;

        vis[p] = 1;
        if(dfs(p + 1)) return true;

        vis[p] = 2;
        if(dfs(p + 1)) return true;
        return false;
    }

}

void deal(step s, int f[3], int cc)
 {
    if(f[1] == 0)
    {
        int bg = s.get();
        for(int i = 0; i < f[2] - 1; i++)
        {
            q.add(MP(PII(s.get(), s.nt()), cc));
//            printf("%d %d %d\n", s.get(), s.nt(), cc);
            s.next();
        }
        q.add(MP(PII(bg, s.get()), cc));
    }
    else
    {
        for(int i = 0; i < (f[1] - 2) / 2; i++)
        {
            q.add(MP(PII(s.get(), s.nt()), cc));
//            printf("%d %d %d\n", s.get(), s.nt(), cc);
            s.next(); s.next();
        }
        for(int i = 0; i < f[2] + 2 - 1; i++)
        {
            q.add(MP(PII(s.get(), s.nt()), cc));
//            printf("%d %d %d\n", s.get(), s.nt(), cc);
            s.next();
        }
    }
}

int main()
{
//    freopen("out.txt", "r", stdin);
    int CASE; scanf("%d", &CASE);
    while(CASE--)
    {
        n = 0;
        for(int i = 0; i < 3; i++) scanf("%d", &w[i]);
        for(int i = 0; i < 3; i++) scanf("%d", &b[i]);

//        cout << endl;

        for(int i = 0; i < 3; i++) n += w[i];
        if(n <= 4)
        {
            edges.clear();

            for(int i = 1; i <= n; i++)
                for(int j = i + 1; j <= n; j++)
                    edges.PB(MP(i, j));

            memset(vis, -1, sizeof vis);
            if(dfs(0))
            {
                int cnt = 0;
                for(int i = 0; i < edges.size(); i++) if(vis[i] != -1) cnt++;
                printf("%d\n", cnt);
                for(int i = 0; i < edges.size(); i++)
                {
                    if(vis[i] == -1) continue;
                    else printf("%d %d %d\n", edges[i].AA, edges[i].BB, vis[i] - 1);
                }
            }
            else printf("-1\n");
//            cout << endl;
        }
        else
        {
            if(b[1] % 2 == 1 || w[1] % 2 == 1) { puts("-1"); continue; }
            if(b[2] <= 2 && b[1] == 0 || w[2] <= 2 && w[1] == 0) { puts("-1"); continue; }
            step s1(1), s2(2);
            q.clear();
            deal(s1, b, 1);
            deal(s2, w, 0);
            printf("%d\n", q.size());
            for(int i = 0; i < q.size(); i++)
            {
                printf("%d %d %d\n", q[i].AA.AA, q[i].AA.BB, q[i].BB);
            }
//            cout << endl;
        }
    }
    return 0;
}
