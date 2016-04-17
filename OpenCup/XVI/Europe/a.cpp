#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <stack>
using namespace std;

const char* str[7] = {
    "....x.xxxxx.xxxxx.x...x.xxxxx.xxxxx.xxxxx.......xxxxx.xxxxx.xxxxx.",
    "....x.....x.....x.x...x.x.....x.........x...x...x...x.x...x.x...x.",
    "....x.....x.....x.x...x.x.....x.........x...x...x...x.x...x.x...x.",
    "....x.xxxxx.xxxxx.xxxxx.xxxxx.xxxxx.....x.xxxxx.xxxxx.xxxxx.x...x.",
    "....x.x.........x.....x.....x.x...x.....x...x...x...x.....x.x...x.",
    "....x.x.........x.....x.....x.x...x.....x...x...x...x.....x.x...x.",
    "....x.xxxxx.xxxxx.....x.xxxxx.xxxxx.....x.......xxxxx.xxxxx.xxxxx.",
};
const int ans[11] = {1, 2, 3, 4, 5, 6, 7, -1, 8, 9, 0};
const int st[11] = {60, 0, 6, 12, 18, 24, 30, 36, 48, 54, 42};

char s[7][1000];
char res[7][1000];
int chk(int j) {
    int len = strlen(str[0]);
    for(int i = 0; i < len; i += 6) {
         bool flag = true;
         for(int k = 0; k < 5; k++)
            for(int p = 0; p < 7; p++)
                if(s[p][k + j] != str[p][i + k]) flag = false;
         if(flag) {
            return ans[i / 6];
         }
    }
}

int main() {
    for(int i = 0; i < 7; i++) scanf("%s", s[i]);
    int len = strlen(s[0]);
    long long a = 0, b = 0;
    for(int i = 0 ; i < len; i += 6) {
        int r = chk(i);
        if(r == -1) swap(a, b);
        else a = a * 10LL + r;
    }
    long long c = a + b;
    stack<int>q;
    if(c == 0) q.push(0);
    memset(res, 0, sizeof res);
    while(c) {
        q.push(c % 10) ;
        c /= 10;
    }
    int t = 0;
    while(q.size()) {
        int x = q.top();
        q.pop();
        x = st[x];
        for(int i = 0; i < 7; i++)
            for(int k = 0; k < 6; k++)
            res[i][t + k] = str[i][x + k];
        t += 6;
    }
    len = strlen(res[0]);
    for(int i = 0; i < 7; i++) {
        res[i][len - 1] = 0;
        printf("%s\n", res[i]);
    }
    return 0;
}
