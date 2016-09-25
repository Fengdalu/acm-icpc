//#include <bits/stdc++.h>
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
typedef pair<int,int> PII;
#define MP make_pair
#define PB push_back
#define SZ size()
#define AA first
#define BB second
#define BG begin()
#define ED end()
#define SQ(x) ((x)*(x))
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)

#define Maxn 111

int g[Maxn][Maxn];
int row[Maxn], col[Maxn];
int ur[Maxn], uc[Maxn];
set<PII> S;
int n, m;

int main() {
    int i, j, k, u, v, w;
    while(cin >> n >> m) {
        S.clear();
        memset(ur, 0, sizeof(ur));
        memset(uc, 0, sizeof(uc));
        memset(row, 0, sizeof(row));
        memset(col, 0, sizeof(col));
        for(i = 1; i <= n; i++) {
            for(j = 1; j <= m; j++) {
                cin >> g[i][j];
                row[i] += g[i][j];
                col[j] += g[i][j];
            }
        }
        while(1) {
            S.clear();
            for(i = 1; i <= n; i++) {
                S.insert(MP(row[i], -i));
            }
            for(i = 1; i <= m; i++) {
                S.insert(MP(col[i], i));
            }
            PII tp = *(S.BG);
            //cout << "do " << tp.AA << " " << tp.BB << endl;
            if(tp.AA >= 0) break;
            u = tp.BB;
            if(u < 0) {
                u = -u;
                row[u] *= -1;
                ur[u] ^= 1;
                for(j = 1; j <= m; j++) {
                    if((ur[u] ^ uc[j])== 0) {
                        col[j] = col[j] + 2 * g[u][j];
                    }
                    else {
                        col[j] = col[j] - 2 * g[u][j];
                    }
                }
            }
            else {
                col[u] *= -1;
                uc[u] ^= 1;
                for(i = 1; i <= n; i++) {
                    if((ur[i] ^ uc[u]) == 0) {
                        row[i] = row[i] + 2 * g[i][u];
                    }
                    else {
                        row[i] = row[i] - 2 * g[i][u];
                    }
                }
            }
            //for(i = 1; i <= n; i++) cout << row[i] << " "; cout << endl;
            //for(i = 1; i <= m; i++) cout << col[i] << " "; cout << endl;
        }


        vector<int> used;
        for(i = 1; i <= n; i++) {
            if(ur[i]) used.PB(i);
        }
        printf("%d", used.SZ);
        for(i = 0; i < used.SZ; i++) printf(" %d", used[i]); printf("\n");
        used.clear();
        for(i = 1; i <= m; i++) {
            if(uc[i]) used.PB(i);
        }
        printf("%d", used.SZ);
        for(i = 0; i < used.SZ; i++) printf(" %d", used[i]); printf("\n");
    }

    return 0;
}
