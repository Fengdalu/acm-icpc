#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
#define AA first
#define BB second
#define MP make_pair
const int N = 100001;
int to[N][27]; // `节点指针`
int w['z'+1]; // `字母下标`
int word[N]; // `节点标记`
int cnt;

bool zero(double x) { return fabs(x) < 1e6; }
/*
inline pair<double, double> chk(vector<double>&f) {
    if(f.size() == 0) return MP(1, 0);
    double l = f[0] * .95, r = f[0] * 1.05;
    for(auto &p: f) {
        double ll = p * .95, rr = p * 1.05;
        l = max(ll, l); r = min(rr, r);
    }
    return make_pair(l, r);
}

inline bool chk(int mask, double f[]) {
    vector<double>a, b;
    for(int i = 0; i < 8; i++) {
        if(1 << i & mask) b.push_back(f[i]);
        else a.push_back(f[i]);
    }
    auto x = chk(a), y = chk(b);
    if(a.size() == 0) {
        if(y.AA <= y.BB) return true;
    }
    else if(b.size() == 0) {
        if(x.AA <= x.BB) return true;
    }
    else {
        if(x.AA <= x.BB && y.AA <= y.BB && x.AA <= y.BB && x.AA * 2 < y.BB) return true;
    }
    return false;
}
*/

void insert(char *g) {
    int p = 0;
    char *a = g;
    while(*a) {
        word[p]++;
        int v = w[*a];
        if(!to[p][v]) {
            to[p][v] = ++cnt;
            word[cnt] = 0;
            for(int i = 0; i < 27; i++) to[cnt][i] = 0;
        }
        p = to[p][v];
        a++;
    }
    word[p]++;
}

char buf[2000];
double f[100];
inline int run() {
    int n, m;
    if(scanf("%d%d", &n, &m) != 2) return 0;
    memset(word, 0, sizeof word);
    //memset(to, 0, sizeof to);
    memset(to[0], 0, sizeof to[0]);
    word[0] = 0;
    cnt = 0;
    for(int i = 0; i < n; i++) {
        scanf("%s", buf);
        //buf[30] = 0;
        insert(buf);
    }
    int tot = 0;
    while(m--) {
        int K; scanf("%d", &K);
        int x = 0;
        for(int i = 0; i < K; i++) {
            for(int i = 0; i < 8; i++) scanf("%lf", &f[i]);
            if(x == -1) continue;
            //reverse(f, f + 8);
            /*
            for(char mk = 'a'; mk <= 'z'; mk++) {
                if(chk(mk, f)) c.push_back(mk);
            }
            */
            double sum=0;
            for(int i = 0; i < 8; ++i){
                sum += f[i];
            }
            sum /= 8.0;
            int ch = 0;
            for(int i = 7, d = 1; i >= 0; --i){
                if(f[i] > sum){
                    ch |= d;
                }
                d <<= 1;
            }
            if(to[x][w[ch]]) x = to[x][w[ch]];
            else x = -1;
        }
        if(x != -1) tot += word[x];
    }
    printf("%d\n", tot);
    return 1;
}

int main() {
    for(char ch = 'a'; ch <= 'z'; ch++) w[ch] = ch - 'a';
    while(run());
    return 0;
}
