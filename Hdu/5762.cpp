#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int f[200010];
int x[100010], y[100010];
int n;
int main() {
    int _T;
    scanf("%d", &_T);
    while(_T--) {
        int n, m;
        scanf("%d%d", &n, &m);
        for(int i = 0; i < n; i++) {
            scanf("%d%d", &x[i], &y[i]);
        }
        if(n > 1000) puts("YES");
        else {
            for(int i = 0; i <= 2 * m; i++) f[i] = 0;
            bool flag = false;
            for(int i = 0; i < n; i++) if(!flag)
                for(int j = i + 1; j < n; j++) if(!flag) {
                    int a = abs(x[i] - x[j]);
                    int b = abs(y[i] - y[j]);
                    f[a + b]++;
                    if(f[a + b] == 2) flag = true;
                }
            if(flag) puts("YES");
            else puts("NO");
        }
    }
    return 0;
}
