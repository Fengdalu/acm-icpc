#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int a[200];
int main() {
    int n, k, m;
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 0; i < k; i++) scanf("%d", &a[i]);
    int tot = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int x;
            scanf("%d", &x);
            int p;
            for(p = 0; p < k; p++)
                if(a[p] == x) break;
            tot += p + 1;
            while(p > 0) {
                a[p] = a[p - 1];
                p--;
            }
            a[0] = x;
        }
    }
    cout << tot << endl;
}
