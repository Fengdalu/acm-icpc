#include <bits/stdc++.h>

using namespace std;
char s[1010];

int main() {
    while(gets(s) != NULL) {
        int n = strlen(s);
        int cur = 0, ans = 0, left = 0;

        for(int i = 0; i < n; i++) {
            if(s[i] == '+') {
                cur++;
                if(left != 0) left--; else ans++;
            }
            else {
                if(cur == 0) ans++; else cur--;
                left++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
