#include <cstdio>
#include <cstring>
#include <string>
#include <cstring>
#include <iostream>
#include <sstream>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

char s[100];
int main() {
    int n;
    cin >> n;
    while(n--) {
        scanf("%s", s);
        int len = strlen(s + 4), p = 10, tot = 0;
        int y = atoi(s + 4);
        for(int k = 1; k < len; k++) {
            tot += p;
            p *= 10;
        }
        while(y < 1989 + tot) y += p;
        printf("%d\n", y);
    }
    return 0;
}
