#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

char ss[10] = "+-*/";

double cal(double a, char c, double b)
{
    if (c == '/' && b == 0) return 240;
    if (c == '+') return a + b;
    if (c == '-') return a - b;
    if (c == '*') return a * b;
    if (c == '/') return a / b;
}

int main()
{
    double a, b, c, d;
    cin >> a >> b >> c >> d;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            for (int k = 0; k < 4; k++)
            {
                double kk;
                kk = cal(cal(a, ss[i], b), ss[j], cal(c, ss[k], d));
                if (kk == 24.0) {printf("(%.0f%c%.0f)%c(%.0f%c%.0f)\n", a, ss[i], b, ss[j], c, ss[k], d); return 0;}
                kk = cal(cal(cal(a, ss[i], b), ss[j], c), ss[k], d);
                if (kk == 24.0) {printf("(%.0f%c%.0f)%c%.0f)%c%.0f\n", a, ss[i], b, ss[j], c, ss[k], d); return 0;}
                kk = cal(cal(a, ss[i], cal(b, ss[j], c)), ss[k], d);
                if (kk == 24.0) {printf("(%.0f%c%.0f)%c%.0f)%c%.0f\n", a, ss[i], b, ss[j], c, ss[k], d); return 0;}
                kk = cal(a, ss[i], cal(cal(b, ss[j], c), ss[k], d));
                if (kk == 24.0) {printf("%.0f%c((%.0f%c%.0f)%c%.0f)\n", a, ss[i], b, ss[j], c, ss[k], d); return 0;}
                kk =  cal(a, ss[i], cal(b, ss[j], cal(c, ss[k], d)));
                if (kk == 24) {printf("%.0f%c(%.0f%c(%.0f%c%.0f))\n", a, ss[i], b, ss[j], c, ss[k], d); return 0;}
                //	printf("%lf ", cal(a, ss[i], cal(b, ss[j], cal(c, ss[k], d))));
            }
    //	cout << cal(a, '*', cal(b, '-', cal(c, '/', d)));
    return 0;
}