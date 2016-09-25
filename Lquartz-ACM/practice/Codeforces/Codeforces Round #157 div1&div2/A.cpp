#include <bits/stdc++.h>
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

#define Maxn 11

char str[Maxn];

int main() {
    int i, j, k, u, v, w;

    int n = 8;
    int flag = 1;
    for(i = 0; i < n; i++) {
        scanf("%s", str);
        for(j = 1; j < 8; j++) {
            if(str[j] == str[j - 1]) break;
        }
        if(j < n) flag = 0;
    }
    if(flag) printf("YES\n");
    else printf("NO\n");
    return 0;
}
