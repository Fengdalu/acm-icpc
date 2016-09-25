//#pragma comment(linker,"/STACK:102400000,102400000")
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <map>
#include <set>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <numeric>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <functional>

using namespace std;

#define PB push_back
#define MP make_pair
#define AA first
#define BB second
#define BGN begin()
#define END end()
#define SZ size()
#define SORT(p) sort(p.BGN,p.ED)
#define CLR(a, b) memset(a, (b), sizeof(a))
#define mabs(x) (x < 0 ? -x : x)
#define sqr(x) ((x)*(x))
#define ITE ::iterator
typedef long long LL;
typedef pair<int, int> PII;
typedef vector <int> VI;
typedef set < int > SI;

int n, t, c;
int a[210000];

int main() {
    int Test;
    while(cin >> n >> t >> c) {
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int big = 0;
        for(int i = 0; i < c; i++) {
            if(a[i] > t) big++;
        }
        int ans = 0;
        if(big == 0) ans++;
        for(int i = c; i < n; i++) {
            if(a[i - c] > t) big--;
            if(a[i] > t) big++;
            if(big == 0) {
                ans++;
            }

        }
        cout << ans <<endl;
    }
    return 0;
}
