#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
#define N 2000000
#define AA first
#define BB second

namespace SA
{
    int len;
    int num[N];  //待处理的串
    int sa[N], rank[N], height[N];    //sa[1~n]value(0~n-1); rank[0..n-1]value(1..n); height[2..n]
    int wa[N], wb[N], wv[N], wd[N];

    int cmp(int *r, int a, int b, int x) {
        return r[a] == r[b] && r[a + x] == r[b + x];
    }

    void da(int *r, int n, int m) {       //  倍增算法 r为待匹配数组  n为总长度+1 m为字符范围
        int i, j, k, p, *x = wa, *y = wb, *t;
        for(i = 0; i < m; i++) wd[i] = 0;
     for(i = 0; i < n; i++) wd[x[i] = r[i]]++;
        for(i = 1; i < m; i++) wd[i] += wd[i - 1];
        for(i = n - 1; i >= 0; i--) sa[--wd[x[i]]] = i;
        for(j = 1, p = 1; p < n; j <<= 1, m = p) {
            for(p = 0, i = n - j; i < n; i++) y[p++] = i;
            for(i = 0; i < n; i++) if(sa[i] >= j) y[p++] = sa[i] - j;
            for(i = 0; i < n; i++) wv[i] = x[y[i]];
            for(i = 0; i < m; i++) wd[i] = 0;
            for(i = 0; i < n; i++) wd[wv[i]]++;
            for(i = 1; i < m; i++) wd[i] += wd[i - 1];
            for(i = n - 1; i >= 0; i--) sa[--wd[wv[i]]] = y[i];
            for(t = x, x = y, y = t, p = 1, x[sa[0]] = 0, i = 1; i < n; i++) {
                x[sa[i]] = cmp(y, sa[i - 1], sa[i], j) ? p - 1 : p++;
            }
        }

        for(i = 0, k = 0; i < n; i++) rank[sa[i]] = i;
        for(i = 0; i < n - 1; height[rank[i++]] = k) {
            for(k ? k-- : 0, j = sa[rank[i] - 1]; r[i + k] == r[j + k]; k++);
        }
    }
}
using namespace SA;

int s[N];
char buf[2000];
bool vis[200];
int LB;
int q[2000];
int cnt;
int n;

bool chk(int l, int r, int len)
{
    memset(vis, 0, sizeof vis);
    int cc = 0;
    for(int i = l; i < r; i++ )
    if(sa[i] != cnt && s[sa[i]] != 0)
    {
        int no = upper_bound(q, q + LB, sa[i]) - q;
        int np = upper_bound(q, q + LB, sa[i] + len - 1) - q;
        if(no != np) continue;
        no--;
        if(!vis[no]) { cc++; }
        vis[no] = true;
    }
    if(cc > n / 2) return true;
    return false;
}

bool ok(int l)
{
    int bg = 0;
    for(int i = 1; i < cnt; i++)
    {
        if(height[i] < l)
        {
            if(chk(bg, i, l)) return true;
            bg = i;
        }
    }
    if(chk(bg, cnt, l)) return true;
    return false;
}

vector<int>ans;
void ok1(int l)
{
    int bg = 0;
    for(int i = 1; i < cnt; i++)
    {
        if(height[i] < l)
        {
            if(chk(bg, i, l)) ans.push_back(sa[i - 1]);
            bg = i;
        }
    }
    if(chk(bg, cnt, l)) ans.push_back(sa[cnt - 1]);
}

int main()
{
//    freopen("input.txt", "r", stdin);
    while(true)
    {
        scanf("%d", &n);
        if(n == 0) break;
        cnt = 0;
        int l = 1, r = 0;
        LB = 0;

        q[LB++] = cnt;
        for(int i = 0; i < n; i++)
        {
            scanf("%s", buf);
            int len = strlen(buf);
            r = max(r, len);

            for(int j = 0; j < len; j++) s[cnt++] = buf[j] - 'a' + 100;
            s[cnt++] = i;
            q[LB++] = cnt;
        }
        cnt--;
        s[cnt] = 0;

        da(s, cnt + 1, 127);

//        cout << "BD: "; for(int i = 0; i < LB; i++) cout << q[i] << " "; cout << endl;
//        cout << "HI: "; for(int i = 0; i < cnt; i++) cout << height[i] << " "; cout << endl;
//        cout << "SA: "; for(int i = 0; i < cnt; i++) cout << sa[i] << " "; cout << endl;

        while(l < r)
        {
            int mid = (l + r) / 2 + 1;
            if(ok(mid)) l = mid;
            else r = mid - 1;
        }
        ans.clear(); ok1(l);
        if(ok(l) && ans.size())
        {
            for(int i = 0; i < ans.size(); i++)
            {
                for(int j = 0; j < l; j++) printf("%c", 'a' + s[j + ans[i]] - 100);
                puts("");
            }
        }
        else puts("?");
        puts("");
    }
    return 0;
}
