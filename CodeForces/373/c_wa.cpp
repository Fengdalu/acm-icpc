#include <bits/stdc++.h>

#define cmax(x,y) x = std::max(x, y)
#define cmin(x,y) x = std::min(x, y)

char s[200100];
int add[200100];
int n, t;
int main() {
    scanf("%d%d", &n, &t);
    scanf("%s", s);
    std::reverse(s, s + n);
    int pre = 0;
    int w = 0;
    bool flag = false;
    int pos = 0;
    for(int i = 0; i < n; i++) if(s[i] == '.') { pos = i + 1; break; }
    for(int i = 0; i < n - 1; i++) if(s[i] != '.') {
        w++;
        if(s[i] - '0' >= 5) {
            if(w > t) break;
            t -= w;
            pre = i + 1;
            while(s[pre] == '.') pre++;
            s[pre]++;
            int g = pre;
            while(s[g] - '0' >= 10) {
                if(s[g] == '.') { g++; continue; }
                s[g] = (s[g] - '0') % 10 + '0';
                if(s[g + 1] != '.')
                    s[g + 1]++, g++, pre++;
                else s[g + 2]++, g += 2, pre += 2;
            }
            w = 0;
            n = std::max(n, g + 1);
        }
    }
    for(int i = n - 1; i >= pre; i--) printf("%c", s[i]);
    for(int i = pre; i > pos; i--) printf("0");
    return 0;
}

