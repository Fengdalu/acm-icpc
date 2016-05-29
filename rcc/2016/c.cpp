#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

char s[1000];
string ans[10];
int n, m;

bool dfs(int i, int mm) {
    if(i == n && mm == m) {
        for(int i = 0; i < m; i++)
            for(int j = i + 1; j < m; j++)
                if(ans[i] == ans[j]) return false;
        return true;
    }
    if(i == n) return false;

    ans[mm].push_back(s[i]);
    if(dfs(i + 1, mm)) return true;
    if(mm != m) if(dfs(i + 1, mm + 1)) return true;

    ans[mm] = ans[mm].substr(0, ans[mm].size() - 1);

    if(ans[mm].size())
       if(mm != m)
           if(dfs(i, mm + 1)) return true;
    return false;
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%s", s);
        n = strlen(s);
        scanf("%d", &m);
        if(n >= m * (m + 1) / 2) {
            printf("YES\n");
            int J = 0;
            for(int i = 1; i < m; i++) {
                for(int j = 0; j < i; j++) {
                    printf("%c", s[J++]);
                }
                printf("\n");
            }
            while(J < n) printf("%c", s[J++]);
            printf("\n");
        }
        else {
            for(int i = 0; i < m; i++) ans[i] = "";
            if(dfs(0, 0)) {
                printf("YES\n");
                for(int i = 0; i < m; i++)
                    printf("%s\n", ans[i].c_str());
            }
            else {
                printf("NO\n");
            }
        }
    }
    return 0;
}
