#include <iostream>
#include <cstdio>
#include <cstring>
#include <bitset>
using namespace std;

bitset<10010>p1[27], p2[27], f[27], g[27], b1, b2;
int l0[27], l1[27];
int last[27];
char a[10010], b[10010];

int main() {
    while(~scanf("%s%s", a, b)) {
        int n;
        n = strlen(a);
        for(int i = 0; i < 27; i++) p1[i].reset(), p2[i].reset();
        b1.reset(), b2.reset();
        p1[a[0] - 'a'][0] = 1;
        p2[b[0] - 'a'][0] = 1;
        b1[0] = b2[0] = (a[0] == b[0]);
        memset(last, 0, sizeof last);
        printf("%d", (a[0] == b[0]));
        for(int i = 1; i < n; i++) {
            int ca = a[i] - 'a', cb = b[i] - 'a';
            p1[ca] <<= (i - last[ca]); last[ca] = i;
            p1[cb] <<= (i - last[cb]); last[cb] = i;

            p1[ca][0] = 1;
            p2[cb][i] = 1;
            b1 <<= 1; b1 &= p2[ca]; b1[0] = (b[0] == a[i]);
            b2 &= p1[cb]; b2[i] = (a[0] == b[i]);
            if(b1[i] || b2[0] || (b1 & (b2 >> 1)).any()) printf("1"); else printf("0");
        }
        puts("");
    }
    return 0;
}
