#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

struct obj
{
    int id; int c;
}t[200];

char s[200][200];
bool pp[200][200];
bool f[200];

int cmp(obj a, obj b)
{
    return a.c < b.c;
}

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> s[i];

    int ans = 0;
    memset(pp, 0, sizeof pp);

    bool res = true;
    for(int i = 0; i < n; i++)
    {
        bool flg = false;
        for(int j = 0; j < n; j++)
        if(s[i][j] == '.')
        {
            flg = true;
            pp[i][j] = true;
            break;
        }
        if(!flg) { res = false; break; }
    }
    if(!res)
    {
        res = true;
        memset(pp, 0, sizeof pp);
        for(int j = 0; j < n; j++)
        {
            bool flg = false;
            for(int i = 0; i < n; i++)
            if(s[i][j] == '.')
            {
                flg = true;
                pp[i][j] = true;
                break;
            }
            if(!flg){ res = false; break; }
        }
    }
    if(!res) cout << -1 << endl;
    else
    {
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
            if(pp[i][j])
                cout << i + 1 << " " << j + 1 << endl;
    }
    return 0;
}
