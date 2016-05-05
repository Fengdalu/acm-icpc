#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int ans[1000010];
int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    long long a = 0, b = 0;
    for(int i = 0; i < q; i++) {
        int x;
        scanf("%d", &x);
        if(x == 1) {
            int y;
            scanf("%d", &y);
            a += y;
            b += y;
        }
        else {
            if(a % 2 == 0) { a++; b--; }
            else { a--; b++; }
        }
    }
    for(int i = 0; i < n; i++) {
        if(i % 2 == 0)  ans[(i + a % n + n) % n] = i + 1;
        else ans[(i + b % n + n) % n] = i + 1;
    }
    for(int i = 0; i < n; i++)
        cout << ans[i] << " ";
    return 0;
}

