#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char s[200010];
int main() {
    scanf("%s", s);
    int len = strlen(s);
    int ans = 0;
    int tot = 0;
    int pre = 0;
    s[len] = '#';
    len++;
    for(int i = 1; i < len; i++) {
        if(i != len - 1 && s[i] == s[i - 1]) continue;
        else {
            int j;
            if((i - pre) % 2 == 1) j = pre + 1;
            else j = pre;
            char op;
            for(op = 'a'; op != 'z' + 1; op++)
                if(op != s[i] && op != s[pre] && (pre == 0 || op != s[pre - 1])) break;
            while(j < i) {
                s[j] = op;
                j += 2;
            }
            pre = i;
        }
    }
    s[len - 1]  = 0;
    printf("%s", s);
}

