#include <cstdio>
#include <cstring>
#include <set>
#include <iostream>
using namespace std;

bool f[1000][1000];
int main() {
    long long n, m;
    int T;
    cin >> T;
    for(int ii = 1; ii <= T; ii++) {
        memset(f, 0, sizeof f);
        cin >> n >> m;
        cout << "Case #" << ii << ": ";
        if(n == 2) {
            if(m != 1) cout << "IMPOSSIBLE" << endl;
            else {
                cout << "POSSIBLE" << endl;
                cout << "01" << endl;
                cout << "00" << endl;
            }
            continue;
        }
        long long tot = 1;
        int cur = 2;
        f[1][cur] = f[cur][n] = 1;
        while(cur + 1 < n) {
            cur++;
            if(tot + tot + 1 > m) {
                m -= tot;
                for(int i = 0; (1LL << i) <= m; i++)
                if(1LL << i & m) { f[1][cur] = f[cur][i + 2] = 1; }
                m = 0;
                break;
            }
            else {
                for(int j = 2; j < cur; j++)
                    f[cur][j] = 1;
                f[1][cur] = f[cur][n] = 1;
                tot += tot + 1;
            }
        }
        m -= tot;
        if(m > 1) {
            cout << "IMPOSSIBLE" << endl;
        }
        else {
            if(m == 1) f[1][n] = 1;
            cout << "POSSIBLE" << endl;
            for(int i = 1; i <= n; i++) {
                for(int j = 1; j <= n; j++)
                    if(f[i][j]) cout << "1";
                    else cout << "0";
                cout << endl;
            }


        }
    }
}
