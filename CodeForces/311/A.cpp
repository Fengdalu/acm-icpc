#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int c, cc, l;
    int n[3], m[3];
    scanf("%d", &c);
    for(int i = 0; i < 3; i++) scanf("%d%d", &n[i], &m[i]);

    l = c - n[1] - n[2];
    cc = min(m[0], l);
    printf("%d ", cc);

    c -= cc;

    l = c - n[2];
    cc = min(m[1], l);
    printf("%d ", cc);

    c -= cc;

    printf("%d\n", c);
    return 0;
}
