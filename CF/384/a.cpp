#include <bits/stdc++.h>

using namespace std;

char f[100100];
int main() {
    int n, s, t;
    scanf("%d%d%d%s", &n, &s, &t, f);
    s--; t--;
    printf("%d\n", f[s] == f[t] ? 0 : 1);
    return 0;
}
