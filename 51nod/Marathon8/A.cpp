#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int Maxn = 1000010;
char buf[Maxn];
int f1[Maxn], f2[Maxn];
int n;

int main() {
    scanf("%s", buf + 1);
    n = strlen(buf + 1);
    memset(f1, 0, sizeof f1);
    memset(f2, 0, sizeof f2);
    for(int i = 1; i <= n; i++) {
        if(buf[i] == '0') f1[i]++;
        else f2[i]++;
        f1[i] += f1[i - 1];
        f2[i] += f2[i - 1];
    }
    if(f2[n] == n) { printf("%d\n", n); return 0; }
    if(f1[n] == n) { printf("%d\n", 0); return 0; }
    for(int i = 1; i < n; i++) {
        int cnt1 = f1[i], cnt2 = f2[n] - f2[i];
        if(cnt1 == cnt2) {
            printf("%d\n", i);
            return 0;
        }
    }
    puts("-1");
    return 0;
}

