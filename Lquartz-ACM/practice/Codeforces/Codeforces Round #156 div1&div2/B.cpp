
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

#define Maxn 1111111

char str[Maxn];

int sum[300];

int main() {
    int i, j, k, u, v, w;

    while(cin >> str) {
        int len = strlen(str);
        memset(sum, 0, sizeof(sum));
        for(i = 0; i < len; i++) {
            sum[str[i]]++;
        }
        if(sum['x'] > sum['y']) {
            for(i = 0; i < sum['x'] - sum['y']; i++) putchar('x');
            printf("\n");
        }
        else {
            for(i = 0; i < sum['y'] - sum['x']; i++) putchar('y');
            printf("\n");
        }
    }

    return 0;
}
