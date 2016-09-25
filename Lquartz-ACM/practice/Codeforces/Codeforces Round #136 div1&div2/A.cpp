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

#define Maxn 1011
int a[Maxn];
int n;

int main() {
    int i, j, k, u, v, w;

    while(cin >> n) {
        a[1] = n;
        for(i = 2; i <= n; i++) {
            a[i] = i - 1;
        }
        for(i = 1; i <= n; i++) {
            printf("%d", a[i]);
            if(i == n) printf("\n");
            else printf(" ");
        }
        
    }

    return 0;
}
