#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
vector<int>ans;

int deep(int x) {
    return log2(x);
}

int main() {
    int x, y;
    scanf("%d%d", &x, &y);
    if(deep(x) < deep(y)) {
        swap(x, y);
    }
    ans.push_back(x);
    ans.push_back(y);
    while(deep(x) != deep(y)) {
        int father = x >> 1;
        if(father * 2 == x) ans.push_back(father * 2 + 1);
        else ans.push_back(father * 2);
        x = father;
    }
    if(x == y) {
        puts("-1");
        return 0;
    }
    while(x != y) {
        int fx = x >> 1;
        int fy = y >> 1;
        if(fx != fy) {
            if(x == fx * 2) ans.push_back(fx * 2 + 1); else ans.push_back(fx * 2);
            if(y == fy * 2) ans.push_back(fy * 2 + 1); else ans.push_back(fy * 2);
        }
        x = fx;
        y = fy;
    }
    int father;
    while(x / 2 > 1) {
        int father = x / 2;
        if(x == father * 2) ans.push_back(father * 2 + 1);
        else ans.push_back(father * 2);
        x = father;
    }
    if(x == 2) ans.push_back(3);
    else if(x == 3) ans.push_back(2);
    sort(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); i++) printf("%d ", ans[i]);
    return 0;
}
