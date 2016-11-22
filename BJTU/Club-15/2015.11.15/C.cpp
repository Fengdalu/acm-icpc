#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

vector<int>G;

int main()
{
    int n, m;
    while(true)
    {
        scanf("%d%d", &n, &m);
        if(!n && !m) break;
        int sum = 1;
        while(m)
        {
            if(m & 1) sum *= n;
            m /= 2; sum %= 1000; n *= n; n %= 1000;
        }
        printf("%d\n", sum);
    }
    return 0;
}

