#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long ll;

const int maxn = 200;
int p[10];
int tot = 0;
int f[10];

int main() {
    int n, m;
    int a, b;
    cin >> n >> m;
    a = n; b = m;
    n--; m--;
    int b1 = 0;
    int b2 = 0;
    while(n) { b1++; n /= 7; }
    while(m) { b2++; m /= 7; }
    b1 = max(b1, 1);
    b2 = max(b2, 1);
    tot = 0;
    for(int mk = 0; mk < (1 << 7); mk++) {
        int cnt = 0;
        for(int i = 0; i < 7; i++)
        if(1 << i & mk) f[cnt++] = i;
        if(cnt != b1 + b2) continue;
        for(int i = 0; i < cnt; i++) p[i] = i;
        do {
            int n1 = 0, n2 = 0;
            for(int k = 0; k < b1; k++) n1 = n1 * 7 + f[p[k]];
            for(int k = b1; k < b1 + b2; k++) n2 = n2 * 7 + f[p[k]];
            if(n1 < a && n2 < b) {
                tot++;
            }
        } while(next_permutation(p, p + cnt));
    }
    cout << tot << endl;
    return 0;
}
