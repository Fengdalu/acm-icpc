#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

char s[10000010];
const int mod = 10000;
int f1[mod], f2[mod];
int main() {
    int n, cas = 1;
    for(int i = 0; i < mod; i++) f1[i] = i % 73;
    for(int i = 0; i < mod; i++) f2[i] = i % 137;
    while(~scanf("%s", s)) {
        printf("Case #%d: ", cas++);
        int len = strlen(s);
        int m1 = 0, m2 = 0;
        for(int i = 0; i < len; i++) {
            m1 = (m1 * 10) + s[i] - '0'; m1 = f1[m1];
            m2 = (m2 * 10) + s[i] - '0'; m2 = f2[m2];
        }
        if(!m1 && !m2) puts("YES"); else puts("NO");
    }
    return 0;
}

