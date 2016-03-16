#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>

std::pair<int, int>a[2000], b[2000];
int cnt1, cnt2;
char s[2000][2000];
int n, m;

int dist(std::pair<int, int> a, std::pair<int, int>b) {
    return std::abs(a.first - b.first) + std::abs(a.second - b.second);
}

int main() {
    while(true) {
        scanf("%d%d", &n, &m);
        if(!n && !m) break;
        for(int i = 0; i < n; i++) scanf("%s", s[i]);
        cnt1 = cnt2 = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++) {
                if(s[i][j] == 'H') a[cnt1++] = std::make_pair(i, j);
                if(s[i][j] == 'C') b[cnt2++] = std::make_pair(i, j);
            }
        int p = 0, r = 0;
        for(int i = 0; i < cnt1; i++)
            for(int j = 0; j < cnt2; j++)  {
                if(dist(a[i], b[j]) < dist(a[p], b[r]))  {
                    p = i;
                    r = j;
                }
            }
        printf("%d %d %d %d\n", a[p].first, a[p].second, b[r].first, b[r].second);
    }
}
Distributed under GPLv3. | Project Homepage | Developer: 51isoft crccw | Current Style: Cerulean.

Select Style:   Fluid Width?
