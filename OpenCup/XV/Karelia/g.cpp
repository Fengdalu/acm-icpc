#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <stack>
#include <queue>
using namespace std;

int n;
char s[10000];
int len;

string ck(string a, string b) {
    if(a.size() == b.size()) return min(a, b);
    return (a.size() < b.size()) ? a : b;
}
string cal(int l, int r) {
    int tot = 0;
    for(int i = l; i <= r; i++) {
        if(tot == 0 && s[i] == '|') return ck(cal(l, i - 1), cal(i + 1, r));
        if(s[i] == '(') tot++;
        if(s[i] == ')') tot--;
    }
    int k = l;
    queue<string>q;
    while(k <= r) {
        if(s[k] == '(') {
            int tot = 1;
            int start = k;
            k++;
            while(tot) {
                if(s[k] == ')') tot--;
                else if(s[k] == '(')tot++;
                k++;
            }
            q.push(cal(start + 1, k - 2));
        }
        else { string ss; ss.push_back(s[k]); q.push(ss); k++; }
    }
    string pre = "";
    string ans("");
    while(q.size()) {
        if(q.front() == "*") {
            q.pop();
            pre = "";
        }
        else {
            ans += pre;
            pre = q.front();
            if(q.front() == "$") pre = "";
            q.pop();
        }
    }
    if(pre != "") ans += pre;
    return ans;
}

int main() {
    freopen("shortest-accepted.in", "r", stdin);
    scanf("%d", &n);
    while(n--) {
        scanf("%s", s);
        len = strlen(s);
        string ans = cal(0, len - 1);
        if(ans == "") ans = "$";
        printf("%s\n", ans.c_str());
    }
    return 0;
}
