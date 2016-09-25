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

LL ax, ay, bx, by, cx, cy;

LL calc(LL px, LL py, LL qx, LL qy) {
   LL ret = px * qy - py * qx;
    return ret;
} 

int main() {
    int i, j, k, u, v, w;
    while(cin >> ax >> ay >> bx >> by >> cx >> cy) {
        LL ii = calc(bx - ax, by - ay, cx - bx, cy - by);
        if(ii == 0) {
            printf("TOWARDS\n");
        }
        else if(ii > 0) {
            printf("LEFT\n");
        }
        else if(ii < 0) {
            printf("RIGHT\n");
        }
    }

    return 0;
}
