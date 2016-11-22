#include <bits/stdc++.h>

const int N = 5010;
int fa[N];
char ch[N];
char ans[N];
int in[N];
std::vector<int>g[N];

int find(int x) {
    if(fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}

void add(int i, int j) {
    g[i].push_back(j);
    in[j]++;
}

int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", ch);
    int len = strlen(ch);
    for(int i = 0; i <= len; i++) fa[i] = i;
    for(int i = 0; i < len; i++) {
        if(ch[i] == '=') fa[find(i)] = find(i + 1);
    }
    for(int i = 0; i < len; i++) {
        if(ch[i] == '>') add(find(i + 1), find(i));
        else if(ch[i] == '<') add(find(i), find(i + 1));
    }
    std::queue<int> q;
    std::fill(ans, ans + len + 1, 'a' - 1);
    for(int i = 0; i <= len; i++) {
        if(find(i) == i && in[i] == 0) {
            ans[i] = 'a';
            q.push(i);
        }
    }
    while(q.size()) {
        int t = q.front();
        char ch = ans[t];
        ch++;
        q.pop();
        for(int i = 0; i != g[t].size(); i++) {
            int v = g[t][i];
            ans[v] = std::max((int)ans[v], (int)ch);
            in[v]--; if(in[v] == 0) q.push(v);
        }
    }
    for(int i = 0; i < len + 1; i++)
    if(find(i) != i) ans[i] = ans[find(i)];
    for(int i = 0; i < len + 1; i++) {
        if(ans[i] >= 'a' + n) {
            puts("-1");
            exit(0);
        }
    }
    for(int i = 0; i < len + 1; i++) printf("%c", ans[i]);
    return 0;
}
