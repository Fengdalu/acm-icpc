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

set<int> S1, S2;
set<int> :: iterator its; 
map<int, int> M1, M2;
map<int, int> :: iterator itm;
int h, w, n;

void change(int x, set<int> & S, map<int, int> & M) {
    int i, j, k, u, v, w;
    S.insert(x);
    its = S.find(x);
    u = *(--its); 
    its++; 
    v = *(++its);
    M[v - u]--;
    if(M[v - u] == 0) M.erase(v - u);
    M[v - x]++; M[x - u]++;
}

int main() {
    int i, j, k, u, v, w;
    char op[100];
    while(cin >> w >> h >> n) {
        S1.clear(); S2.clear();
        M1.clear(); M2.clear();
        S1.insert(0); S1.insert(w);
        M1[w] = 1;
        S2.insert(0); S2.insert(h);
        M2[h] = 1;
        for(i = 0; i < n; i++) {
            cin >> op >> u;
            if(op[0] == 'V') {
                change(u, S1, M1);
            }
            else {
                change(u, S2, M2);
            }
            PII tp1 = *(--M1.ED);
            PII tp2 = *(--M2.ED);
            LL ans = 1LL * tp1.AA * tp2.AA;
            cout << ans << endl;
        }
    }

    return 0;
}
