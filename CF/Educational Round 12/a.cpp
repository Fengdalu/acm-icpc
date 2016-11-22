#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int a, t, w, b;
    cin >> a >> t;
    w = t;
    cin >> a >> t;
    b = t;
    queue<int>q;
    for(int i = 300; i < 24 * 60; i += a) {
        q.push(i + t);
    }
    int h;
    int tot = 0;
    scanf("%d:%d", &h, &t);
    t += h * 60;
    int l = t, r = t + w + b;
    while(q.size()) {
        int x = q.front();
        q.pop();
        if(l < x && x < r) tot++;
    }
    cout << tot;
    return 0;
}
