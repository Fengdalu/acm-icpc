#include <bits/stdc++.h>

const int N = 1e5+100;

typedef std::pair<int, int> pii;
#define mp std::make_pair
int a[N], b[N], c[N];
std::map<pii, std::vector<pii> >q;

int main() {
    int n; 
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d%d%d", a + i, b + i, c + i);
    for(int i = 0; i < n; i++) {
        if(b[i] < a[i]) std::swap(a[i], b[i]);
        if(c[i] < a[i]) std::swap(a[i], c[i]);
        if(c[i] < b[i]) std::swap(c[i], b[i]);
        int x = a[i], y = b[i], z = c[i];
        if(x == y && y == z)
            q[mp(x, y)].push_back(mp(z, i));
        else if(x == y) {
            q[mp(x, y)].push_back(mp(z, i));
            q[mp(y, z)].push_back(mp(x, i));
        }
        else if(y == z) {
            q[mp(y, z)].push_back(mp(x, i));
            q[mp(x, y)].push_back(mp(z, i));
        }
        else {
            q[mp(x, y)].push_back(mp(z, i));
            q[mp(x, z)].push_back(mp(y, i));
            q[mp(y, z)].push_back(mp(x, i));
        }
    }
    pii ans;
    int R = -1;
    for(auto &t : q) {
        int C = std::min(t.first.second, t.first.first);
        std::vector<pii> &V = t.second;
        std::sort(V.begin(), V.end(), std::greater<pii>());
        C = std::min(C, V[0].first);
        if(C > R) { ans.first = ans.second = V[0].second; R = C; }
        if(V.size() > 1) {
            C = std::min(std::min(t.first.second, t.first.first), V[0].first + V[1].first);
            if(C > R) {
                ans.first = V[0].second;
                ans.second = V[1].second;
                R = C;
            }
        }
    }
    if(ans.first > ans.second) std::swap(ans.first, ans.second);
    if(ans.first == ans.second) printf("1\n%d\n", ans.first + 1);
    else printf("2\n%d %d\n", ans.first + 1, ans.second + 1);
    return 0;
}
