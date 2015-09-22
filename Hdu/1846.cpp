#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int c, n, m;
    cin >> c;
    while(c--)
    {
        cin >> m >> n;
        if(m % (n + 1) == 0) cout << "second" << endl;
        else cout << "first" << endl;
    }
    return 0;
}
