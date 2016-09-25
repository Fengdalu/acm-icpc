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

int x[100];

bool check() {
    int sum = x[0] + x[1] + x[2];
    if(x[4] < 1 || x[4] > 100000) return false;
    if(x[8] < 1 || x[8] > 100000) return false;
    if(x[0] + x[3] + x[6] != sum) return false;
    if(x[1] + x[4] + x[7] != sum) return false;
    if(x[2] + x[5] + x[8] != sum) return false;
    if(x[0] + x[4] + x[8] != sum) return false;
    if(x[2] + x[4] + x[6] != sum) return false;
    return true;
}


int main() {
    int i, j, k, u, v, w;

    for(i = 0; i < 9; i++) scanf("%d", &x[i]);
    for(i = 1; i <= 100000; i++) {
        x[0] = i;
        x[4] = x[0] + x[1] + x[2] - x[3] - x[5];
        x[8] = x[0] + x[1] + x[2] - x[6] - x[7];
        if(check()) {
            for(i = 0; i < 3; i++) {
                for(j = 0; j < 3; j++) {
                    if(j) printf(" ");
                    printf("%d", x[i * 3 + j]);
                }
                printf("\n");
            }
            break;
        }
    }
    return 0;
}
