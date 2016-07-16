#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[500];

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++) scanf("%d", &a[i]);
    if(m == 1) {
        if(n == 1) printf("%d\n%d\n%d\n", 1, 1, 1);
        else printf("%d\n2\n%d %d\n", n, n - 1, 1);
    }
    else {
        vector<int>f, g;
        for(int i = 0; i < m; i++)
        if(a[i] % 2) f.push_back(a[i]);
        else g.push_back(a[i]);
        if(f.size() > 2) {
            puts("Impossible");
            return 0;
        }
        vector<int>ans, ans1;
        if(f.size()) ans.push_back(f[0]);
        for(int i = 0; i < g.size(); i++) ans.push_back(g[i]);
        if(f.size() > 1) ans.push_back(f[1]);
        if(ans[0] == 1) {
            ans1.push_back(2);
            for(int i = 1; i < ans.size(); i++)  {
                int t = ans[i];
                if(i == ans.size() - 1) t--;
                if(t) ans1.push_back(t);
            }
        }
        else {
            ans1.push_back(ans[0] - 1);
            for(int i = 1; i < ans.size(); i++) {
                int t = ans[i];
                if(i == ans.size() - 1) t++;
                ans1.push_back(t);
            }
        }
        for(int i = 0; i < m; i++) cout << ans[i] << " ";
        cout << endl;
        cout << ans1.size() << endl;
        for(int i = 0; i < ans1.size(); i++) cout << ans1[i] << " ";
        cout << endl;
    }
    return 0;
}
