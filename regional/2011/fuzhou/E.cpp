#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>

const int N = 600010;
int n;
inline int lowbit(int x) {
    return x & (-x);
}

struct bit1 {
    int _[N+1];
    void init() {
        memset(_, 0, sizeof _);
    }
    void push(int x, int v) {
        while(x < N) {
            _[x] = std::max(_[x], v);
            x += lowbit(x);
        }
    }

    int cal(int x) {
        static int t;
        t = 0;
        while(x) {
            t = std::max(t, _[x]);
            x -= lowbit(x);
        }
        return t;
    }
} b1;

struct bit2 {
    int _[N+1];
    void init() {
        memset(_, 0x3f, sizeof _);
    }
    void push(int x, int v) {
        while(x < N) {
            _[x] = std::min(_[x], v);
            x += lowbit(x);
        }
    }

    int cal(int x) {
        static int t = 0;
        t = N + 1;
        while(x > 0) {
            t = std::min(t, _[x]);
            x -= lowbit(x);
        }
        return t;
    }
} b2;

int a[N];
int left[N], right[N];
int cnt;
int cntx;
char key[N];
char target[N*2];

void dfs(int x) {
    //std::cout << "dfs " << x << std::endl;
    if(a[x] & 1) target[cnt++] = '1';
    else target[cnt++] = '0';

    if(~left[x]) {
        dfs(left[x]);
        if(a[x] & 1) target[cnt++] = '1';
        else target[cnt++] = '0';
    }
    if(~right[x]) {
        dfs(right[x]);
        if(a[x] & 1) target[cnt++] = '1';
        else target[cnt++] = '0';
    }
}

// `a为主串，b为钥串`
int *Next;
void getNext(char *b, int m) {
    static int j,k;
    j = 0;
    k = -1;
    Next[0] = -1;
    while(j < m)
    {
        if(k == -1 || b[j] == b[k])
        Next[++j] = ++k;
        else k = Next[k];
    }
}

// `得到b在a中的第一次出现位置`
// `因为next与STL冲突所以用Next代替`
int KMP_Index(char *a, char *b, int n, int m) {
    static int i, j;
    static int tot;
    i = 0, j = 0;
    getNext(b, m);
    tot = 0;
    while(i < n) {
        if(j == -1 || a[i] == b[j]) {
            i++;
            j++;
        }
        else j = Next[j];
        if(j == m) tot++;
    }
    return tot;
}

int pos[N];
void solve() {
    static int _t = 0;
    b1.init();
    b2.init();
    int n;
    scanf("%d", &n);
    std::fill(left + 1, left + n + 1, -1);
    std::fill(right + 1, right + n + 1, -1);
    for(int i = 1; i <= n; i++)  {
        scanf("%d", &a[i]);
        pos[a[i]] = i;
    }
    b1.push(a[1], a[1]);
    b2.push(N - a[1], a[1]);
    for(int i = 2; i <= n; i++) {
        int p = a[i];
        int t;
        int v1 = b1.cal(p), v2 = b2.cal(N - p);
        if(v1 == 0) left[pos[v2]] = i;
        else if(v2 > n) right[pos[v1]] = i;
        else {
            v1 = pos[v1]; v2 = pos[v2];
            if(left[v2] != -1) right[v1] = i;
            else left[v2] = i;
        }
        b1.push(a[i], a[i]); b2.push(N - a[i], a[i]);
    }
    cnt = 0;
    dfs(1);
    Next = a;
    target[cnt] = 0;
    scanf("%s", key);
    int vv = strlen(key);
    printf("Case #%d: %d\n", ++_t, KMP_Index(target, key, cnt, vv));
}

int main() {
    int _t; scanf("%d", &_t);
    while(_t--) solve();
    return 0;
}
