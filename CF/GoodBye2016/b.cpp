#include <bits/stdc++.h>

using namespace std;

char buf[200];
int main() {
    int n;
    scanf("%d", &n);
    int dis = 0;
    bool flag = true;
    while(n--) {
        int k; string s;
        scanf("%d%s", &k, buf);
        s = string(buf);
        if(s == "North")  {
            if(dis == 0) flag = false;
            else dis -= k;
        }
        else if(s == "South") {
            if(dis == 20000) flag = false;
            else dis += k;
        }
        else if(dis == 0 || dis == 20000) flag = false;
        if(dis < 0 || dis > 20000) flag = false;
    }
    if(flag && dis == 0) printf("YES");
    else printf("NO");
    return 0;
}
