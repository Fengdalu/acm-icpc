#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int a[10000];
int main() {
    int n;
    int tot = 0;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    int l = n + 1, r = -1;
    int add = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] == 0) {
            if(l <= r) {
                tot += r - l + 1;
                l = n + 1;
                r = -1;
                add++;
            }
        }
        else {
                l = min(i, l);
                r = max(i, r);
        }
    }
    if(l <= r) {
        tot += r - l + 1;
        add++;
    }
    cout << max(0, tot + add - 1) << endl;
}
