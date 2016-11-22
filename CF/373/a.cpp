#include <bits/stdc++.h>

int a[100];
int main() {
    int n; scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", a + i);
    if(n == 1) {
        if(a[0] == 0) printf("UP");
        else if(a[0] == 15) printf("DOWN");
        else puts("-1");
        return 0;
    }
    if(a[n - 1] > a[n - 2]) {
        if(a[n - 1] == 15) printf("DOWN");
        else printf("UP");
    }
    else {
        if(a[n - 1] == 0) printf("UP");
        else printf("DOWN");
    }
    return 0;
}

