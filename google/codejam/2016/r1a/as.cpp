#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

string S;
vector<string>a;
void dfs(string s, int x) {
    if(x == S.size()) { a.push_back(s); }
    else {
        if(x == 0) { dfs(S.substr(0, 1), x + 1); }
        else {
            dfs(s + S[x], x + 1);
            dfs(S[x] + s, x + 1);
        }
    }
}
int main() {
    int T;
    cin >> T;
    for(int tt = 0; tt < T; tt++) {
        cin >> S;
        dfs("", 0);
        a.clear();
        sort(a.begin(), a.end());
        reverse(a.begin(), a.end());
        cout << "Case #" << tt + 1 << ": " << a[0] << endl;
    }
}
