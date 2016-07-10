#include <cstdio>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int f['Z' + 10];
int g[10];


int main() {
    int T;
    cin >> T;
    for(int C = 1; C <= T; C++) {
        memset(f, 0, sizeof f);
        memset(g, 0, sizeof g);
        string s;
        cin >> s;
        for(int i = 0; i < s.size(); i++)
            f[s[i]]++;
        g[0] = f['Z'];
        f['E'] -= g[0];
        f['R'] -= g[0];
        f['O'] -= g[0];

        g[2] = f['W'];
        f['T']  -= g[2];
        f['O'] -= g[2];


        g[6] = f['X'];
        f['S'] -= g[6];
        f['I'] -= g[6];

        g[7] = f['S'];
        f['N'] -= g[7];
        f['E'] -= 2 * g[7];
        f['V'] -= g[7];

        g[5] = f['V'];
        f['F'] -= g[5];
        f['I'] -= g[5];
        f['E'] -= g[5];

        g[8] = f['G'];
        f['I'] -= g[8];
        f['H'] -= g[8];
        f['T'] -= g[8];
        f['E'] -= g[8];

        g[3] = f['H'];
        f['T'] -= g[3];
        f['R'] -= g[3];
        f['E'] -= 2 * g[3];

        g[4] = f['R'];
        f['F'] -= g[4];
        f['O'] -= g[4];


        g[1] = f['O'];
        f['N'] -= g[1];
        g[9] = f['N'] / 2;
        cout << "Case #" << C << ": ";
        for(int i = 0; i < 10; i++)
            for(int j = 0; j < g[i]; j++) cout << i;
        cout << endl;
    }
    return 0;
}
