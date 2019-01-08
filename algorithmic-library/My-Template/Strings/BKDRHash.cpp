/*
 * 全局 init()
 * get(u64* H, int L, int w) 获取 L 开头 长度为 w 的 hash
 */
const int N = 1e5+100;
typedef unsigned long long ull;
const ull mod = 1e9 + 7;
struct Hash {
  ull P[N];
  ull H[N];
  void init() {
    P[0] = 1;
    for(int i = 1; i < N; i++)
      P[i] = P[i - 1] * mod;
  }

  template <typename T>
    void make(T *a, int n) {
      H[n] = 0;
      for(int i = n - 1; i >= 0; i--)
        H[i] = H[i + 1] * mod + a[i] + 1;
    }

  ull get(int L, int w) {
    return H[L] - H[L + w] * P[w];
  }
} T;


