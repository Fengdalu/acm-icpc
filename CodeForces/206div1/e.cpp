#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

char s[50];
int dp[20][10];
vector<int> w[10][10];
int ans[20][6];

bool cal(int pos, int mod) {
    if(pos == -1 && mod == 0) return true;
    else if(pos == -1) return false;
    if(dp[pos][mod] != -1) return dp[pos][mod];
    int tp = s[pos] - '0';

    for(int i = 0; i <= 9; i++) {
        int p, q;
        if(i > tp) {
            if(mod == 0) continue;
            p = mod - 1; q = tp + 10 - i;
        }
        else { p = mod; q = tp - i; }
        if(w[p][q].size())
            if(cal(pos - 1, i)) {
                for(int j = 0; j < w[p][q].size(); j++)
                    ans[pos][j] = w[p][q][j];
                dp[pos][mod] = true;
                return true;

            }
    }
    return dp[pos][mod] = false;
}

void init() {
    int n = pow(3, 7);
    for(int i = 0; i < n; i++) {
        vector<int>q;
        int k = i;
        for(int j = 0; j < 6; j++) {
            int p = k % 3;
            if(p == 0) q.push_back(0);
            else if(p == 1) q.push_back(4);
            else q.push_back(7);
            k /= 3;
        }
        int ans = 0;
        for(int i = 0; i < q.size(); i++)
            ans += q[i];
        w[ans / 10][ans % 10] = q;
    }
}

int main() {
    init();
    int t; scanf("%d", &t);
    while(t--) {
        scanf("%s", s);
        int len = strlen(s);
        memset(dp, -1, sizeof dp);
        reverse(s, s + len);
        if(cal(len - 1, 0)) {
            for(int i = 0; i < 6; i++) {
                int j;
                for(j = len - 1; j >= 0; j--)
                    if(ans[j][i]) break;
                if(j == -1) printf("0");
                while(j >= 0) {
                    printf("%d", ans[j][i]);
                    j--;
                }
                printf(" ");
            }
            printf("\n");
        } else puts("-1");
    }
    return 0;
}
