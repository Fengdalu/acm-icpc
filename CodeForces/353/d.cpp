#include <cstdio>
#include <cstring>
#include <iostream>
#include <set>
using namespace std;

set<pair<int, int> >a, b;
typedef set<pair<int, int> >::iterator itt;
int v[100010];
int fa[100010];
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &v[i]);
        a.insert(make_pair(-v[i], i));
        b.insert(make_pair(v[i], i));
    }
    for(int i = 1; i <= n; i++) {
        itt ia = a.find(make_pair(-v[i], i));
        itt ib = b.find(make_pair(v[i], i));
        if(ia != a.end()) {
            a.erase(ia);
            b.erase(ib);
        }
        ia = a.upper_bound(make_pair(-v[i], -1));
        ib = b.upper_bound(make_pair(v[i], -1));
        int id;
        if(ia != a.end()) {
            id = ia->second;
            cout << id << endl;
            fa[id] = v[i];
            b.erase(b.find(make_pair(v[id], id)));
            a.erase(a.find(make_pair(-v[id], id)));
        }
        if(ib != b.end()) {
            id = ib->second;
            cout << id << endl;
            fa[id] = v[i];
            b.erase(b.find(make_pair(v[id], id)));
            a.erase(a.find(make_pair(-v[id], id)));
        }
        cout << endl;
    }
    for(int i = 2; i <= n; i++) printf("%d ", fa[i]);
}
