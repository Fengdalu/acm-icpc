#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
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
const LL MOD = 1000000007;
int n;
vector <LL> a;
int main() {
    int i, j;
    LL k;
    //freopen("", "r", stdin);
    freopen("H_01.out", "w", stdout);
    srand((unsigned int)time(NULL));
    for(i = 1; i <= 25000; i++) {
        k = rand() % MOD;
        k = (k * k) % MOD;
        k = (k * k) % MOD;
        a.PB(k*MOD/2-k*k + MOD);
    }
    for(i = 25001; i <= 50000; i++) {
        a.PB(a[i % 250]);
    }
//    for(i = 50000; i > 0; i--) a.PB(i);
    for(i = 0; i < a.SZ; i++) {
        cout << a[i] << endl;
    }
    return 0;
}
