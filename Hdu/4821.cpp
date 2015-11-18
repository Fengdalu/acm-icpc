#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
using namespace std;
typedef unsigned long long u64;
const int N = 100005;
const u64 Base = 31;

char s[N];
u64 Hash[N];
u64 Pow[N];
int m, l;
int n;
map<u64, int>f;

void Init() {
    Pow[0] = 1;
    for(int i = 1; i < N; i++) Pow[i] = Pow[i - 1] * Base;
}

void Init(u64* Hash, int len) {
    Hash[len] = 0;
    for(int i = len - 1; i >= 0; i--) Hash[i] = (u64)Hash[i + 1] * Base + (s[i] - 'a' + 1);
}

u64 Get(u64* Hash, int p, int L) {
    return Hash[p] - Hash[p + L] * Pow[L];
}

int main(){
    //freopen("input.in", "r", stdin);
    Init();
    while(~scanf("%d%d", &m, &l)) {
        scanf("%s", s);
        n = strlen(s);
        int ans = 0;
        Init(Hash, n);
        for(int i = 0; i < l && i + m * l < n; i++) {
            f.clear();
            for(int j = i; j < i + m * l; j += l) {
                f[Get(Hash, j, l)]++;
            }
            if(f.size() == m) ans++;
            for(int j = i + m * l; j <= n - l; j += l) {
                int J = j - m * l;
                f[Get(Hash, J, l)]--;
                if(f[Get(Hash, J, l)] == 0) f.erase(Get(Hash, J, l));
                f[Get(Hash, j, l)]++;
                if(f.size() == m) ans++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
