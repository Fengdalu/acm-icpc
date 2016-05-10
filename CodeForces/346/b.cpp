#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string s[100010];
vector<pair<int, int> >a[100010];
char buf[100010];
int cmp(pair<int, int>a, pair<int, int>b) {
    if(a.first == b.first) return s[a.second] < s[b.second];
    return a.first > b.first;
}
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++) {
        int p, c;
        scanf("%s%d%d", buf, &p, &c);
        s[i] = string(buf);
        a[p].push_back(make_pair(c, i));
    }
    for(int i = 1; i <= m; i++) sort(a[i].begin(), a[i].end(), cmp);
    for(int i = 1; i <= m; i++) {
        if(a[i].size() > 2 && a[i][1].first == a[i][2].first) printf("?");
        else printf("%s %s", s[a[i][0].second].c_str(), s[a[i][1].second].c_str());
        puts("");
    }
}
