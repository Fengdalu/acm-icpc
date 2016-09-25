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
#define Maxm 1011111
struct node {
    struct node * fail;
    struct node * next[26];
    int is;
    int lab;
}Tree[Maxn], * root;
int tot;
//node * que[Maxn];
queue<node * > que;
int head, tail;
node * newNode() {
    node * p = &Tree[tot++];
    p->fail = NULL;
    for(int i = 0; i < 26; i++) p->next[i] = NULL;
    p->is = false;
    p->lab = 0;
    return p;
}
void Insert(node * root, char str[], int n) {
    int i, k;
    for(i = 0; str[i]; i++) {
        k = str[i] - 'a';
        if(root->next[k] == NULL) {
            root->next[k] = newNode();
        }
        root = root->next[k];
    }
    root->is = true;
    root->lab += 1;
}

void buildAC() {
    head = tail = 0;
    root->fail = root;
    que.push(root);
    int i;
    node * now;
    while(!que.empty()) {
        now = que.front(); que.pop();
        for(i = 0; i < 26; i++) {
            if(now->next[i] != NULL) {
                if(now == root) now->next[i]->fail = root;
                else {
                    now->next[i]->fail = now->fail->next[i];
                    now->next[i]->is |= now->fail->next[i]->is;
                }
                que.push(now->next[i]);
            }
            else {
                if(now == root) now->next[i] = root;
                else now->next[i] = now->fail->next[i];
            }
        }
    }
}
int n;
int ans;
void doit() {
    int i, j, k;
    node * p = root;
    int ch = getchar();
    ch = getchar();
    for(i = 0; ch != '\n'; i++) {
        k = ch - 'a';
        p = p->next[k];
        if(p->is) {
            node * q = p;
            while(q->is) {
                q->is = false;
                ans += q->lab;
                q = q->fail;
            }
        }
        ch = getchar();
    }
}

char s1[100];
int main() {
    int i, j, u, v, w, te;
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    scanf("%d", &te);
    while(te--) {
        scanf("%d", &n);
        tot = 0;
        root = newNode();
        for(i = 0; i < n; i++) {
            scanf("%s", s1);
            Insert(root, s1, i);
        }
        buildAC();
        ans = 0;
        doit();
        printf("%d\n", ans);
    }
    return 0;
}
