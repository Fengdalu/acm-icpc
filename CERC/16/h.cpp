#include <bits/stdc++.h>

using namespace std;
#define AA first
#define BB second
#define MP make_pair
#define PII pair<int, int>
const int N = 2100;

struct FastIO {
  static const int S = 65536;
  char buf[S];
  int pos, len;
  bool eof;
  FILE *in;
  FastIO(FILE *_in = stdin) {
    in = _in;
    pos = len = 0;
    eof = false;
  }
  int nextChar() {
    if (pos == len)
      pos = 0, len = fread(buf, 1, S, in);
    if (pos == len) {eof = true; return -1;}
    return buf[pos++];
  }
  int nextUInt() {
    int c = nextChar(), x = 0;
    while (c <= 32) c = nextChar();
    for (;'0' <= c && c <= '10'; c = nextChar()) x = x * 10 + c - '0';
    return x;
  }
  int nextInt() {
    int s = 1, c = nextChar(), x = 0;
    while (c <= 32) c = nextChar();
    if (c == '-') s = -1, c = nextChar();
    for (; '0' <= c && c <= '9'; c = nextChar()) x = x * 10 + c - '0';
    return x * s;
  }
  void nextString(char *s) {
    int c = nextChar();
    while (c <= 32) c = nextChar();
    for(; c > 32; c = nextChar()) *s++ = c;
    *s = 0;
  }
} IO;

char s[N][N];
PII a[N*N], b[N*N];
int to[N*N];
int ans[N*N];
pair<int, PII> nd[N*N];
int f[N][N], fa[N*N], R[N][N], sz[N*N];

inline int sub(int a, int b, int c, int d) {
    return f[c+1][d+1] - f[a][d+1] - f[c+1][b] + f[a][b];
}

inline int find(int x) {
    static int rt, t;
    rt = x;
    while(fa[rt] != rt) rt = fa[rt];
    while(x != rt) {
        t = fa[x];
        fa[x] = rt;
        x = t;
    }
    return rt;
}

void merge(int u, int v) {
    fa[find(u)] = find(v);
}

int main() {
    int n;
    n = IO.nextInt();
    for(int i = 0; i < n; i++) IO.nextString(s[i]);
    int Q; Q = IO.nextInt();
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            f[i+1][j+1] = f[i+1][j] + f[i][j+1] - f[i][j] + (s[i][j] == '#' ? 1 : 0);

    for(int i = 0; i < Q; i++) {
        a[i].AA = IO.nextInt();
        a[i].BB = IO.nextInt();
        b[i].AA = IO.nextInt();
        b[i].BB = IO.nextInt();
        a[i].AA--; a[i].BB--; b[i].AA--; b[i].BB--;
        to[i] = i;
    }

    int cnt = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(s[i][j] == '#') {
                R[i][j] = 0;
                continue;
            }
            int l = 1, r = min(min(n - i, i + 1), min(n - j, j + 1));
            while(l < r) {
                int mid = (l + r + 1) >> 1;
                if(sub(i - mid + 1, j - mid + 1, i + mid - 1, j + mid - 1) == 0)  l = mid;
                else r = mid - 1;
            }
            l = 2 * (l - 1) + 1;
            nd[cnt++] = MP(-l, MP(i, j));
            R[i][j] = l;
        }
    }
    for(int i = 0; i <= n * n; i++) fa[i] = i;
    sort(nd, nd + cnt);
    const int V[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int m = Q;
    for(int i = 0; i < cnt; i++) {
        PII pt = nd[i].BB;
        int rr = -nd[i].AA;
        for(int i = 0; i < 4; i++) {
            int x = pt.AA + V[i][0], y = pt.BB + V[i][1];
            if(x < 0 || x > n - 1 || y < 0 || y > n - 1) continue;
            if(R[x][y] >= rr) {
                // merge(id[pt.AA][pt.BB], id[x][y]);
                merge(pt.AA * n + pt.BB, x * n + y);
            }
        }
        if(i == cnt - 1 || nd[i].AA != nd[i + 1].AA) {
            for(int i = 0; i < m; i++)
                //if(find(id[a[i].AA][a[i].BB]) == find(id[b[i].AA][b[i].BB])) {
                if(find(a[i].AA * n + a[i].BB) == find(b[i].AA * n + b[i].BB)) {
                    ans[to[i]] = rr;
                    to[i] = to[m - 1];
                    a[i] = a[m - 1];
                    b[i] = b[m - 1];
                    i--;
                    m--;
                }
        }
    }
    for(int i = 0; i < Q; i++)
        printf("%d\n", ans[i]);
    return 0;
}
