#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>

const int N = 2000;
char s[N];
const int inf = 1e9;


int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    int ans = inf;
    std::set<int> f;
    bool flag = true;
    for(int i = 0; i < n; i++) {
        scanf("%s", s);
        int a = 0;
        int b = 0;
        for(int j = 0; j < m; j++) if(s[j] == 'G') a = j;
        else if(s[j] == 'S') b = j;
        if(b > a)
            f.insert(b - a);
        else flag = false;
    }
    if(!flag) puts("-1"); else printf("%d\n", (int)f.size());
    return 0;
}

