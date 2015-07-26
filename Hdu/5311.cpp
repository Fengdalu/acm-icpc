#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

string s("anniversary");
string a, b, c;
string f;
char buf[200];

int main()
{
    int T; scanf("%d", &T);
    while(T--)
    {
        scanf("%s", buf);
        f = string(buf);
        bool flg = false;
        for(int i = 1; i < s.length(); i++) for(int j = 1; j < s.length(); j++)
        if(i + j < s.length())
        {
            int k = s.length() - i - j;
            a = s.substr(0, i); b = s.substr(i, j); c = s.substr(i + j, k);
            //cout <<a << " " << b << " " << c << endl;
            int p;
            p = f.find(a, 0);
            if(p != f.npos) p = f.find(b, p + a.size());
            if(p != f.npos) p = f.find(c, p + b.size());
            if(p != f.npos) { flg = true; break; }
        }
        if(flg) puts("YES"); else puts("NO");
    }
    return 0;
}
