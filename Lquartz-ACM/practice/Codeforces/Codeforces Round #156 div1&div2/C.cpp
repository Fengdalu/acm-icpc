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

#define Maxn 41111
vector<int> a, b, g[Maxn];
map<int,int> mp;
int mmp[Maxn];
int n;

int calc(int ii, int jj) {
    int i, j, k, u, v, cnt = 1;
    i = 1; j = 0;
    u = g[ii][0];
    v = -1;
    while(i < g[ii].SZ || j < g[jj].SZ) {
        //printf("i %d j %d cnt %d u %d v %d\n", i, j, cnt, u, v);
        if(cnt & 1) {
            while(j < g[jj].SZ) {
                if(g[jj][j] > u) {
                    break;
                }
                j++;
            }
            if(j >= g[jj].SZ) {
                return cnt;
            }
            cnt++;
            v = g[jj][j];
            j++;
        }
        else {
            while(i < g[ii].SZ) {
                if(g[ii][i] > v) {
                    break;
                }
                i++;
            }
            if(i >= g[ii].SZ) {
                return cnt;
            }
            u = g[ii][i];
            cnt++;
            i++;
        }
    }
    return cnt;
}

int main() {
    int i, j, k, u, v, w;

    while(cin >> n) {
        a.clear();
        b.clear();
        for(i = 0; i < n; i++) {
            cin >> w;
            a.PB(w);
            b.PB(w);
        }
        sort(b.BG, b.ED);
        mp.clear();
        b.erase(unique(b.BG, b.ED), b.ED);
        for(i = 0; i < b.SZ; i++) {
            mp[b[i]] = i + 1;
            mmp[i + 1] = b[i];
        }
        for(i = 0; i < n; i++) a[i] = mp[a[i]];
        for(i = 0; i <= n; i++) g[i].clear();
        for(i = 0; i < n; i++) {
            g[a[i]].PB(i);
        }
        for(i = 0; i <= b.SZ; i++) {
            //for(j = 0; j < g[i].SZ; j++) printf(" %d", g[i][j]);
            //printf("\n");
        }
        int ans = 1;
        for(i = 1; i <= b.SZ; i++) cmax(ans, (int)g[i].SZ);
        for(i = 1; i <= b.SZ; i++) {
            for(j = 1; j <= b.SZ; j++) {
                if(j == i) continue;
                //printf("calc i %d j %d %d \n", i, j, calc(i, j));
                cmax(ans, calc(i, j));
            }
        }
        cout << ans << endl;
    }


    return 0;
}
