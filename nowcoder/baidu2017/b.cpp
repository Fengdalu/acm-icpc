#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int run() {
    int n, m;
    if(scanf("%d%d", &n, &m) == -1) return 0;
    vector<bool>in(201, 0);
    int ans = 0;
    queue<int>q;
    while(m--) {
        int x; scanf("%d", &x);
        if(!in[x]) ans++;
        else continue;
        in[x] = true;
        q.push(x);
        while(q.size() > n) {
            in[q.front()] = 0;
            q.pop();
        }
    }
    printf("%d\n", ans);
    vector<bool>().swap(in);
    return 1;
}

int main() {
    while(run());
    return 0;
}
