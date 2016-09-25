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

#define Maxn 111111

char str[Maxn];
int len;

int main() {
    int i, j, k, u, v, w;
    while(cin >> str) {
        len = strlen(str);
        for(i = 0, j = 0; i < len - 1; i++) {
            if(!j && str[i] == '0') {
                j = 1;
            }
            else {
                putchar(str[i]);
            }
        }
        if(j) putchar(str[len - 1]);
        putchar('\n');
    }

    return 0;
}
