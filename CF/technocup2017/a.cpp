#include <bits/stdc++.h>

typedef long long ll;
std::vector<ll> q;
typedef long long ll;
bool cal(ll a, ll b) {
    if(a > b) return false;
    if(a == b) {
        return true;
    }
    if(cal(a * 2, b)) {
        q.push_back(a * 2);
        return true;;
    }
    if(cal(a * 10 + 1, b)) {
        q.push_back(a * 10 + 1);
        return true;
    }
    return false;
}

int main() {
    int a, b; scanf("%d%d", &a, &b);
    if(cal(a, b)) {
        puts("YES");
        q.push_back(a);
        std::reverse(q.begin(), q.end());
        printf("%d\n", (int)q.size());
        for(int i = 0; i < q.size(); i++)
            printf("%d ", (int)q[i]);
        return 0;
    }
    else puts("NO");
}

