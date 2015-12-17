#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
#define LL long long
#define MOD 1000000009
#define M 333333336

void gen() {
    LL a = 0, b = 1, cnt = 0;
    while(true) {
        LL c = b + a;
        c %= MOD;
        a = b;
        b = c;
        cnt++;
        if(a == 0 && b == 1) break;
    }
    cout << cnt <<endl;
}

struct obj{
    LL a[2][2];
    obj() { memset(a, 0, sizeof a); }
};

obj mul(obj &a, obj &b) {
    obj c;
    for(int i = 0; i < 2; i++) for(int j = 0; j < 2; j++) for(int k = 0; k < 2; k++) {
        c.a[i][j] += (a.a[i][k] * b.a[k][j] % MOD);
        c.a[i][j] %= MOD;
    }
    return c;
}

LL calc(LL n) {
    if(!n) return 0;
    obj ans;
    ans.a[0][0] = 1;
    ans.a[0][1] = 0;
    ans.a[1][0] = 0;
    ans.a[1][1] = 1;
    obj m;
    m.a[0][0] = 1; m.a[0][1] = 1; m.a[1][0] = 1; m.a[1][1] = 0;
    while(n) {
        if(n & 1) ans = mul(ans, m);
        n >>= 1; m = mul(m, m);
    }
    return ans.a[0][1];
}

int main() {
    LL n;
    scanf("%I64d", &n);
    n %= M;
    printf("%I64d\n", calc(n));
}
