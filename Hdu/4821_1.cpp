#include <bits/stdc++.h>

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

char buf[N];
int main() {
    T.init();
    int m, l;
    while(~scanf("%d%d", &m, &l)) {
        int ans = 0;
        scanf("%s", buf);
        int len = strlen(buf);
        T.make(buf, len);
        for(int i = 0; i < l; i++) {
            std::map<ull, int> f;
            std::queue<ull> q;
            for(int j = i; j + l <= len; j += l)  {
                if(q.size() == m) {
                    f[q.front()]--;
                    if(f[q.front()] == 0)
                        f.erase(f.find(q.front()));
                    q.pop();
                }
                ull h = T.get(j, l);
                f[h]++;
                q.push(h);
                if(q.size() == m && f.size() == m) ans++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
