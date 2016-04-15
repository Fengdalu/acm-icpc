#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;

map<string, int>f;
string o[10000];
char s[1000];

int main() {
    int n;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    int cnt;
    for(int i = 0; i < n; i++)  {
        scanf("%s", s);
        string g(s);
        int pos = g.find(".");
        g = g.substr(pos + 1, g.size() - pos);
        if(f.find(g) == f.end()) o[cnt++] = g;
        f[g]++;
    }
    for(int i = 0; i < cnt; i++) {
        printf("%s: %d\n", o[i].c_str(), f[o[i]]);
    }
    return 0;
}

