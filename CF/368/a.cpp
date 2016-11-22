#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    map<char, int>f;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            char op[3]; scanf("%s", op);
            f[op[0]]++;
        }
    if(f['G'] + f['W'] + f['B'] == n * m) puts("#Black&White");
    else puts("#Color");
    return 0;
}
