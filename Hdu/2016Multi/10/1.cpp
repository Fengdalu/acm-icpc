#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> PII;
#define PB(x) push_back(x)
#define SZ size()
#define AA first
#define BB second
#define MP(x, y) make_pair(x, y)

int a[100010];
double qry(int l1, int r1, int l2, int r2, int w) {
    int w1 = r1 - l2, w2 = r2 - l2;
    if(l1 <= l2 && r2 <= r1) {
        if(w <= l2 - l1) {
            return a[l1 + w - 1];
        }
        else if(w <= r2 - l1 + 1 + r2 - l2 + 1) {
            return a[l2 + (w - (l2 - l1) + 1) / 2 - 1];
        }
        else {
            w -= (r2 - l1 + 1 + r2 - l2 + 1);
            return a[r2 + w];
        }
    }
    else if(r1 < l2){
        if(w <= r1 - l1 + 1) return a[l1 + w - 1];
        else return a[l2 + w - (r1 - l1 + 1) - 1];
    }
    else {
        if(w <= l2 - l1) {
            return a[l1 + w - 1];
        }
        else if(w <= (r1 - l1 + 1) + (r1 - l2 + 1)){
            return a[l2 + (w - (l2 - l1) + 1) / 2 - 1];
        }
        else {
            w -= r1 - l1 + 1 + r1 - l2 + 1;
            return a[r1 + w];
        }
    }
    return -1;
}

void run() {
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    while(m--) {
        int l1, r1, l2, r2;
        scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
        if(l1 > l2) {
            swap(l1, l2); swap(r1, r2);
        }
        int sum = r1 - l1 + 1 + r2 - l2 + 1;
        if(sum & 1)  {
            printf("%.1f\n", 1.0 * qry(l1, r1, l2, r2, sum / 2 + 1));
        }
        else {
            printf("%.1f\n", (qry(l1, r1, l2, r2, sum / 2 + 1) + qry(l1, r1, l2, r2, sum / 2)) / 2.0);
        }
    }
}

int main() {
    int _T; scanf("%d", &_T);
    while(_T--) {
        run();
    }
    return 0;
}
