#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

#define PB push_back
#define MP make_pair
#define AA first
#define BB second
#define SZ size()
#define OP begin()
#define ED end()
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
#define SQ(x) ((x)*(x))

#define NAME ""

#define Maxn 2011
#define LEN 3

struct node {
    struct node * next[LEN];
    struct node * fail ;
    int lab;
}trie[Maxn * 100];//here
node * root;
int tot, nindex;
int sid[Maxn], bid[Maxn][Maxn], ubid[Maxn];
char smat[Maxn][Maxn], bmat[Maxn][Maxn];
int sh, sw, bh, bw;

node * NewNode() {
    node * p = &trie[tot++];
    for(int i = 0; i < LEN; i++) p->next[i] = NULL;
    p->fail = NULL;
    p->lab = -1;
    return p;
}

int getKey(char ch) {//here
    if(ch == 'x') return 1;
    else if(ch == 'o') return 0;
    else return -1;
}

int Insert(char str[], int len, node * p) {
    //printf("insert %s %d\n", str, len);
    int i, key;
    for(i = 0; i < len; i++) {
        key = getKey(str[i]);
        if(p->next[key] == NULL) {
            p->next[key] = NewNode();
        }
        p = p->next[key];
    }
    if(p->lab == -1) {
        p->lab = nindex++;
    }
    return p->lab;
}

node * que[Maxn * 100];//here
int head, tail;

void buildAC() {
    int i;
    head = tail = 0;
    que[tail++] = root;
    root->fail = root;
    node * p, * q;
    while(head < tail) {
        p = que[head++];
        q = p->fail;
        for(i = 0; i < LEN; i++) {
            if(p->next[i] != NULL) {
                if(p == root) {
                    p->next[i]->fail = root;
                }
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

int S[Maxn], T[Maxn];
int next[Maxn], is[Maxn];
void getnext(int T[], int LT, int next[]) {
    int i, j;
    next[0] = -1; next[1] = 0;
    for(i = 1, j = 0; i < LT; ) {
        while(j != -1 && T[i] != T[j]) j = next[j];
        i++; j++;
        next[i] = j;
    }
}

int KMP(int S[], int LS, int T[], int LT, int next[]) {
    int i, j;
    int ret = 0;
    for(i = 0; i < LS; i++) is[i] = 0;
    for(i = 0, j = 0; i < LS; i++) {
        while(j != -1 && S[i] != T[j]) j = next[j];
        j++;
        if(j == LT) {
            is[i - LT + 1] = 1;
            ret++;
            j = next[j];
        }
    }
    return ret;
}
/*
void getnext(int T[], int LT, int next[]) {
    int i, j;
    next[0] = -1;
    for(i = 1, j = -1; i < LT; i++) {
        while(j != -1 && T[i] != T[j + 1]) j = next[j];
        if(T[i] == T[j + 1]) {
            next[i] = j + 1;
            j++;
        }
        else {
            next[i] = j;
        }
    }
    //for(i = 0; i < LT; i++) printf("next %d %d\n", i, next[i]);
}

int KMP(int S[], int LS, int T[], int LT, int next[]) {
    int i, j;
    int ret = 0;
    for(i = 0; i < LS; i++) is[i] = 0;
    for(i = 0, j = -1; i < LS; i++) {
        while(j != -1 && S[i] != T[j + 1]) j = next[j];
        if(S[i] == T[j + 1]) {
            j++;
            if(j == LT - 1) {
                ret++;
                j = next[j];
            }
        }
    }
    return ret;
}
*/

void Find(char str[], int len, int n, node * p) {
    //printf("find %s len %d n %d\n", str, len, n);
    int i, key;
    for(i = 0; i < len; i++) {
        key = getKey(str[i]);
        p = p->next[key];
        if(i >= sw - 1) {
            bid[n][i - sw + 1] = p->lab;
        }
    }
}

int main() {
    int i,j;
    //freopen(NAME".in", stdin, "r");
    //freopen(NAME".out", stdout, "w);
    while(scanf("%d%d%d%d", &sh, &sw, &bh, &bw) != EOF) {
        for(i = 0; i < sh; i++) {
            scanf("%s", smat[i]);
        }
        for(i = 0; i < bh; i++) {
            scanf("%s", bmat[i]);
        }
        memset(sid, -1, sizeof(sid));
        memset(bid, -1, sizeof(bid));
        tot = 0;
        nindex = 1;//here
        root = NewNode();
        for(i = 0; i < sh; i++) {
            sid[i] = Insert(smat[i], sw, root);
        }
        //printf("end Insert\n");
        buildAC();
        //printf("end buildAC\n");
        for(i = 0; i < bh; i++) {
            Find(bmat[i], bw, i, root);
        }
        //for(i = 0; i < bh; i++) {
            //for(j = 0; j < bw; j++) printf("%4d", bid[i][j]);
            //printf("\n");
        //}
        int ans = 0;
        sid[sh] = -1;
        getnext(sid, sh, next);
        //printf("end getnext\n");
        for(j = 0; j < bw; j++) {
            if(j + sw > bw) break;
            for(i = 0; i <= bh; i++) ubid[i] = bid[i][j];
            ans += KMP(ubid, bh, sid, sh, next);
        }
        printf("%d\n", ans);
    }
    return 0;
}
