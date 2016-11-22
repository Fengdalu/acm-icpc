#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char buf[1000000];
int n;
bool vis['z' + 1];
int main() {
    scanf("%d", &n);
    scanf("%s", buf);
    if(n > 26) { cout << -1 << endl; return 0; }
    int tot = 0;
    for(int i = 0; i < n; i++) {
        if(vis[buf[i]])  tot++;
        vis[buf[i]] = true;
    }
    cout << tot << endl;
    return 0;
}
