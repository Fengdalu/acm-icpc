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
const LL MOD = 1000000007;
int hash(int h)   
{   
    h ^= (h >> 20) ^ (h >> 12);   
    return h ^ (h >> 7) ^ (h >> 4);   
}  

int main() {
    int i, j, k;
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    LL key = (1<<5)-1;
    for(k = 0; k < 10000; k++) {
        key = k;
        for(i = 0, j = 0; i < k *10; i++) {
            if(hash(i) == hash(key)) {
                printf("%d\n", i);
                j++;
            }
            
        }
        
        printf("%d j = %d\n", k, j);
    }
    return 0;
}
