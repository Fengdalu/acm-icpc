#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int maxn = 2000100;
int n;
int prime[maxn];
int a[maxn];
int c[maxn];

int main() {
    int cnt = 0;
    prime[1] = false;
    for(int i = 2; i < maxn; i++) {
        if(!prime[i]) a[cnt++] = i;
        for(int j = 0; j < cnt && a[j] * i < maxn; j++) {
            prime[i * a[j]] = true;
            if(i % a[j] == 0) break;
        }
    }
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &c[i]);
    int ans = 0;
    queue<int>q;
    for(int i = 0; i < n; i++)
    if(c[i] == 1) q.push(1);
    ans = max(0, ans);
    int pls = 0;
    if(q.size()) {
        for(int i = 0; i < n; i++)
            if(!prime[1 + c[i]] && c[i] != 1) {
                q.push(c[i]);
                break;
            }
    }
    else {
        for(int i = 0; i < n; i++)
        if(!pls)
            for(int j = i + 1; j < n; j++)
                if(!pls)
                if(!prime[c[i] + c[j]]) {
                    q.push(c[i]);
                    q.push(c[j]);
                    pls = true;
                }
    }
    if(!q.size()) q.push(c[0]);
    printf("%d\n", (int)q.size());
    while(!q.empty()) {
        printf("%d ", q.front()) ;
        q.pop();
    }
    return 0;
}

