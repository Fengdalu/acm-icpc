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
#define Maxn 1111
#define Maxm 111111

//HDU_3068
const int N=2010000;
int len, p[N];
char s[N], str[N];

void Manacher (char str[], int p[]) {
    int i;
    int mx = 0;
    int id;
    for (i=len; i < N; i++)
        str[i] = 0; //没有这一句有问题。。就过不了ural1297，比如数据：ababa aba
    for (i=1; i<len; i++) {
        if ( mx > i )
            p[i] = min ( p[2*id-i], p[id]+id-i );
        else
            p[i] = 1;
        for (; str[i+p[i]] == str[i-p[i]]; p[i]++)
            ;
        if ( p[i] + i > mx ) {
            mx = p[i] + i;
            id = i;
        }
    }
}

void init() {
    int i, j, k;
    str[0] = '$';
    str[1] = '#';
    for (i=0; i<len; i++) {
        str[i*2+2] = s[i];
        str[i*2+3] = '#';
    }
    len = len*2+2;
    s[len] = 0;
}

int main() {
    int i, ans, ca = 0;
    while (scanf ("%s", s) != EOF) {
        len = strlen (s);
        if(strcmp(s, "END") == 0) break;
        init();
        Manacher (str, p);
        ans = 0;
        for (i=0; i<len; i++)
            if (p[i]>ans)
                ans = p[i];
        ca++;
        printf ("Case %d: %d\n", ca, ans-1);
    }
    return 0;
}
