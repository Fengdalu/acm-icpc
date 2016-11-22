#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <fstream>
using namespace std;
#define LL long long
#define u32  unsigned int
#define AA first
#define BB second
typedef pair<int, int> PII;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define PB(x) push_back(x)
#define SZ size()
#define MP(a, b) make_pair(a, b)
#define OP begin()
#define ED end()
#define CLR clear()
#define INS(x) insert(x)
#define FOR(i, n) for(int i = 0; i < (n); i++)
#define FORR(i, n) for(int i = 1; i <= (n); i++)
#define REP(i, L, R) for(int i = (L); i <= (R); i++)
#define MEM(a) memset(a, 0, sizeof a)
#define ECH(x) for(__typeof x.OP it = x.OP; it != x.ED; it++)
#define ONES(x) __builtin_popcount(x)
/*===========================================================*/

struct node{
    int a[3];
    int id;
    bool operator < (const node& x) const
    {
        return id < x.id;
    }
    bool operator == (const node &x) const
    {
        int t[3], p[3];
        FOR(i, 3) t[i] = x.a[i];
        FOR(i, 3) p[i] = a[i];
        sort(t, t + 3);
        sort(p, p + 3);
        FOR(i, 3) if(t[i] != p[i]) return false;
        return true;
    }
    void print()
    {
        FOR(i, 3) cout << a[i] << " "; cout << endl;
    }

    LL operator * (const node &x) const
    {
        LL ans = 0;
        FOR(i, 3) ans += (LL)x.a[i] * a[i];
        return ans;
    }

    int len()
    {
        FOR(i, 3) if(a[i] != 0) return true;
        return false;
    }
};

int P1[3], P2[3], P3[3], P4[3];

node get(node a, node b)
{
    node p;
    FOR(i, 3) p.a[i] = b.a[i] - a.a[i];
    return p;
}

node add(node a, node b)
{
    node p;
    FOR(i, 3) p.a[i] = a.a[i] + b.a[i];
    return p;
}

node cube[8];
vector<node>ans;
int main()
{
    //freopen("input.in", "r", stdin);
    ios::sync_with_stdio(false);
    FOR(i, 8)
    {
        node x;
        FOR(j, 3) cin >> x.a[j];
        x.id = i;
        cube[i] = x;
    }

    do
    {
        FOR(i, 3) P1[i] = P2[i] = P3[i] = P4[i] = i;
        node O, A, B, C;
        O.id = cube[0].id;
        A.id = cube[1].id;
        B.id = cube[2].id;
        C.id = cube[3].id;
        do{
        FOR(i, 3) C.a[i] = cube[3].a[P4[i]];
        do{
        FOR(i, 3) B.a[i] = cube[2].a[P3[i]];
        do{
        FOR(i, 3) A.a[i] = cube[1].a[P2[i]];
        do{
        FOR(i, 3) O.a[i] = cube[0].a[P1[i]];

            node X = get(O, A);
            node Y = get(O, B);
            node Z = get(O, C);
            if(!X.len() || !Y.len() || !Z.len()) continue;
            if(X * Y != 0LL || Y * Z != 0LL || X * Z != 0LL) continue;
            node P = add(A, Z); P.id = cube[4].id;
            node Q = add(B, Z); Q.id = cube[5].id;
            node R = add(C, add(X, Y)); R.id = cube[6].id;
            node S = add(O, add(X, Y)); S.id = cube[7].id;
            if(P == cube[4] && Q == cube[5] && R == cube[6] && S == cube[7])
            {
                cout << "YES" << endl;
                ans.CLR;
                ans.PB(A); ans.PB(B); ans.PB(C); ans.PB(O); ans.PB(P); ans.PB(Q); ans.PB(R); ans.PB(S);
                sort(ans.OP, ans.ED);
                FOR(i, ans.SZ)
                cout << ans[i].a[0] << " " << ans[i].a[1] << " " << ans[i].a[2] << endl;
                return 0;
            }
        }while(next_permutation(P1, P1 + 3));}
        while(next_permutation(P2, P2 + 3));}
        while(next_permutation(P3, P3 + 3));}
        while(next_permutation(P4, P4 + 3));

    }while(next_permutation(cube + 1, cube + 8));
    cout << "NO" << endl;
    return 0;
}

