#include <iostream>

using namespace std;

char s[10000];
int n;

bool check(char s[10000])
{
    for(int i = 0; i < n; i++) if(s[i] == '?') return false;
    for(int i = 0; i < n / 2; i++) if(s[i] != s[n - i - 1]) return false;
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    while(cin >> n)
    {
        cin >> s;
        int l = -1;
        if(n == 1)
        {
            cout << "QwQ" << endl;
            continue;
        }

        if(check(s)) { cout << "QwQ" << endl; continue; }
        for(int i = n - 1; i >= 0; i--)
        if(!(n & 1 && i == n / 2))
            if(s[i] == '?') { l = i; break; }
        for(int i = 0; i < n; i++)
        if(s[i] == '?')
            s[i] = 'a';
        if(check(s)) s[l] = 'b';
        if(check(s)) cout << "QwQ" << endl;
        else cout << s << endl;
    }
    return 0;
}
