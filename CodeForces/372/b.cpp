#include <bits/stdc++.h>

char s[50010];
int f[300];
int main() {
    scanf("%s", s);
    int len = strlen(s);
    if(len < 26) {
        puts("-1");
        return 0;
    }
    for(int i = 0; i < 25; i++) f[s[i]]++;
    for(int i = 25; i < len; i++) {
       f[s[i]]++;
       bool flag = true;
       int cnt = 0;
       for(char ch = 'A'; ch != 'Z' + 1 && flag; ch++) {
           if(f[ch] > 1)  flag = false;
           if(f[ch] == 1) cnt++;
       }
       if(flag && cnt + f['?'] == 26) {
           char J = 'A';
           for(int j = i - 25; j <= i; j++) if(s[j] == '?') {
                while(J != 'Z' + 1 && f[J] == 1) J++;
                s[j] = J;
                J++;
           }
           for(int j = 0; j < len; j++) if(s[j] == '?'){
                s[j] = 'A';
           }
           printf("%s\n", s);
           return 0;
       }
       f[s[i - 25]]--;
    }
    puts("-1");
    return 0;
}
