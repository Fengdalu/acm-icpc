#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

const long long mod = 1e9 + 7;
long long f[10];
long long len[10];
char buf[100050];
string s;
string a[100050];
int n;

int main() {
        scanf("%s", buf);
        s = string(buf);
        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            scanf("%s", buf);
            a[i] = string(buf);
        }
        for(int i = 0; i < 10; i++) f[i] = i;
        for(int i = 0; i < 10; i++) len[i] = 10;
        for(int i = n - 1; i >= 0; i--) {
            int d;
            if(a[i][a[i].size() - 1] == '>') {
                sscanf(a[i].c_str(), "%d->", &d);
                f[d] = 0;
                len[d] = 1;
                continue;
            }
            else sscanf(a[i].c_str(), "%d->%s", &d, buf);
            int m = strlen(buf);
            long long tot = 1;
            long long sum = 0;
            for(int j = 0; j < m; j++) {
                int d = buf[j] - '0';
                sum = (sum * len[d] % mod + f[d]) % mod;
                tot = (tot * len[d]) % mod;
            }
            f[d] = sum;
            len[d] = tot;
        }
        long long ans = 0;
        for(int i = 0; i < s.size(); i++) {
            int d = s[i] - '0';
            ans = ((ans * len[d]) % mod + f[d]) % mod;
    }
    cout << ans << endl;
    return 0;
}
