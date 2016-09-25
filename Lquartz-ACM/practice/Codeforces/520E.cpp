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
const LL MOD = 1000000007LL;
int n, k;
char str[Maxn];
LL C[Maxn], CC[Maxn];
LL sum[Maxn];
LL ans;
LL ee[Maxn];
LL inv[Maxn];

int main() {
    int i, j;
    LL u, v, w, x, y, z;
    for(inv[1]=1,i=2;i<110000;i++)inv[i]=inv[MOD%i]*(MOD-MOD/i)%MOD;//MOD is prime
    while(cin >> n >> k) {
        cin >> str;
        ee[0] = 1;
        for(i = 1; i <= n; i++) ee[i] = ee[i - 1] * 10 % MOD;
        memset(CC, 0, sizeof(CC));
        for(i = n - 1, u = 1; i >= 0; i--) {
            CC[i] = (CC[i + 1] + (str[i] - '0') * u) % MOD;
            u = u * 10 % MOD;
        }
        if(k == 0) {
            ans = 0;
            for(i = n - 1, u = 1; i >= 0; i--) {
                ans = (ans + (str[i] - '0') * u) % MOD;
                u = u * 10 % MOD;
            }
            cout << ans << endl;
            continue;
        }
        ans = 0;
        memset(C, 0, sizeof(C));
        if(k > 0){
            C[k - 1] = 1;
            C[k] = k;
        }
        else {
            C[k] = 1;
        }
        memset(sum, 0, sizeof(sum));
        for(i = k + 1, j = 2; i <= n; i++, j++) {
            C[i] = C[(i - 1)] * i % MOD * inv[j] % MOD;
        }
        sum[n - 2] = C[n - 2];
        for(i = n - 3, u = 1; i >= 0; i--) {
            u = u * 10 % MOD;
            sum[i] = (sum[i + 1] + C[i] * u) % MOD;
        }

        //for(i = k - 1; i <= n; i++) cout << "C " << i << " " << C[i] << endl;
        //for(i = k - 1; i <= n; i++) cout << "sum " << i << " " << sum[i] << endl;
        for(i = 0; i < n - 1; i++) {
            u = i;
            v = n - 2 - i;
            w = (k - 1) - u;
            if(w <= 0) {
                j = v;
                ans = (ans + CC[i + 1] * C[n - 2 - j]) % MOD;
            }
            else {
                j = v - w;
                //ans = (ans + (str[i] - '0') * ee[n - 1 - i]) % MOD; 
            }
            //cout << i << " " << u << " " << v << " " << w << " " << j << endl;
            ans = (ans + (str[i] - '0') * sum[n - 2 - j] )% MOD;

            //cout << "ans " << ans << endl;
        }
        cout << ans << endl;
    }

    return 0;
}
