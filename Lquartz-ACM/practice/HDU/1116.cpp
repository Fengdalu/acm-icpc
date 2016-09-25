#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

#define Maxn 30
int appear[Maxn], ideg[Maxn], odeg[Maxn];
char str[1111];
int n;
int fa[Maxn], used[Maxn];

int getfa(int x) {
    if(fa[x] == x)return x;
    else return (fa[x] = getfa(fa[x]));
}

int main() {
    int i, j, u, v, x, y, ex;
    int T;
    scanf("%d", &T);
    for(int CA = 1; CA <= T; CA++) {
        scanf("%d", &n);
        for(i = 0; i <= 26; i++) {
            odeg[i] = ideg[i] = 0;
            fa[i] = i;
            used[i] = 0;
        }
        ex = -1;
        for(i = 1; i <= n; i++) {
            scanf("%s", str);
            u = str[0] - 'a';
            v = str[strlen(str) - 1] - 'a';
            odeg[u]++; ideg[v]++;
            used[v] = used[u] = 1;
            x = getfa(u), y = getfa(v);
            ex = x;
            if(x != y) {
                fa[y] = x;
            }
        }
        for(i = 0, j = 0, u = 0, v = 0; i < 26; i++) {
            if(ideg[i] == odeg[i]) continue;
            else if(ideg[i] == odeg[i] + 1) u++;
            else if(ideg[i] + 1 == odeg[i]) v++;
            else {
                j++;
                break;
            }
        }
//        cout << j  << " " << u << " " << v << endl;
        for(i = 0, y = 0; i < 26; i++) {
            x = getfa(i);
            if(x == i && used[i]) {
                y++;
            }
        }
        if(y > 1) j++;
//        cout << j << endl;
        if(j == 0 && u == v && u < 2) {
            printf("Ordering is possible.\n");
        }
        else {
            printf("The door cannot be opened.\n");
        }
    }
    return 0;
}
