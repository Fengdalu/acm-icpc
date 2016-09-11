/*
 * f[i][j]: $i$开头$2^j$长度区间的最大值
 *
 */
#include <algorithm>

const int N = 1e5;
const int POW = 32;
int f[N][POW];
int mm[N];
void init(int n) {
    for(int j = 0; j < POW; j++)
        for(int i = 0; i < n; i++)
            if(i + (1 << (j + 1)) <= n) {
                f[i][j + 1] = std::max(f[i][j], f[i + (1 << j)][j]);
            }
    mm[0] = -1;
    for(int i = 1; i < N; i++) {
        if((i & (i - 1)) == 0) mm[i] = mm[i - 1] + 1;
        else mm[i] = mm[i - 1];
    }
}

int cal(int l, int r) {
    int k = mm[r - l + 1];
    return std::max(f[l][k], f[r - (1 << k) + 1][k]);
}
