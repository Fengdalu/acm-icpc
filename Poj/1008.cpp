#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

const char* a[19] = {"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu", "uayet"};
const int aa[19] = {20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 5};
const char* b[20] = {"imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"};

int s2n(int y, char m[], long long d)
{
    for (int i = 0; i < 19; i++)
    {
        if (strcmp(m, a[i])) d = d + aa[i];
        else break;
    }
    return d + (y) * 365;
}

int main()
{
    int n;
    char m[20];
    int y, d;
    cin >> n;
    cout << n << endl;
    while(n--)
    {
        scanf("%d. %s %d", &d, m, &y);
        //cout << d << m << y;
        int dd = s2n(y, m, d);
        //cout << dd << endl;
        printf("%d %s %d\n", dd % 13 + 1, b[dd % 20], dd / 260);
    }
    return 0;
}