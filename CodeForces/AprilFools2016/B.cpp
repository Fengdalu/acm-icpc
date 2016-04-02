#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

bool vis[1 << 20];
int a[100], b[100];
int n;

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    int d = 0;
    int p, q;
    for(int d = 0; d <= 10000000; d++) {
        int mask = 0;
        for(int i = 0; i < n; i++)
        if(d % a[i] == b[i]) mask |= 1 << i;
        if(mask != 0) p++;
        else q++;
    }
    printf("%.7f", (double)p / (p + q));
}
