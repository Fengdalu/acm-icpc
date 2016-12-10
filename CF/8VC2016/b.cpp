#include <bits/stdc++.h>

using namespace std;
int dp[210][210][210];
char s[1000];

void cal(int a, int b, int c) {
    if(a < 0 || b < 0 || c < 0) return ;
    if(dp[a][b][c] != -1) return ;
    dp[a][b][c] = true;
    cal(a - 1, b - 1, c + 1);
    cal(a + 1, b - 1, c - 1);
    cal(a - 1, b + 1, c - 1);
    if(a - 2 >= 0) cal(a - 1, b, c);
    if(b - 2 >= 0) cal(a, b - 1, c);
    if(c - 2 >= 0) cal(a, b, c - 1);
}

int main() {
    int n; scanf("%d", &n);
    scanf("%s", s);
    map<char, int> f;
    for(int i = 0; i < n; i++) f[s[i]]++;
    memset(dp, -1, sizeof dp);
    cal(f['R'], f['G'], f['B']);
    if(dp[0][0][1] != -1) printf("B");
    if(dp[0][1][0] != -1) printf("G");
    if(dp[1][0][0] != -1) printf("R");
    return 0;
}

