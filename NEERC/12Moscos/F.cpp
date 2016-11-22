#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <set>
#include <bitset>
using namespace std;
#define PII pair<int, int>
#define MP(a, b) make_pair(a, b)
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define PB(x) push_back(x)
#define SZ size()
#define LL long long
#define PB(x) push_back(x)
#define FOR(i, n) for(int i = 0; i < n; i++)
#define FORR(i, n) for(int i = 1; i <= n; i++)
#define N 10010

vector<int> G[N];
int K;
double P[N], A[N];
int in[N];
int n;
int X, Y, Z;
deque<int>q;
char buf[100];

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> K;
    FORR(i, n) cin >> P[i] >> A[i];
    FORR(i, n) G[i].clear();
    FORR(i, K) { int x, y; cin >> x >> y; G[x].PB(y); in[y]++; }
    FORR(i, n) if(!in[i]) q.PB(i);
    int X, Y, Z; cin >> X >> Y >> Z;
    A[X] += (double)Y;
    while(!q.empty())
    {
        int x = q.front(); q.pop_front();
        double s = 0;
        if(A[x] > P[x])
        {
            s = A[x] - P[x]; A[x] -= s;
            if(G[x].SZ)s /= (double)G[x].SZ; else s = 0.0;
        }
        FOR(i, G[x].SZ)
        {
            A[G[x][i]] += s;
            in[G[x][i]]--;
            if(in[G[x][i]] == 0) q.PB(G[x][i]);
        }
    }
    sprintf(buf, "%.6f", A[Z]);
    cout << buf << endl;
}