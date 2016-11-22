#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define N 20010

struct obj
{
    int id;
    string a, b;
}f[N];
int n;

string cal(string &s)
{
    string ans = s;
    for(int i = 0; i < ans.length(); i++) ans[i] = tolower(ans[i]);
    int p = ans.find('@', 0);

    if(ans.substr(p + 1) == "bmail.com")
    {
        string pre = "";
        for(int i = 0; i < p; i++)
        if(ans[i] == '.') continue;
        else if(ans[i] == '+') break;
        else pre = pre + ans[i];
        return pre + "@" + "bmail.com";
    }
    return ans;
}

int cmp(const obj &a, const obj &b)
{
    if(a.b == b.b) return a.id < b.id;
    return a.b < b.b;
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> f[i].a;
    for(int i = 0; i < n; i++) f[i].id = i;
    for(int i = 0; i < n; i++) f[i].b = cal(f[i].a);
    sort(f, f + n, cmp);

    int p = 0;
    int cc = 1;
    int g = 1;
    for(int i = 1; i < n; i++) if(f[i].b != f[i - 1].b) g++;

    cout << g << endl;
    for(int i = 1; i < n; i++)
    {
        if(f[i].b != f[i - 1].b)        {
            cout << cc;
            cc = 1;
            for(int j = p; j < i; j++) cout << " " << f[j].a;
            cout << endl;
            p = i;
        }
        else cc++;
    }
    cout << cc << " ";
    cc = 1;
    for(int j = p; j < n; j++) cout << " " << f[j].a;
    cout << endl;
    return 0;
}
