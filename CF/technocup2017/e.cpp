#include <bits/stdc++.h>

typedef unsigned long long u64;

const u64 mod = 1e9 + 7;
template <typename T>
u64 get(T s) {
    u64 tot = 0;
    for(int i = s.size() - 1; i >= 0; i--)
        tot = tot * mod + (s[i] - 'a' + 1);
    return tot;
}

const int N = 1e6;
char buf[1000000];
typedef std::map<u64, std::vector<int> >::iterator IT;
typedef std::vector<int> VI;
u64 P[N+N];
u64 S[N+N];
int main() {
    P[0] = 1;
    for(int i = 1; i < N+N; i++) P[i] = P[i - 1] * mod;
    int n, k;
    scanf("%d%d", &n, &k);
    scanf("%s", buf);
    std::string s(buf);
    std::map<u64, VI> g;
    int M; scanf("%d", &M);
    int i = 0;
    while(M--) {
        scanf("%s", buf);
        g[get(std::string(buf))].push_back(++i);
    }
    s = s + s;
    for(int i = s.size() - 1; i >= 0; i--) S[i] = S[i + 1] * mod + (s[i] - 'a' + 1);
    for(int op = 0; op < k; op++) {
        std::map<u64, int> id;
        bool flag = true;
        std::queue<int> ans;
        int i = op;
        for(int j = 0; j < n; j++) {
            u64 h = S[i] - S[i + k] * P[k];
            VI &V = g[h];
            int &cnt = id[h];
            if(cnt >= V.size()) { flag = false; break; }
            ans.push(V[cnt++]);
            i += k;
            if(i >= n * k) i %= n * k;
        }
        if(!flag) continue;
        puts("YES");
        while(ans.size()) { printf("%d ", ans.front()); ans.pop(); }
        return 0;
    }
    puts("NO");
    return 0;
}
