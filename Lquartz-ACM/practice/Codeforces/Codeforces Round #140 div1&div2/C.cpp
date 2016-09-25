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

LL n, m;

LL calc(LL x, LL y) {
    if(y == 0) return 1;
    if(y == 1) return x;
    LL p = calc(x, y / 2) % m;
    p = p * p % m;
    if(y & 1) p = p * x % m;
    //cout << "calc " << x << " " << y << " " << p << endl;
    return p;
}

int main() {
    int i, j, k;
    LL u, v, w, p, q, r;

    while(cin >> n >> m) {
        if(n == 1) {
            cout << 2 % m << endl;
            continue;
        }
        p = calc(3, n - 1);
        q = p - 1;
        if(q < 0) q += m;
        //cout << p << " " << q << endl << endl;
        cout << (p * 2 + q) % m << endl;
    }
    return 0;
}
