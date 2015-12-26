#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
using namespace std;

int n;
int h1, a1, d1;
int h2, a2, d2;
char buf[10];


int main() {
    while(~scanf("%s", buf)) {
        scanf("%d%d%d", &h1, &a1, &d1);
        scanf("%d%d%d", &h2, &a2, &d2);
        int k1 = a1 - d2;
        int k2 = a2 - d1;
        if(k1 <= 0) {
            printf("Warrior loses\n");
        }
        else if(k2 <= 0) {
            printf("Warrior wins\n");
        }
        else {
            int t1 = (h1 + k2 - 1) / k2;
            int t2 = (h2 + k1 - 1) / k1;
            if(buf[0] == 'W') t2--;
            else t1--;
            if(t1 < t2) printf("Warrior loses\n");
            else printf("Warrior wins\n");
        }
    }
    return 0;
}
