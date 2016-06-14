#include <cstdio>
#include <iostream>
using namespace std;
#define cmax(x, y) x = max(x, y)

double dp[18][1 << 18];
double p[22][22];
int n;

int main() {
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> p[i][j];

    dp[0][1] = 1.0;
    for(int mk = 0; mk < (1 << n); mk++) {
        for(int i = 0; i < n; i++)
        if(1 << i & mk)
            for(int j = 0; j < n; j++)
                if(i != j && ((1 << j) & mk)) {
                    cmax(dp[i][mk], p[j][i] * dp[j][mk ^ (1 << i)] + p[i][j] * dp[i][mk ^ (1 << j)]);
                }
    }
    double ans = -1;
    int all = (1 << n); all--;
    for(int i = 0; i < n; i++)
        cmax(ans, dp[i][all]);
    printf("%.15f", ans);
    return 0;
}
