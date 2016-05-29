#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int vis[1000];
char op[10];

int main() {
    int t;
    scanf("%d", &t);
    int n, q;
    while(t--) {
        scanf("%d%d", &n, &q);
        for(int i = 1; i <= n; i++) vis[i] = true;
        while(q--) {
            int x;
            scanf("%s%d", op, &x);
            if(op[0] == '?') {
                int c = 0;
                for(int j = 1; j <= n; j++) {
                    if(vis[j]) c++;
                    if(c == x) {
                        printf("%d\n", j);
                        break;
                    }
                }
            }
            else vis[x] = vis[n - x + 1] =  false;
        }
    }
    return 0;
}
