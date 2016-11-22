#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
#define LL long long

vector<string>A, B;
string s;

int main() {
    ios::sync_with_stdio(false);
    cin >> s;
    string tmp("");
    for(int i = 0; i < s.length(); i++) {
        if(s[i] != ';' && s[i] != ',') tmp += s[i];
        if(s[i] == ';' || s[i] == ',' || i == s.length() - 1) {
            bool flg = true;
            if(tmp == "") { B.push_back(tmp); continue; }
            for(int j = 0; j < tmp.length(); j++) if(tmp[j] > '9' || tmp[j] < '0') {
                flg = false;
                break;
            }
            if(tmp[0] == '0') flg = false;
            if(flg || tmp == "0") A.push_back(tmp); else B.push_back(tmp);
            tmp = string("");
        }
    }
    if(s[s.length() - 1] == ',' || s[s.length() - 1] == ';') B.push_back(string(""));
    if(!A.size()) cout << "-" << endl;
    else {
        cout << "\"" << A[0];
        for(int i = 1; i < A.size(); i++) cout << "," << A[i]; cout << "\"" << endl;
    }
    if(!B.size()) cout << "-" << endl;
    else {
        cout << "\"" << B[0];
        for(int i = 1; i < B.size(); i++) cout << "," << B[i]; cout << "\"" << endl;
    }
    return 0;
}
