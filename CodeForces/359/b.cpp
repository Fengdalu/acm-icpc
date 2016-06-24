#include <cstdio>
#include <iostream>
using namespace std;

typedef long long ll;

const int maxn = 200;
int a[maxn];
int n;
int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n - 1; j++)
            if(a[j] > a[j + 1]) {
                printf("%d %d\n", j + 1, j + 2);
                swap(a[j], a[j + 1]);
            }
    return 0;
}
