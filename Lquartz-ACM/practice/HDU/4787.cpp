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
#define Maxm 5111111
struct node {
    struct node * fail;
    struct node * next[2];
    int isnull[2];
    int is, lab;
}trie0[Maxn], trie1[Maxn], *root0, *root1, *que[Maxn];
int head, tail;
int tot0, tot1;
node * newNode(node * trie, int & tot) {
    node * p = &trie[tot++];
    p->is = p->lab = false;
    p->fail = p->next[0] = p->next[1] = NULL;
    p->isnull[0] = p->isnull[1] = true;
    return p;
}
void Insert(node * root, node * trie, int & tot, char str[]) {
    int i, k;
    for(i = 0; str[i]; i++) {
        k = str[i] - '0';
        if(root->isnull[k]) {
            root->next[k] = newNode(trie, tot);
            root->isnull[k] = false;
        }
        root = root->next[k];
    }
    root->is = true;
    root->lab = true;
}
void buildAC(node * root) {
    head = tail = 0;
    que[tail++] = root;
    root->fail = root;
    node * p, * q;
    int i;
    while(head < tail) {
        p = que[head++];
        for(i = 0; i < 2; i++) {
            q = p->fail;
            if(p->isnull[i]) {
                if(p == root) p->next[i] = root;
                else p->next[i] = q->next[i];
            }
            else {
                if(p == root) p->next[i]->fail = root;
                else {
                    p->next[i]->fail = q->next[i];
                    p->next[i]->is |= q->next[i]->is;
                }
                que[tail++] = p->next[i];
            }
        }
    }
}
char str[Maxm], ss[Maxm];
int pre;
bool have(node * root, char str[]) {
    int i, k;
    for(i = 0; str[i]; i++) {
        k = str[i] - '0';
        if(root->isnull[k]) return false;
        root = root->next[k];
    }
    if(root->lab) return true;
    else return false;
}
void Shift(char ss[], int t) {
    int L = strlen(ss);
    t %= L;
    int i, j;
    for(i = t, j = 0; i < L; i++, j++) str[j] = ss[i];
    for(i = 0; j < L; i++, j++) str[j] = ss[i];
    str[j] = '\0';
}
void Move(node * root, int dep) {
    if(root->lab) {
        ss[dep] = '\0';
        Insert(root1, trie1, tot1, ss);
    }
    int k;
    for(k = 0; k < 2; k++) {
        if(root->isnull[k]) continue;
        ss[dep] = k + '0';
        Move(root->next[k], dep + 1);
    }
}
int query(node * root, char str[]) {
    node * p, * q;
    int i, k, ret = 0;
    for(i = 0, p = root, ret = 0; str[i]; i++) {
        k = str[i] - '0';
        p = p->next[k];
        if(p->is) {
            q = p;
            while(q->is) {
                if(q->lab) ret++;
                q = q->fail;
            }
        }
    }
    return ret;
}
int n, m, L;
int main() {
//    cout << sizeof(ss) << endl;
    int i, j, u, v, w;
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    int te, cnt0, cnt1;
    scanf("%d", &te);
    char op;
    for(int ca = 1; ca <= te; ca++) {
        scanf("%d", &n);
        tot0 = tot1 = 0;
        cnt0 = cnt1 = 0;
        root0 = newNode(trie0, tot0);
        root1 = newNode(trie1, tot1);
        buildAC(root0);
        buildAC(root1);
        m = (int)sqrt(n);
        pre = 0;
        printf("Case #%d:\n", ca);
        for(i = 1; i <= n; i++) {
            scanf("%s", ss);
            L = strlen(ss);
            op = ss[0];
            for(u = 1, v = 0; u <= L; u++, v++) ss[v] = ss[u];
//            printf("before %s %d\n", ss, pre);
            Shift(ss, pre);
//            printf("after %s\n", str);
            if(op == '?') {
//                pre = query(root0, str);
//                pre += query(root1, str);
                printf("%d\n", (pre = query(root0, str) + query(root1, str)));
            }
            else if(op == '+'){
                if(!have(root0, str) && !have(root1, str)) {
                    if(cnt0 + 1 >= m) {
                        Insert(root1, trie1, tot1, str);
                        Move(root0, 0);
                        buildAC(root1);
                        cnt0 = 0;
                        tot0 = 0;
                        root0 = newNode(trie0, tot0);
                        buildAC(root0);
                    }
                    else {
                        Insert(root0, trie0, tot0, str);
                        cnt0++;
                        buildAC(root0);
                    }
                }
            }
        }
    }
    return 0;
}

