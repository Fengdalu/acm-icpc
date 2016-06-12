#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

typedef long long LL;
LL C[100][100];

void init() {
    for(int i = 0; i < 100; i++) {
        C[i][0] = 1;
        for(int j = 1; j < i; j++) {
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
        }
        C[i][i] = 1;
    }
}

char s[100];
void run() {
    init();
    scanf("%s", s);
    int len = strlen(s);
    for(int i = 1; i < len; i++) {
        if(s[i] <= s[i - 1]) {
            puts("0");
            return ;
        }
    }
    LL ans = 0;
    for(int i = 0; i < len - 1; i++)  ans += C[26][i + 1];
    char m = 'a';
    for(int i = 0; i < len; i++) {
        for(char c = m; c < s[i]; c++) {
            ans += C['z' - c][len - i - 1];
        }
        if(s[i] + 1 > m) m = s[i] + 1;
    }
    cout << ans + 1<< endl;
}

int main() {
    run();
}
