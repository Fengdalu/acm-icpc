#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

const int maxn = 10010;
long long per[maxn], ans[maxn];
long long ans1[maxn];
int main() {
    long long x, m, k, c;
    int t;
    scanf("%d", &t);
    for(int ii = 1; ii <= t; ii++) {
        cin >> x >> m >> k >> c;
        for(int i = 0; i < k; i++) per[i] = i;
        for(int i = 0; i < k; i++) ans[i] = i;
        while(m) {
            if(m % 2 == 1) {
                for(int i = 0; i < k; i++)
                    ans1[i] = (per[ans[i]] * 10 + x) % k;
                for(int i = 0; i < k; i++)
                    ans[i] = ans1[i];
            }
            m /= 2;
            for(int i = 0; i < k; i++)
                ans1[i] = (per[per[i]] * 10 + x) % k;
            for(int i = 0; i < k; i++)
                per[i] = ans1[i];
        }
        bool flag = false;
        if(ans[0] == c) flag = true;
        printf("Case #%d:\n", ii);
        if(flag) puts("Yes");
        else puts("No");
    }
    return 0;
}

