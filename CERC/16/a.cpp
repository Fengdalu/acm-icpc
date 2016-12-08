#include <bits/stdc++.h>

using namespace std;

#define AA first
#define BB second
#define MP make_pair
#define PII pair<int, int>
#define PB push_back
#define SZ size()

char s[200][200];
int fa[50000];
vector<string> b[50000][4];

int find(int x) {
    if(fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}

vector<string> rot(vector<string>a) {
    int w = a[0].SZ;
    vector<string> t;
    for(int j = 0; j < w; j++)  {
        string l;
        for(int i = 0; i < a.SZ; i++) {
            l.push_back(a[i][j]);
        }
        reverse(l.begin(), l.end());
        t.PB(l);
    }
    return t;
}

bool check(vector<string> &a, vector<string> &b) {
    if(a.SZ != b.SZ) return false;
    if(a[0].SZ != b[0].SZ) return false;
    for(int i = 0; i < a.SZ; i++)
        if(a[i] != b[i]) return false;
    return true;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++)
        scanf("%s", s[i]);

    int w = 0, h = 0;
    for(int i = 1; i < n; i++) {
        bool flag = true;
        for(int j = 0; j < m; j++)
            if(s[i][j] != '#') flag = false;
        if(flag) {
            h = i;
            break;
        }
    }

    for(int j = 1; j < m; j++) {
        bool flag = true;
        for(int i = 0; i < n; i++)
            if(s[i][j] != '#') flag = false;
        if(flag) {
            w = j;
            break;
        }
    }

    int cnt = 0;
    vector<PII> a;
    for(int i = 1; i < n; i += h)
        for(int j = 1; j < m; j += w)
            a.PB(PII(i, j));

    for(int i = 0; i < a.SZ + 1; i++) fa[i] = i;

    int sz = a.SZ;
    for(int i = 0; i < a.SZ; i++) {
        vector<string> t;
        for(int k = 0; k < h - 1; k++) {
            string l;
            for(int p = 0; p < w - 1; p++) {
                l.push_back(s[a[i].AA + k][a[i].BB + p]);
            }
            t.push_back(l);
        }
        b[i][0] = t;
        for(int j = 1; j < 4; j++) b[i][j] = rot(b[i][j - 1]);
    }

    for(int i = 0; i < sz; i++) {
        for(int j = 1; j < sz; j++)  {
            bool flag = false;
            for(int k = 0; k < 4; k++) {
                flag |= check(b[i][0], b[j][k]);
            }
            if(flag) {
                fa[find(i)] = find(j);
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < a.SZ; i++)
        if(find(i) == i) ans++;
    printf("%d\n", ans);
    return 0;
}
