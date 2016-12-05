#include <bits/stdc++.h>

using namespace std;
const int N = 2e6+199;
int n;
int a[2][N];
int c[N];

bool check(int w) {
    for(int j = 0; j < 2; j++) {
        vector<int> v;
        for(int i = 0; i < n; i++)
            if(a[j][i] > w) v.push_back(a[j][i]);
        int sz = v.size();
        if(sz % 2 != 0) return false;
        for(int i = 0; i < sz; i += 2)
            if(v[i] != v[i + 1]) return false;
    }
    return true;
}

int main() {
    scanf("%d", &n);
    int cnt = 0;
    for(int j = 0; j < 2; j++) {
        for(int i = 0; i < n; i++) scanf("%d", &a[j][i]);
        for(int i = 0; i < n; i++) c[cnt++] = a[j][i];
    }
    c[cnt++] = 0;
    sort(c, c + cnt);
    cnt = unique(c, c + cnt) - c;
    int l = 0, r = cnt - 1;
    while(l < r) {
        int mid = (l + r) >> 1;
        if(check(c[mid])) r = mid;
        else l = mid + 1;
    }
    printf("%d\n", c[l]);
}
