#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
using namespace std;

typedef set<int>::iterator IT;
int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    set<int>s;
    for(int i = 2; i * i <= k; i++)
    if(k % i == 0) {
        int t = 1;
        do {
            t *= i;
            k /= i;
        }while(k % i == 0);
        s.insert(t);
    }
    if(k != 1) s.insert(k);
    for(int i = 0; i < n; i++) {
        queue<IT>q;
        int c;
        scanf("%d", &c);
        for(IT it = s.begin(); it != s.end(); it++) {
            if(c % *it == 0) {
                q.push(it);
            }
        }
        while(q.size()) {
            s.erase(q.front());
            q.pop();
        }
    }
    if(s.size()) puts("No");
    else puts("Yes");
    return 0;
}
