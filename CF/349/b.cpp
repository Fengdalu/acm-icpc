#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

int a[100010];
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    sort(a, a + n);
    reverse(a, a + n);
    long long tot = 0;
    bool flag = false;
    for(int i = 1; i < n; i++)  {
        tot += a[i];
        if(tot >= a[0]) flag =true;
    }
    if(flag) cout << 1 << endl;
    else cout << a[0] - tot + 1 << endl;

}
