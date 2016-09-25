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
#define Maxn 251111
#define Maxm 111111
struct node {
    struct node * fail;
    struct node * next[26];
    int is;
}Tree[Maxn], * root, *que[Maxn];
int head, tail;
int tot;
int ii;
node * newNode() {
    node * p = &Tree[tot++];
    p->fail = NULL;
    for(ii = 0; ii < 26; ++ii) p->next[ii] = NULL;
    p->is = -1;
    return p;
}
void Insert(char str[], int n) {
    int i, k;
    node * p = root;
    for(i = 0; str[i]; ++i) {
        k = str[i] - 'A';
        if(p->next[k] == NULL) {
            p->next[k] = newNode();
        }
        p = p->next[k];
    }
    p->is = n;
}
void buildAC() {
    int i;
    node * p, * q;
    root->fail = root;
    head = tail = 0;
    que[tail++] = root;
    while(head < tail) {
        p = que[head++]; q = p->fail;
        for(i = 0; i < 26; ++i) {
            if(p->next[i] != NULL) {
                if(p == root) {
                    p->next[i]->fail = root;
                }
                else {
                    p->next[i]->fail = q->next[i];
                    if(p->next[i]->is == -1 && q->next[i]->is) {
                        p->next[i]->is = 0;
                    }
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
char str[1001][55];
int n, cnt[1001];
char ss[2100000];
int main() {
    int i, j, k, u, v, w;
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    while(scanf("%d", &n) != EOF) {
        tot = 0;
        root = newNode();
        char ch;
        for(i =1 ; i <= n; i++) {
            scanf("%s", str[i]);
            Insert(str[i], i);
        }
        buildAC();
        for(i = 0; i <= n; ++i) cnt[i] = 0;
        ch = getchar();
        ch = getchar();
        node * p = root, * q;
        while(ch != '\n') {
            k = ch - 'A';
            if(k < 0 || k >= 26) {
                p = root;
            }
            else {
                p = p->next[k];
                if(p->is != -1) {
                    q = p;
                    while(q->is != -1) {
                        ++ cnt[q->is];
                        q = q->fail;
                    }
                }
            }
            ch = getchar();
        }
        for(i = 1; i <= n; ++i) {
            if(cnt[i]) printf("%s: %d\n", str[i], cnt[i]);
        }
    }
    return 0;
}

