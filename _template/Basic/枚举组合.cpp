/* __builtin_clz  前导 0
 * __builtin_ctz 后缀 0
 */
#define ONES(x) __builtin_popcount(x) // 1 数目

// 枚举 C(n, k) 所有可能, 复杂度 O(C(n, k))
int next_combination(int n, int k) {
    int ret, b = k & -k, t = (k + b);
    ret = (((t ^ k) >> 2) / b) | t;
    if (ret >= (1 << n)) return 0;
    return ret;
}

void run(int n, int k) {
    int ik = (1 << k) - 1;
    do {

    } while(ik = next_combination(n, ik));
}
