#include <cstdio>
#include <cstring>
#include <iostream>
#include <set>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int x;
    set<int>a;
    set<int>s;
    set<int>::iterator it;
    scanf("%d", &x);
    s.insert(x);
    for(int i = 2; i <= n; i++) {
        int x;
        scanf("%d", &x);
        it = s.upper_bound(x);
        if(it != s.end() && a.find(*it) == a.end()) {
            printf("%d ", *it);
            a.insert(*it);
        }
        else {
            it--;
            printf("%d ", *it);
        }
        s.insert(x);
    }
    return 0;
}
