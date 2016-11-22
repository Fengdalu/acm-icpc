#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

map<int, int>a;
int x[200010], y[200010];
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        a[x]++;
    }
    int m;
    scanf("%d", &m);
    for(int i = 0; i < m; i++) scanf("%d", &x[i]);
    for(int i = 0; i < m; i++) scanf("%d", &y[i]);
    int tot = 0, tot2 = 0, id = 0;
    for(int i = 0; i < m; i++) {
        int t = a[x[i]];
        int q = a[y[i]];
        if(t > tot) { tot = t; tot2 = q; id = i; }
        else if(t == tot && q > tot2) { tot = t; tot2 = q; id = i; }
    }
    cout << id + 1 << endl;
}
