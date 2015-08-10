#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;
#define LL long long
#define PB(x) push_back(x)
#define MP(x, y) make_pair(x, y)
#define PII pair<int, int>
#define AA first
#define BB second
#define N 1000100

namespace BIT
{
    int c[N];
    void init()
    {
        memset(c, 0, sizeof c);
    }
    int lowbit(int x) { return (x & (-x)); }
    void add(int x, int cc)
    {
        while(x < N)
        {
            c[x] += cc;
            x += lowbit(x);
        }
    }

    int cal(int x)
    {
        int ans = 0;
        while(x)
        {
            ans += c[x];
            x -= lowbit(x);
        }
        return ans;
    }
}

int a[N];
int c[N];
int n, m;
int op;
int len;
int lll;

void insert(int op)
{
    len++;
    c[len] = op;
    BIT::add(len, 1);
    lll++;
}

int find(int pos)
{
    int l = 1, r = len;
    while(l < r - 1)
    {
        int mid = (l + r) / 2;
        if(BIT::cal(mid) < pos) l = mid;
        else r = mid;
    }
//    cout << "LR" << l << " " << r  << endl;
    if(BIT::cal(l) == pos) return l;
    else if(BIT::cal(r) == pos) return r;
    return -1;
}

bool remove(int pos)
{
    int p = find(pos);
    if(p != -1)
    {
//        cout << "REMOVE " << pos << " " << p << endl;
        BIT::add(p, -1);
        lll--;
        return true;
    }
    return false;
}

int main()
{
//    freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++) scanf("%d", &a[i]);
    BIT::init();

    len = lll = 0;
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &op);
        if(op >= 0) insert(op);
        else
        {
            int pos = lower_bound(a, a + m, lll) - a;
            pos = min(pos, m - 1);
            for(int j = pos; j > -1; j--) remove(a[j]);
        }
//        cout << "POS "; for(int i = 1; i <= lll; i++) cout << find(i) << " "; cout << endl;
//        cout << "VAL "; for(int i = 1; i <= lll; i++) if(c[find(i)] == 0) printf("0 "); else printf("1 "); printf("\n");
//        cout << "ADD "; for(int i = 1; i <= len; i++) if(BIT::cal(i) - BIT::cal(i - 1) == 0) printf("0 "); else printf("1 "); printf("\n");
//        cout << "END" << endl << endl;
    }
//    cout << find(6) << endl;
    if(!lll) printf("Poor stack!");
    else for(int i = 1; i <= lll; i++) if(c[find(i)] == 0) printf("0"); else printf("1"); printf("\n");
    return 0;
}