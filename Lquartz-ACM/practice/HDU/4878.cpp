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
#define MP make_pair
#define AA first
#define BB second
#define SZ size()
#define BG begin()
#define OP begin()
#define ED end()
#define SQ(x) ((x)*(x))
#define cmax(x, y) x = max(x, y)
#define cmin(x, y) x = min(x, y)

const double eps = 1e-8;
const LL MOD = 5047621;
#define Maxn 50
#define Maxm 190

struct node {
    int flag;
    struct node * fail;
    struct node * next[26];
} trie[Maxn], * root;
int sum, head, tail;
node * que[Maxn];

int P[] = {179, 173, 163};
char str[Maxn][Maxn];
int dp[Maxm][Maxn][Maxn];
int adp[Maxn][Maxn];
int bdp[2][Maxn];
vector<int> prime;
int n;
LL L;

node * newNode() {
    node * p = &trie[sum++];
    p->flag = 1;
    p->fail = NULL;
    for(int i = 0; i < 26; i++) p->next[i] = NULL;
    return p;
}

void Insert(node * root, char * str, int cur, int m, int n) {
    for(int i = 0, k; str[i]; i++) {
        k = str[i] - 'A';
        if(root->next[k] == NULL) {
            root->next[k] = newNode();
        }
        root = root->next[k];
    }
    root->flag = (m + strlen(str)) * prime[n] % P[cur];
}

void buildAC(int cur) {
    head = tail = 0;
    que[tail++] = root;
    root->fail = root;
    while(head < tail) {
        node * now = que[head++];
//        cout << "head " << head << endl;
        for(int i = 0; i < 26; i++) {
            if(now->next[i] != NULL) {
                if(now == root) {
                    now->next[i]->fail = root;
                }
                else {
                    now->next[i]->fail = now->fail->next[i];
                    now->next[i]->flag = 
                    (now->next[i]->flag * now->fail->next[i]->flag) % P[cur];
                }
                que[tail++] = now->next[i];
            }
            else {
                if(now == root) {
                    now->next[i] = root;
                }
                else {
                    now->next[i] = now->fail->next[i];
                }
            }
        }
    }
//    cout << "end " << endl;
}

void Pow1(int cur, int a[Maxn][Maxn], int b[Maxn][Maxn]) {
    int c[Maxn][Maxn] = {0};
    int i, j, k;
    for(k = 0; k < sum; k++) {
        for(i = 0; i < sum; i++) {
            for(j = 0; j < sum; j++) {
                c[i][j] = (c[i][j] + a[i][k] * b[k][j]);
            }
        }
    }
    for(i = 0; i < sum; i++) {
        for(j = 0; j < sum; j++) {
            a[i][j] = c[i][j] % P[cur];
        }
    }
}

void Pow2(int cur, int a[2][Maxn], int b[Maxn][Maxn]) {
    int c[2][Maxn] = {0};
    int i, j, k;
    for(k = 0; k < sum; k++) {
        for(i = 0; i < 1; i++) {
            for(j = 0; j < sum; j++) {
                c[i][j] = (c[i][j] + a[i][k] * b[k][j]);
            }
        }
    }
    for(i = 0; i < 1; i++) {
        for(j = 0; j < sum; j++){
            a[i][j] = c[i][j] % P[cur];
        }
    }
}

void doit(int cur, int m) {
    int i, j, k;
    for(i = 0; i < sum; i++) {
        for( j = 0; j < sum; j++) {
            dp[m][i][j] = 0;
        }
    }
    for(i = 0; i < sum; i++) {
        for(j = 0; j < 26; j++) {
            k = trie[i].next[j] - trie;
            dp[m][i][k] = (dp[m][i][k] + trie[k].flag) % P[cur];
        }
    }
    if(m > 1) {
        Pow1(cur, adp, dp[m]);
    }
    else {
        for(i = 0; i < sum; i++) {
            for(j = 0; j < sum; j++) {
                adp[i][j] = dp[m][i][j];
            }
        }
    }
}
LL extGcd (LL a, LL b, LL &x, LL &y) {
    LL ret = a;
    if (b) {
        ret = extGcd (b, a % b, y, x);
        y -= (a / b) * x;
    } else x = 1, y = 0;
    return ret;
}
//适用于m不是质数 gcd(a,m)==1时有逆元
LL modInv (LL a, LL m) {
    LL x, y;
    extGcd(a,m,x,y);
    return (m+x%m)%m;
}
//if m为质数 [费马小定理]a^(m-1)=1 mod m ==>a^(m-2)是a关于m的逆元
//a_i*x=b_i {%m_i}  m_i可以不互质
//pair<b,m>         x=b {%m}
pair<LL,LL> linearMod( vector<LL>&A,vector<LL>&B,vector<LL>&M ) {
    LL x=0,m=1;
    for ( int i=0; i<A.SZ; i++ ) {
        LL a=A[i]*m,b=B[i]-A[i]*x,d=__gcd( M[i],a );
        if ( b%d )return MP( 0,-1 );
        LL t=b/d*modInv( a/d,M[i]/d )%( M[i]/d );
        x+=m*t;
        m*=M[i]/d;
        x%=m;
    }
    return MP( ( ( x%m )+m )%m,m );
}
int main() {
    int i, j, ca = 0;
//    freopen("1007.in", "r", stdin);
//    freopen("1007_.out", "w", stdout);
    prime.clear();
    prime.PB(-1);
    for(i = 2; i < 400; i++) {
        for(j = 2; j * j <= i; j++) {
            if(i % j == 0) break;
        }
        if(j * j > i) prime.PB(i);
    }
    vector<LL> AA, BB, MM;
    AA.PB(1), AA.PB(1), AA.PB(1);
    MM.PB(P[0]), MM.PB(P[1]), MM.PB(P[2]);
    while(scanf("%d%I64d", &n, &L) != EOF) {
        for(i = 1; i <= n; i++) {
            scanf("%s", str[i]);
        }
        BB.clear();
        for(int cur = 0; cur < 3; cur++) {
            for(i = 1; i <= P[cur]; i++) {
//                cout << "\t P[cur] " << i << endl;
                sum = 0;
                root = newNode();
                for(j = 1; j <= n; j++) {
//                    cout << "Insert " << str[i] << endl;
                    Insert(root, str[j], cur, i, j);
                }
//                cout << "sum " << sum << endl;
                buildAC(cur);
                doit(cur, i);
            }
            for(j = 0; j < sum; j++) bdp[0][j] = 0;
            bdp[0][0] = 1;
            LL t = L / P[cur];
            while(t) {
                if(t & 1) Pow2(cur, bdp, adp);
                Pow1(cur, adp, adp);
                t >>= 1;
            }
            for(j = 1; j <= L % P[cur]; j++) {
                Pow2(cur, bdp, dp[j]);
            }
            int all = 0;
            for(j = 0; j < sum; j++) {
                all = (all + bdp[0][j]) % P[cur];
//                cout << "node " << j << " " << bdp[0][j] << endl;
            }
//            cout << "all " << all << endl;
            BB.PB(all);
        }
        pair<LL, LL> gg = linearMod(AA, BB, MM);
        ca++;
        cout << "Case #" << ca << ": " << gg.AA << endl;
    }
    return 0;
}

/*
2 3
AB
BB
4 1
A
B
C
D
1 2
A
3 3
ZZ
ZZA
ZZZ 
4 100000000000000000
CCCCCCCC
CCCCCCCCC
CCCCCCCCCC
CCCCCCCCCCC
*/
