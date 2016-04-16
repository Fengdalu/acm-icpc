#include <iostream>
#include <cstdio>
#include <cmath>
#include <set>
#include <vector>
using namespace std;
#define ONES(x) __builtin_popcount(x)

int a[100];
int b[100];
int n;
int q[1000];

int main() {
    int T;
    cin >> T;
    for(int tt = 0; tt < T; tt++) {
        cin >> n;
        int ans = 0;
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) a[i]--;
        for(int i = 0; i < n; i++) b[i] = i;
        do {
            for(int i = n - 1; i >= 0; i--) {
                int cnt = 0;
                for(int j = 0; j <= i; j++)
                    q[cnt++] = b[j];
                bool flag = true;
                for(int j = 0; j <= i && flag; j++) {
                    int x = a[q[j]];
                    if(x != q[(j - 1 + cnt) % cnt] && x != q[(j + 1) % cnt])
                        flag = false;
                }
                if(flag) { ans = max(ans, cnt); break;}
            }
        }while(next_permutation(b, b + n));
        cout << "Case #" << tt + 1 << ": " << ans << endl;
    }
}
