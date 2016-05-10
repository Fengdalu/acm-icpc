#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int a[100100];
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    sort(a, a + n);
    int j = 0;
    queue<int>ans;
    for(int i = 1; m >= i; i++)
    if(a[j] == i) j++;
    else { ans.push(i); m -= i;}
    printf("%d\n", ans.size());
    while(ans.size()) {
        printf("%d ", ans.front());
        ans.pop();
    }
}
