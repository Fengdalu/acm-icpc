#include <bits/stdc++.h>

const int NN = 27;
const int N = 2000100;
int to[N][NN]; // 节点指针
int w[300]; // 字母下标
int word[N]; // 节点标记
int fail[N]; // 失配指针
int len[N];
char s[N];
int p[N];
int ind[N];
int nt[N], v[N];
int et;
int cnt;

void init() {
    cnt = 0;
    word[0] = 0;
    memset(to[0], 0, sizeof to[0]);
}

char cp(char x) {
    if('A' <= x && x <= 'Z') x = 'a' + x - 'A';
    return x;
}

void insert(char *a) {
    int p = 0;
    int wcnt = 0;
    while(*a) {
        int v = w[*a];
        if(!to[p][v]) {
            to[p][v] = ++cnt;
            memset(to[cnt], 0, sizeof to[cnt]);
            word[cnt] = 0;
        }
        p = to[p][v];
        a++;
        wcnt++;
    }
    word[p] = wcnt;
}


void add(int a, int b) {
    v[et] = b;
    nt[et] = ind[a];
    ind[a] = et++;
}


void ac() {
    std::queue<int>q;
    memset(fail, 0, sizeof fail);
    for(int i = 0; i < NN; i++) if(to[0][i]) {
        q.push(to[0][i]);
    }
    while(q.size()) {
        int p = q.front();
        q.pop();
        for(int i = 0; i < NN; i++) {
            int v = to[p][i];
            if(v) {
                fail[v] = to[fail[p]][i];
                q.push(v);
            }
            else {
                to[p][i] = to[fail[p]][i];
            }
        }
        add(fail[p], p);
    }
}

void dfs(int x) {
    for(int k = ind[x]; k != -1; k = nt[k]) {
        word[v[k]] = std::max(word[v[k]], word[x]);
        dfs(v[k]);
    }
}

int main()  {
    std::fill(w, w + 300, 26);
    for(char ch = 'a'; ch != 'z' + 1; ch++) w[ch] = ch - 'a';
    int _t; scanf("%d", &_t);
    while(_t--) {
        init();
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            scanf("%s", s);
            int len = strlen(s);
            for(int i = 0; i < len; i++) s[i] = cp(s[i]);
            insert(s);
        }
        std::fill(ind, ind + cnt + 1, -1);
        et = 0;
        ac();
        gets(s);
        gets(s);
        dfs(0);
        int len = strlen(s);
        int k = 0;
        for(int i = 0; i != len; i++) {
            k = to[k][w[cp(s[i])]];
            p[i] = word[k];
        }
        int pre = len;
        for(int i = len - 1; i != -1; i--) {
            pre = std::min(pre, i - p[i]);
            if(i > pre) s[i] = '*';
        }
        printf("%s\n", s);
    }
    return 0;
}

