#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int a[1000], b[1000];
char s[1000];
int n, m;

int main() {
    int t;
    scanf("%d", &t);
    int n, m;
    while(t--) {
        scanf("%d%d", &n, &m);
        for(int i = 0; i < n; i++) scanf("%d", &a[i]);
        for(int i = 0; i < m; i++) scanf("%d", &b[i]);
        sort(a, a + n);
        reverse(a, a + n);
        sort(b, b + m);
        int tot = 0;
        scanf("%s", s);
        int p = 0, q = 0;
        int ans = 0;
        for(int i = 0; i < n + m; i++)  {
            if(s[i] == '+') tot += a[p++];
            else if(tot >= b[q]) tot -= b[q++];
            else ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}
