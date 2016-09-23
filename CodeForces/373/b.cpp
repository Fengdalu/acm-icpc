#include <bits/stdc++.h>

#define cmax(x,y) x = std::max(x, y)
#define cmin(x,y) x = std::min(x, y)

char s[1000100];
int n;
int check(int op) {
    int p = 0, q = 0;
    for(int i = 0; i < n; i++) {
        int num = (s[i] == 'r') ? 0 : 1;
        if(num != op)  {
            if(num) p++; else q++;
        }
        op ^= 1;
    }
    return abs(p - q) + std::min(p, q);
}

int main() {
    scanf("%d", &n);
    scanf("%s", s);
    std::cout << std::min(check(0), check(1)) << std::endl;
    return 0;
}
