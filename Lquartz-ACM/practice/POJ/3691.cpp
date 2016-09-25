#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

#define Maxn 1005

struct node {
    bool is;
    struct node * next[4];
    struct node * fail;
}Tree[Maxn], *root;
char dna[Maxn];
int n;
char str[Maxn];

node * que[Maxn];
int head, tail;

int f[Maxn][Maxn];
int tot;

int tokey(char c) {
    switch(c) {
        case 'A' : return 0;
        case 'G' : return 1;
        case 'C' : return 2;
        case 'T' : return 3;
    }
}

struct node * newNode() {
    struct node * p = &Tree[tot++];
    p->is = false;
    p->fail = NULL;
    for(int i = 0; i < 4; i++) p->next[i] = NULL;
    return p;
}

void Insert(node * root, char* str) {
    int i, k;
    for(i = 0; str[i]; i++) {
        k = tokey(str[i]);
        if(root->next[k] == NULL) {
            root->next[k] = newNode();
        }
//        if(root->is) root->next[k]->is = true;
        root = root->next[k];
    }
    root->is = true;
}

void buildAC(node * root) {
    head = tail = 0;
    que[tail++] = root;
    root->fail = root;
    while(head < tail) {
        node * now = que[head++];
        for(int i = 0; i < 4; i++) {
            if(now->next[i] != NULL) {
                if(now == root) now->next[i]->fail = root;
                else {
                    now->next[i]->fail = now->fail->next[i];
                    now->next[i]->is |= now->fail->next[i]->is;
                }
                que[tail++] = now->next[i];
            }
            else {
                if(now == root) now->next[i] = root;
                else now->next[i] = now->fail->next[i];
            }
        }
    }
}
#define cmin(x,y) x=min(x,y)
#define MOD 10007
int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out1.txt", "w", stdout);
    int i, j, k, l, to, CA = 0;
    while(scanf("%d", &n) != EOF && n) {
        CA++;
        tot = 0;
        root = newNode();
        for(i = 0; i < n; i++) {
            scanf("%s", str);
            Insert(root, str);
        }
        buildAC(root);
        dna[0] = '#';
        scanf("%s", dna + 1);
        int len = strlen(dna);
        for(i = 0; i <= len; i++) {
            for(j = 0; j < tot; j++) {
                f[i][j] = MOD;
            }
        }
        f[0][0] = 0;
        for(i = 1; i < len; i++) {
            for(j = 0; j < tot; j++) {
                if(f[i - 1][j] != MOD) {
                    k = tokey(dna[i]);
                    node * cur = &Tree[j];
                    for(l = 0; l < 4; l++) {
                        to = cur->next[l] - Tree;
                        if(l == k) {
                            if(!Tree[to].is)
                                cmin(f[i][to], f[i - 1][j]);
                        }
                        else {
                            if(!Tree[to].is)
                                cmin(f[i][to], f[i - 1][j] + 1);
                        }
                    }
                }
            }
        }
//        for(i = 0; i < len; i++) {
//            for(j = 0; j < tot; j++) printf("%5d ", f[i][j]); printf("\n");
//        }
        int ans = MOD;
        for(j = 0; j < tot; j++) {
            cmin(ans, f[len - 1][j]);
        }
        if(ans == MOD) ans = -1;
        printf("Case %d: %d\n", CA, ans);
//        printf("%d\n", n);
    }
    return 0;
}

/*
2
AAA
AAG
AAAG    
2
A
TG
TGAATG
4
A
G
C
T
AGT

4
A
AT
C
CG
ATCG
31
TAACGCTGTTCT
TCCACTTAGCGG
TCCAGATATTCAT
AACCGGACG
CCCGCTGGCACTA
GAGTCAGG
AATTTT
A
GCTTATCGA
GGGGATGGCCGAC
AGGATCGCGGCG
T
CTTGACCAAGCAGA
TCGGCTGCGGAAGC
GTCGAGAGGCTACA
ACTCAATTAG
TACCGTTG
GGGTTATATGATATACCTG
GTTTAC
G
CACGAAATGATCCGTCC
CCTTTAGACACTAGCG
CTGTA
AGGTGCCTCCGT
AATCATCGATCG
ATG
CCTTA
G
AGGTGTCC
TCGA
TTGATTA
CGATGCCAAAAGTAGGCTTCTGCCTTCCAGGCAAATTCCCAGCTTTTTGACCCTCGTCGTGGGCGTTACATTTCAGGCCACATGGAGCAACCAACGAGTGG
0
*/
