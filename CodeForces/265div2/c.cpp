#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

char a[1000];
char b[1000];
int n;
int p;
int main() {
    scanf("%d%d", &n, &p);
    char s = 'a' + p - 1;
    scanf("%s", a);
    reverse(a, a + n);
    for(int i = 0; i < n; i++) {
        strcpy(b, a);
        for(char c = b[i] + 1; c != s + 1; c++) {
        b[i] = c;
        bool flag = true;
        for(int j = i; j < n - 1 && flag; j++)
        if(b[j] == b[j + 1]) flag = false;
        for(int j = i; j < n - 2; j++)
        if(b[j] == b[j + 2]) flag = false;
        if(flag) {
            for(int j = i - 1; j >= 0; j--)
            if(j == n - 1) {
                if(b[j + 1] == 'a') b[j] = 'b';
                else b[j] = 'a';
            }
            else {
                if(b[j + 1] != 'a' && b[j + 2] != 'a') b[j] = 'a';
                else if(b[j + 1] != 'b' && b[j + 2] != 'b') b[j] = 'b';
                else b[j] = 'c';
            }
            reverse(b, b + n);
            printf("%s", b);
            return 0;
        }
        }
    }
    puts("NO");
}

