/*
 * 初始把 b[n + 1] 赋为 -1
 * Hdu 1711
 */
template<typename T>
void build(T b[], int next[], int m) {
    int k = -1;
    for(int i = 0; i < m; i++) {
        while(k != -1 && b[k + 1] != b[i]) k = next[k];
        if(k + 1 != i && b[k + 1] == b[i]) k++;
        next[i] = k;
    }
}
// 得到 b 在 a 中的第一个匹配位置
template <typename T>
int kmp(T a[], T b[], int next[], int n, int m) {
    int k = -1;
    for(int i = 0; i < n; i++) {
        while(k != -1 && b[k + 1] != a[i]) k = next[k];
        if(b[k + 1] == a[i]) k++;
        if(k == m - 1) return i - m + 2;
    }
    return -1;
}
