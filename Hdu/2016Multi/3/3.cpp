#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <bitset>

using namespace std;

typedef long long LL;
typedef pair<int, int> pii;
typedef pair<pii,int> piii;
typedef pair<LL,LL> pll;
typedef pair<LL,int> pli;
typedef pair<int,LL> pil;

//#pragma comment(linker, "/STACK:102400000,102400000")

#define MP3(x,y,z) make_pair(make_pair(x,y),z)
#define MP make_pair
#define AA first
#define XX first.first
#define YY first.second
#define BB second
#define PB push_back
#define SZ size()
#define dbg(x) cerr <<#x<<" = " << x << endl

const double PI = acos(-1.0);
const LL MOD = 1000000000 + 7;

#define clr(a,b) memset(a,b,sizeof(a))
#define cmin(x,y) x = min(x,y)
#define cmax(x,y) x = max(x,y)
#define ccmin(x,y) {if(~x) x = std::min(x,y);else x = y;}
#define ccmax(x,y) {if(~x) x = std::max(x,y);else x = y;}
#define FOR(i,x) for(int i = 0, __END__ = (int)(x); i < __END__ ; i++)
#define FORR(i,x) for(int i = 1, __END__ = (int)(x); i <= __END__ ; i++)
#define REP(i,x,y) for(int i = (int)(x), __END__ = (int)(y); i <= __END__; i++)

const int MAXN = 1000 + 5;

int a_rook[MAXN][MAXN];
int sum_i_rook[MAXN][MAXN];
int sum_j_rook[MAXN][MAXN];
void dfs_rook(int i, int j)
{
    a_rook[i][j] = 1 ^ (sum_i_rook[i][j - 1] & sum_j_rook[i - 1][j]);
    sum_i_rook[i][j] = sum_i_rook[i][j - 1] & a_rook[i][j];
    sum_j_rook[i][j] = sum_j_rook[i - 1][j] & a_rook[i][j];
}
void init_rook()
{
    clr(a_rook, -1);
    a_rook[1][1] = 0;
    REP(i,2,1000) a_rook[i][1] = a_rook[1][i] = 1;
    REP(i,2,1000) sum_i_rook[i][1] = 1;
    REP(j,2,1000) sum_j_rook[1][j] = 1;
    REP(i,2,1000) REP(j,2,1000)
         dfs_rook(i,j);
}
int a_queen[MAXN][MAXN];
int sum_i_queen[MAXN][MAXN];
int sum_j_queen[MAXN][MAXN];
int sum_ij_queen[MAXN][MAXN];
void dfs_queen(int i, int j)
{
    a_queen[i][j] = 1 ^ (sum_i_queen[i][j - 1] & sum_j_queen[i - 1][j] & sum_ij_queen[i - 1][j - 1]);
    sum_i_queen[i][j] = sum_i_queen[i][j - 1] & a_queen[i][j];
    sum_j_queen[i][j] = sum_j_queen[i - 1][j] & a_queen[i][j];
    sum_ij_queen[i][j] = sum_ij_queen[i - 1][j - 1] & a_queen[i][j];
}
void init_queen()
{
    clr(a_queen, -1);
    a_queen[1][1] = 0;
    REP(i,2,1000) a_queen[i][1] = a_queen[1][i] = 1;
    REP(i,2,1000) sum_i_queen[i][1] = 1;
    REP(j,2,1000) sum_j_queen[1][j] = 1;
    REP(i,1,1000) sum_ij_queen[1][i] = sum_ij_queen[i][1] = 1;
    sum_ij_queen[1][1] = 0;
    REP(i,2,1000) REP(j,2,1000)
         dfs_queen(i,j);
}
int a_king[MAXN][MAXN];
int sum_i_king[MAXN][MAXN];
int sum_j_king[MAXN][MAXN];
void dfs_king(int i, int j)
{
    a_king[i][j] = 1 ^ (a_king[i][j - 1] & a_king[i - 1][j] & a_king[i - 1][j - 1]);
}
void init_king()
{
    clr(a_king, -1);
    a_king[1][1] = 0;
    REP(i,2,1000) a_king[i][1] = a_king[1][i] = (i + 1) & 1;
    REP(i,2,1000) REP(j,2,1000)
         dfs_king(i,j);
}
int a_knight[MAXN][MAXN];
inline int hefa_knight(int i, int j)
{
    if(i >= 1 && j >= 1) return 1;
    return 0;
}

void dfs_knight(int i, int j)
{
    int x = -1;
    int &now = a_knight[i][j];
    vector<int>q;
    if(hefa_knight(i - 2, j - 1)) q.push_back(a_knight[i - 2][j - 1]);
    if(hefa_knight(i - 1, j - 2)) q.push_back(a_knight[i - 1][j - 2]);
    if(q.size() == 1) {
        int x = q[0];
        if(x == 0) now = 1;
        else if(x == 1) now = 0;
        else now = -1;
    }
    else if(q.size() == 2) {
        sort(q.begin(), q.end());
        int a = q[0], b = q[1];
        if(a == 0 || b == 0) now = 1;
        else if(a == 1 && b == 1) now = 0;
        else now = -1;
    }
    else now = -1;
}
void init_knight()
{
    clr(a_knight, -1);
    a_knight[1][1] = 0;
    REP(i,2,1000) REP(j,2,1000)
         dfs_knight(i,j);
}
int main()
{
    init_rook();
    init_king();
    init_queen();
    init_knight();
    /*
    FORR(i,10){FORR(j,10)printf("%d ",a_rook[i][j]);puts("");}puts("");
    FORR(i,10){FORR(j,10)printf("%d ",a_king[i][j]);puts("");}puts("");
    FORR(i,10){FORR(j,10)printf("%d ",a_queen[i][j]);puts("");}puts("");
    FORR(i,10){FORR(j,10)printf("%02d ",a_knight[i][j]);puts("");}puts("");
    */
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int x,y,z;
        scanf("%d%d%d",&z,&x,&y);
        int ans;
        if(z == 1) ans = a_king[x][y];
        if(z == 2) ans = a_rook[x][y];
        if(z == 3) ans = a_knight[x][y];
        if(z == 4) ans = a_queen[x][y];
        if(ans == 1) puts("B");
        else if(ans == 0) puts("G");
        else puts("D");
    }
    return 0;
}
