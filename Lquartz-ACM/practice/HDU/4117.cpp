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
#define Maxn 300005
#define Maxm 20005
struct node {
    struct node * next[26];
    struct node * fail;
    int is;
    int v;
}A[Maxn], *root, *que[Maxn];
int head, tail;
char str[Maxn];
int st[Maxm];
int tot, ans, n;
int value[Maxm];
node * newNode() {
    node * p = &A[tot++];
    p->fail = NULL;
    p->is = false;
    p->v = -MOD;
    for(int i = 0; i <26; i++) p->next[i] = NULL;
    return p;
}
void Insert(node * root, char str[], int l, int r) {
    int i, k;
    for(i = l; i < r; i++) {
        k = str[i] - 'a';
        if(root->next[k] == NULL) root->next[k] = newNode();
        root = root->next[k];
    }
    root->is = 1;
}
void buildAC() {
    int k;
    head = tail = 0;
    que[tail++] = root;
    root->fail = root;
    node * p, * q;
    while(head < tail) {
        p = que[head++]; q = p->fail;
        for(k = 0; k < 26; k++) {
            if(p->next[k] != NULL) {
                if(p == root) p->next[k]->fail = root;
                else {
                    p->next[k]->fail = q->next[k];
                    p->next[k]->is |= q->next[k]->is;
                }
                que[tail++] = p->next[k];
            }
            else {
                if(p == root) p->next[k] = root;
                else p->next[k] = q->next[k];
            }
        }
    }
}
void query(int n, int l, int r, int v0) {
    int i, k, v;
    node * p, * q;
    p = root;
    v = v0;
    for(i = l; i < r; i++) {
        k = str[i] - 'a';
        p = p->next[k];
        if(p->is) {
            q = p;
            while(q->is) {
                cmax(v, v0 + q->v);
                q = q->fail;
            }
        }
    }
    cmax(p->v, v);
    cmax(ans, v);
}
int main() {
    int i, j, u, v, w;
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    int te;
    scanf("%d", &te);
    for(int ca = 1; ca <= te; ca++) {
        scanf("%d", &n);
        st[0] = 0;
        tot = 0;
        ans = 0;
        root = newNode();
        for(i = 1; i <= n; i++){
            scanf("%s%d", str + st[i - 1], &value[i]);
            for(j = st[i - 1]; str[j]; j++);
            st[i] = j;
            Insert(root, str, st[i - 1], st[i]);
        }
        buildAC();
        for(i = 1; i <= n; i++) {
            query(i, st[i - 1], st[i], value[i]);
        }
        printf("Case #%d: %d\n", ca, ans);
    }
    return 0;
}

/*
4

5
a 1
ab 2
abb 3
baba 5
abbab 8

4
aa 2
a 1
aaa 4
aaaa 8

4
a 1
a -8
a -1
a 3

4
ab 1
bab 2
abab 4
babab 8
*/
