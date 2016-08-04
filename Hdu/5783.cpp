#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <stack>
using namespace std;

int a[1001000];
int main() {
    int n;
    while(~scanf("%d", &n)) {
        for(int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        int ans = 0, pre = 0;
        stack<int>q;
        int tot = 0;
        for(int i = 0; i < n; i++) {
            pre = a[i];
            while(q.size() && pre < 0) {
                pre += q.top(); q.pop();
                tot--;
            }
            tot++; q.push(pre);
            pre = 0;
        }
        cout << tot << endl;
   }
    return 0;
}
