#include <bits/stdc++.h>

typedef long long ll;
std::map<int, int>f;
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int x; scanf("%d", &x);
        f[x]++;
    }
    if(f.size() == 1) {
        std::cout << "YES";
    }
    else if(f.size() == 2) {
        std::cout << "YES";
    }
    else if(f.size() > 3) {
        std::cout << "NO";
    }
    else if(f.size() == 3) {
        int a[3];
        int b[3];
        int i = 0;
        for(auto &x: f) {
            a[i] = x.first;
            b[i] = x.second;
            i++;
        }
        if(2 * a[1] != a[0] + a[2]) std::cout << "NO";
        else std::cout << "YES";
    }
    return 0;
}
