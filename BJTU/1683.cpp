#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char s[110];
int c[110];

int main()
{
    ios::sync_with_stdio(false);
    while(cin >> s)
    {
        int len = strlen(s);
        int cnt = 0;
        int tmp = 0;
        for(int i = 0; i < len; i++)
        {
            if(s[i] == '@')
            {
                c[cnt++] = tmp;
                tmp = 0;
            }
            else tmp++;
        }
        c[cnt++] = tmp;
        if(cnt == 1) { cout << "No solution" << endl; continue; }
        long long ans = (c[0] != 0);
        for(int i = 1; i < cnt - 1; i++)
            ans *= (long long)(c[i] - 1);

        ans *= (long long)(c[cnt - 1] != 0);
        //cout << ans << endl;
        if(ans <= 0) cout << "No solution" << endl;
        else if(ans == 1)
        {
            int j;
            for(j = len - 1; ; j--) if(s[j] == '@') break;
            int i = 0;
            for(; s[i] != '@'; i++) cout << s[i];
            for(;i < j;)
            {
                if(s[i] == '@') { cout << s[i++]; continue; }
                cout << s[i++];
                cout << ",";
                cout << s[i++];
            }
            for(;j < len; j++) cout << s[j];
            cout << endl;
        }
        else cout << ans << endl;
    }
    return 0;
}
