#include <bits/stdc++.h>

char s[100];
char ans[2][100];
std::map<char, std::vector<int> >f;

int main() {
    scanf("%s", s);
    for(int i = 0; i < 27; i++)
        f[s[i]].push_back(i);
    int w = 0;
    int p1, p2;
    char sp;
    for(char a = 'A'; a <= 'Z'; a++)
        if(f[a].size() == 2) {
            w = f[a][1] - f[a][0] - 1;
            p1 = f[a][0], p2 = f[a][1];
            sp = a;
        }
    if(w < 1) {
        puts("Impossible");
        return 0;
    }
    if(w == 25) {
        ans[0][0] = sp;
        int J = 1;
        for(int i = 1; i < 13; i++)
            ans[0][i] = s[J++];
        for(int i = 12; i >= 0; i--)
            ans[1][i] = s[J++];
    }
    else if(w % 2 == 0) {
        int L = w / 2;
        int p = 12 - L;
        ans[0][p] = sp;
        int J = 0;

        if(p1 > p + 1) {
            for(int i = p1 - p - 2; i >= 0; i--)
                ans[0][i] = s[J++];
        }

        for(int i = std::max(0, p - p1 + 1); i <= p; i++)
            ans[1][i] = s[J++];
        J = p1 + 1;
        for(int i = p + 1; i < 13; i++)
            ans[0][i] = s[J++];
        for(int i = 12; i >= p + 1; i--)
            ans[1][i]  = s[J++];
        J = p2 + 1;
        for(int i = p - 1; i >= 0 && J < 27; i--)
            ans[0][i] = s[J++];
        int i = 0;
        while(J < 27)
            ans[1][i++] = s[J++];
    }
    else {
        int L = (w) / 2;
        int p = 12 - L;
        ans[0][p] = sp;
        int J = 0;
        if(p1 > p) {
            for(int i = p1 - p - 1; i >= 0; i--) {
                ans[0][i] = s[J++];
            }
        }
        for(int i = std::max(0, p - p1); i < p; i++)
            ans[1][i] = s[J++];
        J = p1 + 1;
        for(int i = p + 1; i < 13; i++)
            ans[0][i] = s[J++];
        for(int i = 12; i >= p; i--)
            ans[1][i]  = s[J++];
        J = p2 + 1;
        for(int i = p - 1; i >= 0 && J < 27; i--)
            ans[0][i] = s[J++];
        int i = 0;
        while(J < 27)
            ans[1][i++] = s[J++];
    }
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 13; j++)
        if(ans[i][j]) printf("%c", ans[i][j]);
        else printf(" ");
        puts("");
    }
    /*
    printf("%s\n", ans[0]);
    printf("%s\n", ans[1]);
    */
    return 0;
}
