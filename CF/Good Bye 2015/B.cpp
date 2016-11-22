#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;
#define PII pair<int, int>
#define AA first
#define BB second
#define MP(x, y) make_pair(x, y)
#define LL long long
#define OP begin()
#define ED end()
#define PB(x) push_back(x)
#define SZ size()

LL a, b;
vector<LL>s;
vector<LL>f;

int main() {
    cin >> a >> b;
    for(int i = 0; i <= 62; i++) s.PB(1LL << i);
    for(int i = 1; i < s.SZ; i++) {
        LL x = 0;
        for(int j = 0; j < i; j++) x |= s[j];
        for(int j = 0; j < i - 1; j++) if(x - s[j] != 0) f.PB(x - s[j]);
    }
    sort(f.OP, f.ED);
    f.resize(unique(f.OP, f.ED) - f.OP);
    int ans = 0;
    for(int i = 0; i < f.SZ; i++) if(a <= f[i] && f[i] <= b){
        ans++;
    }
    cout << ans << endl;
    return 0;
}
