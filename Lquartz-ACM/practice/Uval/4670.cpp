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
#define Maxn 12111
#define Maxm 111111
struct node {
    struct node * fail;
    struct node * next[26];
    bool is;
    int lab;
}Tree[Maxn], * root, * que[Maxn];
int tot, head, tail;

node * newNode() {
    node * p = &Tree[tot++];
    p->is = false;
    p->lab = 0;
    p->fail = NULL;
    for(int i = 0; i < 26; i++) p->next[i] = NULL;
    return p;
}
void Insert(char str[], int n) {
    node * p = root;
    for(int i = 0, k; str[i]; i++) {
        k = str[i] - 'a';
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
        for(i = 0; i < 26; i++) {
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
int n, cnt[200];
char str[200][77];
char ss[10000];
void query() {
    gets(ss);
    int ch;
    node * p = root, * q;
    int k;
    ch = getchar();
//    ch = getchar();
    while(true) {
        k = ch - 'a';
        if(k < 0 || k >= 26) break;
        p = p->next[k];
        if(p->is) {
            q = p;
            while(q->is) {
                cnt[q->lab]++;
                q = q->fail;
            }
        }
        ch = getchar();
    }
}
int main() {
    int i, j, u, v, w;
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    while(scanf("%d", &n) != EOF && n) {
        tot = 0;
        root = newNode();
        for(i = 1; i <= n; i++) {
            scanf("%s", str[i]);
            Insert(str[i], i);
        }
        buildAC();
        for(i = 1; i <= n; i++) {
            cnt[i] = 0;
        }
        query();
        int dmax = cnt[1];
        for(i = 2; i <= n; i++) cmax(dmax, cnt[i]);
        printf("%d\n", dmax);
        for(i = 1; i <= n; i++) {
            if(cnt[i] == dmax) printf("%s\n", str[i]);
        }
    }
    return 0;
}
/*
2 
aba 
bab 
ababababac 
6 
beta 
alpha 
haha 
delta 
dede 
tata 
dedeltalphahahahototatalpha 
0
*/
