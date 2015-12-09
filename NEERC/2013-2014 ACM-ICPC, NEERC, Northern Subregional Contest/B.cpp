#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int c[20];
string s;
string names[20];
vector< pair<int, int> >Q;
int n, m, tot;
int cnt;

int cmp(pair<int, int>a, pair<int, int>b) {
    if(a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}

int main() {
    freopen("bad.in", "r", stdin);
    freopen("bad.out", "w", stdout);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> names[i];
    }
    for(int i = 0; i < m; i++) {
        cin >> s;
        int flg = 0;
        for(int j = 0; j < n; j++) {
            if(s[j] == 'X') flg++;
        }
        tot++;
        if(flg == 0 || flg >= 2) { cnt++; continue; }
        for(int j = 0; j < n; j++) {
            if(s[j] == 'X')c[j]++;
        }
    }
    for(int i = 0; i < n; i++) Q.push_back(make_pair(c[i], i));
    sort(Q.begin(), Q.end(), cmp);
    for(int i = 0; i < Q.size(); i++) {
        printf("%s %.2f%%\n", names[Q[i].second].c_str(), 100.0 * Q[i].first / tot);
    }
    printf("Invalid %.2f%%", 100.0 * cnt / tot);
    return 0;
}
