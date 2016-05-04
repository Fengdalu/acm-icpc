#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int mod = 1e9 + 7;
long long f[52]['z' + 1][2], g[52]['z' + 1][2];
int n;
char s[100], s0[100];

void add(long long &a, long long b) {
    a = (a + b) % mod;
}
int main() {
    scanf("%d", &n);
    scanf("%s", s);
    int len = strlen(s);
    if(s[0] == '?') {
        for(char c = 'a'; c < 'z' + 1; c++)
            f[0][c][0] = 1;
    }
    else f[0][s[0]][0] = 1;
    for(int i = 1; i < len; i++)
        if(s[i] == '?')
                for(char c = 'a'; c < 'z' + 1; c++)
                    for(char p = 'a'; p < 'z' + 1; p++)
                        add(f[i][p][0], f[i - 1][c][0]);
            else
                for(char c = 'a'; c < 'z' + 1; c++)
                    add(f[i][s[i]][0], f[i - 1][c][0]);
    for(int q = 0; q < len - 1; q++) {
        memset(g, 0, sizeof g);
        scanf("%s", s);

        for(int i = 0; i < len; i++) {
            for(char c = 0; c < 'z' + 1; c++) {
                long long tot = (f[i][c][0] + f[i][c][1]) % mod;
                if(!tot) continue;
                for(int)
            }
        }
    }
    return 0;
}
