#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

char s[100010];
int a[100010];
bool vis[100010];
int main()  {
    int n;
    scanf("%d", &n);
    scanf("%s", s);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    int p = 0;
    while(true) {
        if(p < 0 || p >= n) break;
        if(vis[p]) {
            cout << "INFINITE";
            return 0;
        }
        vis[p] = true;
        if(s[p] == '>') p += a[p];
        else p -= a[p];
    }
    cout << "FINITE";
}

