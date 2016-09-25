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

int n, ans, now;

int main() {
    int Test;
    while(cin >> n) {
        ans = 0, now = 0;
        int x;
        for(int i = 0; i < n; i++) {
            cin >> x;
            if(x == -1) {
                if(now > 0) {
                    now--;
                }
                else {
                    ans++;
                }
            }
            else {
                now += x;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
