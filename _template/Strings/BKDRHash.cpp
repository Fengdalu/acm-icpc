/*
 * 把字符串变成X进制数，可以完成$ O(1) $比较 ,
 * 调用 Init() 初始化幂 ,
 * 调用 Init(u64* Hash, int len) 初始化 Hash 数组 ,
 * Get(u64* Hash, int p, int L) 表示获得以 p 开头长度为 L 的字符串 Hash 。
 * Base 需要选用质数
 */

typedef unsigned long long u64;
const u64 Base = 31;
const int N = 1e5;
char s[N];
u64 Hash[N];
u64 Pow[N];
void Init() {
    Pow[0] = 1;
    for(int i = 1; i < N; i++) Pow[i] = Pow[i - 1] * Base;
}

void Init(u64* Hash, int len) {
    Hash[len] = 0;
    for(int i = len - 1; i >= 0; i--)
        Hash[i] = (u64)Hash[i + 1] * Base + (s[i] - 'a' + 1);
}

u64 Get(u64* Hash, int p, int L) {
    return Hash[p] - Hash[p + L] * Pow[L];
}
