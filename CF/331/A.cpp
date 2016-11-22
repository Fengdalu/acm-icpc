#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
using namespace std;
#define SZ size()
#define OP begin()
#define ED end()

int n;
set<int>X, Y;
set<int>::iterator it1, it2;

int main() {
    int n; scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        X.insert(x); Y.insert(y);
    }
    bool flg = true;
    if(X.SZ != 2) flg = false;
    if(Y.SZ != 2) flg = false;

    it1 = X.OP; it1++;
    it2 = Y.OP; it2++;
    if(flg) printf("%d", (*it1 - *X.OP) * (*it2 - *Y.OP) );
    else puts("-1");
}
