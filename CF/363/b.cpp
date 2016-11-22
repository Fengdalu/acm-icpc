#include <bits/stdc++.h>
using namespace std;

int n, m;
char s[2000][2000];
int r[2000], c[2000];
int main() {
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++) scanf("%s", s[i]);
    int tot = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(s[i][j] == '*') { r[i]++; c[j]++; tot++;}
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if((s[i][j] == '.' && r[i] + c[j] == tot) || (s[i][j] == '*' && r[i] + c[j] == tot + 1)) {
                cout << "YES" << endl;
                cout << i + 1 << " " << j + 1 << endl;
                return 0;
            }
    cout <<"NO" << endl;
    return 0;
}
