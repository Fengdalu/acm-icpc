#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int s[2000][2000];
int main() {
    int n;

    map<ll, int>f, g;
    scanf("%d", &n);
    if(n == 1) {
        cout << 1 << endl;
        return 0;
    }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &s[i][j]);
    for(int i = 0; i < n; i++) {
        ll sum = 0;
        bool flag = false;
        for(int j = 0; j < n; j++) {
            sum += s[i][j];
            if(!s[i][j]) flag = true;
        }
        if(flag) f[sum]++; else g[sum]++;
        sum = flag = 0;
        for(int j = 0; j < n; j++) {
            if(!s[j][i]) flag = true;
            sum += s[j][i];
        }
        if(flag) f[sum]++; else g[sum]++;
    }
    ll sum = 0;
    bool flag = false;
    for(int i = 0; i < n; i++) {
        sum += s[i][i];
        if(!s[i][i])  flag = true;
    }
    if(flag) f[sum]++; else g[sum]++;
    sum = flag = 0;
    for(int i = 0; i < n; i++) {
        sum += s[i][n - 1 - i];
        if(!s[i][n - 1 - i])  flag = true;
    }
    if(flag) f[sum]++; else g[sum]++;


    if(f.size() == 1  && g.size() == 1 && g.begin()->first > f.begin()->first) {
        cout << g.begin()->first - f.begin()->first << endl;
    }
    else {
        cout << -1 << endl;
    }
    return 0;
}
