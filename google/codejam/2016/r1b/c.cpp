#include <iostream>
#include <cstdio>
#include <map>
#include <string>
#include <cstring>
#include <set>
using namespace std;

int fa[2010];
int find(int x) {
    if(fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}

string l[2000], r[2000];

int main() {
    int T;
    cin >> T;
    for(int ii = 0; ii < T; ii++) {
        int m;
        cin >> m;
        map<string, int>dic;
        int n = 0;
        for(int i = 0; i < m; i++) {
            string a, b;
            cin >> a >> b;
            if(dic.find(a) == dic.end())
                dic[a] = n++;
            if(dic.find(b) == dic.end())
                dic[b] = n++;
            l[i] = a;
            r[i] = b;
        }
        for(int mask = 0; mask < (1 << n); mask++) {
            set<string>a, b;
            for(int i = 0; i < n; i++)
           if(1 << i & mask) {
                a.insert(l[i]);
                b.insert(r[i]);
            }
            bool flag = true;
            for(int i = 0; i < n; i++)
            if((1 << i & mask) == 0)
                if(a.find(l[i]) == a.end() || b.find(r[i]) == b.end())
                    flag = false;
            if(flag)
                ans = max(ans, ones(mask));
        }
        printf("Case #%d: %d\n", ii, ans);

}}
