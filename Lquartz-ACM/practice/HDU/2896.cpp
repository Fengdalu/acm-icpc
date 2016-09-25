#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <bitset>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
 
#define PB push_back
#define PF push_front
#define PPB pop_back
#define PPF pop_front
#define MP make_pair
#define AA first
#define BB second
#define SZ size()
#define BG begin()
#define OP begin()
#define ED end()
#define SORT(x) sort(x.begin(), x.end())
#define SQ(x) ((x)*(x))
#define cmax(x, y) x = max(x, y)
#define cmin(x, y) x = min(x, y)
 
const double eps = 1e-8;
const LL MOD = 1000000007;
const LL INF = 0x3f3f3f3f;
#define Maxn 111111
#define Maxm 111111
struct node {
    struct node * fail;
    struct node * next[130];
    bool is;
    int lab;
}Tree[Maxn], * root, * que[Maxn];
int head, tail;
int tot;

node * newNode() {
    node * p = &Tree[tot++];
    p->is = false;
    p->lab = -1;
    p->fail= NULL;
    for(int i = 0; i < 130; i++) p->next[i] = NULL;
    return p;
}

void Insert(char str[], int n) {
    int i, k;
    node * p = root;
    for(i = 0; str[i]; i++) {
        k = str[i];
        if(p->next[k] == NULL) {
            p->next[k] = newNode();
        }
        p = p->next[k];
    }
    p->is = true;
    p->lab = n;
}

void buildAC() {
    head = tail = 0;
    root->fail = root;
    que[tail++] = root;
    node * p, *q;
    int i;
    while(head < tail) {
        p = que[head++]; q = p->fail;
        for(i = 0; i < 130; i++) {
            if(p->next[i] != NULL) {
                if(p == root) p->next[i]->fail = root;
                else {
                    p->next[i]->fail = q->next[i];
                }
                que[tail++] = p->next[i];
            }
            else {
                if(p == root) p->next[i] = root;
                else p->next[i] = q->next[i];
            }
        }
    }
}
int n, m;
char str[11000];
vector<int> g;
void doit(char str[]) {
    node * p = root, * q;
    int i, k;
    for(i = 0; str[i]; i++) {
        k = str[i];
        p = p->next[k];
        if(p->is) {
            g.PB(p->lab);
            p = root;
        }
    }
}
int main() {
    int i, j, u, v, w;
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    while(scanf("%d", &n) != EOF) {
        tot = 0;
        root = newNode();
        gets(str);
        for(i = 1; i <= n; i++) {
            gets(str);
            Insert(str, i);
        }
        buildAC();
        scanf("%d", &m);
        int all = 0;
        gets(str);
        for(i = 1; i <= m; i++) {
            g.clear();
            gets(str);
            doit(str);
            if(g.SZ > 0) {
                printf("web %d:", i);
                SORT(g);
                g.erase(unique(g.BG, g.ED), g.ED);
                for(j = 0; j < g.SZ; j++) printf(" %d", g[j]);
                printf("\n");
                all++;
            }
        }
        printf("total: %d\n", all);
    }
    return 0;
}

/*
4
abcd
bce
cf
g
1
abcf
*/
