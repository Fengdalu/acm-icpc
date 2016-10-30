#include <bits/stdc++.h>

typedef std::pair<int, int> pii;
struct LR {
    int L, R, c;
    LR(){}
    LR(int L, int R, int c) : L(L), R(R), c(c) {}
};
const int N = 256;
const int op = 32;
const int ed = 126;
char s[(int)2e5];
int vis[N];
int cnt = 0;

int find(std::vector<int> fa, int x) {
    if(fa[x] == x) return x;
    return fa[x] = find(fa, fa[x]);
}

bool check(char i) {
    if('a' <= i && i <= 'z') return true;
    if('A' <= i && i <= 'Z') return true;
    if('0' <= i && i <= '9') return true;
    if(i == ' ') return true;
    return false;
}

std::string deal(int* s)  {
    std::vector<LR> TL;
    int J = op;
    while(J <= ed) {
        int K = J;
        while(K <= ed && s[K] == s[J]) K++;
        TL.push_back(LR(J, K - 1, s[J]));
        J = K;
    }
    std::string ans;
    J = 0;
    while(J < TL.size()) {
        while(J < TL.size() && TL[J].c == 1) J++;
        int K = J;
        while(K < TL.size() && TL[K].c != 1) K++;
        std::vector<int> q;
        for(int i = J; i < K; i++) {
            for(int j = TL[i].L; j <= TL[i].R; j++)
                if(check(j)) q.push_back(j);
        }
        if(q.size() == 1) {
            ans.push_back(q[0]);
        }
        else if(q.size() == 2) {
            int u = q[0], v = q[1];
            ans.push_back(u);
            ans.push_back(v);
        }
        else if(q.size() != 0) {
            ans.push_back(TL[J].L);
            ans.push_back('-');
            ans.push_back(*q.rbegin());
        }
        J = K;
    }
    return ans;
}

int main() {
    gets(s);
    int n = strlen(s);
    for(int i = op; i <= ed; i++) vis[i] = 2;
    for(int i = 'a'; i <= 'z'; i++) vis[i] = 0;
    for(int i = 'A'; i <= 'Z'; i++) vis[i] = 0;
    for(int i = '0'; i <= '9'; i++) vis[i] = 0; vis[' '] = 0;
    for(int i = 0; i < n; i++) vis[s[i]] = true;
    std::string a = deal(vis);
    a = "^" + a;

    for(int i = 'a'; i <= 'z'; i++) vis[i] ^= 1;
    for(int i = 'A'; i <= 'Z'; i++) vis[i] ^= 1;
    for(int i = '0'; i <= '9'; i++) vis[i] ^= 1; vis[' '] ^= 1;
    std::string b = deal(vis);
    if((b.size() < a.size()) || (a.size() == b.size() && b < a)) a = b;
    if(a == "^") a = "^!";
    printf("%%\[%s\]", a.c_str());
    return 0;
}

