#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <iostream>
using namespace std;

typedef long long ll;
int d[100010];
int main() {
    int _T;
    scanf("%d", &_T);
    int n, k;
    while(_T--) {
        scanf("%d%d", &n, &k);
        priority_queue<int>q;
        for(int i = 0; i < n - 1; i++) scanf("%d", &d[i]);
        for(int i = 0; i < n - 1; i++) q.push(d[i]);
        ll ans = 0;
        for(int i = 0; i < n - 1; i++) ans += d[i];
        k--;
        while(q.size() && k) {
            ans -= q.top(); q.pop();
            k--;
        }
        cout << ans + n << endl;
    }
    return 0;
}
