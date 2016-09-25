#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
#define Maxn 21111
#define Maxm 121111
#define PB push_back
#define MP make_pair
#define AA first
#define BB second
int ok[Maxm];
int a[100];
PII g[6 * 100];
int tot;
int ca = 0;
int sum = 0;

int main() {
    int i, j, k, u, v, w;
    while(true) {
        for(i = 1; i <= 6; i++) scanf("%d", &a[i]);
        sum = 0;
        for(i = 1; i <= 6; i++) sum += i * a[i];
        if(sum == 0) break;
        ca++;
        tot = 0;
        for(i = 1; i <= 6; i++) {
            for(j = 1; ; j <<= 1) {
                if(a[i] > 0) {
                    if(a[i] <= j) {
                        g[tot++] = MP(i * a[i], i);
                        break;
                    }
                    g[tot++] = MP(i * j, i);
                    a[i] -= j;
                }
                else break;
            }
        }
        //for(i = 0; i < tot; i++) {
            //cout << g[i].AA << " " << g[i].BB << endl;
        //}
        memset(ok, 0, sizeof(ok));
        ok[0] = 1;
        for(i = 0; i < tot; i++) {
            for(j = sum / 2; j >= g[i].AA; j--) {
                ok[j] = ok[j] || ok[j - g[i].AA];
            }
        }
        //for(i = 0; i <= sum / 2; i++) cout << i << " ~ " << ok[i] << endl;
        printf("Collection #%d:\n", ca);
        if(sum % 2 == 0 && ok[sum / 2]) {
            printf("Can be divided.\n");
        }
        else {
            printf("Can't be divided.\n");
        }
        printf("\n");
    }
    return 0;
}
