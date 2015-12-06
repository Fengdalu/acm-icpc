#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

char s[10000];
string S, O, V;
string ans;

int main() {
    gets(s);
    int len = strlen(s);

    string w;
    bool flg = false;
    for(int i = 0; i < len; i++) {
        if(s[i] == '{' || s[i] == '(' || s[i] == '[') { flg = true; w = ""; }
        else  if(s[i] == '}' || s[i] == ')' || s[i] == ']') {
            if(s[i] == '}') O = w;
            else if(s[i] == ')') S = w;
            else if(s[i] == ']') V = w;
            w = "";
            flg = false;
            if(S != "" && V != "" && O != "") {
                ans += O;
                ans += " ";
                ans += S;
                ans += " ";
                ans += V;
                S = V = O = "";
            }
        }
        else if(flg) w += s[i];
        else ans += s[i];
    }
    int i = 0;
    for(;ans[i] == ' ';i++);
    for(int j = i; j < ans.length(); j++)  if(j == i) printf("%c", toupper(ans[j]));
    else if(ans[j] == ' ' &&  ans[j - 1] == ' ') continue;
    else printf("%c", tolower(ans[j]));
    return 0;
}