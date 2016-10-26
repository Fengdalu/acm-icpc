#include <bits/stdc++.h>

std::string s;
char buf[1010];
void cal(std::string s, int &A, int &B) {
    if(s.size() >= 3 && s[s.size() - 3] == '.') {
        B += atoi(s.substr(s.size() - 2, 2).c_str());
        int tmp = 0;
        for(int i = 0; i < s.size() - 2; i++) {
            if(s[i] == '.') continue;
            tmp = tmp * 10 + s[i] - '0';
        }
        A += tmp;
        return ;
    }
    int tmp = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '.') continue;
        tmp = tmp * 10 + s[i] - '0';
    }
    A += tmp;
}

int main() {
    scanf("%s", buf);
    s = std::string(buf);
    int J = 0;
    int A = 0, B = 0;
    while(J < s.size()) {
        while(isalpha(s[J])) J++;
        int P = J;
        while(!isalpha(s[J]) && J < s.size()) J++;
        cal(s.substr(P, J - P), A, B);
    }
    A = A + B / 100;
    B %= 100;
    std::string ans;
    bool flag = B != 0;
    int cnt = 0;
    while(B) {
        cnt++;
        ans.push_back(B % 10 + '0');
        B /= 10;
    }
    if(cnt < 2 && flag) ans.push_back('0');
    if(flag) ans.push_back('.');
    cnt = 0;
    while(A) {
        if(cnt != 0 && cnt % 3 == 0) ans.push_back('.');
        cnt ++;
        ans.push_back(A % 10 + '0');
        A /= 10;
    }
    if(cnt < 1) ans.push_back('0');
    std::reverse(ans.begin(), ans.end());
    printf("%s\n", ans.c_str());
    return 0;
}
