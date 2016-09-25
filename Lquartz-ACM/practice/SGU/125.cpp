#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <bitset>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

#define PB push_back
#define MP make_pair
#define AA first
#define BB second
#define SZ size()
#define BG begin()
#define OP begin()
#define ED end()
#define SQ(x) ((x)*(x))
#define cmax(x, y) x = max(x, y)
#define cmin(x, y) x = min(x, y)

const double eps = 1e-8;
const LL MOD = 1000000007;
int depr[4][20];
int depc[4][20];
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
int a[4][4], b[4][4];
int n;

inline bool inrange(int u, int v) {
    if(u >= 0 && u < n && v >= 0 && v < n) return true;
    else return false;
}

bool check(int u, int v) {
    int x, y;
    int ret = 0;
    for(int i = 0; i < 4; i++) {
        x = u + dx[i], y = v + dy[i];
        if(!inrange(x, y)) continue;
        if(a[u][v] < a[x][y]) ret++;
    }
    return ret == b[u][v];
}

bool dfs(int dep) {
//    cout << "dfs " << dep << endl;
    if(dep == n * n) {
        if(!check(n - 1, n - 1)) return false;
        if(inrange(n - 1, n - 2)) {
            if(!check(n - 1, n - 2)) return false;
        }
        if(inrange(n - 1, n - 3)) {
            if(!check(n - 1, n - 3)) return false;
        }
        
        return true;
    }
    bool ret = false;
    int nx = depr[n][dep], ny = depc[n][dep];
//    cout << "\t " << nx << " " << ny << endl;
    for(int i = 0; i < 9; i++) {
        a[nx][ny] = i;
        if(inrange(nx - 1, ny)) {
//            cout << "\t\t" << "check " << nx - 1 << " " << ny << endl;
            if(!check(nx - 1, ny)) continue;
        }
        ret = dfs(dep + 1);
        if(ret) break;
        a[nx][ny] = -1;
    }
}

int main() {
    int i, j;
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    cin >> n;
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            cin >> b[i][j];
        }
    }
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            a[i][j] = -1;
        }
    }
    depr[1][0] = 0; 
    depc[1][0] = 0;
    depr[2][0] = 0; depr[2][1] = 0; depr[2][2] = 1; depr[2][3] = 1;
    depc[2][0] = 0; depc[2][1] = 1; depc[2][2] = 0; depc[2][3] = 1;
    depr[3][0] = 0; depr[3][1] = 0; depr[3][2] = 1; depr[3][3] = 0; depr[3][4] = 1; 
    depr[3][5] = 2; depr[3][6] = 1; depr[3][7] = 2; depr[3][8] = 2;
    depc[3][0] = 0; depc[3][1] = 1; depc[3][2] = 0; depc[3][3] = 2; depc[3][4] = 1; 
    depc[3][5] = 0; depc[3][6] = 2; depc[3][7] = 1; depc[3][8] = 2; 
    
    if(dfs(0)) {
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                if(j) cout << " ";
                cout << a[i][j];
            }
            cout << endl;
        }
    }
    else {
        cout << "NO SOLUTION" << endl;
    }
    return 0;
}
/*
3
1 2 1
1 2 1
1 1 0

*/
