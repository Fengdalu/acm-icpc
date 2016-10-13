#include <bits/stdc++.h>

int a[30][30];


int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            scanf("%d", &a[j][i]);
    bool flag = false;
    for(int i = 0; i < m; i++) if(!flag)
        for(int j = i; j < m; j++) if(!flag) {
            std::swap(a[i], a[j]);

            bool tmp = true;
            for(int i = 0; i < n; i++) {
                int t = 0;
                for(int j = 0; j < m; j++)
                    if(a[j][i] != j + 1) t++;
                if(t > 2) tmp = false;
            }
            if(tmp) flag = true;
            std::swap(a[i], a[j]);
        }
    if(flag) puts("YES");
    else puts("NO");
    return 0;
}

