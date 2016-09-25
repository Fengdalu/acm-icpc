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

int x, d;
int have[11];

int check(int w) {
    int v;
    while(w) {
        v = w % 10;
        w /= 10;
        if(have[v]) return 1;
    }
    return 0;
}

int main() {
    int i, j, k, u, v, w;

    while(cin >> x) {
        w = x;
        memset(have, 0, sizeof(have));
        while(w) {
            v = w % 10;
            w /= 10;
            have[v] = 1;
        }
        d = 0;
        for(i = 1; i * i <= x; i++) {
            if(x % i == 0) {
                if(check(i)) d++;
                j = x / i;
                if(i != j && check(j)) d++;
            }
        }
        cout << d << endl;
    }

    return 0;
}
