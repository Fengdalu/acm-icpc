#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int cnt['z' + 1][2];
char s[100];
int main() {
    int n;
    while(~scanf("%d", &n)) {
        memset(cnt, 0, sizeof cnt);
        for(int i = 0; i < n; i++) {
            scanf("%s", s);
            int len = strlen(s);
            cnt[s[0]][0]++, cnt[s[len - 1]][1]++;
        }
        int ans = 0;
        for(char ch = 'a'; ch <= 'z'; ch++) if((cnt[ch][0] + cnt[ch][1]) & 1) ans++;
        if(ans <= 2) puts("Yes");
        else puts("No");
    }
    return 0;
}
