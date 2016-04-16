#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

string S;
int main() {
    int T;
    cin >> T;
    for(int tt = 0; tt < T; tt++) {
        cin >> S;
        string t;
        for(int i = 0; i < S.size(); i++) {
            if(S[i] + t > t + S[i])
                t = S[i] + t;
            else
                t = t + S[i];
        }
        cout << "Case #" << tt + 1 << ": " << t << endl;
    }
}
