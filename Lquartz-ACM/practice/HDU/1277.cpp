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
#define Maxn 612111
#define Maxm 111111
struct node {
    struct node * fail;
    struct node * next[10];
    bool is;
    int lab;
}Tree[Maxn], * root, * que[Maxn];
int tot, head, tail;

node * newNode() {
    node * p = &Tree[tot++];
    p->is = false;
    p->lab = 0;
    p->fail = NULL;
    for(int i = 0; i < 10; i++) p->next[i] = NULL;
    return p;
}
void Insert(char str[], int n) {
    node * p = root;
    for(int i = 0, k; str[i]; i++) {
        k = str[i] - '0';
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
    int i;
    node * p, * q;
    root->fail = root;
    que[tail++] = root;
    while(head < tail) {
        p = que[head++]; q = p->fail;
        for(i = 0; i < 10; i++) {
            if(p->next[i] != NULL) {
                if(p == root) p->next[i]->fail = root;
                else {
                    p->next[i]->fail = q->next[i];
                    p->next[i]->is |= q->next[i]->is;
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

string id[11111];
char s1[100], s2[100], s3[100], key[100];
char str[61000], ss[61000];
int m, n, len;
int used[11000];
vector<int> g;
void query() {
    node * p , * q;
    p = root;
    for(int i = 0, k; str[i]; i++) {
        k = str[i]-'0';
        p = p->next[k];
        if(p->is) {
            q = p;
            while(q->is) {
                if(!used[q->lab]) {
                    used[q->lab] = 1;
                    g.PB(q->lab);
                }
                q->is = false;
                q = q->fail;
            }
        }
    }
}
int main() {
    int i, j, u, v, w;
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    while(scanf("%d%d", &m, &n) != EOF) {
        len = 0;
        for(i = 0; i < m; i++) {
            scanf("%s", ss);
            for(j = 0; ss[j]; j++, len++) {
                str[len] = ss[j];
            }
        }
        str[len] = '\0';
        tot = 0;
        root = newNode();
        for(i = 1; i <= n; i++) {
            scanf("%s%s%s%s", s1, s2, s3, key);
            id[i] = (string)s1 + " " + (string)s2 + " " + (string)s3;
            Insert(key, i);
        }
        buildAC();
        for(i = 1; i <= n; i++) used[i] = 0;
        g.clear();
        query();
        if(g.SZ) {
            printf("Found key:");
            for(i = 0; i < g.SZ; i++) {
                printf(" %s", id[g[i]].c_str());
            }
            printf("\n");
        }
        else {
            printf("No key can be found !\n");
        }
    }
    return 0;
}

