#include <bits/stdc++.h>

using namespace std;
const int M = 2;
const int N = 400000;
const int NN = N * 5;
const int inf = 1e8;
#define PII pair<int, int>
#define AA first
#define BB second
#define MP make_pair

char b[200100];
bool loop = false;
struct trie {
  int to[N][M]; // 节点指针
  int w[256]; // 字母下标
  int fail[N]; // 失配指针
  int vis[N], vis1[N];
  int cnt, cnt1;
  int last[N];
  int nt[NN], v[NN];
  int son[N];
  PII dp[N];

  trie() {
    // 标注下标
    w['0'] = 0;
    w['1'] = 1;
  }

  void add(int i, int j) {
    v[cnt1] = j;
    nt[cnt1] = last[i];
    last[i] = cnt1++;
  }

  int newNode() {
    cnt++;
    memset(to[cnt], 0, sizeof to[cnt]);
    return cnt;
  }

  void init() {
    cnt = cnt1 = 0;
    memset(to[0], 0, sizeof to[0]);
    memset(last, -1, sizeof last);
  }

  void insert(char *a) {
    int p = 0;
//    printf("P: ");
    while(*a) {
      int v = w[*a];
      if(!to[p][v]) {
        to[p][v] = newNode();
      }
      p = to[p][v];
      a++;
//      printf(" %d", p);
    }
//    puts("");
    vis[p] = true;
  }

  void ac() {
    std::queue<int>q;
    memset(fail, 0, sizeof fail);
    for(int i = 0; i < 2; i++) if(to[0][i]) {
      q.push(to[0][i]);
    }
    while(q.size()) {
      int p = q.front();
      q.pop();
      for(int i = 0; i < 2; i++) {
        int v = to[p][i];
        if(v) {
          fail[v] = to[fail[p]][i];
          q.push(v);
        }
        else
          to[p][i] =  to[fail[p]][i];
      }
    }

    for(int i = 1; i <= cnt; i++) add(fail[i], i);
//    for(int i = 0; i <= cnt; i++) printf("%d %d\n", to[i][0], to[i][1]);
    for(int i = 0; i <= cnt; i++) dp[i] = MP(-1, -1);
  }

  void dfs(int u, bool flag) {
    if(flag) vis[u] = true;
    flag |= vis[u];
    for(int k = last[u]; k != -1; k = nt[k])
      dfs(v[k], flag);
  }

  PII dfs1(int u) {
    if(loop) return MP(inf, 0);
//    printf("dfs1 %d\n", u);
    if(loop) return MP(-1, -1);
    if(vis[u]) return MP(-1, 0);
    if(dp[u] != MP(-1, -1)) return dp[u];
    if(to[u][0] == u || to[u][1] == u) {loop = true; return MP(inf, 0);}
    PII l = dfs1(to[u][0]), r = dfs1(to[u][1]);
    if(loop) return MP(inf, 0);
    if(!l.BB && !r.BB) dp[u] = MP(0, 1), son[u] = -1;
    else if(!l.BB) dp[u] = r, son[u] = 1;
    else if(!r.BB) dp[u] = l, son[u] = 0;
    else {
      if(l.AA >= r.AA) dp[u] = l, son[u] = 0; else dp[u] = r, son[u] = 1;
    }
    dp[u].AA++;
    return dp[u];
  }

  void output(int u) {
    if(son[u] == 0) {
      printf("0");
      output(to[u][0]);
    }
    else if(son[u] == 1) {
      printf("1");
      output(to[u][1]);
    }
  }
} T;

int main() {
//  freopen("a.in", "r", stdin);
  int n;
  scanf("%d", &n);
  T.init();
  for(int i = 0; i < n; i++) {
    scanf("%s", b);
    T.insert(b);
  }
  T.ac();
  T.dfs(0, 0);
  loop = false;
//  for(int i = 1; i <= T.cnt; i++) printf("%d ", T.vis[i]); puts("");
  T.dfs1(0);
  if(loop) puts("-1");
  else T.output(0);
}
