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

int A[10];

char str[][20] = {"chest","biceps", "back"}; 
int n;

int main() {
    int i, j, k, u, v, w;

    while(cin >> n) {
        memset(A, 0, sizeof(A));
        for(i = 0; i < n; i++) {
            cin >> w;
            A[i % 3] += w;
        }
        v = -1;
        for(i = 0; i < 3; i++) {
            if(A[i] > v) {
                v = A[i]; u = i;
            }
        }
        printf("%s\n", str[u]);
    }

    return 0;
}
