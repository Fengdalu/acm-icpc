#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int f[100][100];
int main() {
    int n; cin >> n;
    int x = 1;
    int c = n / 2;
    int tot = 0;
    for(int i = 0; i <= n / 2; i++, tot++)
        for(int j = c - tot; j <= c + tot; j++) {
            f[i][j] = x;
            x = x + 2;
        }
    tot -= 2;
    for(int i = n / 2 + 1; i < n; i++, tot--)
        for(int j = c - tot; j <= c + tot; j++) {
            f[i][j] = x;
            x = x + 2;
        }
    x = 2;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            if(f[i][j] == 0) cout << x << " ", x += 2;
            else cout << f[i][j] << " ";
        cout << endl;
    }
   return 0;
}
