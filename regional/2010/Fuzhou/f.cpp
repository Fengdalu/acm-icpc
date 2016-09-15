#include <bits/stdc++.h>

const int N = 500*1010;
int to[N][27]; // 节点指针
int w['Z' + 1]; // 字母下标
int word[N]; // 节点标记
int vis[N]; // 节点标记
int fail[N]; // 失配指针
int in[300];
int d[N];
int cnt;
std::vector<int>g[N];

void init() {
    cnt = 0;
    memset(to[0], 0, sizeof to[0]);
    vis[0] = word[0] = d[0] = 0;
    g[0].clear();
}

void insert(char *a, int num) {
    int p = 0;
    while(*a) {
        int v = w[*a];
        if(!to[p][v]) {
            to[p][v] = ++cnt;
            memset(to[cnt], 0, sizeof to[cnt]);
            word[cnt] = 0;
            vis[cnt] = 0;
            g[cnt].clear();
        }
        d[to[p][v]] = d[p] + 1;
        p = to[p][v];
        a++;
    }
    word[p] = num;
}

void ac() {
    std::queue<int>q;
    memset(fail, 0, sizeof fail);
    for(int i = 0; i < 27; i++) if(to[0][i]) {
        q.push(to[0][i]);
    }
    while(q.size()) {
        int p = q.front();
        q.pop();
        for(int i = 0; i < 27; i++) {
            int v = to[p][i];
            if(v) {
                fail[v] = to[fail[p]][i];
                q.push(v);
            }
            else
                to[p][i] =  to[fail[p]][i];
        }
    }
}

int n;
const int LEN = 5200000;
char buf[LEN];
char s[LEN];

void dfs(int k) {
    bool flg = vis[k];
    if(k != 0) {
        g[fail[k]].push_back(k);
    }
    for(char ch = 0; ch != 27; ch++) {
        int nt = to[k][ch];
        if(d[nt] > d[k]) {
            dfs(nt);
            vis[k] |= vis[nt];
        }
    }
    //std::cout << std::endl;
}

void dfs1(int x) {
    for(int i = 0; i != g[x].size(); i++) {
        dfs1(g[x][i]);
        vis[x] |= vis[g[x][i]];
    }
    if(vis[x]) in[word[x]] = true;
}
void solve() {
    for(char a = 'A'; a <= 'Z'; a++) w[a] = a - 'A';
    init();
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%s", buf);
        int len = strlen(buf);
        insert(buf, i + 1);
    }
    ac();
    scanf("%s", s);
    int len = strlen(s);
    int cnt1 = 0;
    int xx = 0;
    char op = 0;
    for(int i = 0; i < len; i++) {
        if('0' <= s[i] && s[i] <= '9') {
            xx = xx * 10 + (s[i] - '0');
        }
        else if(s[i] == ']') {
            while(xx--) buf[cnt1++] = op;
            xx = 0;
        }
        else if(s[i] != '[') {
            if(xx != 0) op = s[i];
            else buf[cnt1++] = s[i];
        }
    }

   // std::cout << buf << std::endl;
    memset(vis, 0, sizeof vis);
    memset(in, 0, sizeof in);
    int k = 0;
    for(int i = 0; i < cnt1; i++) {
        vis[k] = true;
        k = to[k][w[buf[i]]];
    }
    vis[k] = true;
    k = 0;
    std::reverse(buf, buf + cnt1);
    for(int i = 0; i < cnt1; i++) {
        vis[k] = true;
        k = to[k][w[buf[i]]];
    }
    vis[k] = true;
    dfs(0);
    dfs1(0);
    int tot = 0;
    for(int i = 1; i <= n; i++) if(in[i]) tot++;
    printf("%d\n", tot);
}

int main() {
    int _t;
    scanf("%d", &_t);
    while(_t--) solve();
    return 0;
}
