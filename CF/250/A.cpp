#pragma comment(linker, "/STACK:36777216")
//#pragma GCC optimize ("O2")
#define LOCAL
//#include "testlib.h"
#include <functional>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <numeric>
#include <cstring>
#include <climits>
#include <cassert>
#include <complex>
#include <cstdio>
#include <string>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <list>
#include <set>
#include <map>

using namespace std;
#define LL long long

string a[4];
string *s;

int main()
{
    ios::sync_with_stdio(false);
    for(int i = 0; i < 4; i++) cin >> a[i];
    for(int i = 0; i < 4; i++) a[i] = a[i].substr(2, a[i].size() - 2);

    int ans = -1;
    bool flg = false;
    for(int i = 0; i < 4; i++)
    {
        int c1 = 0, c2 = 0;
        for(int j = 0; j < 4; j++)
        if(i != j)
        {
            if(a[j].size() * 2 <= a[i].size()) c1++;
            if( a[j].size() >= 2 * a[i].size() ) c2++;
        }
        if(c1 >= 3 || c2 >= 3)
        {
            if(ans == -1) ans = i;
            else flg = true;
        }
    }
//    cout << ans << endl;
    if(ans == -1 || flg) printf("C\n");
    else printf("%c\n", 'A' + ans);
    return 0;
}

